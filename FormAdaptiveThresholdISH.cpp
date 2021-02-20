// FormAdaptiveThresholdISH.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormAdaptiveThresholdISH.h"
#include "afxdialogex.h"


// CFormAdaptiveThresholdISH dialog

IMPLEMENT_DYNAMIC(CFormAdaptiveThresholdISH, CDialogEx)

CFormAdaptiveThresholdISH::CFormAdaptiveThresholdISH(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormAdaptiveThresholdISH::IDD, pParent)
	, m_iThr(0)
	, m_iBlockSize(0)
	, m_dOffset(0)
	, m_dScale(0)
{

}

CFormAdaptiveThresholdISH::~CFormAdaptiveThresholdISH()
{
}

void CFormAdaptiveThresholdISH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THRESHOLD, m_iThr);
	DDX_Text(pDX, IDC_EDIT_BLOCKSIZE, m_iBlockSize);
	DDX_Text(pDX, IDC_EDIT_OFFSET, m_dOffset);
	DDX_Text(pDX, IDC_EDIT_SCALE, m_dScale);
}


BEGIN_MESSAGE_MAP(CFormAdaptiveThresholdISH, CDialogEx)
END_MESSAGE_MAP()


// CFormAdaptiveThresholdISH message handlers
void CFormAdaptiveThresholdISH::SetOperation(COperation* pOperation)
{
	m_pAdaptiveThresholdISH = (COpAdaptiveThresholdISH*)pOperation;

	m_iThr = m_pAdaptiveThresholdISH->m_iThr;
	m_iBlockSize = m_pAdaptiveThresholdISH->m_iBlockSize;
	m_dOffset = m_pAdaptiveThresholdISH->m_dOffset;
	m_dScale = m_pAdaptiveThresholdISH->m_dScale;

	UpdateData(FALSE);
}


void CFormAdaptiveThresholdISH::ApplyChanges()
{
	UpdateData(TRUE);

	m_pAdaptiveThresholdISH->m_iThr = m_iThr;
	m_pAdaptiveThresholdISH->m_iBlockSize = m_iBlockSize;
	m_pAdaptiveThresholdISH->m_dOffset = m_dOffset;
	m_pAdaptiveThresholdISH->m_dScale = m_dScale;
}

BOOL CFormAdaptiveThresholdISH::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
