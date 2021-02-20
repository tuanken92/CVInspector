#include "stdafx.h"
#include "CVInspector.h"
#include "Operation_Transform.h"

////////////////////
// COpCvtColor
////////////////////
COpCvtColor::COpCvtColor()
{
	m_strName = _T("Convert Color");
	m_iType = OP_CVTCOLOR;
	m_iConvertType = CV_BGR2GRAY;
}

COpCvtColor::~COpCvtColor()
{
}

// COpCvtColor 멤버 함수
BOOL COpCvtColor::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 3 && m_iConvertType == CV_BGR2GRAY)
	{
		AfxMessageBox(_T("Cannot convert Color Format!, Source image's channel should be 3!"));
		return FALSE;
	}

	if (m_InImage.channels() != 1 && m_iConvertType == CV_GRAY2BGR)
	{
		AfxMessageBox(_T("Cannot convert Color Format!, Source image's channel should be 1!"));
		return FALSE;
	}

	if (m_InImage.channels() != 3 && m_iConvertType == CV_BGR2HSV)
	{
		AfxMessageBox(_T("Cannot convert Color Format!, Source image's channel should be 3!"));
		return FALSE;
	}
	cvtColor(m_InImage, m_OutImage, m_iConvertType);

	return TRUE;
}

////////////////////
// COpFlip
////////////////////
COpFlip::COpFlip()
{
	m_strName = _T("Flip Image");
	m_iType = OP_FLIP;
	m_iFlipCode = 0;
}

COpFlip::~COpFlip()
{
}

// COpFlip 멤버 함수
BOOL COpFlip::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}
	
	if (m_iFlipCode == 3)
	{
		cv::transpose(m_InImage, m_OutImage);
	}
	else
	{
		flip(m_InImage, m_OutImage, m_iFlipCode);
	}
	

	return TRUE;
}

////////////////////
// COpRotate
////////////////////
COpRotate::COpRotate()
{
	m_strName = _T("Rotate Image");
	m_iType = OP_ROTATE;
	m_dAngle = 90.0;
}

COpRotate::~COpRotate()
{
}

// COpRotate 멤버 함수
BOOL COpRotate::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Mat RotMat(2, 3, CV_32FC1);
	m_OutImage = Mat::zeros(m_InImage.rows, m_InImage.cols, m_InImage.type());

	/// Compute a rotation matrix with respect to the center of the image 
	Point ptCenter = Point(m_InImage.cols / 2, m_InImage.rows / 2);

	/// Get the rotation matrix with the specifications above 
	RotMat = getRotationMatrix2D(ptCenter, m_dAngle, 1.0);
	warpAffine(m_InImage, m_OutImage, RotMat, m_InImage.size());

	return TRUE;
}


////////////////////
// COpBinarize
////////////////////
COpBinarize::COpBinarize()
{
	m_strName = _T("Binarize");
	m_iType = OP_BINARIZE;
	m_iBinarizeType = CV_THRESH_BINARY;
	m_dThr = 128.0;
	m_bUseOtsu = FALSE;
}

COpBinarize::~COpBinarize()
{
}

// COpBinarize 멤버 함수
BOOL COpBinarize::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_bUseOtsu)
	{
		threshold(m_InImage, m_OutImage, m_dThr, 255, m_iBinarizeType | CV_THRESH_OTSU);
	}
	else
	{
		threshold(m_InImage, m_OutImage, m_dThr, 255, m_iBinarizeType);
	}


	return TRUE;
}

////////////////////
// COpJPThreshold
////////////////////
COpJPThreshold::COpJPThreshold()
{
	m_strName = _T("JPBinarize");
	m_iType = OP_JPTHRESHOLD;
	m_iTypeThr = 0;
	m_iThrLower = 128;
	m_iThrUpper = 255;
}

COpJPThreshold::~COpJPThreshold()
{
}

