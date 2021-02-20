// FormRotate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormRotate.h"
#include "afxdialogex.h"


// CFormRotate ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormRotate, CDialogEx)

CFormRotate::CFormRotate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormRotate::IDD, pParent)
	, m_dAngle(0)
{

}

CFormRotate::~CFormRotate()
{
}

void CFormRotate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ANGLE, m_dAngle);
}


BEGIN_MESSAGE_MAP(CFormRotate, CDialogEx)
END_MESSAGE_MAP()


// CFormRotate �޽��� ó�����Դϴ�.
void CFormRotate::SetOperation(COperation* pOperation)
{
	m_pRotate = (COpRotate*)pOperation;
	
	m_dAngle = m_pRotate->m_dAngle;

	UpdateData(FALSE);
}

void CFormRotate::ApplyChanges()
{
	UpdateData(TRUE);

	m_pRotate->m_dAngle = m_dAngle;
}

BOOL CFormRotate::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
