// FormFilter2D.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFilter2D.h"
#include "afxdialogex.h"


// CFormFilter2D 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormFilter2D, CDialogEx)

CFormFilter2D::CFormFilter2D(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormFilter2D::IDD, pParent)
	, m_iAnchorX(0)
	, m_iAnchorY(0)
	, m_dDelta(0)
	, m_strKernel(_T(""))
{

}

CFormFilter2D::~CFormFilter2D()
{
}

void CFormFilter2D::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ANCHOR_X, m_iAnchorX);
	DDX_Text(pDX, IDC_EDIT_ANCHOR_Y, m_iAnchorY);
	DDX_Text(pDX, IDC_EDIT_DELTA, m_dDelta);
	DDX_Text(pDX, IDC_EDIT_KERNEL, m_strKernel);
}


BEGIN_MESSAGE_MAP(CFormFilter2D, CDialogEx)
END_MESSAGE_MAP()


// CFormFilter2D 메시지 처리기입니다.
void CFormFilter2D::SetOperation(COperation* pOperation)
{
	m_pFilter2D = (COpFilter2D*)pOperation;

	m_iAnchorX = m_pFilter2D->m_AnchorPos.x;
	m_iAnchorY = m_pFilter2D->m_AnchorPos.y;
	m_dDelta = m_pFilter2D->m_dDelta;
	m_strKernel = m_pFilter2D->m_strKernel;

	UpdateData(FALSE);
}


void CFormFilter2D::ApplyChanges()
{
	UpdateData(TRUE);

	if (m_strKernel.IsEmpty())
	{
		AfxMessageBox(_T("Invalid Kernel!"));
		return;
	}

	m_pFilter2D->m_AnchorPos = CPoint(m_iAnchorX, m_iAnchorY);

	m_pFilter2D->m_dDelta = m_dDelta;
	m_pFilter2D->ParseString(m_strKernel);
}

BOOL CFormFilter2D::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN)
	{
		if (GetDlgItem(IDC_EDIT_KERNEL) == GetFocus())
		{
			CEdit* tmpEdit = (CEdit*)GetDlgItem(IDC_EDIT_KERNEL);
			int iLen = tmpEdit->GetWindowTextLength();
			tmpEdit->SetSel(iLen, iLen);
			tmpEdit->ReplaceSel(_T("\r\n"));
		}
		return TRUE;
	}

	if(pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
