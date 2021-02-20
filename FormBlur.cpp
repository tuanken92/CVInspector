// FormBlur.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormBlur.h"
#include "afxdialogex.h"


// CFormBlur 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormBlur, CDialogEx)

CFormBlur::CFormBlur(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormBlur::IDD, pParent)
	, m_iBlurType(0)
	, m_iAnchorX(-1)
	, m_iAnchorY(-1)
	, m_dGaussianSigma(0)
	, m_dBilateralSigmaColor(0)
	, m_dBilateralSigmaSpace(0)
	, m_iKernelX(3)
	, m_iKernelY(3)
{

}

CFormBlur::~CFormBlur()
{
}

void CFormBlur::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_BLUR_TYPE1, m_iBlurType);
	DDX_Text(pDX, IDC_EDIT_ANCHOR_X, m_iAnchorX);
	DDX_Text(pDX, IDC_EDIT_ANCHOR_Y, m_iAnchorY);
	DDX_Text(pDX, IDC_EDIT_GAUSSIAN_SIGMA, m_dGaussianSigma);
	DDX_Text(pDX, IDC_EDIT_BILATERAL_SIGMA_COLOR, m_dBilateralSigmaColor);
	DDX_Text(pDX, IDC_EDIT_BILATERAL_SIGMA_SPACE, m_dBilateralSigmaSpace);
	DDX_Text(pDX, IDC_EDIT_KERNEL_X, m_iKernelX);
	DDX_Text(pDX, IDC_EDIT_KERNEL_Y, m_iKernelY);
}


BEGIN_MESSAGE_MAP(CFormBlur, CDialogEx)
END_MESSAGE_MAP()


// CFormBlur 메시지 처리기입니다.
void CFormBlur::SetOperation(COperation* pOperation)
{
	m_pBlur = (COpBlur*)pOperation;

	m_iBlurType = m_pBlur->m_iBlurType;
	m_iKernelX = m_pBlur->m_iKernelX;
	m_iKernelY = m_pBlur->m_iKernelY;
	m_iAnchorX = m_pBlur->m_AnchorPos.x;
	m_iAnchorY = m_pBlur->m_AnchorPos.y;
	m_dGaussianSigma = m_pBlur->m_dGaussianSigma;
	m_dBilateralSigmaColor = m_pBlur->m_dBilateralSigmaColor;
	m_dBilateralSigmaSpace = m_pBlur->m_dBilateralSigmaSpace;

	UpdateData(FALSE);
}


void CFormBlur::ApplyChanges()
{
	UpdateData(TRUE);

	m_pBlur->m_iBlurType = m_iBlurType;
	m_pBlur->m_iKernelX = m_iKernelX;
	m_pBlur->m_iKernelY = m_iKernelY;
	m_pBlur->m_AnchorPos = CPoint(m_iAnchorX, m_iAnchorY);	
	m_pBlur->m_dGaussianSigma = m_dGaussianSigma;
	m_pBlur->m_dBilateralSigmaColor = m_dBilateralSigmaColor;
	m_pBlur->m_dBilateralSigmaSpace = m_dBilateralSigmaSpace;
}

BOOL CFormBlur::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
