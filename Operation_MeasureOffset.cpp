#include "stdafx.h"
#include "CVInspector.h"
#include "Operation_MeasureOffset.h"

////////////////////
// COpOffsetTemplate
////////////////////
COpOffsetTemplate::COpOffsetTemplate()
{
	m_strName = _T("Offset Template");
	m_iType = OP_OFFSETTEMPLATE;

	m_iMethod = CV_TM_SQDIFF;
	m_dMatchingScoreThr = 0.7;

	m_iSearchAreaOffset = -1;

	m_iRefPointX = 0;
	m_iRefPointY = 0;

	m_dScaleX = 1.0;
	m_dScaleY = 1.0;
	m_dOffsetX = 0.0;
	m_dOffsetY = 0.0;

	m_dResultOffsetX = 0;
	m_dResultOffsetY = 0;

	m_strRefFilePath.Empty();
}

COpOffsetTemplate::~COpOffsetTemplate()
{
}

// COpOffsetTemplate ¸â¹ö ÇÔ¼ö
BOOL COpOffsetTemplate::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}
	
	if (m_TemplateImage.empty())
	{
		if (m_strRefFilePath.IsEmpty())
		{
			m_TemplateImage = m_InImage(Rect(0, 0, m_InImage.cols / 16, m_InImage.rows / 16)).clone();
			AfxMessageBox(_T("Set reference template image first."));			
		}
		else
		{
			CT2CA tmpStr(m_strRefFilePath);
			std::string strFile(tmpStr);
			m_TemplateImage = imread(strFile);
			if (m_TemplateImage.empty())
			{
				AfxMessageBox(_T("Invalid reference template file path. Cannot load template image."));
				return FALSE;
			}
		}
	}

	if (m_InImage.channels() != m_TemplateImage.channels())
	{
		AfxMessageBox(_T("Channel of the template image should be same as the channel of the input image."));
		return FALSE;
	}

	int iResultCols = m_InImage.cols - m_TemplateImage.cols;
	int iResultRows = m_InImage.rows - m_TemplateImage.cols;

	if (iResultCols < 0 || iResultRows < 0)
	{
		AfxMessageBox(_T("Size of the template image cannot be bigger than size of the target image."));
		return FALSE;
	}

	double dMinVal = 0.0;
	double dMaxVal = 0.0;
	Point minLoc;
	Point maxLoc;
	Point matchLoc;

	m_OutImage = m_InImage.clone();

	Mat resultImg(iResultRows, iResultCols, CV_32FC1);

	matchTemplate(m_InImage, m_TemplateImage, resultImg, m_iMethod);
	normalize(resultImg, resultImg, 0, 1, NORM_MINMAX, -1, Mat());

	minMaxLoc(resultImg, &dMinVal, &dMaxVal, &minLoc, &maxLoc, Mat());

	BOOL bMatched = FALSE;
	if (m_iMethod == CV_TM_SQDIFF || m_iMethod == CV_TM_SQDIFF_NORMED)
	{
		matchLoc = minLoc;
		if (m_dMatchingScoreThr < (1.0 - dMinVal))
		{
			bMatched = TRUE;
		}
	}
	else
	{
		matchLoc = maxLoc;
		if (m_dMatchingScoreThr < dMaxVal)
		{
			bMatched = TRUE;
		}
	}

	if (bMatched)
	{
		m_dResultOffsetX = (m_iRefPointX - matchLoc.x) * m_dScaleX + m_dOffsetX;
		m_dResultOffsetY = (m_iRefPointY - matchLoc.y) * m_dScaleY + m_dOffsetY;
	}
	else
	{
		m_dResultOffsetX = 0.0;
		m_dResultOffsetY = 0.0;
	}

	return TRUE;
}