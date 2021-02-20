#include "stdafx.h"
#include "CVInspector.h"
#include "Operation_Feature.h"


////////////////////
// COpCanny
////////////////////
COpCanny::COpCanny()
{
	m_strName = _T("Canny");
	m_iType = OP_CANNY;
	m_dThr1 = 32.0;
	m_dThr2 = 64.0;
	m_iApertureSize = 3;

}

COpCanny::~COpCanny()
{
}

// COpCanny 멤버 함수
BOOL COpCanny::Process(COperation* pPrevOp, COperation* pPrevOp2)
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

	if (m_iApertureSize % 2 == 0)
	{
		AfxMessageBox(_T("Canny aperture size must be an odd number. 1,3,5, or 7."));
		return FALSE;
	}

	Canny(m_InImage, m_OutImage, m_dThr1, m_dThr2, m_iApertureSize);

	return TRUE;
}

////////////////////
// COpContour
////////////////////
COpContour::COpContour()
{
	m_strName = _T("Contour");
	m_iType = OP_CONTOUR;
	m_iMode = CV_RETR_EXTERNAL;
	m_iMethod = CV_CHAIN_APPROX_SIMPLE;
	m_iLineWidth = 3;	// -1(CV_FILLED)
	m_iLineType = 4;	// 4, 8, 16(CV_AA);
	m_iMaxLevel = -1;
	m_bConvexHull = FALSE;
}

COpContour::~COpContour()
{
}

// COpContour 멤버 함수
BOOL COpContour::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Contour function only can take a gray scale image."));
		return FALSE;
	}

	m_ResultContours.clear();
	vector<Vec4i> hierarchy;

	Mat tmpImg = m_InImage.clone();
	findContours(tmpImg, m_ResultContours, hierarchy, m_iMode, m_iMethod);
	
	// Use ConvexHull - ThanhLM
	int iSize = m_ResultContours.size();
	vector<vector<cv::Point>> vHull(iSize);
	if (m_bConvexHull)
	{
		for (int i = 0; i < iSize; i++)
		{
			cv::convexHull((Mat)m_ResultContours[i], vHull[i], FALSE);
		}
		m_ResultContours = vHull;
	}

	if (pPrevOp2 == NULL)
	{
		// drawContours의 첫번째 인자는 빈 매트릭스는 안된다. 
		m_OutImage = m_InImage.clone();
		m_OutImage.setTo(0);
	}
	else
	{
		// clone 하지 않으면 debug 모드에서 에러난다.
		Mat bgImage = pPrevOp2->GetResultImage();
		m_OutImage = bgImage.clone();
	}

	int iMaxLevel = INT_MAX;
	if (m_iMaxLevel >= 0)
	{
		iMaxLevel = m_iMaxLevel;
	}
	drawContours(m_OutImage, m_ResultContours, -1, cv::Scalar(255, 255, 255), m_iLineWidth, m_iLineType, hierarchy, iMaxLevel);

	return TRUE;
}


////////////////////
// COpBlob
////////////////////
COpBlob::COpBlob()
{
	m_strName = _T("Blob");
	m_iType = OP_BLOB;

	m_fThresholdStep = 5.0;
	m_fMinThreshold = 40.0;
	m_fMaxThreshold = 60.0;
	m_iMinRepeatability = 0;
	m_fMinDistBetweenBlobs = 0.0;
	m_bFilterByColor = FALSE;
	m_iBlobColor = 0;
	m_bFilterByArea = FALSE;
	m_fMinArea = 0.0;
	m_fMaxArea = 0.0;
	m_bFilterByCircularity = FALSE;
	m_fMinCircularity = 0.0;
	m_fMaxCircularity = 0.0;
	m_bFilterByInertia = FALSE;
	m_fMinInertiaRatio = 0.0;
	m_fMaxInertiaRatio = 0.0;
	m_bFilterByConvexity = FALSE;
	m_fMinConvexity = 0.0;
	m_fMaxConvexity = 0.0;
}

COpBlob::~COpBlob()
{
}
#include "opencv2/nonfree/features2d.hpp"

