// FormRotate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormRotate.h"
#include "afxdialogex.h"


// CFormRotate 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormRotate, CDialogEx)

CFormRotate::CFormRotate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormRotate::IDD, pParent)
	, m_dAngle(0)
{

}

CFormRotate::~CFormRotate()
{
}

void CFormRotate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ANGLE, m_dAngle);
}


BEGIN_MESSAGE_MAP(CFormRotate, CDialogEx)
END_MESSAGE_MAP()


// CFormRotate 메시지 처리기입니다.
void CFormRotate::SetOperation(COperation* pOperation)
{
	m_pRotate = (COpRotate*)pOperation;
	
	m_dAngle = m_pRotate->m_dAngle;

	UpdateData(FALSE);
}

void CFormRotate::ApplyChanges()
{
	UpdateData(TRUE);

	m_pRotate->m_dAngle = m_dAngle;
}

BOOL CFormRotate::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
