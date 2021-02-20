#include "stdafx.h"
#include "CVInspector.h"
#include "Operation_Process.h"


////////////////////
// COpFilter2D
////////////////////
COpFilter2D::COpFilter2D()
{
	m_strName = _T("Filter2D");
	m_iType = OP_FILTER2D;

	m_iDepth = -1;
	m_dDelta = 0.0;
	m_iBorderType = BORDER_DEFAULT;
	m_AnchorPos = CPoint(-1, -1);

	m_strKernel = _T("");
}

COpFilter2D::~COpFilter2D()
{
}

// COpFilter2D 멤버 함수
void COpFilter2D::ParseString(CString strInput)
{
	if (strInput.IsEmpty())
	{
		return;
	}

	m_strKernel = strInput;

	int i = 0;
	int j = 0;

	CString strTmp = _T("");
	CString strRow = _T("");

	double dVal = 0.0;

	Mat kernel = Mat::zeros(256, 256, CV_32F);

	while (AfxExtractSubString(strRow, strInput, i++, _T('\n')))
	{
		j = 0;
		while (AfxExtractSubString(strTmp, strRow, j++, _T(',')))
		{
			dVal = _wtof(strTmp);
			kernel.at<float>(i - 1, j - 1) = (float)dVal;
		}
	}

	Rect cropRect(0, 0, j - 1, i - 1);
	m_Kernel = kernel(cropRect).clone();
}

BOOL COpFilter2D::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_Kernel.empty())
	{
		AfxMessageBox(_T("Invalid Kernel"));
		return FALSE;
	}

	Point anchor(m_AnchorPos.x, m_AnchorPos.y);

	filter2D(m_InImage, m_OutImage, m_iDepth, m_Kernel, anchor, m_dDelta, m_iBorderType);

	return TRUE;
}

////////////////////
// COpMorphology
////////////////////
COpMorphology::COpMorphology()
{
	m_strName = _T("Morphology");
	m_iType = OP_MORPHOLOGY;
	m_iMorphologyType = 0;	// Erode
	m_iKernelSizeX = 3;
	m_iKernelSizeY = 3;
	m_iIterationNo = 1;
	m_AnchorPos = CPoint(-1, -1);
}

COpMorphology::~COpMorphology()
{
}

// COpMorphology 멤버 함수
BOOL COpMorphology::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_iKernelSizeX % 2 == 0 || m_iKernelSizeY % 2 ==0)
	{
		AfxMessageBox(_T("The kernel size should be an odd number."));
		return FALSE;
	}

	Mat kernel;
	/*if (m_iKernelSizeX <= 3 || m_iKernelSizeY <= 3)
	{
	kernel = Mat();
	}
	else*/
	{
		//kernel = getStructuringElement(0, Size(m_iKernelSize, m_iKernelSize), Point(m_iKernelSize / 2, m_iKernelSize / 2));
		kernel = getStructuringElement(m_iShapeStructure, Size(m_iKernelSizeX, m_iKernelSizeY), Point(m_iKernelSizeX / 2, m_iKernelSizeY / 2));
	}
	Point anchor(m_AnchorPos.x, m_AnchorPos.y);

	if (m_iMorphologyType == 0)	// Erode
	{
		erode(m_InImage, m_OutImage, kernel, anchor, m_iIterationNo);
	}
	else if (m_iMorphologyType == 1)	// Dilate
	{
		dilate(m_InImage, m_OutImage, kernel, anchor, m_iIterationNo);
	}
	else
	{
		morphologyEx(m_InImage, m_OutImage, m_iMorphologyType, kernel, anchor, m_iIterationNo);
	}

	return TRUE;
}


////////////////////
// COpBlur
////////////////////
COpBlur::COpBlur()
{
	m_strName = _T("Blur");
	m_iType = OP_BLUR;
	m_iBlurType = 0;	// Blur
	m_iKernelX = 3;
	m_iKernelY = 3;
	m_AnchorPos = CPoint(-1, -1);
	m_dGaussianSigma = 1.0;
	m_dBilateralSigmaColor = 150.0;
	m_dBilateralSigmaSpace = 150.0;
}

COpBlur::~COpBlur()
{
}

