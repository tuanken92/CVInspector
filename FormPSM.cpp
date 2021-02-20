// FormPSM.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormPSM.h"
#include "afxdialogex.h"


// CFormPSM ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormPSM, CDialogEx)

CFormPSM::CFormPSM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormPSM::IDD, pParent)
	, m_iSubtractType(0)
	, m_iDir(0)
	, m_iXOffset(0)
	, m_iYOffset(0)
{

}

CFormPSM::~CFormPSM()
{
}

void CFormPSM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_PSM_SUBTRACT_TYPE, m_iSubtractType);
	DDX_Radio(pDX, IDC_PSM_DIR, m_iDir);
	DDX_Text(pDX, IDC_EDIT_OFFSET_X, m_iXOffset);
	DDX_Text(pDX, IDC_EDIT_OFFSET_Y, m_iYOffset);
}


BEGIN_MESSAGE_MAP(CFormPSM, CDialogEx)
END_MESSAGE_MAP()


// CFormPSM �޽��� ó�����Դϴ�.
void CFormPSM::SetOperation(COperation* pOperation)
{
	m_pPSM = (COpPSM*)pOperation;

	m_iSubtractType = m_pPSM->m_iSubtractType;
	m_iDir = m_pPSM->m_iDir;
	m_iXOffset = m_pPSM->m_iXOffset;
	m_iYOffset = m_pPSM->m_iYOffset;

	UpdateData(FALSE);
}


void CFormPSM::ApplyChanges()
{
	UpdateData(TRUE);

	m_pPSM->m_iSubtractType = m_iSubtractType;
	m_pPSM->m_iDir = m_iDir;
	m_pPSM->m_iXOffset = m_iXOffset;
	m_pPSM->m_iYOffset = m_iYOffset;
}


BOOL CFormPSM::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
