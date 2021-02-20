// FormHoughCircle.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormHoughCircle.h"
#include "afxdialogex.h"


// CFormHoughCircle ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormHoughCircle, CDialogEx)

CFormHoughCircle::CFormHoughCircle(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormHoughCircle::IDD, pParent)
	, m_dAccuRes(0)
	, m_dMinDist(0)
	, m_dParameter1(0)
	, m_dParameter2(0)
	, m_iMinRadius(0)
	, m_iMaxRadius(0)
	, m_iBGImageNo(0)
{

}

CFormHoughCircle::~CFormHoughCircle()
{
}

void CFormHoughCircle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ACCU_RES, m_dAccuRes);
	DDX_Text(pDX, IDC_EDIT_MIN_DIST, m_dMinDist);
	DDX_Text(pDX, IDC_EDIT_PARAMETER1, m_dParameter1);
	DDX_Text(pDX, IDC_EDIT_PARAMETER2, m_dParameter2);
	DDX_Text(pDX, IDC_EDIT_MIN_RADIUS, m_iMinRadius);
	DDX_Text(pDX, IDC_EDIT_MAX_RADIUS, m_iMaxRadius);
	DDX_Text(pDX, IDC_EDIT_BGIMAGENO2, m_iBGImageNo);
}


BEGIN_MESSAGE_MAP(CFormHoughCircle, CDialogEx)
END_MESSAGE_MAP()


// CFormHoughCircle �޽��� ó�����Դϴ�.
void CFormHoughCircle::SetOperation(COperation* pOperation)
{
	m_pHoughCircle = (COpHoughCircle*)pOperation;

	m_dAccuRes = m_pHoughCircle->m_dAccuRes;
	m_dMinDist = m_pHoughCircle->m_dMinDist;
	m_dParameter1 = m_pHoughCircle->m_dParam1;
	m_dParameter2 = m_pHoughCircle->m_dParam2;
	m_iMinRadius = m_pHoughCircle->m_iMinRadius;
	m_iMaxRadius = m_pHoughCircle->m_iMaxRadius;
	m_iBGImageNo = m_pHoughCircle->GetSecondImgIndex();

	UpdateData(FALSE);
}


void CFormHoughCircle::ApplyChanges()
{
	UpdateData(TRUE);

	m_pHoughCircle->m_dAccuRes = m_dAccuRes;
	m_pHoughCircle->m_dMinDist = m_dMinDist;
	m_pHoughCircle->m_dParam1 = m_dParameter1;
	m_pHoughCircle->m_dParam2 = m_dParameter2;
	m_pHoughCircle->m_iMinRadius = m_iMinRadius;
	m_pHoughCircle->m_iMaxRadius = m_iMaxRadius;
	m_pHoughCircle->SetSecondImgIndex(m_iBGImageNo);
}

BOOL CFormHoughCircle::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
