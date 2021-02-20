// FormCrop.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormCrop.h"
#include "afxdialogex.h"


// CFormCrop 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormCrop, CDialogEx)

CFormCrop::CFormCrop(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormCrop::IDD, pParent)
	, m_iLeft(0)
	, m_iTop(0)
	, m_iRight(0)
	, m_iBottom(0)
	, m_bMagnifyCropArea(FALSE)
{

}

CFormCrop::~CFormCrop()
{
}

void CFormCrop::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LEFT, m_iLeft);
	DDX_Text(pDX, IDC_EDIT_TOP, m_iTop);
	DDX_Text(pDX, IDC_EDIT_RIGHT, m_iRight);
	DDX_Text(pDX, IDC_EDIT_BOTTOM, m_iBottom);
	DDX_Control(pDX, IDC_SPIN_LEFT, m_ctrlLeft);
	DDX_Control(pDX, IDC_SPIN_TOP, m_ctrlTop);
	DDX_Control(pDX, IDC_SPIN_RIGHT, m_ctrlRight);
	DDX_Control(pDX, IDC_SPIN_BOTTOM, m_ctrlBottom);
	DDX_Check(pDX, IDC_MAGNIFY_CROPAREA, m_bMagnifyCropArea);
}


BEGIN_MESSAGE_MAP(CFormCrop, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MOVE_LR, &CFormCrop::OnDeltaposSpinMoveLr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MOVE_UD, &CFormCrop::OnDeltaposSpinMoveUd)
END_MESSAGE_MAP()


// CFormCrop 메시지 처리기입니다.
void CFormCrop::SetOperation(COperation* pOperation)
{
	m_pCrop = (COpCrop*)pOperation;

	CRect tmpRect = m_pCrop->m_CropRect;
	m_iLeft = tmpRect.left;
	m_iTop = tmpRect.top;
	m_iRight = tmpRect.right;
	m_iBottom = tmpRect.bottom;	

	m_ctrlLeft.SetRange32(0, 32000);
	m_ctrlTop.SetRange32(0, 32000);
	m_ctrlRight.SetRange32(0, 32000);
	m_ctrlBottom.SetRange32(0, 32000);

	m_bMagnifyCropArea = !(m_pCrop->GetShowDisplayImage());

	UpdateData(FALSE);
}


void CFormCrop::ApplyChanges()
{
	UpdateData(TRUE);

	CRect tmpRect(m_iLeft, m_iTop, m_iRight, m_iBottom);
	m_pCrop->m_CropRect = tmpRect;
	m_pCrop->SetShowDisplayImage(!m_bMagnifyCropArea);
}


void CFormCrop::OnDeltaposSpinMoveLr(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pNMUpDown->iDelta < 0)
	{
		m_iLeft++;
		m_iRight++;
	}
	else
	{
		m_iLeft--;
		m_iRight--;
	}
	*pResult = 0;

	UpdateData(FALSE);
}


void CFormCrop::OnDeltaposSpinMoveUd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pNMUpDown->iDelta < 0)
	{
		m_iTop--;
		m_iBottom--;
	}
	else
	{
		m_iTop++;
		m_iBottom++;
	}
	*pResult = 0;

	UpdateData(FALSE);
}


BOOL CFormCrop::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
