// FormFlip.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFlip.h"
#include "afxdialogex.h"


// CFormFlip 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormFlip, CDialogEx)

CFormFlip::CFormFlip(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormFlip::IDD, pParent)
	, m_iFlipCode(0)
{

}

CFormFlip::~CFormFlip()
{
}

void CFormFlip::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_FLIP_AXIS, m_iFlipCode);
}


BEGIN_MESSAGE_MAP(CFormFlip, CDialogEx)
END_MESSAGE_MAP()


// CFormFlip 메시지 처리기입니다.
void CFormFlip::SetOperation(COperation* pOperation)
{
	m_pFlip = (COpFlip*)pOperation;
	if (m_pFlip->m_iFlipCode < 0)
	{
		m_iFlipCode = 2;
	}
	else
	{
		m_iFlipCode = m_pFlip->m_iFlipCode;
	}

	UpdateData(FALSE);
}

void CFormFlip::ApplyChanges()
{
	UpdateData(TRUE);

	if (m_iFlipCode == 2)
	{
		m_pFlip->m_iFlipCode = -1;
	}
	else
	{
		m_pFlip->m_iFlipCode = m_iFlipCode;
	}
}

BOOL CFormFlip::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
