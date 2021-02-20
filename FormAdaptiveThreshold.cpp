// FormAdaptiveThreshold.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormAdaptiveThreshold.h"
#include "afxdialogex.h"


// CFormAdaptiveThreshold 대화 상자입니다.

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


// CFormAdaptiveThreshold 메시지 처리기입니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
