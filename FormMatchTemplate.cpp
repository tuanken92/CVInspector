// FormMatchTemplate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMatchTemplate.h"
#include "afxdialogex.h"


// CFormMatchTemplate 대화 상자입니다.

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


// CFormMatchTemplate 메시지 처리기입니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
