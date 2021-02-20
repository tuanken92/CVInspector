// FormContrast.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormContrast.h"
#include "afxdialogex.h"


// CFormContrast dialog

IMPLEMENT_DYNAMIC(CFormContrast, CDialogEx)

CFormContrast::CFormContrast(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormContrast::IDD, pParent)
	, iAlpha(0)
	, iBeta(0)
{

}

CFormContrast::~CFormContrast()
{
}

void CFormContrast::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ALPHA, iAlpha);
	DDX_Text(pDX, IDC_EDIT_BETA, iBeta);
}


BEGIN_MESSAGE_MAP(CFormContrast, CDialogEx)
END_MESSAGE_MAP()


// CFormContrast message handlers
void CFormContrast::SetOperation(COperation* pOperation)
{
	m_pContrast = (COpContrast*)pOperation;

	iAlpha = m_pContrast->m_iAlpha;
	iBeta = m_pContrast->m_iBeta;

	UpdateData(FALSE);
}


void CFormContrast::ApplyChanges()
{
	UpdateData(TRUE);

	m_pContrast->m_iAlpha = iAlpha;
	m_pContrast->m_iBeta = iBeta;
}

BOOL CFormContrast::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}