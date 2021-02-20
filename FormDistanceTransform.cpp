// FormDistanceTransform.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormDistanceTransform.h"
#include "afxdialogex.h"


// CFormDistanceTransform dialog

IMPLEMENT_DYNAMIC(CFormDistanceTransform, CDialogEx)

CFormDistanceTransform::CFormDistanceTransform(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormDistanceTransform::IDD, pParent)
	, m_iDistanceType(0)
	, m_iMarkSize(0)
{

}

CFormDistanceTransform::~CFormDistanceTransform()
{
}

void CFormDistanceTransform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_DISTANCE_TYPE1, m_iDistanceType);
	DDX_Text(pDX, IDC_EDIT_MARKSIZE, m_iMarkSize);
}


BEGIN_MESSAGE_MAP(CFormDistanceTransform, CDialogEx)
END_MESSAGE_MAP()


// CFormDistanceTransform message handlers
void CFormDistanceTransform::SetOperation(COperation* pOperation)
{
	m_pDistance = (COpDistance*)pOperation;
	m_iDistanceType = m_pDistance->m_iDistanceType;
	m_iMarkSize = m_pDistance->m_iMarkSize;
	

	UpdateData(FALSE);
}


void CFormDistanceTransform::ApplyChanges()
{
	UpdateData(TRUE);
	m_pDistance->m_iDistanceType = m_iDistanceType;
	m_pDistance->m_iMarkSize = m_iMarkSize;
}

BOOL CFormDistanceTransform::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}