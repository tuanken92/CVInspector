// FormAdaptiveThreshold.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormAdaptiveThreshold.h"
#include "afxdialogex.h"


// CFormAdaptiveThreshold ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormAdaptiveThreshold, CDialogEx)

CFormAdaptiveThreshold::CFormAdaptiveThreshold(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormAdaptiveThreshold::IDD, pParent)
	, m_dConstant(0)
	, m_iBlockSize(0)
	, m_iType(0)
	, m_iAdaptiveMethod(0)
{

}

CFormAdaptiveThreshold::~CFormAdaptiveThreshold()
{
}

void CFormAdaptiveThreshold::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_dConstant);
	DDX_Text(pDX, IDC_EDIT_BLOCKSIZE, m_iBlockSize);
	DDX_Radio(pDX, IDC_RADIO_BIN_TYPE1, m_iType);
	DDX_Radio(pDX, IDC_RADIO_ADAPTIVE_METHOD, m_iAdaptiveMethod);
}


BEGIN_MESSAGE_MAP(CFormAdaptiveThreshold, CDialogEx)
END_MESSAGE_MAP()


// CFormAdaptiveThreshold �޽��� ó�����Դϴ�.
void CFormAdaptiveThreshold::SetOperation(COperation* pOperation)
{
	m_pAdaptiveThreshold = (COpAdaptiveThreshold*)pOperation;

	m_dConstant = m_pAdaptiveThreshold->m_dConstant;
	m_iBlockSize = m_pAdaptiveThreshold->m_iBlockSize;
	m_iType = m_pAdaptiveThreshold->m_iThresholdType;
	m_iAdaptiveMethod = m_pAdaptiveThreshold->m_iAdaptiveMethod;

	UpdateData(FALSE);
}


void CFormAdaptiveThreshold::ApplyChanges()
{
	UpdateData(TRUE);
	m_pAdaptiveThreshold->m_dConstant = m_dConstant;
	m_pAdaptiveThreshold->m_iBlockSize = m_iBlockSize;
	m_pAdaptiveThreshold->m_iThresholdType = m_iType;
	m_pAdaptiveThreshold->m_iAdaptiveMethod = m_iAdaptiveMethod;
}

BOOL CFormAdaptiveThreshold::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
