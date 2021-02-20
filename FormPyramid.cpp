// FormPyramid.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormPyramid.h"
#include "afxdialogex.h"


// CFormPyramid 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormPyramid, CDialogEx)

CFormPyramid::CFormPyramid(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormPyramid::IDD, pParent)
	, m_bPyrType(FALSE)
	, m_iSizeX(0)
	, m_iSizeY(0)
{

}

CFormPyramid::~CFormPyramid()
{
}

void CFormPyramid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_PYRTYPE1, m_bPyrType);
	DDX_Text(pDX, IDC_SIZEX, m_iSizeX);
	DDX_Text(pDX, IDC_SIZEY, m_iSizeY);
}


BEGIN_MESSAGE_MAP(CFormPyramid, CDialogEx)
END_MESSAGE_MAP()


// CFormPyramid 메시지 처리기입니다.
void CFormPyramid::SetOperation(COperation* pOperation)
{
	m_pPyramid = (COpPyramid*)pOperation;
	
	m_bPyrType = m_pPyramid->m_bDownOrUp;
	m_iSizeX = m_pPyramid->m_iSizeX;
	m_iSizeY = m_pPyramid->m_iSizeY;

	UpdateData(FALSE);
}


void CFormPyramid::ApplyChanges()
{
	UpdateData(TRUE);

	m_pPyramid->m_bDownOrUp;
	m_pPyramid->m_iSizeX = m_iSizeX;
	m_pPyramid->m_iSizeY = m_iSizeY;
}

BOOL CFormPyramid::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