// COpBinarize 멤버 함수
BOOL COpJPThreshold::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	cv::Mat LowerImg, UpperImg;

	LowerImg = m_InImage.clone();
	UpperImg = m_InImage.clone();

	if (m_iTypeThr == 0)// Nomal
	{
		cv::threshold(LowerImg, LowerImg, m_iThrLower, 255.0, CV_THRESH_BINARY);
		cv::threshold(UpperImg, UpperImg, m_iThrUpper, 255.0, CV_THRESH_BINARY_INV);
		cv::bitwise_and(LowerImg, UpperImg, m_OutImage);
	}
	else if (m_iTypeThr == 1) // Inv
	{
		cv::threshold(LowerImg, LowerImg, m_iThrLower, 255.0, CV_THRESH_BINARY_INV);
		cv::threshold(UpperImg, UpperImg, m_iThrUpper, 255.0, CV_THRESH_BINARY);
		cv::bitwise_or(LowerImg, UpperImg, m_OutImage);
	}
	else if (m_iTypeThr == 2) // Tozero
	{
		cv::threshold(LowerImg, LowerImg, m_iThrLower, 255.0, CV_THRESH_TOZERO);
		cv::threshold(UpperImg, UpperImg, m_iThrUpper, 255.0, CV_THRESH_TOZERO_INV);
		cv::bitwise_and(LowerImg, UpperImg, m_OutImage);
	}
	else if (m_iTypeThr == 3) // Tozero Inv
	{
		cv::threshold(LowerImg, LowerImg, m_iThrLower, 255.0, CV_THRESH_TOZERO_INV);
		cv::threshold(UpperImg, UpperImg, m_iThrUpper, 255.0, CV_THRESH_TOZERO);
		cv::bitwise_or(LowerImg, UpperImg, m_OutImage);
	}
	return TRUE;
}

////////////////////
// COpJPThresholdAuto
////////////////////
COpJPThresholdAuto::COpJPThresholdAuto()
{
	m_strName = _T("JPThresholdAuto");
	m_iType = OP_JPTHRESHOLDAUTO;

	m_iDir = 0;
	m_iStdDev = 1;
}

COpJPThresholdAuto::~COpJPThresholdAuto()
{
}

// COpBinarize 멤버 함수
BOOL COpJPThresholdAuto::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	cv::Mat ProcImg = m_InImage.clone();
	//	cv::blur(ProcImg, ProcImg, cv::Size(3,3));

	cv::Mat ResultImg(cv::Size(ProcImg.size()), CV_8UC1, cv::Scalar(0));

	cv::Rect SearchRect;
	cv::Mat SearchImg;
	if (m_iDir == 0)		// Hor
	{
		int iSize = 2;
		if (ProcImg.rows < iSize)	iSize = ProcImg.cols;
		int iStep = iSize / 2;
		for (int i = 0; i<ProcImg.cols - iSize; i = i + iStep)
		{
			SearchRect.x = i;
			SearchRect.y = 0;
			SearchRect.width = iSize;
			SearchRect.height = ProcImg.rows;
			SearchImg = ProcImg(SearchRect).clone();
			cv::Scalar mean, stddev;
			cv::meanStdDev(SearchImg, mean, stddev);
			if (stddev.val[0] > m_iStdDev)
			{
				cv::threshold(SearchImg, SearchImg, 128, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);
				SearchImg.copyTo(ResultImg(SearchRect));
			}
		}
	}
	else			// Ver
	{
		int iSize = 2;
		if (ProcImg.rows < iSize)	iSize = ProcImg.rows;
		int iStep = iSize / 2;
		for (int i = 0; i<ProcImg.rows - iSize; i = i + iStep)
		{
			SearchRect.x = 0;
			SearchRect.y = i;
			SearchRect.width = ProcImg.cols;
			SearchRect.height = iSize;
			SearchImg = ProcImg(SearchRect).clone();
			cv::Scalar mean, stddev;
			cv::meanStdDev(SearchImg, mean, stddev);
			if (stddev.val[0] > m_iStdDev)
			{
				cv::threshold(SearchImg, SearchImg, 30, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);
				SearchImg.copyTo(ResultImg(SearchRect));
			}
		}
	}

	m_OutImage = ResultImg.clone();

	return TRUE;
}