// COpBlur 멤버 함수
BOOL COpBlur::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Point anchor(m_AnchorPos.x, m_AnchorPos.y);
	Size kernelSize(m_iKernelX, m_iKernelY);

	if (m_iBlurType == 0)	// blur
	{
		blur(m_InImage, m_OutImage, kernelSize, anchor);
	}
	else if (m_iBlurType == 1)	// gaussian
	{
		GaussianBlur(m_InImage, m_OutImage, kernelSize, m_dGaussianSigma);
	}
	else if (m_iBlurType == 2)	// median
	{
		medianBlur(m_InImage, m_OutImage, m_iKernelX);
	}
	else if (m_iBlurType == 3)	// box filter
	{
		boxFilter(m_InImage, m_OutImage, -1, kernelSize, anchor);
	}
	else if (m_iBlurType == 4)	// bilateral
	{
		bilateralFilter(m_InImage, m_OutImage, m_iKernelX, m_dBilateralSigmaColor, m_dBilateralSigmaSpace);
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}


////////////////////
// COpEdge
////////////////////
COpEdge::COpEdge()
{
	m_strName = _T("Edge");
	m_iType = OP_EDGE;

	m_iEdgeType = 0;	// Laplacian
	m_iKernelSize = 1;
	m_dScale = 1.0;
	m_dDelta = 0.0;
	m_iDx = 1;
	m_iDy = 1;
}

COpEdge::~COpEdge()
{
}

// COpEdge 멤버 함수
BOOL COpEdge::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Edge function only can take a gray scale image."));
		return FALSE;
	}

	if (m_iKernelSize % 2 == 0)
	{
		AfxMessageBox(_T("Edge function kernel value must be an odd number. 1,3,5, or 7."));
		return FALSE;
	}

	if (m_iDx < 0 || m_iDy < 0)
	{
		AfxMessageBox(_T("Order of the deritive cannot be negative value."));
		return FALSE;
	}

	Mat tmpEdge;

	if (m_iEdgeType == 0)	// Laplacian
	{
		Laplacian(m_InImage, tmpEdge, CV_32F, m_iKernelSize, m_dScale, m_dDelta);
	}
	else if (m_iEdgeType == 1)	// Sobel
	{
		if (m_iDx > 0 && m_iDy > 0)
		{
			Mat tmpMat1, tmpMat2;
			Sobel(m_InImage, tmpMat1, CV_32F, m_iDx, 0, m_iKernelSize, m_dScale, m_dDelta);
			Sobel(m_InImage, tmpMat2, CV_32F, 0, m_iDy, m_iKernelSize, m_dScale, m_dDelta);
			addWeighted(tmpMat1, 0.5, tmpMat2, 0.5, 0, tmpEdge);
		}
		else
		{
			Sobel(m_InImage, tmpEdge, CV_32F, m_iDx, m_iDy, m_iKernelSize, m_dScale, m_dDelta);
		}
	}
	else if (m_iEdgeType == 2)	// Scharr
	{
		// Dx 와 Dy가 동시에 1이면 안된다.
		if (m_iDx > 0 && m_iDy > 0)
		{
			Mat tmpMat1, tmpMat2;
			Scharr(m_InImage, tmpMat1, CV_32F, m_iDx, 0, m_dScale, m_dDelta);
			Scharr(m_InImage, tmpMat2, CV_32F, 0, m_iDy, m_dScale, m_dDelta);
			addWeighted(tmpMat1, 0.5, tmpMat2, 0.5, 0, tmpEdge);
		}
		else
		{
			Scharr(m_InImage, tmpEdge, CV_32F, m_iDx, m_iDy, m_dScale, m_dDelta);
		}
	}
	else
	{
		return FALSE;
	}

	convertScaleAbs(tmpEdge, m_OutImage);

	return TRUE;
}


////////////////////
// COpFloodFill
////////////////////
COpFloodFill::COpFloodFill()
{
	m_strName = _T("Floodfill");
	m_iType = OP_FLOODFILL;

	m_iLowerDiff = 8;
	m_iUpperDiff = 8;
	m_iNeighbor = 8;
	m_bUseFixedRange = TRUE;
}

COpFloodFill::~COpFloodFill()
{
}

