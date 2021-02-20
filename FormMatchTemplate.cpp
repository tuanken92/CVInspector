// FormMatchTemplate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMatchTemplate.h"
#include "afxdialogex.h"


// CFormMatchTemplate ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormMatchTemplate, CDialogEx)

CFormMatchTemplate::CFormMatchTemplate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormMatchTemplate::IDD, pParent)
	, m_iMethod(0)
	, m_iTemplateImgNo(-1)
	, m_bShowMatchedResult(FALSE)
{

}

CFormMatchTemplate::~CFormMatchTemplate()
{
}

void CFormMatchTemplate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_MATCHTEMPLATE_TYPE, m_iMethod);
	DDX_Text(pDX, IDC_EDIT_TEMPLATE_IMG_NO, m_iTemplateImgNo);
	DDX_Check(pDX, IDC_SHOW_MATCHED_RESULT, m_bShowMatchedResult);
}


BEGIN_MESSAGE_MAP(CFormMatchTemplate, CDialogEx)
END_MESSAGE_MAP()


// CFormMatchTemplate �޽��� ó�����Դϴ�.
void CFormMatchTemplate::SetOperation(COperation* pOperation)
{
	m_pMatchTemplate = (COpMatchTemplate*)pOperation;

	m_iMethod = m_pMatchTemplate->m_iMethod;
	m_iTemplateImgNo = m_pMatchTemplate->GetSecondImgIndex();
	m_bShowMatchedResult = m_pMatchTemplate->GetShowDisplayImage();

	UpdateData(FALSE);
}


void CFormMatchTemplate::ApplyChanges()
{
	UpdateData(TRUE);
	m_pMatchTemplate->m_iMethod = m_iMethod;
	m_pMatchTemplate->SetSecondImgIndex(m_iTemplateImgNo);
	m_pMatchTemplate->SetShowDisplayImage(m_bShowMatchedResult);
}

BOOL CFormMatchTemplate::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
