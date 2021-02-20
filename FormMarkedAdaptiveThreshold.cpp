// FormMarkedAdaptiveThreshold.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMarkedAdaptiveThreshold.h"
#include "afxdialogex.h"


// CFormMarkedAdaptiveThreshold dialog

IMPLEMENT_DYNAMIC(CFormMarkedAdaptiveThreshold, CDialogEx)

CFormMarkedAdaptiveThreshold::CFormMarkedAdaptiveThreshold(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormMarkedAdaptiveThreshold::IDD, pParent)
	, m_iType(0)
	, m_iBlockSizeX(0)
	, m_iBlockSizeY(0)
	, m_iMarkImgNo(0)
	, m_iCValue(0)
{

}

CFormMarkedAdaptiveThreshold::~CFormMarkedAdaptiveThreshold()
{
}

void CFormMarkedAdaptiveThreshold::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_MARKED_ADAP_THR_TYPE, m_iType);
	DDX_Text(pDX, IDC_EDIT_BLOCKSIZE_X, m_iBlockSizeX);
	DDX_Text(pDX, IDC_EDIT_BLOCKSIZE_Y, m_iBlockSizeY);
	DDX_Text(pDX, IDC_EDIT_TEMPLATE_IMG_NO, m_iMarkImgNo);
	DDX_Text(pDX, IDC_EDIT_C_VALUE, m_iCValue);
}


BEGIN_MESSAGE_MAP(CFormMarkedAdaptiveThreshold, CDialogEx)
END_MESSAGE_MAP()


// CFormMarkedAdaptiveThreshold message handlers
void CFormMarkedAdaptiveThreshold::SetOperation(COperation* pOperation)
{
	m_pMarkedAdaptiveThreshold = (COpMarkedAdaptiveThreshold*)pOperation;

	m_iType = m_pMarkedAdaptiveThreshold->m_Type;
	m_iMarkImgNo = m_pMarkedAdaptiveThreshold->GetSecondImgIndex();
	m_iBlockSizeX = m_pMarkedAdaptiveThreshold->m_iKernelX;
	m_iBlockSizeY = m_pMarkedAdaptiveThreshold->m_iKernelY;
	m_iCValue = m_pMarkedAdaptiveThreshold->m_iCValue;
	UpdateData(FALSE);
}


void CFormMarkedAdaptiveThreshold::ApplyChanges()
{
	UpdateData(TRUE);
	m_pMarkedAdaptiveThreshold->m_Type = m_iType;
	m_pMarkedAdaptiveThreshold->SetSecondImgIndex(m_iMarkImgNo);
	m_pMarkedAdaptiveThreshold->m_iKernelX = m_iBlockSizeX;
	m_pMarkedAdaptiveThreshold->m_iKernelY = m_iBlockSizeY;
	m_pMarkedAdaptiveThreshold->m_iCValue = m_iCValue;	
}

BOOL CFormMarkedAdaptiveThreshold::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