// COpFloodFill 멤버 함수
BOOL COpFloodFill::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	vector<Point> SeedPoints;

	if (NULL != pPrevOp2)
	{
		SeedPoints = pPrevOp->GetResultPoints();
		if (SeedPoints.size() <= 0)
		{
			AfxMessageBox(_T("Invalid seedpoints."));
			return FALSE;
		}
	}

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	BOOL bIsColor = FALSE;

	if (m_InImage.channels() != 1)
	{
		bIsColor = TRUE;
	}

	m_OutImage = m_InImage.clone();

	Mat MaskImage;
	MaskImage.create(m_InImage.rows + 2, m_InImage.cols + 2, CV_8UC1);
	MaskImage = Scalar::all(0);

	Point SeedPoint(0, 0);
	int iFlags = (255 << 8) + m_iNeighbor;

	if (m_bUseFixedRange)
	{
		iFlags += CV_FLOODFILL_FIXED_RANGE;
	}

	int iXStep = 1;
	int iYStep = 1;

	Scalar New_Val, Lo_Diff, Up_Diff;
	Rect ccomp;

	// SeedPoints가 이전 결과로 부터 입력되면
	if (NULL != pPrevOp2)
	{
		for (int i = 0; i < (int)(SeedPoints.size()); ++i)
		{
			uchar ucVal = m_OutImage.at<uchar>(SeedPoints[i].y, SeedPoints[i].x);

			if (ucVal != 0)
			{
				if (bIsColor)
				{
					Vec3b rgb = m_OutImage.at<Vec3b>(SeedPoints[i].y, SeedPoints[i].x);
					New_Val = Scalar(rgb[0], rgb[1], rgb[2]);
				}
				else
				{
					New_Val = Scalar(ucVal, ucVal, ucVal);
				}
				Lo_Diff = Scalar(m_iLowerDiff, m_iLowerDiff, m_iLowerDiff);
				Up_Diff = Scalar(m_iUpperDiff, m_iUpperDiff, m_iUpperDiff);

				floodFill(m_OutImage, MaskImage, SeedPoints[i], New_Val, &ccomp, Lo_Diff, Up_Diff, iFlags);
			}
		}
	}
	else
	{
		for (SeedPoint.x = 0; SeedPoint.x < m_OutImage.cols; SeedPoint.x += iXStep)
		{
			for (SeedPoint.y = 0; SeedPoint.y < m_OutImage.rows; SeedPoint.y += iYStep)
			{
				if (MaskImage.at<uchar>(SeedPoint.y + 1, SeedPoint.x + 1) != 0)
					continue;

				uchar ucVal = m_OutImage.at<uchar>(SeedPoint.y, SeedPoint.x);

				if (ucVal != 0)
				{
					if (bIsColor)
					{
						Vec3b rgb = m_OutImage.at<Vec3b>(SeedPoint.y, SeedPoint.x);
						New_Val = Scalar(rgb[0], rgb[1], rgb[2]);
					}
					else
					{
						New_Val = Scalar(ucVal, ucVal, ucVal);
					}
					Lo_Diff = Scalar(m_iLowerDiff, m_iLowerDiff, m_iLowerDiff);
					Up_Diff = Scalar(m_iUpperDiff, m_iUpperDiff, m_iUpperDiff);

					floodFill(m_OutImage, MaskImage, SeedPoint, New_Val, &ccomp, Lo_Diff, Up_Diff, iFlags);
				}
			}
		}
	}

	return TRUE;
}


////////////////////
// COpHistogram
////////////////////
COpHistogram::COpHistogram()
{
	m_strName = _T("Histogram");
	m_iType = OP_HISTOGRAM;

	m_iHistSize = 255;
	m_fHistRangeL = 0.0;
	m_fHistRangeH = 255.0;

	m_bShowDisplayImage = TRUE;
}

COpHistogram::~COpHistogram()
{
}

