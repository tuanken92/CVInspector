// FormHarrisCorner.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormHarrisCorner.h"
#include "afxdialogex.h"


// CFormHarrisCorner 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormHarrisCorner, CDialogEx)

CFormHarrisCorner::CFormHarrisCorner(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormHarrisCorner::IDD, pParent)
	, m_iAperture(0)
	, m_dParameterK(0)
	, m_iNonMaxSize(0)
	, m_iNeighbor(0)
	, m_iMarkerColorR(0)
	, m_iMarkerColorG(0)
	, m_iMarkerColorB(0)
	, m_iMarkerSize(0)
	, m_iBGImageNo(0)
{

}

CFormHarrisCorner::~CFormHarrisCorner()
{
}

void CFormHarrisCorner::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_APERTURE, m_iAperture);
	DDX_Text(pDX, IDC_EDIT_PARAMETERK, m_dParameterK);
	DDX_Text(pDX, IDC_EDIT_NONMAXSIZE, m_iNonMaxSize);
	DDX_Text(pDX, IDC_EDIT_NEIGHBOR, m_iNeighbor);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_R, m_iMarkerColorR);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_G, m_iMarkerColorG);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_B, m_iMarkerColorB);
	DDX_Text(pDX, IDC_EDIT_MARKERSIZE, m_iMarkerSize);
	DDX_Text(pDX, IDC_EDIT_BGIMAGENO, m_iBGImageNo);
}


BEGIN_MESSAGE_MAP(CFormHarrisCorner, CDialogEx)
END_MESSAGE_MAP()


// CFormHarrisCorner 메시지 처리기입니다.
void CFormHarrisCorner::SetOperation(COperation* pOperation)
{
	m_pHarrisCorner = (COpHarrisCorner*)pOperation;

	m_iNeighbor = m_pHarrisCorner->m_iNeighbor;
	m_iAperture = m_pHarrisCorner->m_iAperture;
	m_dParameterK = m_pHarrisCorner->m_dParameterK;
	m_iNonMaxSize = m_pHarrisCorner->m_iNonMaxSize;

	m_iMarkerColorR = m_pHarrisCorner->GetMarkerColor(0);
	m_iMarkerColorG = m_pHarrisCorner->GetMarkerColor(1);
	m_iMarkerColorB = m_pHarrisCorner->GetMarkerColor(2);
	m_iMarkerSize = m_pHarrisCorner->GetMarkerSize();

	m_iBGImageNo = m_pHarrisCorner->GetSecondImgIndex();

	UpdateData(FALSE);
}


void CFormHarrisCorner::ApplyChanges()
{
	UpdateData(TRUE);

	m_pHarrisCorner->m_iNeighbor = m_iNeighbor;
	m_pHarrisCorner->m_iAperture = m_iAperture;
	m_pHarrisCorner->m_dParameterK = m_dParameterK;
	m_pHarrisCorner->m_iNonMaxSize = m_iNonMaxSize;

	m_pHarrisCorner->SetMarkerColor(m_iMarkerColorR, m_iMarkerColorG, m_iMarkerColorB);
	m_pHarrisCorner->SetMarkerSize(m_iMarkerSize);
	m_pHarrisCorner->SetSecondImgIndex(m_iBGImageNo);
}

BOOL CFormHarrisCorner::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
