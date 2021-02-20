// FormTimeDelay.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormTimeDelay.h"
#include "afxdialogex.h"


// CFormTimeDelay ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormTimeDelay, CDialogEx)

CFormTimeDelay::CFormTimeDelay(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormTimeDelay::IDD, pParent)
	, m_iDelayTime(100)
{

}

CFormTimeDelay::~CFormTimeDelay()
{
}

void CFormTimeDelay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DELAY_TIME, m_iDelayTime);
}


BEGIN_MESSAGE_MAP(CFormTimeDelay, CDialogEx)
END_MESSAGE_MAP()


// CFormTimeDelay �޽��� ó�����Դϴ�.
void CFormTimeDelay::SetOperation(COperation* pOperation)
{
	m_pTimeDelay = (COpTimeDelay*)pOperation;
	m_iDelayTime = m_pTimeDelay->m_iDelayTime;

	UpdateData(FALSE);
}


void CFormTimeDelay::ApplyChanges()
{
	UpdateData(TRUE);

	m_pTimeDelay->m_iDelayTime = m_iDelayTime;
}


BOOL CFormTimeDelay::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
