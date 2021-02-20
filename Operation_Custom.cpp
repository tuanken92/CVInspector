#include "stdafx.h"
#include "CVInspector.h"
#include "Operation_Custom.h"

////////////////////
// COpCustomFunc1
////////////////////
COpCustomFunc1::COpCustomFunc1()
{
	m_strName = _T("Custom Func1");
	m_iType = OP_CUSTOMFUNC1;

}

COpCustomFunc1::~COpCustomFunc1()
{
}

// COpCustomFunc1 멤버 함수

BOOL COpCustomFunc1::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	int i = 0;

	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Custom Func1 only can take a gray scale image."));
		return FALSE;
	}

	// Blur
	Mat blurImage;
	blur(m_InImage, blurImage, cv::Size(5, 5));

	// Binarize
	Mat binImage;
	cv::threshold(blurImage, binImage, 64.0, 255, THRESH_BINARY);

	// close
	Mat closeImage;
	morphologyEx(binImage, closeImage, cv::MORPH_CLOSE, Mat());

	// find the biggest blob
	vector<vector<Point> > contours;
	vector<vector<Point> > result_contours;
	vector<Vec4i> hierarchy;

	// find contours 함수가 원본을 변경하므로 함수 호출전에 Clone해서 넘겨주자.
	Mat ProcImg = closeImage.clone();

	int iMode = CV_RETR_LIST;
	int iMethod = CV_CHAIN_APPROX_NONE;

	cv::findContours(ProcImg, contours, hierarchy, iMode, iMethod);

	cv::Rect blobRect;
	int iContourCnt = (int)contours.size();

	if (iContourCnt <= 0)
	{
		AfxMessageBox(_T("No blob."));
		return FALSE;
	}

	int iMaxArea = 0;
	int iMaxIndex = 0;

	for (i = 0; i<iContourCnt; i++)
	{
		int iContourArea = (int)cv::contourArea(contours[i]); //(int)contours[i].size();

		if (iMaxArea < iContourArea)
		{
			iMaxArea = iContourArea;
			iMaxIndex = i;
		}		
	}

	vector<Point> outlineContour;
	for (i = 0; i < (int)contours[iMaxIndex].size(); i++)
	{
		int iPX = contours[iMaxIndex][i].x;
		int iPY = contours[iMaxIndex][i].y;

		if (iPY < 16 || iPX < 16) continue;

		// 아랫 부분만 남기고 나머지를 지우기 위해 지금 포인트 보다 윗쪽이 White 인 경우만 저장
		if (closeImage.at<uchar>(cv::Point(iPX, iPY - 2)) > 0)
		{
			outlineContour.push_back(contours[iMaxIndex][i]);
		}
	}

	m_OutImage = m_InImage.clone();
	m_OutImage.setTo(0);

//	result_contours.push_back(outlineContour);
//	cv::drawContours(m_OutImage, result_contours, -1, cv::Scalar(255), 1);

	int iStep = 4;

	for (i = iStep; i < (int)outlineContour.size(); i++)
	{
		Point curPt = outlineContour[i];
		Point refPt = outlineContour[i - iStep];

		Point offsetPt(4, 16);

		Rect r1(curPt - offsetPt, curPt);	// 대상 위치
		Rect r2(refPt - offsetPt, refPt);	// 대상 위치
		Mat m1 = m_InImage(r1);
		Mat m2 = m_InImage(r2);
		Mat tmp = m1.clone();
		Mat m3 = m_OutImage(r1);

		absdiff(m1, m2, tmp);

		m3 = cv::max(m3, tmp);
	}

	return TRUE;
}


////////////////////
// COpCustomFunc2
////////////////////
COpCustomFunc2::COpCustomFunc2()
{
	m_strName = _T("Custom Func2");
	m_iType = OP_CUSTOMFUNC2;

}

COpCustomFunc2::~COpCustomFunc2()
{
}

// COpCustomFunc2 멤버 함수

