// Operation.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "Operation.h"
#include "FormCvtColor.h"

////////////////////
// COperation
////////////////////
COperation::COperation()
{
	m_iInputImgIndex = -1;
	m_iSecondImgIndex = -1;
	m_bShowDisplayImage = FALSE;

	m_MarkerColor = Scalar(0, 0, 255);
	m_iMarkerType = 0;
	m_iMarkerSize = 10;
}

COperation::~COperation()
{
}

// COperation 멤버 함수
BOOL COperation::Process(COperation* pPrevOp, COperation* pPrevOp2)
{
	return TRUE;
}

Mat COperation::GetResultImage()
{
	return m_OutImage;
}

Mat COperation::GetInputImage()
{
	return m_InImage;
}

Mat COperation::GetDisplayImage()
{
	if (m_bShowDisplayImage)
	{
		return m_DispImage;
	}

	return m_OutImage;
}

int COperation::GetInputImgIndex()
{
	return m_iInputImgIndex;
}

void COperation::SetInputImgIndex(int iInputImgIndex)
{
	m_iInputImgIndex = iInputImgIndex;
}

int COperation::GetSecondImgIndex()
{
	return m_iSecondImgIndex;
}

void COperation::SetSecondImgIndex(int iSecondImgIndex)
{
	m_iSecondImgIndex = iSecondImgIndex;
}

int COperation::GetTypeID()
{
	return m_iType;
}

CString COperation::GetName()
{
	return m_strName;
}

BOOL COperation::GetShowDisplayImage()
{
	return m_bShowDisplayImage;
}

void COperation::SetShowDisplayImage(BOOL bShowDisplayImage)
{
	m_bShowDisplayImage = bShowDisplayImage;
}

void COperation::SetMarkerColor(Scalar scColor)
{
	m_MarkerColor = scColor;
}

Scalar COperation::GetMarkerColor()
{
	return m_MarkerColor;
}

void COperation::SetMarkerColor(int iR, int iG, int iB)
{
	m_MarkerColor = Scalar(iB, iG, iR);
}

int COperation::GetMarkerColor(int iComponent)
{
	if (iComponent == 0)		return (int)m_MarkerColor[2];
	else if (iComponent == 1)	return (int)m_MarkerColor[1];
	else						return (int)m_MarkerColor[0];

	return (int)m_MarkerColor[0];

}
void COperation::SetMarkerSize(int iRadius)
{
	m_iMarkerSize = iRadius;
}

int COperation::GetMarkerSize()
{
	return m_iMarkerSize;
}

vector<Point> COperation::GetResultPoints()
{
	return m_ResultPoints;
}

vector<Vec4i> COperation::GetResultLines()
{
	return m_ResultLines;
}

vector<Vec3f> COperation::GetResultCircles()
{
	return m_ResultCircles;
}

vector<Rect> COperation::GetResultRects()
{
	return m_ResultRects;
}

vector<vector<Point> > COperation::GetResultContours()
{
	return m_ResultContours;
}

vector<KeyPoint> COperation::GetResultKeyPoints()
{
	return m_ResKeyPoints;
}

