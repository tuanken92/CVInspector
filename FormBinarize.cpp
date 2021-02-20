// FormBinarize.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormBinarize.h"
#include "afxdialogex.h"


// CFormBinarize 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormBinarize, CDialogEx)

CFormBinarize::CFormBinarize(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormBinarize::IDD, pParent)
	, m_iBinarizeType(0)
	, m_dThr(128)
	, m_bUseOtsu(FALSE)
{

}

CFormBinarize::~CFormBinarize()
{
}

void CFormBinarize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_BIN_TYPE1, m_iBinarizeType);
	DDX_Text(pDX, IDC_EDIT_BIN_THR, m_dThr);
	DDX_Check(pDX, IDC_CHECK_OTSU, m_bUseOtsu);
}


BEGIN_MESSAGE_MAP(CFormBinarize, CDialogEx)
END_MESSAGE_MAP()


// CFormBinarize 메시지 처리기입니다.
void CFormBinarize::SetOperation(COperation* pOperation)
{
	m_pBinarize = (COpBinarize*)pOperation;

	m_dThr = m_pBinarize->m_dThr;
	m_iBinarizeType = m_pBinarize->m_iBinarizeType;
	m_bUseOtsu = m_pBinarize->m_bUseOtsu;
	
	UpdateData(FALSE);
}


void CFormBinarize::ApplyChanges()
{
	UpdateData(TRUE);
	m_pBinarize->m_dThr = m_dThr;
	m_pBinarize->m_iBinarizeType = m_iBinarizeType;
	m_pBinarize->m_bUseOtsu = m_bUseOtsu;
}



BOOL CFormBinarize::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		ApplyChanges();
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
