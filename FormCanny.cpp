// FormCanny.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormCanny.h"
#include "afxdialogex.h"


// CFormCanny 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormCanny, CDialogEx)

CFormCanny::CFormCanny(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormCanny::IDD, pParent)
	, m_dThreshold1(32)
	, m_dThreshold2(64)
	, m_iApertureSize(3)
{

}

CFormCanny::~CFormCanny()
{
}

void CFormCanny::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THR1, m_dThreshold1);
	DDX_Text(pDX, IDC_EDIT_THR2, m_dThreshold2);
	DDX_Text(pDX, IDC_EDIT_APERTURE, m_iApertureSize);
}


BEGIN_MESSAGE_MAP(CFormCanny, CDialogEx)
END_MESSAGE_MAP()


// CFormCanny 메시지 처리기입니다.
void CFormCanny::SetOperation(COperation* pOperation)
{
	m_pCanny = (COpCanny*)pOperation;

	m_dThreshold1 = m_pCanny->m_dThr1;
	m_dThreshold2 = m_pCanny->m_dThr2;
	m_iApertureSize = m_pCanny->m_iApertureSize;
	
	UpdateData(FALSE);
}


void CFormCanny::ApplyChanges()
{
	UpdateData(TRUE);

	m_pCanny->m_dThr1 = m_dThreshold1;
	m_pCanny->m_dThr2 = m_dThreshold2;
	m_pCanny->m_iApertureSize = m_iApertureSize;
}

BOOL CFormCanny::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