// COpHistogram 멤버 함수
BOOL COpHistogram::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	m_OutImage = m_InImage.clone();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Histogram function only can take a gray scale image."));
		return FALSE;
	}

	int iHistSize[1];
	float fHistRange[2];
	const float* fRanges[1];
	int iChannels[1];

	cv::MatND hist;

	iHistSize[0] = m_iHistSize;
	fHistRange[0] = m_fHistRangeL;
	fHistRange[1] = m_fHistRangeH;
	fRanges[0] = fHistRange;
	iChannels[0] = 0;

	calcHist(&m_InImage, 1, iChannels, cv::Mat(), hist, 1, iHistSize, fRanges);

	double dMax = 0.0;
	double dMin = 0.0;

	minMaxLoc(hist, &dMin, &dMax, 0, 0);
	int iXOffset = 64;
	int iYOffset = 64;

	int iRefSizeX = 1024;
	int iRefSizeY = 256;

	Mat histImg(iRefSizeY + (2 * iYOffset), iRefSizeX + (2 * iXOffset), CV_8UC3, cv::Scalar(255, 255, 255));
	int iHighest = (int)(0.9*iRefSizeY);
	int iBlockWidth = iRefSizeX / m_iHistSize;

	// Draw Bin Data
	for (int i = 0; i < iHistSize[0]; i++)
	{
		float fBinVal = hist.at<float>(i);
		int iIntensity = (int)(fBinVal*iHighest / dMax);
		Rect binRect(i*iBlockWidth + iXOffset, iRefSizeY - iIntensity + iYOffset, iBlockWidth, iIntensity);

		rectangle(histImg, binRect, Scalar::all(96), CV_FILLED);
	}

	// Draw Axis
	cv::line(histImg, Point(iXOffset, histImg.rows - 10), Point(iXOffset, 10), Scalar(0, 0, 0), 1, 8);
	cv::line(histImg, Point(10, histImg.rows - iYOffset), Point(histImg.cols - 10, histImg.rows - iYOffset), Scalar(0, 0, 0), 1, 8, 0);

	// Draw Tick
	for (int i = 0; i <= 16; i++)
	{
		int iTmpVal = (int)(i * m_fHistRangeH / 16);
		int iXPos = iXOffset + iBlockWidth * m_iHistSize / 16 * i;
		int iYPos = histImg.rows - iYOffset;

		cv::line(histImg, Point(iXPos, iYPos + 5), Point(iXPos, iYPos -  5), Scalar(0, 0, 0), 1);
		
		CString strTmp;
		strTmp.Format(_T("%d"), iTmpVal);
		CT2CA tmpStr(strTmp);
		std::string strLabel(tmpStr);

		cv::putText(histImg, strLabel, Point(iXPos - 10, iYPos + 20), FONT_HERSHEY_PLAIN, 1.0, Scalar(0, 0, 0), 1, 8);
	}	
	m_DispImage = histImg.clone();

	return TRUE;
}


////////////////////
// COpEqualHist
////////////////////
COpEqualHist::COpEqualHist()
{
	m_strName = _T("Equal Hist.");
	m_iType = OP_EQUALHIST;
}

COpEqualHist::~COpEqualHist()
{
}

// COpHistogram 멤버 함수
BOOL COpEqualHist::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Histogram Equalization only can take a gray scale image."));
		return FALSE;
	}

	equalizeHist(m_InImage, m_OutImage);

	return TRUE;
}


////////////////////
// COpMatchTemplate
////////////////////
COpMatchTemplate::COpMatchTemplate()
{
	m_strName = _T("Match Template");
	m_iType = OP_MATCHTEMPLATE;

	m_iMethod = CV_TM_SQDIFF;
	m_iTemplateImageNo = -1;
	m_bShowDisplayImage = TRUE;
}

COpMatchTemplate::~COpMatchTemplate()
{
}

// COpMatchTemplate
BOOL COpMatchTemplate::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Mat maskImage;
	if (pPrevOp2 != NULL)	maskImage = pPrevOp2->GetResultImage();

	if (maskImage.total() == 0)
	{
		AfxMessageBox(_T("Invalid template image."));
		return FALSE;
	}

	if (m_InImage.channels() != maskImage.channels())
	{
		AfxMessageBox(_T("Channel of the template image should be same as the channel of the input image."));
		return FALSE;
	}

	int iResultCols = m_InImage.cols - maskImage.cols;
	int iResultRows = m_InImage.rows - maskImage.cols;

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

	m_DispImage = m_InImage.clone();

	Mat resultImg(iResultRows, iResultCols, CV_32FC1);

	matchTemplate(m_InImage, maskImage, resultImg, m_iMethod);
	normalize(resultImg, resultImg, 0, 1, NORM_MINMAX, -1, Mat());

	minMaxLoc(resultImg, &dMinVal, &dMaxVal, &minLoc, &maxLoc, Mat());

	if (m_iMethod == CV_TM_SQDIFF || m_iMethod == CV_TM_SQDIFF_NORMED)
	{
		matchLoc = minLoc;
	}
	else
	{
		matchLoc = maxLoc;
	}

	int iThickness = 4;
	if (m_DispImage.cols > 2048)
	{
		iThickness = 8;
	}
	rectangle(m_DispImage, matchLoc, Point(matchLoc.x + maskImage.cols, matchLoc.y + maskImage.rows), Scalar::all(0), iThickness, 8, 0);

	// CStr2Str
	CString str;
	str.Format(_T("%.2f"), dMaxVal);
	std::wstring ws(str);
	std::string s;
	s.assign(ws.begin(), ws.end());

	cv::putText(m_DispImage, s, cv::Point(matchLoc.x, matchLoc.y - 5), CV_FONT_HERSHEY_SIMPLEX, 2, Scalar::all(0), iThickness, 8, 0);
	
	// Display를 위해 0에서 255로 변경
	Mat tmpMat;
	normalize(resultImg, tmpMat, 0, 255, CV_MINMAX);
	tmpMat.convertTo(m_OutImage, CV_8U);

	//m_OutImage = resultImg.clone();

	return TRUE;
}


