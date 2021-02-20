// FormDrawLine.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormDrawLine.h"
#include "afxdialogex.h"


// CFormDrawLine dialog

IMPLEMENT_DYNAMIC(CFormDrawLine, CDialogEx)

CFormDrawLine::CFormDrawLine(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormDrawLine::IDD, pParent)
	, m_iStartX(0)
{

}

CFormDrawLine::~CFormDrawLine()
{
}

void CFormDrawLine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DRAW_START_X, m_iStartX);
}


BEGIN_MESSAGE_MAP(CFormDrawLine, CDialogEx)
END_MESSAGE_MAP()


// CFormDrawLine message handlers