////////////////////
// COpResize
////////////////////
COpResize::COpResize()
{
	m_strName = _T("Resize");
	m_iType = OP_RESIZE;
	m_iInterpolationType = INTER_NEAREST;
	m_iNewSizeX = 0;
	m_iNewSizeY = 0;
	m_dNewRatioX = 1.0;
	m_dNewRatioY = 1.0;
}

COpResize::~COpResize()
{
}

// COpResize 멤버 함수
BOOL COpResize::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	Size resizeSize(m_iNewSizeX, m_iNewSizeY);
	resize(m_InImage, m_OutImage, resizeSize, m_dNewRatioX, m_dNewRatioY, m_iInterpolationType);

	return TRUE;
}


////////////////////
// COpCrop
////////////////////
COpCrop::COpCrop()
{
	m_strName = _T("Crop");
	m_iType = OP_CROP;
	m_CropRect.SetRectEmpty();

	m_bShowDisplayImage = TRUE;
}

COpCrop::~COpCrop()
{
}

// COpCrop 멤버 함수
BOOL COpCrop::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_CropRect.IsRectEmpty())
	{
		return FALSE;
	}

	m_CropRect.NormalizeRect();

	if (m_CropRect.left < 0)
	{
		AfxMessageBox(_T("Invalid crop area, Left position of the crop rect must be bigger than 0."));
		return FALSE;
	}
	else if (m_CropRect.top < 0)
	{
		AfxMessageBox(_T("Invalid crop area, Top position of the crop rect must be bigger than 0."));
		return FALSE;
	}
	else if (m_CropRect.right >= m_InImage.cols)
	{
		AfxMessageBox(_T("Invalid crop area, Right position of the crop rect must be smaller than width of the original image."));
		return FALSE;
	}
	else if (m_CropRect.bottom >= m_InImage.rows)
	{
		AfxMessageBox(_T("Invalid crop area, Bottom position of the crop rect must be smaller than height of the original image."));
		return FALSE;
	}

	Rect cropRect = Rect(m_CropRect.left, m_CropRect.top, m_CropRect.Width(), m_CropRect.Height());

	m_DispImage = m_InImage.clone();

	int iThickness = 4;
	if (m_DispImage.cols > 2048)
	{
		iThickness = 8;
	}
	Scalar color;
	if (m_DispImage.channels() != 1)
	{
		color = Scalar(0, 0, 255);
	}
	else
	{
		color = Scalar(128, 128, 128);
	}
	rectangle(m_DispImage, cropRect, color, iThickness);

	m_OutImage = m_InImage(cropRect).clone();

	return TRUE;
}


////////////////////
// COpSplit
////////////////////
COpSplit::COpSplit()
{
	m_strName = _T("Split");
	m_iType = OP_SPLIT;
	m_iTargetChannel = 0;
}

COpSplit::~COpSplit()
{
}

// COpSplit 멤버 함수
BOOL COpSplit::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() <= 1)
	{
		AfxMessageBox(_T("Channel of the input image should be bigger than 1."));
		return FALSE;
	}

	if (m_iTargetChannel > m_InImage.channels() - 1)
	{
		AfxMessageBox(_T("Selected target channel is invalid."));
		return FALSE;
	}

	Mat tmpOut[4];
	split(m_InImage, tmpOut);

	m_OutImage = tmpOut[m_iTargetChannel].clone();

	return TRUE;
}


////////////////////
// COpPyramid
////////////////////
COpPyramid::COpPyramid()
{
	m_strName = _T("Pyramid");
	m_iType = OP_PYRAMID;
	m_bDownOrUp = TRUE;	// true down, false up
	m_iSizeX = 0;
	m_iSizeY = 0;
}

COpPyramid::~COpPyramid()
{
}

// COpPyramid 멤버 함수
BOOL COpPyramid::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_bDownOrUp)
	{
		pyrDown(m_InImage, m_OutImage, Size(m_iSizeX, m_iSizeY));
	}
	else
	{
		pyrUp(m_InImage, m_OutImage, Size(m_iSizeX, m_iSizeY));
	}

	return TRUE;
}


////////////////////
// COpDFT
////////////////////
COpDFT::COpDFT()
{
	m_strName = _T("DFT");
	m_iType = OP_DFT;
	m_bInverse = FALSE;

	m_bShowDisplayImage = TRUE;
}

