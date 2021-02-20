#include "stdafx.h"
#include "CVInspector.h"
#include "Operation_Basic.h"

////////////////////
// COpOpenImage
////////////////////
COpOpenImage::COpOpenImage()
{
	m_strName = _T("Open Image");
	m_iType = OP_OPENIMAGE;
	m_iReadType = CV_LOAD_IMAGE_UNCHANGED;
}

COpOpenImage::~COpOpenImage()
{
}

// COpOpenImage ¸â¹ö ÇÔ¼ö
BOOL COpOpenImage::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	CT2CA tmpStr(m_strFileName);
	std::string strFile(tmpStr);

	m_OutImage = imread(strFile, m_iReadType);

	if (m_OutImage.empty())
	{
		return FALSE;
	}

	return TRUE;
}

////////////////////
// COpCaptureCam
////////////////////
COpCaptureCam::COpCaptureCam()
{
	m_strName = _T("Capture from Camera");
	m_iType = OP_CAPTURECAM;

	m_bOpened = FALSE;
	m_iCamNo = 0;
	m_iImgWidth = 640;
	m_iImgHeight = 480;
}

COpCaptureCam::~COpCaptureCam()
{
}

// COpCaptureCam ¸â¹ö ÇÔ¼ö
BOOL COpCaptureCam::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	if (!m_bOpened)
	{
		m_bOpened = m_Camera.open(m_iCamNo); // open the video camera no. 0
	}

	if (!m_bOpened)  // if not success
	{
		AfxMessageBox(_T("Cannot open Camera."));
		return FALSE;
	}

	double dWidth = m_Camera.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = m_Camera.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	if (dWidth != (double)m_iImgWidth)
	{
		m_Camera.set(CV_CAP_PROP_FRAME_WIDTH, (double)m_iImgWidth);
		Sleep(500);
	}
	if (dHeight != (double)m_iImgHeight)
	{
		m_Camera.set(CV_CAP_PROP_FRAME_HEIGHT, (double)m_iImgHeight);
		Sleep(500);
	}

	Mat frame;
	bool bSuccess = m_Camera.read(frame); // read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
		AfxMessageBox(_T("Cannot get a frame from Camera."));
		return FALSE;
	}
	else
	{
		m_Camera.read(frame); // read a new frame from video once more for get newest frame
	}

	m_OutImage = frame;

	return TRUE;
}

////////////////////
// COpArithmetic
////////////////////
COpArithmetic::COpArithmetic()
{
	m_strName = _T("Simple Arithmetic");
	m_iType = OP_ARITHMETIC;
	m_iOperatorType = 0;	// Add
	m_iSecondImgIndex = 0;
	m_dAlpha = 0.5;
	m_dBeta = 0.5;
	m_dGama = 0.0;
}

COpArithmetic::~COpArithmetic()
{
}

// CArithmatic ¸â¹ö ÇÔ¼ö
BOOL COpArithmetic::Check2Images(Mat img1, Mat img2)
{
	// check channels
	if (img1.channels() != img2.channels())
	{
		return FALSE;
	}

	// check dimension
	if (img1.cols != img2.cols || img1.rows != img2.rows)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL COpArithmetic::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();
	
	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Mat maskImage;
	if (pPrevOp2 != NULL)	maskImage = pPrevOp2->GetResultImage();

	if (m_iOperatorType != 6)
	{
		if (!Check2Images(m_InImage, maskImage))
		{
			AfxMessageBox(_T("Image format and size error!"));
			return FALSE;
		}
	}

	switch (m_iOperatorType)
	{
	case 0:	// add
		m_OutImage = m_InImage + maskImage;
		break;
	case 1:	// sub (Src - 2nd)
		m_OutImage = m_InImage - maskImage;
		break;
	case 2:	// sub (2nd - Src)
		m_OutImage = maskImage - m_InImage;
		break;
	case 3:	// and
		m_OutImage = m_InImage & maskImage;
		break;
	case 4:	// or
		m_OutImage = m_InImage | maskImage;
		break;
	case 5:	// xor
		m_OutImage = m_InImage ^ maskImage;
		break;
	case 6: //inverse
		m_OutImage = ~m_InImage;
		break;
	case 7:	// abs diff
		absdiff(m_InImage, maskImage, m_OutImage);
		break;
	case 8: // addWeight
		addWeighted(m_InImage, m_dAlpha, maskImage, m_dBeta, m_dGama, m_OutImage);
		break;
	default:
		break;
	}

	return TRUE;
}

////////////////////
// COpTimeDelay
////////////////////
COpTimeDelay::COpTimeDelay()
{
	m_strName = _T("Time Delay");
	m_iType = OP_TIMEDELAY;
	m_iDelayTime = 100;	//milliseconds
}

COpTimeDelay::~COpTimeDelay()
{
}

// COpTimeDelay ¸â¹ö ÇÔ¼ö
BOOL COpTimeDelay::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	Sleep(m_iDelayTime);

	return TRUE;
}

////////////////////
// COpCheckCondition
////////////////////
COpCheckCondition::COpCheckCondition()
{
	m_strName = _T("Check Condition");
	m_iType = OP_CHECKCONDITION;
	m_iIterCount = 0;
}

COpCheckCondition::~COpCheckCondition()
{
}

// COpCheckCondition ¸â¹ö ÇÔ¼ö
BOOL COpCheckCondition::Process(COperation* pPrevOp, COperation* pPrevOp2)
{

	return TRUE;
}