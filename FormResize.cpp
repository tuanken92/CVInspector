// FormResize.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormResize.h"
#include "afxdialogex.h"


// CFormResize 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormResize, CDialogEx)

CFormResize::CFormResize(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormResize::IDD, pParent)
	, m_iInterpolationType(0)
	, m_iNewSizeX(0)
	, m_iNewSizeY(0)
	, m_dNewRatioX(0)
	, m_dNewRatioY(0)
{

}

CFormResize::~CFormResize()
{
}

void CFormResize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RESIZE_INTER_TYPE1, m_iInterpolationType);
	DDX_Text(pDX, IDC_EDIT_NEWSIZE_X, m_iNewSizeX);
	DDX_Text(pDX, IDC_EDIT_NEWSIZE_Y, m_iNewSizeY);
	DDX_Text(pDX, IDC_EDIT_NEWRATIO_X, m_dNewRatioX);
	DDX_Text(pDX, IDC_EDIT_NEWRATIO_Y, m_dNewRatioY);
}


BEGIN_MESSAGE_MAP(CFormResize, CDialogEx)
END_MESSAGE_MAP()


// CFormResize 메시지 처리기입니다.
void CFormResize::SetOperation(COperation* pOperation)
{
	m_pResize = (COpResize*)pOperation;

	m_iInterpolationType = m_pResize->m_iInterpolationType;
	m_iNewSizeX = m_pResize->m_iNewSizeX;
	m_iNewSizeY = m_pResize->m_iNewSizeY;
	m_dNewRatioX = m_pResize->m_dNewRatioX;
	m_dNewRatioY = m_pResize->m_dNewRatioY;

	UpdateData(FALSE);
}


void CFormResize::ApplyChanges()
{
	UpdateData(TRUE);

	m_pResize->m_iInterpolationType = m_iInterpolationType;
	m_pResize->m_iNewSizeX = m_iNewSizeX;
	m_pResize->m_iNewSizeY = m_iNewSizeY;
	m_pResize->m_dNewRatioX = m_dNewRatioX;
	m_pResize->m_dNewRatioY = m_dNewRatioY;
}

BOOL CFormResize::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
