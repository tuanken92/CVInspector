// FormFarshidThr.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFarshidThr.h"
#include "afxdialogex.h"


// CFormFarshidThr dialog

IMPLEMENT_DYNAMIC(CFormFarshidThr, CDialogEx)

CFormFarshidThr::CFormFarshidThr(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormFarshidThr::IDD, pParent)
{

}

CFormFarshidThr::~CFormFarshidThr()
{
}

void CFormFarshidThr::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFormFarshidThr, CDialogEx)
END_MESSAGE_MAP()


// CFormFarshidThr message handlers
void CFormFarshidThr::SetOperation(COperation* pOperation)
{
	m_pFarshidThr = (COpFarshidThr*)pOperation;

	
	UpdateData(FALSE);
}


void CFormFarshidThr::ApplyChanges()
{
	UpdateData(TRUE);
	
}



BOOL CFormFarshidThr::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