// COpBlob 멤버 함수
BOOL COpBlob::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Blob function only can take a gray scale image."));
		return FALSE;
	}

	SimpleBlobDetector::Params params;
	params.thresholdStep = m_fThresholdStep;
	params.minThreshold = m_fMinThreshold;
	params.maxThreshold = m_fMaxThreshold;
	params.minRepeatability = m_iMinRepeatability;
	params.minDistBetweenBlobs = m_fMinDistBetweenBlobs;
	if (m_bFilterByColor) { params.filterByColor = true; }
	else { params.filterByColor = false; }
	params.blobColor = m_iBlobColor;
	if (m_bFilterByArea) { params.filterByArea = true; }
	else { params.filterByArea = false; }
	params.minArea = m_fMinArea;
	params.maxArea = m_fMaxArea;
	if (m_bFilterByCircularity) { params.filterByCircularity = true; }
	else { params.filterByCircularity = false; }
	params.minCircularity = m_fMinCircularity;
	params.maxCircularity = m_fMaxCircularity;
	if (m_bFilterByInertia) { params.filterByInertia = true; }
	else { params.filterByInertia = false; }
	params.minInertiaRatio = m_fMinInertiaRatio;
	params.maxInertiaRatio = m_fMaxInertiaRatio;
	if (m_bFilterByConvexity) { params.filterByConvexity = true; }
	else { params.filterByConvexity = false; }
	params.minConvexity = m_fMinConvexity;
	params.maxConvexity = m_fMaxConvexity;

	SimpleBlobDetector blobDetector(params);
	const string detectorName = "SimpleBlob";
	blobDetector.create(detectorName);

	blobDetector.detect(m_InImage, m_ResKeyPoints);

	/*	Mat tmpOutImg;
	drawKeypoints(m_InImage, keyPoints, tmpOutImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	m_OutImage = tmpOutImg.clone();*/


	// draw circles at feature point locations on an image
	vector<KeyPoint>::const_iterator it = m_ResKeyPoints.begin();

	int iRadius = m_iMarkerSize / 2;
	int iThickness = m_iMarkerSize / 4;

	cv::cvtColor(m_InImage, m_OutImage, COLOR_GRAY2BGR);

	while (it != m_ResKeyPoints.end())
	{
		cv::circle(m_OutImage, (*it).pt, iRadius, m_MarkerColor, iThickness);
		++it;
	}

	return TRUE;
}


////////////////////
// COpHoughLine
////////////////////
COpHoughLine::COpHoughLine()
{
	m_strName = _T("Hough Line");
	m_iType = OP_HOUGHLINE;

	m_dRho = 1;
	m_dTheta = CV_PI / 180;
	m_iThreshold = 10;
	m_dMinLineLength = 0.0;
	m_dMaxLineGap = 0.0;
}

COpHoughLine::~COpHoughLine()
{
}

// COpHoughLine 멤버 함수
BOOL COpHoughLine::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Hough Line function only can take a gray scale image."));
		return FALSE;
	}

	m_ResultLines.clear();

	HoughLinesP(m_InImage, m_ResultLines, m_dRho, m_dTheta, m_iThreshold, m_dMinLineLength, m_dMaxLineGap);

	vector<cv::Vec4i>::const_iterator it = m_ResultLines.begin();
	Scalar color(255, 255, 255);

	if (pPrevOp2 == NULL)
	{
		// drawContours의 첫번째 인자는 빈 매트릭스는 안된다. 
		m_OutImage = m_InImage.clone();
		m_OutImage.setTo(0);
	}
	else
	{
		// clone 하지 않으면 debug 모드에서 에러난다.
		Mat bgImage = pPrevOp2->GetResultImage();
		m_OutImage = bgImage.clone();
	}

	while (it != m_ResultLines.end())
	{
		Point pt1((*it)[0], (*it)[1]);
		Point pt2((*it)[2], (*it)[3]);
		line(m_OutImage, pt1, pt2, color);

		++it;
	}
	return TRUE;
}


