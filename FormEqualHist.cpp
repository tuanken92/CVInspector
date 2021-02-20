// FormEqualHist.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormEqualHist.h"
#include "afxdialogex.h"


// CFormEqualHist 대화 상자입니다.

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


// CFormEqualHist 메시지 처리기입니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
