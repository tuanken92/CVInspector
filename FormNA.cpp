// FormNA.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormNA.h"
#include "afxdialogex.h"


// CFormNA ��ȭ �����Դϴ�.

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


// CFormNA �޽��� ó�����Դϴ�.


BOOL CFormNA::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