////////////////////
// COpPSM
////////////////////
COpPSM::COpPSM()
{
	m_strName = _T("Pattern Shift Method");
	m_iType = OP_PSM;

	m_iSubtractType = 0;
	m_iDir = 0;
	m_iXOffset = 8;
	m_iYOffset = 8;
}

COpPSM::~COpPSM()
{
}

// COpPSM 멤버 함수
BOOL COpPSM::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	int width = m_InImage.cols - (m_iXOffset * 2);
	int height = m_InImage.rows - (m_iYOffset * 2);

	Mat  leftImg;
	Mat  rightImg;
	Mat  upImg;
	Mat  downImg;
	Mat  centerImg;

	// center
	Rect rect = Rect(m_iXOffset, m_iYOffset, width, height);
	centerImg = m_InImage(rect);

	Mat ResImage = Mat(m_InImage.size(), m_InImage.type(), Scalar(0));
	Mat ResROIImage = ResImage(rect);

	if (m_iDir == 0)//LeftRight
	{
		// left
		rect = Rect(0, m_iYOffset, width, height);
		leftImg = m_InImage(rect);

		// right
		rect = Rect(m_iXOffset * 2, m_iYOffset, width, height);
		rightImg = m_InImage(rect);

		Mat tmpImage1, tmpImage2;

		if (0 == m_iSubtractType)
		{
			tmpImage1 = leftImg - centerImg;
			tmpImage2 = rightImg - centerImg;
			ResROIImage = cv::max(tmpImage1, tmpImage2);
		}
		else if (1 == m_iSubtractType)
		{
			absdiff(leftImg, centerImg, tmpImage1);
			absdiff(rightImg, centerImg, tmpImage2);
			ResROIImage = cv::min(tmpImage1, tmpImage2);
		}
		else
		{
			bitwise_xor(leftImg, centerImg, tmpImage1);
			bitwise_xor(rightImg, centerImg, tmpImage2);
			ResROIImage = cv::min(tmpImage1, tmpImage2);
		}
	}
	else if (m_iDir == 1)//updown
	{
		// up
		rect = Rect(m_iXOffset, 0, width, height);
		upImg = m_InImage(rect);

		// down
		rect = Rect(m_iXOffset, m_iYOffset * 2, width, height);
		downImg = m_InImage(rect);

		Mat tmpImage1, tmpImage2;

		if (0 == m_iSubtractType)
		{
			tmpImage1 = upImg - centerImg;
			tmpImage2 = downImg - centerImg;
			ResROIImage = cv::max(tmpImage1, tmpImage2);
		}
		else if (1 == m_iSubtractType)
		{
			absdiff(upImg, centerImg, tmpImage1);
			absdiff(downImg, centerImg, tmpImage2);
			ResROIImage = cv::min(tmpImage1, tmpImage2);
		}
		else
		{
			bitwise_xor(upImg, centerImg, tmpImage1);
			bitwise_xor(downImg, centerImg, tmpImage2);
			ResROIImage = cv::min(tmpImage1, tmpImage2);
		}
	}
	else	// both
	{
		// left
		rect = Rect(0, m_iYOffset, width, height);
		leftImg = m_InImage(rect);

		// right
		rect = Rect(m_iXOffset * 2, m_iYOffset, width, height);
		rightImg = m_InImage(rect);

		// up
		rect = Rect(m_iXOffset, 0, width, height);
		upImg = m_InImage(rect);

		// down
		rect = Rect(m_iXOffset, m_iYOffset * 2, width, height);
		downImg = m_InImage(rect);

		// center
		rect = Rect(m_iXOffset, m_iYOffset, width, height);
		centerImg = m_InImage(rect);

		Mat tmpImage1, tmpImage2, tmpLRImage;
		if (0 == m_iSubtractType)
		{
			tmpImage1 = leftImg - centerImg;
			tmpImage2 = rightImg - centerImg;
			tmpLRImage = cv::max(tmpImage1, tmpImage2);
		}
		else if (1 == m_iSubtractType)
		{
			absdiff(leftImg, centerImg, tmpImage1);
			absdiff(rightImg, centerImg, tmpImage2);
			tmpLRImage = cv::min(tmpImage1, tmpImage2);
		}
		else
		{
			bitwise_xor(leftImg, centerImg, tmpImage1);
			bitwise_xor(rightImg, centerImg, tmpImage2);
			tmpLRImage = cv::min(tmpImage1, tmpImage2);
		}

		Mat tmpImage3, tmpImage4, tmtUDImage;
		if (0 == m_iSubtractType)
		{
			tmpImage3 = upImg - centerImg;
			tmpImage4 = downImg - centerImg;
			tmtUDImage = cv::max(tmpImage3, tmpImage4);
		}
		else if (1 == m_iSubtractType)
		{
			absdiff(upImg, centerImg, tmpImage3);
			absdiff(downImg, centerImg, tmpImage4);
			tmtUDImage = cv::min(tmpImage3, tmpImage4);
		}
		else
		{
			bitwise_xor(upImg, centerImg, tmpImage3);
			bitwise_xor(downImg, centerImg, tmpImage4);
			tmtUDImage = cv::min(tmpImage3, tmpImage4);
		}
		cv::min(tmpLRImage, tmtUDImage, ResROIImage);
	}

	m_OutImage = ResImage;

	return TRUE;
}



