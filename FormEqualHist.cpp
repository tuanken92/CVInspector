// FormEqualHist.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormEqualHist.h"
#include "afxdialogex.h"


// CFormEqualHist ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormEqualHist, CDialogEx)

CFormEqualHist::CFormEqualHist(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormEqualHist::IDD, pParent)
{

}

CFormEqualHist::~CFormEqualHist()
{
}

void CFormEqualHist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFormEqualHist, CDialogEx)
END_MESSAGE_MAP()


// CFormEqualHist �޽��� ó�����Դϴ�.
void CFormEqualHist::SetOperation(COperation* pOperation)
{
	m_pEqualHist = (COpEqualHist*)pOperation;

	UpdateData(FALSE);
}


void CFormEqualHist::ApplyChanges()
{
	UpdateData(TRUE);
}

BOOL CFormEqualHist::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
