// FormSplit.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormSplit.h"
#include "afxdialogex.h"


// CFormSplit ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormSplit, CDialogEx)

CFormSplit::CFormSplit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormSplit::IDD, pParent)
	, m_iTargetChannel(0)
{

}

CFormSplit::~CFormSplit()
{
}

void CFormSplit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_CHANNEL1, m_iTargetChannel);
}


BEGIN_MESSAGE_MAP(CFormSplit, CDialogEx)
END_MESSAGE_MAP()


// CFormSplit �޽��� ó�����Դϴ�.
void CFormSplit::SetOperation(COperation* pOperation)
{
	m_pSplit = (COpSplit*)pOperation;
	m_iTargetChannel = m_pSplit->m_iTargetChannel;

	UpdateData(FALSE);
}


void CFormSplit::ApplyChanges()
{
	UpdateData(TRUE);

	m_pSplit->m_iTargetChannel = m_iTargetChannel;
}

BOOL CFormSplit::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
