// FormWatershed.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormWatershed.h"
#include "afxdialogex.h"


// CFormWatershed dialog

IMPLEMENT_DYNAMIC(CFormWatershed, CDialogEx)

CFormWatershed::CFormWatershed(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormWatershed::IDD, pParent)
	, m_iImgNo(0)
{

}

CFormWatershed::~CFormWatershed()
{
}

void CFormWatershed::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MASK_IMGNO, m_iImgNo);
}


BEGIN_MESSAGE_MAP(CFormWatershed, CDialogEx)
END_MESSAGE_MAP()


// CFormWatershed message handlers
void CFormWatershed::SetOperation(COperation* pOperation)
{
	m_pWatershed = (COpWatershed*)pOperation;

	m_iImgNo = m_pWatershed->GetSecondImgIndex();


	UpdateData(FALSE);
}


void CFormWatershed::ApplyChanges()
{
	UpdateData(TRUE);

	m_pWatershed->SetSecondImgIndex(m_iImgNo);
}

BOOL CFormWatershed::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
