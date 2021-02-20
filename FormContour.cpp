// FormContour.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormContour.h"
#include "afxdialogex.h"


// CFormContour 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormContour, CDialogEx)

CFormContour::CFormContour(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormContour::IDD, pParent)
	, m_iMode(0)
	, m_iMethod(0)
	, m_iLineWidth(0)
	, m_iLineType(0)
	, m_iMaxValue(0)
	, m_iBGImageNo(0)
	, m_bUseConvexHull(FALSE)
{

}

CFormContour::~CFormContour()
{
}

void CFormContour::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_MODE1, m_iMode);
	DDX_Radio(pDX, IDC_METHOD1, m_iMethod);
	DDX_Text(pDX, IDC_EDIT_LINEWIDTH, m_iLineWidth);
	DDX_Text(pDX, IDC_EDIT_LINETYPE, m_iLineType);
	DDX_Text(pDX, IDC_EDIT_MAXVALUE, m_iMaxValue);
	DDX_Text(pDX, IDC_EDIT_BGIMAGENO, m_iBGImageNo);
	DDX_Check(pDX, IDC_CHECK_USE_CONVEXHULL, m_bUseConvexHull);
}


BEGIN_MESSAGE_MAP(CFormContour, CDialogEx)
END_MESSAGE_MAP()


// CFormContour 메시지 처리기입니다.
void CFormContour::SetOperation(COperation* pOperation)
{
	m_pContour = (COpContour*)pOperation;

	m_iMode = m_pContour->m_iMode;
	m_iMethod = m_pContour->m_iMethod - 1;
	m_iLineWidth = m_pContour->m_iLineWidth;
	m_iLineType = m_pContour->m_iLineType;
	m_iMaxValue = m_pContour->m_iMaxLevel;
	m_iBGImageNo = m_pContour->GetSecondImgIndex();
	m_bUseConvexHull = m_pContour->m_bConvexHull;

	UpdateData(FALSE);
}


void CFormContour::ApplyChanges()
{
	UpdateData(TRUE);

	m_pContour->m_iMode = m_iMode;
	m_pContour->m_iMethod = (m_iMethod + 1);
	m_pContour->m_iLineWidth = m_iLineWidth;
	m_pContour->m_iLineType = m_iLineType;
	m_pContour->m_iMaxLevel = m_iMaxValue;
	m_pContour->SetSecondImgIndex(m_iBGImageNo);
	m_pContour->m_bConvexHull = m_bUseConvexHull;
}

BOOL CFormContour::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