COpDFT::~COpDFT()
{
}

// COpDFT 멤버 함수
BOOL COpDFT::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_bInverse)
	{
		Mat invTrans;

		dft(m_InImage, invTrans, DFT_INVERSE | DFT_REAL_OUTPUT);
		normalize(invTrans, m_OutImage, 0, 255, CV_MINMAX);
		m_OutImage.convertTo(m_DispImage, CV_8U);
		return TRUE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("DFT funciton only can take a single channel image."));
		return FALSE;
	}

	int iM = getOptimalDFTSize(m_InImage.rows);
	int iN = getOptimalDFTSize(m_InImage.cols);
	Mat paddedImg;
	copyMakeBorder(m_InImage, paddedImg, 0, iM - m_InImage.rows, 0, iN - m_InImage.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = { Mat_<float>(paddedImg), Mat::zeros(paddedImg.size(), CV_32F) };
	Mat complexImg;
	merge(planes, 2, complexImg);

	dft(complexImg, complexImg);

	// compute log(1 + sqrt(Re(DFT(img))**2 + Im(DFT(img))**2))
	split(complexImg, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat mag = planes[0];
	mag += Scalar::all(1);
	log(mag, mag);

	// crop the spectrum, if it has an odd number of rows or columns
	mag = mag(Rect(0, 0, mag.cols & -2, mag.rows & -2));

	int cx = mag.cols / 2;
	int cy = mag.rows / 2;

	// rearrange the quadrants of Fourier image
	// so that the origin is at the image center
	Mat tmp;
	Mat q0(mag, Rect(0, 0, cx, cy));
	Mat q1(mag, Rect(cx, 0, cx, cy));
	Mat q2(mag, Rect(0, cy, cx, cy));
	Mat q3(mag, Rect(cx, cy, cx, cy));

	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(mag, mag, 0, 255, CV_MINMAX);

	m_OutImage = complexImg.clone();

	// convert to 8-bit image
	mag.convertTo(m_DispImage, CV_8U);

	return TRUE;
}


////////////////////
// COpAdaptiveThreshold
////////////////////
COpAdaptiveThreshold::COpAdaptiveThreshold()
{
	m_strName = _T("Adaptive Threshold");
	m_iType = OP_ADAPTIVETHRESHOLD;

	m_dMaxValue = 255;
	m_iAdaptiveMethod = ADAPTIVE_THRESH_MEAN_C;
	m_iThresholdType = THRESH_BINARY;
	m_iBlockSize = 3;
	m_dConstant = 8.0;

	m_bShowDisplayImage = FALSE;
}

COpAdaptiveThreshold::~COpAdaptiveThreshold()
{
}

// COpAdaptiveThreshold 멤버 함수
BOOL COpAdaptiveThreshold::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Adaptive threshold function only can take a gray scale image."));
		return FALSE;
	}

	if (m_iBlockSize % 2 == 0)
	{
		AfxMessageBox(_T("Block size of the adaptive threshold should be an odd number."));
		return FALSE;
	}

	adaptiveThreshold(m_InImage, m_OutImage, m_dMaxValue, m_iAdaptiveMethod, m_iThresholdType, m_iBlockSize, m_dConstant);

	return TRUE;
}

////////////////////
// COpAdaptiveThresholdISH
////////////////////
COpAdaptiveThresholdISH::COpAdaptiveThresholdISH()
{
	m_strName = _T("Adaptive Threshold ISH");
	m_iType = OP_ADAPTIVETHRESHOLDISH;

	m_iThr = 128;
	m_iBlockSize = 3;
	m_dOffset = 2;
	m_dScale = 1;
}

COpAdaptiveThresholdISH::~COpAdaptiveThresholdISH()
{
}

