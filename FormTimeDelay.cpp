// FormTimeDelay.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormTimeDelay.h"
#include "afxdialogex.h"


// CFormTimeDelay 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormTimeDelay, CDialogEx)

CFormTimeDelay::CFormTimeDelay(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormTimeDelay::IDD, pParent)
	, m_iDelayTime(100)
{

}

CFormTimeDelay::~CFormTimeDelay()
{
}

void CFormTimeDelay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DELAY_TIME, m_iDelayTime);
}


BEGIN_MESSAGE_MAP(CFormTimeDelay, CDialogEx)
END_MESSAGE_MAP()


// CFormTimeDelay 메시지 처리기입니다.
void CFormTimeDelay::SetOperation(COperation* pOperation)
{
	m_pTimeDelay = (COpTimeDelay*)pOperation;
	m_iDelayTime = m_pTimeDelay->m_iDelayTime;

	UpdateData(FALSE);
}


void CFormTimeDelay::ApplyChanges()
{
	UpdateData(TRUE);

	m_pTimeDelay->m_iDelayTime = m_iDelayTime;
}


BOOL CFormTimeDelay::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
