// FormRemoveBlobs.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormRemoveBlobs.h"
#include "afxdialogex.h"


// CFormRemoveBlobs ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormRemoveBlobs, CDialogEx)

CFormRemoveBlobs::CFormRemoveBlobs(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormRemoveBlobs::IDD, pParent)
	, m_iMinArea(0)
	, m_iMaxArea(0)
	, m_iMinWidth(0)
	, m_iMinHeight(0)
	, m_iMaxWidth(0)
	, m_iMaxHeight(0)
{

}

CFormRemoveBlobs::~CFormRemoveBlobs()
{
}

void CFormRemoveBlobs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MIN_AREA, m_iMinArea);
	DDX_Text(pDX, IDC_EDIT_MAX_AREA, m_iMaxArea);
	DDX_Text(pDX, IDC_EDIT_MIN_WIDTH, m_iMinWidth);
	DDX_Text(pDX, IDC_EDIT_MIN_HEIGHT, m_iMinHeight);
	DDX_Text(pDX, IDC_EDIT_MAX_WIDTH, m_iMaxWidth);
	DDX_Text(pDX, IDC_EDIT_MAX_HEIGHT, m_iMaxHeight);
}


BEGIN_MESSAGE_MAP(CFormRemoveBlobs, CDialogEx)
END_MESSAGE_MAP()


// CFormRemoveBlobs �޽��� ó�����Դϴ�.
void CFormRemoveBlobs::SetOperation(COperation* pOperation)
{
	m_pRemoveBlobs = (COpRemoveBlobs*)pOperation;

	m_iMinArea = m_pRemoveBlobs->m_iMinArea;
	m_iMaxArea = m_pRemoveBlobs->m_iMaxArea;
	m_iMinWidth = m_pRemoveBlobs->m_iMinWidth;
	m_iMinHeight = m_pRemoveBlobs->m_iMinHeight;
	m_iMaxWidth = m_pRemoveBlobs->m_iMaxWidth;
	m_iMaxHeight = m_pRemoveBlobs->m_iMaxHeight;

	UpdateData(FALSE);
}


void CFormRemoveBlobs::ApplyChanges()
{
	UpdateData(TRUE);

	m_pRemoveBlobs->m_iMinArea = m_iMinArea;
	m_pRemoveBlobs->m_iMaxArea = m_iMaxArea;
	m_pRemoveBlobs->m_iMinWidth = m_iMinWidth;
	m_pRemoveBlobs->m_iMinHeight = m_iMinHeight;
	m_pRemoveBlobs->m_iMaxWidth = m_iMaxWidth;
	m_pRemoveBlobs->m_iMaxHeight = m_iMaxHeight;
}


BOOL CFormRemoveBlobs::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