// COpAdaptiveThreshold 멤버 함수
BOOL COpAdaptiveThresholdISH::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Adaptive threshold function only can take a gray scale image."));
		return FALSE;
	}

	if (m_iBlockSize % 2 == 0)
	{
		AfxMessageBox(_T("Block size of the adaptive threshold should be an odd number."));
		return FALSE;
	}

	//
	AfxMessageBox(_T("Setting... (Not Use)"));
	return FALSE;
	//

	cv::Mat resImage;
	cv::Mat avgImage;
	cv::Mat thrOffsetImage;
	cv::Mat resizeImage1;
	cv::Mat resizeImage2;

	int i = 0;
	int j = 0;

	int iWidth = m_InImage.cols;
	int iHeight = m_InImage.rows;

	double dRefThr = m_iThr;
	double dOffsetLimit = m_dOffset;
	int iAdaptiveThrRange = m_iBlockSize;

	// average image를 만든다. 
	// 속도 단축을 위해 Resize 한다.
	int iResizeScale = 4;

	int iArraySize = (iAdaptiveThrRange*iAdaptiveThrRange) / (iResizeScale*iResizeScale);
	double* kernel = new double[iArraySize];
	for (i = 0; i < iArraySize; i++)
	{
		kernel[i] = 1.0 / double(iArraySize);
	}
	cv::Mat KernelMat = cv::Mat(iAdaptiveThrRange / iResizeScale, iAdaptiveThrRange / iResizeScale, CV_64FC1, kernel);

	cv::Size NewSize = cv::Size(iWidth / iResizeScale, iHeight / iResizeScale);

	cv::pyrDown(m_InImage, resizeImage1, NewSize);

	cv::filter2D(resizeImage1, resizeImage2, -1, KernelMat);

	// 작게 줄여 Filtering한 이미지의 평균을 구한다. 
	Scalar avgVal = cv::mean(resizeImage2);

	// 다시 원래 크기로 키운다.
	cv::pyrUp(resizeImage2, avgImage, Size(iWidth, iHeight));

	// Threshold Offset Image 생성 
	thrOffsetImage = avgImage - avgVal;
	// Scale 반영
	if (m_dScale != 1.0)
	{
		thrOffsetImage = m_dScale * thrOffsetImage;
	}

	// Threshold Offset이 Offset Limit를 넘지 않도록 조정
	cv::threshold(thrOffsetImage, thrOffsetImage, dOffsetLimit, dOffsetLimit, CV_THRESH_BINARY);

	// Pixel 값과 Average 값의 차이를 계산
	resImage = avgImage - m_InImage;
	// 차이값에서 threshold offset 값 만큼 뺀다.
	resImage = resImage - thrOffsetImage;

	// 최종으로 Threshold값 적용
	cv::threshold(resImage, resImage, dRefThr, 255.0, CV_THRESH_BINARY);

	m_OutImage = resImage.clone();

	return TRUE;
}


////////////////////
// COpMappingImage
////////////////////
COpMappingImage::COpMappingImage()
{
	m_strName = _T("Mapping Image");
	m_iType = OP_MAPPINGIMAGE;

	m_iDir = 0;
	m_iDist = 3;
	m_dThr = 20;
	m_dAlpha = 1;
	m_dBeta = 20;

	m_strComboLight = _T("");
	
	
}

COpMappingImage::~COpMappingImage()
{
}


uchar COpMappingImage::GetPixel(cv::Mat & srcImg, cv::Point pt)
{
	return srcImg.data[pt.y*srcImg.cols + pt.x];
}

void COpMappingImage::SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value)
{
	srcImg.data[pt.y*srcImg.cols + pt.x] = value;
}

