// FormEdge.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormEdge.h"
#include "afxdialogex.h"


// CFormEdge 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormEdge, CDialogEx)

CFormEdge::CFormEdge(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormEdge::IDD, pParent)
	, m_iEdgeType(0)
	, m_iKernelSize(0)
	, m_dScale(0)
	, m_dDelta(0)
	, m_iDx(0)
	, m_iDy(0)
{

}

CFormEdge::~CFormEdge()
{
}

void CFormEdge::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_EDGE_TYPE1, m_iEdgeType);
	DDX_Text(pDX, IDC_EDIT_KERNEL_SIZE, m_iKernelSize);
	DDX_Text(pDX, IDC_EDIT_SCALE, m_dScale);
	DDX_Text(pDX, IDC_EDIT_DELTA, m_dDelta);
	DDX_Text(pDX, IDC_EDIT_DX, m_iDx);
	DDX_Text(pDX, IDC_EDIT_DY, m_iDy);
}


BEGIN_MESSAGE_MAP(CFormEdge, CDialogEx)
END_MESSAGE_MAP()


// CFormEdge 메시지 처리기입니다.
void CFormEdge::SetOperation(COperation* pOperation)
{
	m_pEdge = (COpEdge*)pOperation;

	m_iEdgeType = m_pEdge->m_iEdgeType;
	m_iKernelSize = m_pEdge->m_iKernelSize;
	m_dScale = m_pEdge->m_dScale;
	m_dDelta = m_pEdge->m_dDelta;
	m_iDx = m_pEdge->m_iDx;
	m_iDy = m_pEdge->m_iDy;

	UpdateData(FALSE);
}


void CFormEdge::ApplyChanges()
{
	UpdateData(TRUE);

	m_pEdge->m_iEdgeType = m_iEdgeType;
	m_pEdge->m_iKernelSize = m_iKernelSize;
	m_pEdge->m_dScale = m_dScale;
	m_pEdge->m_dDelta = m_dDelta;
	m_pEdge->m_iDx = m_iDx;
	m_pEdge->m_iDy = m_iDy;
}

BOOL CFormEdge::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
