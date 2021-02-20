// FormDFT.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormDFT.h"
#include "afxdialogex.h"


// CFormDFT ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormDFT, CDialogEx)

CFormDFT::CFormDFT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormDFT::IDD, pParent)
	, m_bShowScaledImage(FALSE)
	, m_bInv(FALSE)
{

}

CFormDFT::~CFormDFT()
{
}

void CFormDFT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_SHOW_SCALEDIMG, m_bShowScaledImage);
	DDX_Check(pDX, IDC_INV, m_bInv);
}


BEGIN_MESSAGE_MAP(CFormDFT, CDialogEx)
END_MESSAGE_MAP()


// CFormDFT �޽��� ó�����Դϴ�.
void CFormDFT::SetOperation(COperation* pOperation)
{
	m_pDFT = (COpDFT*)pOperation;

	m_bShowScaledImage = m_pDFT->GetShowDisplayImage();
	m_bInv = m_pDFT->m_bInverse;
	UpdateData(FALSE);
}


void CFormDFT::ApplyChanges()
{
	UpdateData(TRUE);	
	m_pDFT->SetShowDisplayImage(m_bShowScaledImage);
	m_pDFT->m_bInverse = m_bInv;
}

BOOL CFormDFT::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
