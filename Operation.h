#pragma once

#include <opencv2\opencv.hpp>
using namespace cv;
// COperation 명령 대상입니다.

class COperation : public CObject
{
public:
	COperation();
	virtual ~COperation();

protected:
	int m_iType;
	CString m_strName;
	int m_iInputImgIndex;
	int m_iSecondImgIndex;

	Mat m_InImage;					// Source Image
	Mat m_OutImage;					// 처리 결과 Image
	Mat m_DispImage;				// 처리 결과를 보기 좋게 표현한 Image

	BOOL m_bShowDisplayImage;		

	// 처리 결과 표시
	Scalar m_MarkerColor;			// 처리 결과표시 마커 색상
	int m_iMarkerType;				// 0: Circle, 1:Cross
	int m_iMarkerSize;				// Marker의 크기, 원의 반지름

	// 이미지 이외의 처리 결과들
	vector<Point> m_ResultPoints;				// 결과 Points
	vector<Vec4i> m_ResultLines;				// 결과 Lines (Houghline)
	vector<Vec3f> m_ResultCircles;				// 결과 Circles (HoughCircle)
	vector<Rect>  m_ResultRects;				// 결과 Rectangles
	vector<vector<Point> > m_ResultContours;	// 결과 Contours
	vector<KeyPoint> m_ResKeyPoints;			// 결과 KeyPoints

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	virtual Mat GetResultImage();
	virtual Mat GetDisplayImage();
	
	Mat GetInputImage();
	int GetInputImgIndex();
	void SetInputImgIndex(int iInputImgIndex);
	int GetSecondImgIndex();
	void SetSecondImgIndex(int iSecondImgIndex);
	int GetTypeID();
	CString GetName();	
	BOOL GetShowDisplayImage();
	void SetShowDisplayImage(BOOL bShowDisplayImage);
	void SetMarkerColor(Scalar scColor);
	Scalar GetMarkerColor();
	void SetMarkerColor(int iR, int iG, int iB);
	int GetMarkerColor(int iComponent);
	void SetMarkerSize(int iRadius);
	int GetMarkerSize();
	vector<Point> GetResultPoints();
	vector<Vec4i> GetResultLines();
	vector<Vec3f> GetResultCircles();
	vector<Rect> GetResultRects();
	vector<vector<Point> > GetResultContours();
	vector<KeyPoint> GetResultKeyPoints();
};



