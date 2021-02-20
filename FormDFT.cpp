// FormDFT.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormDFT.h"
#include "afxdialogex.h"


// CFormDFT 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormDFT, CDialogEx)

CFormDFT::CFormDFT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormDFT::IDD, pParent)
	, m_bShowScaledImage(FALSE)
	, m_bInv(FALSE)
{

}

CFormDFT::~CFormDFT()
{
}

void CFormDFT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_SHOW_SCALEDIMG, m_bShowScaledImage);
	DDX_Check(pDX, IDC_INV, m_bInv);
}


BEGIN_MESSAGE_MAP(CFormDFT, CDialogEx)
END_MESSAGE_MAP()


// CFormDFT 메시지 처리기입니다.
void CFormDFT::SetOperation(COperation* pOperation)
{
	m_pDFT = (COpDFT*)pOperation;

	m_bShowScaledImage = m_pDFT->GetShowDisplayImage();
	m_bInv = m_pDFT->m_bInverse;
	UpdateData(FALSE);
}


void CFormDFT::ApplyChanges()
{
	UpdateData(TRUE);	
	m_pDFT->SetShowDisplayImage(m_bShowScaledImage);
	m_pDFT->m_bInverse = m_bInv;
}

BOOL CFormDFT::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
