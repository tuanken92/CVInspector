// FormMeasureTemplateOffset.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMeasureTemplateOffset.h"
#include "afxdialogex.h"


// CFormMeasureTemplateOffset ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormMeasureTemplateOffset, CDialogEx)

CFormMeasureTemplateOffset::CFormMeasureTemplateOffset(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormMeasureTemplateOffset::IDD, pParent)
	, m_iMethod(0)
	, m_dScaleX(0)
	, m_dScaleY(0)
	, m_dOffsetX(0)
	, m_dOffsetY(0)
	, m_strRefFilePath(_T(""))
	, m_dMatchingScoreThr(0)
{

}

CFormMeasureTemplateOffset::~CFormMeasureTemplateOffset()
{
}

void CFormMeasureTemplateOffset::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_MATCHTEMPLATE_TYPE, m_iMethod);
	DDX_Text(pDX, IDC_EDIT_SCALEX, m_dScaleX);
	DDX_Text(pDX, IDC_EDIT_SCALEY, m_dScaleY);
	DDX_Text(pDX, IDC_EDIT_OFFSETX, m_dOffsetX);
	DDX_Text(pDX, IDC_EDIT_OFFSETY, m_dOffsetY);
	DDX_Text(pDX, IDC_EDIT_TEMPLATE_PATH, m_strRefFilePath);
	DDX_Text(pDX, IDC_EDIT_OFFSETY2, m_dMatchingScoreThr);
}


BEGIN_MESSAGE_MAP(CFormMeasureTemplateOffset, CDialogEx)
	ON_BN_CLICKED(IDC_SET_ROI, &CFormMeasureTemplateOffset::OnBnClickedSetRoi)
END_MESSAGE_MAP()


// CFormMeasureTemplateOffset �޽��� ó�����Դϴ�.
void CFormMeasureTemplateOffset::SetOperation(COperation* pOperation)
{
	m_pOffsetTemplate = (COpOffsetTemplate*)pOperation;

	m_iMethod = m_pOffsetTemplate->m_iMethod;
	m_dScaleX = m_pOffsetTemplate->m_dScaleX;
	m_dScaleY = m_pOffsetTemplate->m_dScaleY;
	m_dOffsetX = m_pOffsetTemplate->m_dOffsetX;
	m_dOffsetY = m_pOffsetTemplate->m_dOffsetY;
	m_strRefFilePath = m_pOffsetTemplate->m_strRefFilePath;
	m_dMatchingScoreThr = m_pOffsetTemplate->m_dMatchingScoreThr;

	UpdateData(FALSE);
}

void CFormMeasureTemplateOffset::ApplyChanges()
{
	UpdateData(TRUE);
	m_pOffsetTemplate->m_iMethod = m_iMethod;
	m_pOffsetTemplate->m_dScaleX = m_dScaleX;
	m_pOffsetTemplate->m_dScaleY = m_dScaleY;
	m_pOffsetTemplate->m_dOffsetX = m_dOffsetX;
	m_pOffsetTemplate->m_dOffsetY = m_dOffsetY;
	m_pOffsetTemplate->m_strRefFilePath = m_strRefFilePath;
	m_pOffsetTemplate->m_dMatchingScoreThr = m_dMatchingScoreThr;
}

BOOL CFormMeasureTemplateOffset::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CFormMeasureTemplateOffset::OnBnClickedSetRoi()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
