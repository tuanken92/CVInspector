#pragma once

#include <opencv2\opencv.hpp>
using namespace cv;
// COperation ��� ����Դϴ�.

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
	Mat m_OutImage;					// ó�� ��� Image
	Mat m_DispImage;				// ó�� ����� ���� ���� ǥ���� Image

	BOOL m_bShowDisplayImage;		

	// ó�� ��� ǥ��
	Scalar m_MarkerColor;			// ó�� ���ǥ�� ��Ŀ ����
	int m_iMarkerType;				// 0: Circle, 1:Cross
	int m_iMarkerSize;				// Marker�� ũ��, ���� ������

	// �̹��� �̿��� ó�� �����
	vector<Point> m_ResultPoints;				// ��� Points
	vector<Vec4i> m_ResultLines;				// ��� Lines (Houghline)
	vector<Vec3f> m_ResultCircles;				// ��� Circles (HoughCircle)
	vector<Rect>  m_ResultRects;				// ��� Rectangles
	vector<vector<Point> > m_ResultContours;	// ��� Contours
	vector<KeyPoint> m_ResKeyPoints;			// ��� KeyPoints

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



