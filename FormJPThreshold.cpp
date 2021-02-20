// FormJPThreshold.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormJPThreshold.h"
#include "afxdialogex.h"


// CFormJPThreshold dialog

IMPLEMENT_DYNAMIC(CFormJPThreshold, CDialogEx)

CFormJPThreshold::CFormJPThreshold(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormJPThreshold::IDD, pParent)
	, m_iThrUpper(0)
	, m_iThrLower(0)
	, m_iTypeThr(0)
{

}

CFormJPThreshold::~CFormJPThreshold()
{
}

void CFormJPThreshold::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BIN_THR_UPPER, m_iThrUpper);
	DDX_Text(pDX, IDC_EDIT_BIN_THR_LOWER, m_iThrLower);
	DDX_Radio(pDX, IDC_RADIO_JPTHR_TYPE1, m_iTypeThr);
}


BEGIN_MESSAGE_MAP(CFormJPThreshold, CDialogEx)
END_MESSAGE_MAP()


// CFormJPThreshold message handlers
void CFormJPThreshold::SetOperation(COperation* pOperation)
{
	m_pJPThreshold = (COpJPThreshold*)pOperation;

	m_iThrLower = m_pJPThreshold->m_iThrLower;
	m_iThrUpper = m_pJPThreshold->m_iThrUpper;
	m_iTypeThr = m_pJPThreshold->m_iTypeThr;
	UpdateData(FALSE);
}


void CFormJPThreshold::ApplyChanges()
{
	UpdateData(TRUE);
	m_pJPThreshold->m_iThrLower = m_iThrLower;
	m_pJPThreshold->m_iThrUpper = m_iThrUpper;
	m_pJPThreshold->m_iTypeThr = m_iTypeThr;
}



BOOL CFormJPThreshold::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