////////////////////
// COpRemoveBlobs
////////////////////
COpRemoveBlobs::COpRemoveBlobs()
{
	m_strName = _T("Remove Blobs");
	m_iType = OP_REMOVEBLOBS;

	m_iMinArea = 32;
	m_iMaxArea = -1;
	m_iMinWidth = 8;
	m_iMinHeight = 8;
	m_iMaxWidth = -1;
	m_iMaxHeight = -1;
}

COpRemoveBlobs::~COpRemoveBlobs()
{
}

// COpRemoveBlobs 멤버 함수
BOOL COpRemoveBlobs::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Remove Blobs funciton only can take a single channel image."));
		return FALSE;
	}

	vector<vector<Point> > contours;
	vector<vector<Point> > result_contours;
	vector<Vec4i> hierarchy;

	// find contours 함수가 원본을 변경하므로 함수 호출전에 Clone해서 넘겨주자.
	Mat ProcImg = m_InImage.clone();

	int iMode = CV_RETR_LIST;
	int iMethod = CV_CHAIN_APPROX_NONE;

	int iCh = ProcImg.channels();
	int iType = ProcImg.type();

	cv::findContours(ProcImg, contours, hierarchy, iMode, iMethod);

	// drawContours의 첫번째 인자는 빈 매트릭스는 안된다. 
	m_OutImage = m_InImage.clone();
	m_OutImage.setTo(0);

	cv::Rect blobRect;
	int iContourCnt = (int)contours.size();

	int iBlobCnt = 0;

	for (int i = 0; i<iContourCnt; i++)
	{
		int iContourArea = (int)cv::contourArea(contours[i]); //(int)contours[i].size();

		if (m_iMinArea > 0 && iContourArea < m_iMinArea) continue;
		if (m_iMaxArea > 0 && iContourArea > m_iMaxArea) continue;

		blobRect = cv::boundingRect(contours[i]);
		if (m_iMinWidth > 0 && blobRect.width < m_iMinWidth) continue;
		if (m_iMinHeight > 0 && blobRect.height < m_iMinHeight) continue;
		if (m_iMaxWidth > 0 && blobRect.width > m_iMaxWidth) continue;
		if (m_iMaxHeight > 0 && blobRect.height > m_iMaxHeight) continue;
		
		//cv::drawContours(m_OutImage, contours, i, cv::Scalar(255), CV_FILLED);
		result_contours.push_back(contours[i]);		
	}

	cv::drawContours(m_OutImage, result_contours, -1, cv::Scalar(255), CV_FILLED);
		
	return TRUE;
}