////////////////////
// COpHoughCircle
////////////////////
COpHoughCircle::COpHoughCircle()
{
	m_strName = _T("Hough Circle");
	m_iType = OP_HOUGHCIRCLE;

	m_dAccuRes = 1.0;
	m_dMinDist = 10.0;
	m_dParam1 = 100.0;
	m_dParam2 = 100.0;
	m_iMinRadius = 0;
	m_iMaxRadius = 0;
}

COpHoughCircle::~COpHoughCircle()
{
}

// COpHoughCircle 멤버 함수
BOOL COpHoughCircle::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Hough Circle function only can take a gray scale image."));
		return FALSE;
	}

	m_ResultCircles.clear();

	HoughCircles(m_InImage, m_ResultCircles, CV_HOUGH_GRADIENT, m_dAccuRes, m_dMinDist, m_dParam1, m_dParam2, m_iMinRadius, m_iMaxRadius);

	vector<cv::Vec3f>::const_iterator it = m_ResultCircles.begin();
	Scalar color(255, 255, 255);

	if (pPrevOp2 == NULL)
	{
		// drawContours의 첫번째 인자는 빈 매트릭스는 안된다. 
		m_OutImage = m_InImage.clone();
		m_OutImage.setTo(0);
	}
	else
	{
		// clone 하지 않으면 debug 모드에서 에러난다.
		Mat bgImage = pPrevOp2->GetResultImage();
		m_OutImage = bgImage.clone();
	}

	while (it != m_ResultCircles.end())
	{
		Point pt1;
		pt1.x = (int)((*it)[0]);
		pt1.y = (int)((*it)[1]);
		int iRadius = (int)((*it)[2]);
		circle(m_OutImage, pt1, iRadius, color, 2);

		++it;
	}
	return TRUE;
}


////////////////////
// COpHarrisCorner
////////////////////
COpHarrisCorner::COpHarrisCorner()
{
	m_strName = _T("Harris Corner");
	m_iType = OP_HARRISCORNER;

	m_iNeighbor = 3;
	m_iAperture = 3;
	m_dParameterK = 0.01;
	m_iNonMaxSize = 3;
}

COpHarrisCorner::~COpHarrisCorner()
{
}

// COpHarrisCorner 멤버 함수
BOOL COpHarrisCorner::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Harris Corner function only can take a gray scale image."));
		return FALSE;
	}

	// Harris computation
	Mat cornerStrength;
	cornerHarris(m_InImage, cornerStrength, m_iNeighbor, m_iAperture, m_dParameterK);

	// internal threshold computation
	double dMinStrength;
	double dMaxStrength;
	minMaxLoc(cornerStrength, &dMinStrength, &dMaxStrength);

	// local maxima detection
	Mat dilatedImg;
	Mat localMax;
	dilate(cornerStrength, dilatedImg, cv::Mat());
	compare(cornerStrength, dilatedImg, localMax, CMP_EQ);

	// get the corner map from the computed Harris values
	Mat cornerMap;
	Mat cornerTh;
	double dQualityLevel = 0.01;

	// thresholding the corner strength
	double dThreshold = dQualityLevel*dMaxStrength;
	threshold(cornerStrength, cornerTh, dThreshold, 255, THRESH_BINARY);

	// convert to 8-bit image
	cornerTh.convertTo(cornerMap, CV_8U);

	// non-maxima supression
	bitwise_and(cornerMap, localMax, cornerMap);

	// get the feature points from the computed corner map
	m_ResultPoints.clear();

	for (int y = 0; y < cornerMap.rows; y++)
	{
		const uchar* rowPtr = cornerMap.ptr<uchar>(y);
		for (int x = 0; x < cornerMap.cols; x++)
		{
			if (rowPtr[x])
			{
				m_ResultPoints.push_back(Point(x, y));
			}
		}
	}

	// draw circles at feature point locations on an image
	vector<Point>::const_iterator it = m_ResultPoints.begin();

	int iRadius = m_iMarkerSize / 2;
	int iThickness = m_iMarkerSize / 4;

	if (pPrevOp2 == NULL)
	{
		cv::cvtColor(m_InImage, m_OutImage, COLOR_GRAY2BGR);
	}
	else
	{
		// clone 하지 않으면 debug 모드에서 에러난다.
		Mat bgImage = pPrevOp2->GetResultImage();
		cv::cvtColor(bgImage, m_OutImage, COLOR_GRAY2BGR);		
	}
		
	while (it != m_ResultPoints.end())
	{
		cv::circle(m_OutImage, *it, iRadius, m_MarkerColor, iThickness);
		++it;
	}

	return TRUE;
}

