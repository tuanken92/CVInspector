// FormNA.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormNA.h"
#include "afxdialogex.h"


// CFormNA 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormNA, CDialogEx)

CFormNA::CFormNA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormNA::IDD, pParent)
{

}

CFormNA::~CFormNA()
{
}

void CFormNA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFormNA, CDialogEx)
END_MESSAGE_MAP()


// CFormNA 메시지 처리기입니다.


BOOL CFormNA::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