////////////////////
// COpMarkedAvg 
////////////////////
COpMarkedAgv::COpMarkedAgv()
{
	m_strName = _T("Marked Average");
	m_iType = OP_MARKED_AVG;

	m_iMarkImgNo = 0;
	m_iKernelX = 3;
	m_iKernelY = 3;
}

COpMarkedAgv::~COpMarkedAgv()
{
}

BOOL COpMarkedAgv::Process(COperation* pPrevOp, COperation* pPrevOp2 /* = NULL */)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Mat MaskImg;
	if (pPrevOp2 != NULL)	MaskImg = pPrevOp2->GetResultImage();
	
	if (MaskImg.total() == 0)
	{
		AfxMessageBox(_T("Invalid Mark image."));
		return FALSE;
	}

	// 1. 
	cv::Mat andImg;
	cv::bitwise_and(m_InImage, MaskImg, andImg);

	// 2. Blur
	cv::Mat blurImg;
	cv::blur(andImg, blurImg, cv::Size(m_iKernelX, m_iKernelY));

	// 3. 
	cv::Mat blurImg2;
	cv::blur(MaskImg, blurImg2, cv::Size(m_iKernelX, m_iKernelY));

	// 4. masked average 
	cv::Mat maskedAvgImg;
	cv::divide(blurImg, blurImg2, maskedAvgImg, 255.0);

	// 5. mask
	cv::Mat resultMaskAvgImg;
	cv::bitwise_and(maskedAvgImg, MaskImg, resultMaskAvgImg);
	//
	m_OutImage = resultMaskAvgImg.clone();

	return TRUE;
}

////////////////////
// COpMarkedAdaptiveThreshold 
////////////////////
COpMarkedAdaptiveThreshold::COpMarkedAdaptiveThreshold()
{
	m_strName = _T("Marked Adaptive Threshold");
	m_iType = OP_MARKEDADAPTHRESOLD;

	m_iMarkImgNo = 0;
	m_iKernelX = 3;
	m_iKernelY = 3;
	m_iCValue = 8;
	m_Type = 0;
}

COpMarkedAdaptiveThreshold::~COpMarkedAdaptiveThreshold()
{

}

BOOL COpMarkedAdaptiveThreshold::Process(COperation* pPrevOp, COperation* pPrevOp2 /* = NULL */)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Mat MaskImg;
	if (pPrevOp2 != NULL)	MaskImg = pPrevOp2->GetResultImage();

	if (MaskImg.total() == 0)
	{
		AfxMessageBox(_T("Invalid Mark image."));
		return FALSE;
	}
	// Mask Average => resultMaskAvgImg Image;
	// 1. 
	cv::Mat andImg;
	cv::bitwise_and(m_InImage, MaskImg, andImg);

	// 2. Blur
	cv::Mat blurImg;
	cv::blur(andImg, blurImg, cv::Size(m_iKernelX, m_iKernelY));

	// 3. 
	cv::Mat blurImg2;
	cv::blur(MaskImg, blurImg2, cv::Size(m_iKernelX, m_iKernelY));

	// 4. masked average 
	cv::Mat maskedAvgImg;
	cv::divide(blurImg, blurImg2, maskedAvgImg, 255.0);

	// 5. mask
	cv::Mat resultMaskAvgImg;
	cv::bitwise_and(maskedAvgImg, MaskImg, resultMaskAvgImg);
	// End mask average

	cv::Mat procImg;
	cv::Mat binImg;

	if (m_Type == 0) // diff
	{
		cv::absdiff(maskedAvgImg, m_InImage, procImg);
	}
	else if (m_Type == 1)	// find brighter pixel
	{
		procImg = m_InImage - maskedAvgImg;
	}
	else // find darker pixel
	{
		procImg = maskedAvgImg - m_InImage;
	}

	cv::threshold(procImg, binImg, m_iCValue, 255.0, cv::THRESH_BINARY);

	// 5. mask로 한번 더 and
	cv::Mat resultMaskedAdapThresholdImg;
	cv::bitwise_and(binImg, resultMaskAvgImg, resultMaskedAdapThresholdImg);

	m_OutImage = resultMaskedAdapThresholdImg.clone();

	return TRUE;
}

