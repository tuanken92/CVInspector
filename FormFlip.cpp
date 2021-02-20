// FormFlip.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFlip.h"
#include "afxdialogex.h"


// CFormFlip ��ȭ �����Դϴ�.

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


// CFormFlip �޽��� ó�����Դϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
