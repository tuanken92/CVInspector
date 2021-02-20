// FormJPThresholdAuto.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormJPThresholdAuto.h"
#include "afxdialogex.h"


// CFormJPThresholdAuto dialog

IMPLEMENT_DYNAMIC(CFormJPThresholdAuto, CDialogEx)

CFormJPThresholdAuto::CFormJPThresholdAuto(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormJPThresholdAuto::IDD, pParent)
	, m_iStdDev(0)
	, m_iDir(0)
{

}

CFormJPThresholdAuto::~CFormJPThresholdAuto()
{
}

void CFormJPThresholdAuto::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STDDEV, m_iStdDev);
	DDX_Radio(pDX, IDC_RADIO_JPTHRAUTO_DIR, m_iDir);
}


BEGIN_MESSAGE_MAP(CFormJPThresholdAuto, CDialogEx)
END_MESSAGE_MAP()


// CFormJPThresholdAuto message handlers
void CFormJPThresholdAuto::SetOperation(COperation* pOperation)
{
	m_pJPThresholdAuto = (COpJPThresholdAuto*)pOperation;

	m_iDir = m_pJPThresholdAuto->m_iDir;
	m_iStdDev = m_pJPThresholdAuto->m_iStdDev;
	UpdateData(FALSE);
}


void CFormJPThresholdAuto::ApplyChanges()
{
	UpdateData(TRUE);
	m_pJPThresholdAuto->m_iDir = m_iDir;
	m_pJPThresholdAuto->m_iStdDev = m_iStdDev;
}


BOOL CFormJPThresholdAuto::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}