////////////////////
// COpDiffImage
////////////////////
COpDiffImage::COpDiffImage()
{
	m_strName = _T("Different Image");
	m_iType = OP_DIFFIMAGE;

	m_iDir = 0;
	m_iDiffImgType = 0;
	m_iAnpha = 1;
	m_iBeta = 0;
	m_iMinThr = 5;
	m_iAccum = 2;
}

COpDiffImage::~COpDiffImage()
{

}

uchar COpDiffImage::GetPixel(cv::Mat & srcImg, cv::Point pt)
{
	return srcImg.data[pt.y*srcImg.cols + pt.x];
}

void COpDiffImage::SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value)
{
	srcImg.data[pt.y*srcImg.cols + pt.x] = value;
}

BOOL COpDiffImage::Process(COperation* pPrevOp, COperation* pPrevOp2 /* = NULL */)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}
	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("DiffImage funciton only can take a single channel image."));
		return FALSE;
	}
	cv::Mat ProcImage = m_InImage.clone();
	if (m_iDir == 0) // X
	{
		for (int j = 0; j < ProcImage.rows; j++)
		{
			for (int i = m_iAccum - 1; i<ProcImage.cols - m_iAccum; i++)
			{
				cv::Point pt(i, j);
				uchar curPixel = GetPixel(ProcImage, pt); // GetPix

				if (curPixel>m_iMinThr)
				{
					double prevMean = 0.0;
					double nextMean = 0.0;

					for (int k = 0; k<m_iAccum; k++)
					{
						cv::Point prevPt(i - k, j);
						cv::Point nextPt(i + 1 + k, j);
						prevMean += GetPixel(ProcImage, prevPt);
						nextMean += GetPixel(ProcImage, nextPt);
					}
					prevMean /= (double)m_iAccum;
					nextMean /= (double)m_iAccum;

					if (prevMean>m_iMinThr && nextMean > m_iMinThr)
					{
						uchar value;
						if (m_iDiffImgType == 0)
						{
							value = cv::saturate_cast<uchar>(m_iAnpha*(prevMean - nextMean) + m_iBeta);
						}
						else if (m_iDiffImgType == 1)
						{
							value = cv::saturate_cast<uchar>(m_iAnpha*(nextMean - prevMean) + m_iBeta);
						}
						else
						{
							value = cv::saturate_cast<uchar>(m_iAnpha*fabs(nextMean - prevMean) / pow((double)(curPixel + 100), 0.2) + m_iBeta);
						}

						SetPixel(ProcImage, pt, value);
					}
				}
			}
		}
	}
	else // Y
	{
		for (int i = 0; i < ProcImage.cols; i++)
		{
			for (int j = m_iAccum - 1; j<ProcImage.rows - m_iAccum; j++)
			{
				cv::Point pt(i, j);
				uchar curPixel = GetPixel(ProcImage, pt);

				if (curPixel>m_iMinThr)
				{
					double prevMean = 0.0;
					double nextMean = 0.0;

					for (int k = 0; k<m_iAccum; k++)
					{
						cv::Point prevPt(i, j - k);
						cv::Point nextPt(i, j + 1 + k);
						prevMean += GetPixel(ProcImage, prevPt);
						nextMean += GetPixel(ProcImage, nextPt);
					}
					prevMean /= (double)m_iAccum;
					nextMean /= (double)m_iAccum;

					if (prevMean>m_iMinThr && nextMean > m_iMinThr)
					{
						uchar value;
						if (m_iDiffImgType == 0)
						{
							value = cv::saturate_cast<uchar>(m_iAnpha*(prevMean - nextMean) + m_iBeta);
						}
						else if (m_iDiffImgType == 1)
						{
							value = cv::saturate_cast<uchar>(m_iAnpha*(nextMean - prevMean) + m_iBeta);
						}
						else
						{
							value = cv::saturate_cast<uchar>(m_iAnpha*fabs(nextMean - prevMean) / pow((double)(curPixel + 100), 0.2) + m_iBeta);
						}

						SetPixel(ProcImage, pt, value);
					}
				}
			}
		}
	}
	m_OutImage = ProcImage.clone();
	return TRUE;
}