void COpMappingImage::MakeMapImgX_Dark(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta)
{
	mapImg.create(srcImg.size(), CV_8UC1);
	mapImg = 0;

	for (int j = 0 + iDist; j < srcImg.rows - iDist; j++)
	{
		for (int i = 0 + iDist; i<srcImg.cols - iDist; i++)
		{
			cv::Point pt(i, j);
			double c = GetPixel(srcImg, pt);

			double offset = 100;

			if (c>dThr)
			{
				double t = GetPixel(srcImg, pt - cv::Point(0, iDist));
				double b = GetPixel(srcImg, pt + cv::Point(0, iDist));
				double ec = (t + b) / 2.0;

				double log_c = log(c + offset);
				double log_t = log(t + offset);
				double log_b = log(b + offset);
				double log_ec = (log_t + log_b) / 2.0;

				double val = (log_ec - log_c);
				uchar value = cv::saturate_cast<uchar>(beta + alpha*val);

				if (value == 0) value = 1;

				SetPixel(mapImg, pt, value);
			}
		}
	}
}
void COpMappingImage::MakeMapImgX_Bright(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta)
{
	mapImg.create(srcImg.size(), CV_8UC1);
	mapImg = 0;

	for (int j = 0 + iDist; j < srcImg.rows - iDist; j++)
	{
		for (int i = 0 + iDist; i<srcImg.cols - iDist; i++)
		{
			cv::Point pt(i, j);
			double c = GetPixel(srcImg, pt);

			double offset = 100;

			if (c>dThr)
			{
				double t = GetPixel(srcImg, pt - cv::Point(0, iDist));
				double b = GetPixel(srcImg, pt + cv::Point(0, iDist));
				double ec = (t + b) / 2.0;

				double log_c = log(c + offset);
				double log_t = log(t + offset);
				double log_b = log(b + offset);
				double log_ec = (log_t + log_b) / 2.0;

				double val = (log_c - log_ec);
				uchar value = cv::saturate_cast<uchar>(beta + alpha*val);

				if (value == 0) value = 1;

				SetPixel(mapImg, pt, value);
			}
		}
	}
}
void COpMappingImage::MakeMapImgY_Dark(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta)
{
	mapImg.create(srcImg.size(), CV_8UC1);
	mapImg = 0;

	for (int j = 0 + iDist; j < srcImg.rows - iDist; j++)
	{
		for (int i = 0 + iDist; i<srcImg.cols - iDist; i++)
		{
			cv::Point pt(i, j);
			double c = GetPixel(srcImg, pt);

			double offset = 100;

			if (c>dThr)
			{
				double l = GetPixel(srcImg, pt - cv::Point(iDist, 0));
				double r = GetPixel(srcImg, pt + cv::Point(iDist, 0));
				double ec = (l + r) / 2.0;

				double log_c = log(c + offset);
				double log_l = log(l + offset);
				double log_r = log(r + offset);
				double log_ec = (log_l + log_r) / 2.0;

				double val = (log_ec - log_c);
				uchar value = cv::saturate_cast<uchar>(beta + alpha*val);

				if (value == 0) value = 1;

				SetPixel(mapImg, pt, value);
			}
		}
	}
}
void COpMappingImage::MakeMapImgY_Bright(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta)
{
	mapImg.create(srcImg.size(), CV_8UC1);
	mapImg = 0;

	for (int j = 0 + iDist; j < srcImg.rows - iDist; j++)
	{
		for (int i = 0 + iDist; i<srcImg.cols - iDist; i++)
		{
			cv::Point pt(i, j);
			double c = GetPixel(srcImg, pt);

			double offset = 100;

			if (c>dThr)
			{
				double l = GetPixel(srcImg, pt - cv::Point(iDist, 0));
				double r = GetPixel(srcImg, pt + cv::Point(iDist, 0));
				double ec = (l + r) / 2.0;

				double log_c = log(c + offset);
				double log_l = log(l + offset);
				double log_r = log(r + offset);
				double log_ec = (log_l + log_r) / 2.0;

				double val = (log_c - log_ec);
				uchar value = cv::saturate_cast<uchar>(beta + alpha*val);

				if (value == 0) value = 1;

				SetPixel(mapImg, pt, value);
			}
		}
	}
}

// COpMappingImage
BOOL COpMappingImage::Process(COperation* pPrevOp, COperation* pPrevOp2)
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
	cv::Mat ImageProc = m_InImage.clone();
	cv::Mat MapImage = ImageProc.clone();

	if (m_strComboLight == _T(""))
	{
		AfxMessageBox(_T("DARK or BRIGHT"));
		return FALSE;
	}

	if (m_iDir == 0)
	{
		if (m_strComboLight == _T("BRIGHT"))
		{
			MakeMapImgX_Bright(ImageProc, MapImage, m_iDist, m_dThr, m_dAlpha, m_dBeta);
		}
		else
		{
			MakeMapImgX_Dark(ImageProc, MapImage, m_iDist, m_dThr, m_dAlpha, m_dBeta);
		}
	}
	else if (m_iDir == 1)
	{
		if (m_strComboLight == _T("BRIGHT"))
		{
			MakeMapImgY_Bright(ImageProc, MapImage, m_iDist, m_dThr, m_dAlpha, m_dBeta);
		}
		else
		{
			MakeMapImgY_Dark(ImageProc, MapImage, m_iDist, m_dThr, m_dAlpha, m_dBeta);
		}
	}

	m_OutImage = MapImage.clone();
	return TRUE;
}

