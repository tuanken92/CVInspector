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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
