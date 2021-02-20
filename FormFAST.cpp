// FormFAST.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFAST.h"
#include "afxdialogex.h"


// CFormFAST ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormFAST, CDialogEx)

CFormFAST::CFormFAST(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormFAST::IDD, pParent)
	, m_iThreshold(0)
	, m_iDetectorType(0)
	, m_bNonMaximaSupression(FALSE)
	, m_iBGImageNo(0)
	, m_iMarkerColorR(0)
	, m_iMarkerColorG(0)
	, m_iMarkerColorB(0)
	, m_iMarkerSize(0)
{

}

CFormFAST::~CFormFAST()
{
}

void CFormFAST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THRESHOLD, m_iThreshold);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_iDetectorType);
	DDX_Check(pDX, IDC_CHECK_NONMAXIMASUPRESSION, m_bNonMaximaSupression);
	DDX_Text(pDX, IDC_EDIT_BGIMAGENO, m_iBGImageNo);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_R, m_iMarkerColorR);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_G, m_iMarkerColorG);
	DDX_Text(pDX, IDC_EDIT_MARKERCOLOR_B, m_iMarkerColorB);
	DDX_Text(pDX, IDC_EDIT_MARKERSIZE, m_iMarkerSize);
}


BEGIN_MESSAGE_MAP(CFormFAST, CDialogEx)
END_MESSAGE_MAP()


// CFormFAST �޽��� ó�����Դϴ�.
void CFormFAST::SetOperation(COperation* pOperation)
{
	m_pFAST = (COpFAST*)pOperation;

	m_iThreshold = m_pFAST->m_iThreshold;
	m_iDetectorType = m_pFAST->m_iDetectorType;
	if (m_pFAST->m_bNonMaximaSupression)	m_bNonMaximaSupression = TRUE;
	else m_bNonMaximaSupression = FALSE;

	m_iMarkerColorR = m_pFAST->GetMarkerColor(0);
	m_iMarkerColorG = m_pFAST->GetMarkerColor(1);
	m_iMarkerColorB = m_pFAST->GetMarkerColor(2);
	m_iMarkerSize = m_pFAST->GetMarkerSize();

	m_iBGImageNo = m_pFAST->GetSecondImgIndex();

	UpdateData(FALSE);
}


void CFormFAST::ApplyChanges()
{
	UpdateData(TRUE);

	m_pFAST->m_iThreshold = m_iThreshold;
	m_pFAST->m_iDetectorType = m_iDetectorType;
	if (m_bNonMaximaSupression)	m_pFAST->m_bNonMaximaSupression = true;
	else m_pFAST->m_bNonMaximaSupression = false;

	m_pFAST->SetMarkerColor(m_iMarkerColorR, m_iMarkerColorG, m_iMarkerColorB);
	m_pFAST->SetMarkerSize(m_iMarkerSize);
	m_pFAST->SetSecondImgIndex(m_iBGImageNo);
}

BOOL CFormFAST::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
