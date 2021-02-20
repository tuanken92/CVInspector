// FormArithmetic.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormArithmetic.h"
#include "afxdialogex.h"


// CFormArithmetic ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormArithmetic, CDialogEx)

CFormArithmetic::CFormArithmetic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormArithmetic::IDD, pParent)
	, m_i2ndImageIndex(0)
	, m_iOperatorType(0)
	, m_dAlpha(0)
	, m_dBeta(0)
	, m_dGama(0)
{

}

CFormArithmetic::~CFormArithmetic()
{
}

void CFormArithmetic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_2ND_IMAGE, m_i2ndImageIndex);
	DDX_Radio(pDX, IDC_OPERATOR_TYPE1, m_iOperatorType);
	DDX_Text(pDX, IDC_EDIT_ALPHA, m_dAlpha);
	DDX_Text(pDX, IDC_EDIT_BETA, m_dBeta);
	DDX_Text(pDX, IDC_EDIT_GAMA, m_dGama);
}


BEGIN_MESSAGE_MAP(CFormArithmetic, CDialogEx)
END_MESSAGE_MAP()


// CFormArithmetic �޽��� ó�����Դϴ�.
void CFormArithmetic::SetOperation(COperation* pOperation)
{
	m_pArithmetic = (COpArithmetic*)pOperation;

	m_i2ndImageIndex = m_pArithmetic->GetSecondImgIndex();
	m_iOperatorType = m_pArithmetic->m_iOperatorType;
	m_dAlpha = m_pArithmetic->m_dAlpha;
	m_dBeta = m_pArithmetic->m_dBeta;
	m_dGama = m_pArithmetic->m_dGama;
	UpdateData(FALSE);
}


void CFormArithmetic::ApplyChanges()
{
	UpdateData(TRUE);
	m_pArithmetic->m_iOperatorType = m_iOperatorType;
	m_pArithmetic->SetSecondImgIndex(m_i2ndImageIndex);
	m_pArithmetic->m_dAlpha = m_dAlpha;
	m_pArithmetic->m_dBeta = m_dBeta;
	m_pArithmetic->m_dGama = m_dGama;
	
}



BOOL CFormArithmetic::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
