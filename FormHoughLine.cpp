// FormHoughLine.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormHoughLine.h"
#include "afxdialogex.h"


// CFormHoughLine ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormHoughLine, CDialogEx)

CFormHoughLine::CFormHoughLine(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormHoughLine::IDD, pParent)
	, m_dRho(0)
	, m_dTheta(0)
	, m_iThreshold(0)
	, m_dMinLineLength(0)
	, m_dMaxLineGap(0)
	, m_iBGImageNo(0)
{

}

CFormHoughLine::~CFormHoughLine()
{
}

void CFormHoughLine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RHO, m_dRho);
	DDX_Text(pDX, IDC_EDIT_THETA, m_dTheta);
	DDX_Text(pDX, IDC_EDIT_THRESHOLD, m_iThreshold);
	DDX_Text(pDX, IDC_EDIT_MIN_LINE_LENGTH, m_dMinLineLength);
	DDX_Text(pDX, IDC_EDIT_MAX_LINE_GAP, m_dMaxLineGap);
	DDX_Text(pDX, IDC_EDIT_BGIMAGENO, m_iBGImageNo);
}


BEGIN_MESSAGE_MAP(CFormHoughLine, CDialogEx)
END_MESSAGE_MAP()


// CFormHoughLine �޽��� ó�����Դϴ�.
void CFormHoughLine::SetOperation(COperation* pOperation)
{
	m_pHoughLine = (COpHoughLine*)pOperation;

	m_dRho = m_pHoughLine->m_dRho;
	m_dTheta = m_pHoughLine->m_dTheta;
	m_iThreshold = m_pHoughLine->m_iThreshold;
	m_dMinLineLength = m_pHoughLine->m_dMinLineLength;
	m_dMaxLineGap = m_pHoughLine->m_dMaxLineGap;
	m_iBGImageNo = m_pHoughLine->GetSecondImgIndex();

	UpdateData(FALSE);
}


void CFormHoughLine::ApplyChanges()
{
	UpdateData(TRUE);

	m_pHoughLine->m_dRho = m_dRho;
	m_pHoughLine->m_dTheta = m_dTheta;
	m_pHoughLine->m_iThreshold = m_iThreshold;
	m_pHoughLine->m_dMinLineLength = m_dMinLineLength;
	m_pHoughLine->m_dMaxLineGap = m_dMaxLineGap;
	m_pHoughLine->SetSecondImgIndex(m_iBGImageNo);
}

BOOL CFormHoughLine::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
