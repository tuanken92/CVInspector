// FormMarkedAverage.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMarkedAverage.h"
#include "afxdialogex.h"


// CFormMarkedAverage dialog

IMPLEMENT_DYNAMIC(CFormMarkedAverage, CDialogEx)

CFormMarkedAverage::CFormMarkedAverage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormMarkedAverage::IDD, pParent)
	, m_iBlockSizeX(0)
	, m_iBlockSizeY(0)
	, m_iMarkImgNo(0)
{

}

CFormMarkedAverage::~CFormMarkedAverage()
{
}

void CFormMarkedAverage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_KERNEL_X, m_iBlockSizeX);
	DDX_Text(pDX, IDC_EDIT_KERNEL_Y, m_iBlockSizeY);
	DDX_Text(pDX, IDC_EDIT_MARK_IMG_NO, m_iMarkImgNo);
}


BEGIN_MESSAGE_MAP(CFormMarkedAverage, CDialogEx)
END_MESSAGE_MAP()


// CFormMarkedAverage message handlers
void CFormMarkedAverage::SetOperation(COperation* pOperation)
{
	m_pMarkedAverage = (COpMarkedAgv*)pOperation;

	m_iMarkImgNo = m_pMarkedAverage->GetSecondImgIndex();
	m_iBlockSizeX = m_pMarkedAverage->m_iKernelX;
	m_iBlockSizeY = m_pMarkedAverage->m_iKernelY;

	UpdateData(FALSE);
}

void CFormMarkedAverage::ApplyChanges()
{
	UpdateData(TRUE);
	m_pMarkedAverage->SetSecondImgIndex(m_iMarkImgNo);
	m_pMarkedAverage->m_iKernelX = m_iBlockSizeY;
	m_pMarkedAverage->m_iKernelY = m_iBlockSizeY;
}

BOOL CFormMarkedAverage::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