COpDistance::COpDistance()
{
	m_strName = _T("Distance Transform");
	m_iType = OP_DISTANCETRANSFORM;

	m_iDistanceType = 0;
	m_iMarkSize = 3;
}

COpDistance::~COpDistance()
{
}

// COpMappingImage
BOOL COpDistance::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}
	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Distance funciton only can take a single channel image."));
		return FALSE;
	}
	if (m_iMarkSize != 3 && m_iMarkSize != 5)
	{
		AfxMessageBox(_T("Distance funciton only can take masksize is 3 or 5."));
		return FALSE;
	}

	cv::Mat DispImage = m_InImage.clone();
	cv::distanceTransform(m_InImage, DispImage, m_iDistanceType + 1, m_iMarkSize);
	//if(DispImage.channels() == 1) cv::cvtColor(DispImage, DispImage, CV_GRAY2BGR);
	//cv::normalize(DispImage, DispImage, 0, 1.0, NORM_MINMAX);
	m_OutImage = DispImage.clone();

	return TRUE;
}


COpWatershed::COpWatershed()
{
	m_strName = _T("Watershed");
	m_iType = OP_WARTERSHED;
	m_iMarkImgNo = -1;
}

COpWatershed::~COpWatershed()
{
}

// COpMappingImage
BOOL COpWatershed::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}
	if (m_InImage.channels() != 3)
	{
		AfxMessageBox(_T("Watershed funciton only can take 3 channel image."));
		return FALSE;
	}

	Mat maskImage;
	if (pPrevOp2 != NULL)	maskImage = pPrevOp2->GetResultImage();

	if (maskImage.total() == 0)
	{
		AfxMessageBox(_T("Invalid template image."));
		return FALSE;
	}

	if (maskImage.channels() != 1)
	{
		AfxMessageBox(_T("MaskImage funciton only can take a binarize mark image."));
		return FALSE;
	}

	cv::Mat DispImage = m_InImage.clone();

	Mat dist_8u;
	maskImage.convertTo(dist_8u, CV_8U);
	// Find total markers
	vector<vector<Point> > contours;
	findContours(dist_8u, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	// Create the marker image for the watershed algorithm
	Mat markers = Mat::zeros(maskImage.size(), CV_32SC1);
	// Draw the foreground markers
	for (size_t i = 0; i < contours.size(); i++)
		drawContours(markers, contours, static_cast<int>(i), Scalar::all(static_cast<int>(i)+1), -1);
	// Draw the background marker
	circle(markers, Point(5, 5), 3, CV_RGB(255, 255, 255), -1);
	imshow("Markers", markers * 10000);
	// Perform the watershed algorithm
	watershed(m_InImage, markers);
	Mat mark = Mat::zeros(markers.size(), CV_8UC1);
	markers.convertTo(mark, CV_8UC1);
	bitwise_not(mark, mark);
	imshow("Markers_v2", mark); // uncomment this if you want to see how the mark
	// image looks like at that point
	// Generate random colors
	vector<Vec3b> colors;
	for (size_t i = 0; i < contours.size(); i++)
	{
		int b = theRNG().uniform(0, 255);
		int g = theRNG().uniform(0, 255);
		int r = theRNG().uniform(0, 255);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}
	// Create the result image
	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
	// Fill labeled objects with random colors
	for (int i = 0; i < markers.rows; i++)
	{
		for (int j = 0; j < markers.cols; j++)
		{
			int index = markers.at<int>(i, j);
			if (index > 0 && index <= static_cast<int>(contours.size()))
				dst.at<Vec3b>(i, j) = colors[index - 1];
			else
				dst.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
		}
	}

	m_OutImage = dst.clone();
	return TRUE;
}

