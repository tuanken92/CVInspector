// FormSplit.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormSplit.h"
#include "afxdialogex.h"


// CFormSplit 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormSplit, CDialogEx)

CFormSplit::CFormSplit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormSplit::IDD, pParent)
	, m_iTargetChannel(0)
{

}

CFormSplit::~CFormSplit()
{
}

void CFormSplit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_CHANNEL1, m_iTargetChannel);
}


BEGIN_MESSAGE_MAP(CFormSplit, CDialogEx)
END_MESSAGE_MAP()


// CFormSplit 메시지 처리기입니다.
void CFormSplit::SetOperation(COperation* pOperation)
{
	m_pSplit = (COpSplit*)pOperation;
	m_iTargetChannel = m_pSplit->m_iTargetChannel;

	UpdateData(FALSE);
}


void CFormSplit::ApplyChanges()
{
	UpdateData(TRUE);

	m_pSplit->m_iTargetChannel = m_iTargetChannel;
}

BOOL CFormSplit::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
