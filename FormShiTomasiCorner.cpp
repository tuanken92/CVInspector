// FormShiTomasiCorner.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormShiTomasiCorner.h"
#include "afxdialogex.h"


// CFormShiTomasiCorner ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormShiTomasiCorner, CDialogEx)

CFormShiTomasiCorner::CFormShiTomasiCorner(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormShiTomasiCorner::IDD, pParent)
	, m_iMaxCorner(0)
	, m_dQualityLevel(0)
	, m_dMinDist(0)
	, m_iBlockSize(0)
	, m_bUseHarris(FALSE)
	, m_iMarkerColorR(0)
	, m_iMarkerColorG(0)
	, m_iMarkerColorB(0)
	, m_iMarkerSize(0)
	, m_iBGImageNo(0)
{

}

CFormShiTomasiCorner::~CFormShiTomasiCorner()
{
}

void CFormShiTomasiCorner::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MAXCORNER, m_iMaxCorner);
	DDX_Text(pDX, IDC_EDIT_QUALITYLEVEL, m_dQualityLevel);
	DDX_Text(pDX, IDC_EDIT_MINDIST, m_dMinDist);
	DDX_Text(pDX, IDC_EDIT_BLOCKSIZE, m_iBlockSize);
	DDX_Check(pDX, IDC_CHECK_USEHARRIS, m_bUseHarris);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_R, m_iMarkerColorR);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_G, m_iMarkerColorG);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_B, m_iMarkerColorB);
	DDX_Text(pDX, IDC_EDIT_MARKERSIZE, m_iMarkerSize);
	DDX_Text(pDX, IDC_EDIT_BGIMAGENO, m_iBGImageNo);
}


BEGIN_MESSAGE_MAP(CFormShiTomasiCorner, CDialogEx)
END_MESSAGE_MAP()


// CFormShiTomasiCorner �޽��� ó�����Դϴ�.
void CFormShiTomasiCorner::SetOperation(COperation* pOperation)
{
	m_pShiTomasiCorner = (COpShiTomasiCorner*)pOperation;

	m_iMaxCorner = m_pShiTomasiCorner->m_iMaxCorners;
	m_dQualityLevel = m_pShiTomasiCorner->m_dQualityLevel;
	m_dMinDist = m_pShiTomasiCorner->m_dMinDist;
	m_iBlockSize = m_pShiTomasiCorner->m_iBlockSize;
	if (m_pShiTomasiCorner->m_bUseHarris)	m_bUseHarris = TRUE;
	else m_bUseHarris = FALSE;
	
	m_iMarkerColorR = m_pShiTomasiCorner->GetMarkerColor(0);
	m_iMarkerColorG = m_pShiTomasiCorner->GetMarkerColor(1);
	m_iMarkerColorB = m_pShiTomasiCorner->GetMarkerColor(2);
	m_iMarkerSize = m_pShiTomasiCorner->GetMarkerSize();

	m_iBGImageNo = m_pShiTomasiCorner->GetSecondImgIndex();

	UpdateData(FALSE);
}


void CFormShiTomasiCorner::ApplyChanges()
{
	UpdateData(TRUE);

	m_pShiTomasiCorner->m_iMaxCorners = m_iMaxCorner;
	m_pShiTomasiCorner->m_dQualityLevel = m_dQualityLevel;
	m_pShiTomasiCorner->m_dMinDist = m_dMinDist;
	m_pShiTomasiCorner->m_iBlockSize = m_iBlockSize;
	if (m_bUseHarris)	m_pShiTomasiCorner->m_bUseHarris = true;
	else m_pShiTomasiCorner->m_bUseHarris = false;

	m_pShiTomasiCorner->SetMarkerColor(m_iMarkerColorR, m_iMarkerColorG, m_iMarkerColorB);
	m_pShiTomasiCorner->SetMarkerSize(m_iMarkerSize);
	m_pShiTomasiCorner->SetSecondImgIndex(m_iBGImageNo);
}

BOOL CFormShiTomasiCorner::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
