// FormHistogram.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormHistogram.h"
#include "afxdialogex.h"


// CFormHistogram ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormHistogram, CDialogEx)

CFormHistogram::CFormHistogram(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormHistogram::IDD, pParent)
	, m_iHistSize(0)
	, m_fHistRangeL(0)
	, m_fHistRangeH(0)
{

}

CFormHistogram::~CFormHistogram()
{
}

void CFormHistogram::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HIST_SIZE, m_iHistSize);
	DDX_Text(pDX, IDC_EDIT_HIST_RANGE_L, m_fHistRangeL);
	DDX_Text(pDX, IDC_EDIT_HIST_RANGE_H, m_fHistRangeH);
}


BEGIN_MESSAGE_MAP(CFormHistogram, CDialogEx)
END_MESSAGE_MAP()


// CFormHistogram �޽��� ó�����Դϴ�.
void CFormHistogram::SetOperation(COperation* pOperation)
{
	m_pHistogram = (COpHistogram*)pOperation;

	m_iHistSize = m_pHistogram->m_iHistSize;
	m_fHistRangeL = m_pHistogram->m_fHistRangeL;
	m_fHistRangeH = m_pHistogram->m_fHistRangeH;

	UpdateData(FALSE);
}


void CFormHistogram::ApplyChanges()
{
	UpdateData(TRUE);

	m_pHistogram->m_iHistSize = m_iHistSize;
	m_pHistogram->m_fHistRangeL = m_fHistRangeL;
	m_pHistogram->m_fHistRangeH = m_fHistRangeH;
}

BOOL CFormHistogram::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