////////////////////
// COpShiTomasiCorner
////////////////////
COpShiTomasiCorner::COpShiTomasiCorner()
{
	m_strName = _T("Shi-Tomasi Corner");
	m_iType = OP_SHITOMASICORNER;

	m_iMaxCorners = 2048;
	m_dQualityLevel = 0.01;
	m_dMinDist = 10;
	m_iBlockSize = 3;
	m_bUseHarris = false;
	m_dK = 0.04;
}

COpShiTomasiCorner::~COpShiTomasiCorner()
{
}

// COpShiTomasiCorner 멤버 함수
BOOL COpShiTomasiCorner::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Shi-Tomasi Corner function only can take a gray scale image."));
		return FALSE;
	}

	/// Apply corner detection 
	//vector<Point2f> corners;
	m_ResultPoints.clear();
	goodFeaturesToTrack(m_InImage, m_ResultPoints, m_iMaxCorners, m_dQualityLevel, m_dMinDist, Mat(), m_iBlockSize, m_bUseHarris, m_dK);

	// draw circles at feature point locations on an image
	vector<Point>::const_iterator it = m_ResultPoints.begin();

	int iRadius = m_iMarkerSize / 2;
	int iThickness = m_iMarkerSize / 4;

	if (pPrevOp2 == NULL)
	{
		cv::cvtColor(m_InImage, m_OutImage, COLOR_GRAY2BGR);
	}
	else
	{
		// clone 하지 않으면 debug 모드에서 에러난다.
		Mat bgImage = pPrevOp2->GetResultImage();
		cv::cvtColor(bgImage, m_OutImage, COLOR_GRAY2BGR);
	}

	while (it != m_ResultPoints.end())
	{
		cv::circle(m_OutImage, *it, iRadius, m_MarkerColor, iThickness);
		++it;
	}

	return TRUE;
}

////////////////////
// COpFAST
////////////////////
COpFAST::COpFAST()
{
	m_strName = _T("FAST");
	m_iType = OP_FAST;

	m_iThreshold = 8;
	m_bNonMaximaSupression = true;
	m_iDetectorType = FastFeatureDetector::TYPE_9_16;
}

COpFAST::~COpFAST()
{
}

// COpFAST 멤버 함수
BOOL COpFAST::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("FAST function only can take a gray scale image."));
		return FALSE;
	}

	/// Apply corner detection 
	m_ResKeyPoints.clear();
	FASTX(m_InImage, m_ResKeyPoints, m_iThreshold, m_bNonMaximaSupression, m_iDetectorType);

	// draw circles at feature point locations on an image
	vector<KeyPoint>::const_iterator it = m_ResKeyPoints.begin();

	int iRadius = m_iMarkerSize / 2;
	int iThickness = m_iMarkerSize / 4;

	if (pPrevOp2 == NULL)
	{
		cv::cvtColor(m_InImage, m_OutImage, COLOR_GRAY2BGR);
	}
	else
	{
		// clone 하지 않으면 debug 모드에서 에러난다.
		Mat bgImage = pPrevOp2->GetResultImage();
		cv::cvtColor(bgImage, m_OutImage, COLOR_GRAY2BGR);
	}

	while (it != m_ResKeyPoints.end())
	{
		Point CurPt = it->pt;
		cv::circle(m_OutImage, CurPt, iRadius, m_MarkerColor, iThickness);
		++it;
	}

	return TRUE;
}