BOOL COpCustomFunc2::Process2(COperation* pPrevOp, COperation* pPrevOp2)
{
	int i = 0;

	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Custom Func1 only can take a gray scale image."));
		return FALSE;
	}

	// Binarize
	Mat binImage;
	cv::threshold(m_InImage, binImage, 172.0, 255, THRESH_BINARY_INV);

	// close
	Mat kernel = getStructuringElement(0, Size(5, 5), Point(2, 2));
	Point anchor(-1, -1);
	Mat closeImage;
	morphologyEx(binImage, closeImage, cv::MORPH_CLOSE, kernel, anchor, 3);

	// erode 한다. 실제 외곽선과 가장 비슷한 위치를 찾기 위해서 좀 줄인다. 덤으로 노이즈도 지운다.
	Mat erodeImage;
	morphologyEx(closeImage, erodeImage, cv::MORPH_ERODE, Mat());// , anchor, 2);

	// find the biggest blob
	vector<vector<Point> > contours;
	vector<vector<Point> > result_contours;
	vector<Vec4i> hierarchy;

	// find contours 함수가 원본을 변경하므로 함수 호출전에 Clone해서 넘겨주자.
	Mat ProcImg = erodeImage.clone();

	int iMode = CV_RETR_LIST;
	int iMethod = CV_CHAIN_APPROX_NONE;

	cv::findContours(ProcImg, contours, hierarchy, iMode, iMethod);

	cv::Rect blobRect;
	int iContourCnt = (int)contours.size();

	if (iContourCnt <= 0)
	{
		AfxMessageBox(_T("No blob."));
		return FALSE;
	}

	int iMaxArea = 0;
	int iMaxIndex = 0;

	for (i = 0; i<iContourCnt; i++)
	{
		int iContourArea = (int)cv::contourArea(contours[i]); //(int)contours[i].size();

		if (iMaxArea < iContourArea)
		{
			iMaxArea = iContourArea;
			iMaxIndex = i;
		}
	}

	vector<Point> outlineContour;
	int iBndOffset = 64;

	for (i = 0; i < (int)contours[iMaxIndex].size(); i++)
	{
		int iPX = contours[iMaxIndex][i].x;
		int iPY = contours[iMaxIndex][i].y;

		if (iPY < iBndOffset || iPX < iBndOffset || iPY > (m_InImage.rows - iBndOffset) || iPX > (m_InImage.cols - iBndOffset)) continue;

		outlineContour.push_back(contours[iMaxIndex][i]);
	}

	m_OutImage = m_InImage.clone();
	m_OutImage.setTo(0);

	int iStep = 24;

	for (i = iStep; i < (int)outlineContour.size() - iStep; i++)
	{
		Point curPt = outlineContour[i];
		Point refPt1 = outlineContour[i - iStep];
		Point refPt2 = outlineContour[i + iStep];

		Point offsetPt(7, 7);

		Rect r1(curPt - offsetPt, curPt + offsetPt);	// 대상 위치
		Rect r2(refPt1 - offsetPt, refPt1 + offsetPt);	// 대상 위치
		Rect r3(refPt2 - offsetPt, refPt2 + offsetPt);	// 대상 위치
		Mat m1 = m_InImage(r1);
		Mat m2 = m_InImage(r2);
		Mat m3 = m_InImage(r3);
		Mat tmp = m1.clone();
		Mat tmp1 = m1.clone();
		Mat tmp2 = m1.clone();
		Mat m4 = m_OutImage(r1);

		tmp1 = m2 - m1;
		tmp2 = m3 - m1;
		//absdiff(m1, m2, tmp1);
		//absdiff(m1, m3, tmp2);

		tmp = cv::max(tmp1, tmp2);
		m4 = cv::max(m4, tmp);
	}

	return TRUE;
}

BOOL COpCustomFunc2::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	int i = 0;

	m_InImage = pPrevOp->GetResultImage();

	if (m_InImage.total() == 0)
	{
		return FALSE;
	}

	if (m_InImage.channels() != 1)
	{
		AfxMessageBox(_T("Custom Func1 only can take a gray scale image."));
		return FALSE;
	}

	// Binarize
	Mat binImage;
	cv::threshold(m_InImage, binImage, 172.0, 255, THRESH_BINARY_INV);

	// close
	Mat kernel = getStructuringElement(0, Size(5, 5), Point(2, 2));
	Point anchor(-1, -1);
	Mat closeImage;
	morphologyEx(binImage, closeImage, cv::MORPH_CLOSE, kernel, anchor, 3);

	// erode 한다. 실제 외곽선과 가장 비슷한 위치를 찾기 위해서 좀 줄인다. 덤으로 노이즈도 지운다.
	Mat erodeImage;
	morphologyEx(closeImage, erodeImage, cv::MORPH_ERODE, Mat());// , anchor, 2);

	// find the biggest blob
	vector<vector<Point> > contours;
	vector<vector<Point> > result_contours;
	vector<Vec4i> hierarchy;

	// find contours 함수가 원본을 변경하므로 함수 호출전에 Clone해서 넘겨주자.
	Mat ProcImg = erodeImage.clone();

	int iMode = CV_RETR_LIST;
	int iMethod = CV_CHAIN_APPROX_NONE;

	cv::findContours(ProcImg, contours, hierarchy, iMode, iMethod);

	cv::Rect blobRect;
	int iContourCnt = (int)contours.size();

	if (iContourCnt <= 0)
	{
		AfxMessageBox(_T("No blob."));
		return FALSE;
	}

	int iMaxArea = 0;
	int iMaxIndex = 0;

	for (i = 0; i<iContourCnt; i++)
	{
		int iContourArea = (int)cv::contourArea(contours[i]); //(int)contours[i].size();

		if (iMaxArea < iContourArea)
		{
			iMaxArea = iContourArea;
			iMaxIndex = i;
		}
	}

	vector<Point> outlineContour;
	int iBndOffset = 64;

	for (i = 0; i < (int)contours[iMaxIndex].size(); i++)
	{
		int iPX = contours[iMaxIndex][i].x;
		int iPY = contours[iMaxIndex][i].y;

		if (iPY < iBndOffset || iPX < iBndOffset || iPY >(m_InImage.rows - iBndOffset) || iPX >(m_InImage.cols - iBndOffset)) continue;

		outlineContour.push_back(contours[iMaxIndex][i]);
	}

	m_OutImage = m_InImage.clone();
	m_OutImage.setTo(0);

	vector<int> edgeVal;
	int iAvg = 0;

	for (i = 0; i < (int)outlineContour.size(); i++)
	{
		Point curPt = outlineContour[i];
		
		Point offsetPt(3, 3);

		Rect r1(curPt - offsetPt, curPt + offsetPt);	// 대상 위치
		Mat m1 = m_InImage(r1);

		Scalar meanVal = cv::mean(m1);

		edgeVal.push_back((int)meanVal[0]);

		iAvg += (int)meanVal[0];
	}

	iAvg /= outlineContour.size();

	for (i = 0; i < (int)outlineContour.size(); i++)
	{
		if (edgeVal[i] < iAvg - 24)
		{
			Point curPt = outlineContour[i];
			Point offsetPt(3, 3);
			Rect r1(curPt - offsetPt, curPt + offsetPt);	// 대상 위치
			Mat m1 = m_OutImage(r1);
			m1.setTo(255);
		}
	}
	return TRUE;
}