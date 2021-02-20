// FormFloodFill.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFloodFill.h"
#include "afxdialogex.h"


// CFormFloodFill ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormFloodFill, CDialogEx)

CFormFloodFill::CFormFloodFill(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormFloodFill::IDD, pParent)
	, m_iUpperDiff(0)
	, m_iLowerDiff(0)
	, m_iNeighbor(0)
	, m_bUseFixedRange(FALSE)
{

}

CFormFloodFill::~CFormFloodFill()
{
}

void CFormFloodFill::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_UPPERDIFF, m_iUpperDiff);
	DDX_Text(pDX, IDC_EDIT_LOWERDIFF, m_iLowerDiff);
	DDX_Text(pDX, IDC_EDIT_NEIGHBOR, m_iNeighbor);
	DDX_Check(pDX, IDC_CHECK_USE_FIXED_RANGE, m_bUseFixedRange);
}


BEGIN_MESSAGE_MAP(CFormFloodFill, CDialogEx)
END_MESSAGE_MAP()


// CFormFloodFill �޽��� ó�����Դϴ�.
void CFormFloodFill::SetOperation(COperation* pOperation)
{
	m_pFloodfill = (COpFloodFill*)pOperation;

	m_iUpperDiff = m_pFloodfill->m_iUpperDiff;
	m_iLowerDiff = m_pFloodfill->m_iLowerDiff;
	m_iNeighbor = m_pFloodfill->m_iNeighbor;
	m_bUseFixedRange = m_pFloodfill->m_bUseFixedRange;

	UpdateData(FALSE);
}


void CFormFloodFill::ApplyChanges()
{
	UpdateData(TRUE);

	m_pFloodfill->m_iUpperDiff = m_iUpperDiff;
	m_pFloodfill->m_iLowerDiff = m_iLowerDiff;
	m_pFloodfill->m_iNeighbor = m_iNeighbor;
	m_pFloodfill->m_bUseFixedRange = m_bUseFixedRange;
}

BOOL CFormFloodFill::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