COpContrast::COpContrast()
{
	m_strName = _T("Contrast");
	m_iType = OP_CONTRAST;
	m_iAlpha = 1;
	m_iBeta = 0;
}

COpContrast::~COpContrast()
{
}

uchar COpContrast::GetPixel(cv::Mat & srcImg, cv::Point pt)
{
	return srcImg.data[pt.y*srcImg.cols + pt.x];
}

void COpContrast::SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value)
{
	srcImg.data[pt.y*srcImg.cols + pt.x] = value;
}

// COpMappingImage
BOOL COpContrast::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	uchar curval = 0;
	cv::Vec3b value;
	m_OutImage = m_InImage.clone();
	//convertScaleAbs(m_InImage, m_OutImage, m_iAlpha, m_iBeta); // gray image
	if (m_InImage.channels() == 1)
	{
		m_OutImage.create(m_OutImage.size(), CV_8UC1);
		m_OutImage = 0;

		cv::Mat_<uchar>::iterator it_e = m_OutImage.begin<uchar>();
		cv::Mat_<uchar>::iterator it = m_InImage.begin<uchar>();
		while (it != m_InImage.end<uchar>())
		{
			(*it_e) = cv::saturate_cast<uchar>(m_iAlpha*(*it) + m_iBeta);

			++it;
			++it_e;
		}
	}
	else
	{
		m_OutImage.create(m_OutImage.size(), CV_8UC3);
		m_OutImage = 0;

		cv::Mat_<cv::Vec3b>::iterator it_e = m_OutImage.begin<cv::Vec3b>();
		cv::Mat_<cv::Vec3b>::iterator it = m_InImage.begin<cv::Vec3b>();
		while (it != m_InImage.end<cv::Vec3b>())
		{
			(*it_e)[0] = cv::saturate_cast<uchar>(m_iAlpha*(*it)[0] + m_iBeta);
			(*it_e)[1] = cv::saturate_cast<uchar>(m_iAlpha*(*it)[1] + m_iBeta);
			(*it_e)[2] = cv::saturate_cast<uchar>(m_iAlpha*(*it)[2] + m_iBeta);

			++it;
			++it_e;
		}
	}
	return TRUE;
}

COpFarshidThr::COpFarshidThr()
{
	m_strName = _T("FarshidThr");
	m_iType = OP_FARSHIDTHR;

}

COpFarshidThr::~COpFarshidThr()
{
}

// COpMappingImage
BOOL COpFarshidThr::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}
	int itime = clock();
	int th, thresFarsh;
	double psnr[240], min = 0.0, max = 0.0;
	cv::Mat f, ImgThre_0, ImgThre_1;
	cv::Scalar mean = cv::mean(m_InImage);
	cv::threshold(m_InImage, ImgThre_0, 5, 255, CV_THRESH_BINARY);
	for (th = 10; th < 240; th++)
	{
		cv::threshold(m_InImage, ImgThre_1, th, 255, CV_THRESH_BINARY);
		psnr[th - 10] = cv::PSNR(ImgThre_0, ImgThre_1);

		if (psnr[th - 10] > max) max = psnr[th - 10];
		if (psnr[th - 10] < min) min = psnr[th - 10];
		ImgThre_1.copyTo(ImgThre_0);
	}
	for (th = 10; th < 240; th++)
	{
		psnr[th - 10] = (psnr[th - 10] - min) / (max - min);
	}
	min = 200;
	for (th = 10; th < 240; th++)
	{
		if (psnr[th - 10] < min)
		{
			thresFarsh = th;
		}
	}
			min = psnr[th - 10];
	thresFarsh = (int)(thresFarsh + (255 - mean[0])) / 2;

	cv::threshold(m_InImage, ImgThre_1, thresFarsh, 255, CV_THRESH_BINARY);

	m_OutImage = ImgThre_1.clone();
	int iEndTime = clock() - itime;
	CString strTime;
	strTime.Format(_T("TactTime = %d"), iEndTime);
	AfxMessageBox(strTime);

	return TRUE;
}