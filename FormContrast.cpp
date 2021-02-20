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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}