// FormDiffImage.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormDiffImage.h"
#include "afxdialogex.h"


// CFormDiffImage dialog

IMPLEMENT_DYNAMIC(CFormDiffImage, CDialogEx)

CFormDiffImage::CFormDiffImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormDiffImage::IDD, pParent)
	, m_iDir(0)
	, m_iDiffImgType(0)
	, m_iAnpha(0)
	, m_iBeta(0)
	, m_iMinThr(0)
	, m_iAccum(0)
{

}

CFormDiffImage::~CFormDiffImage()
{
}

void CFormDiffImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_DIFFIMG_X, m_iDir);
	DDX_Radio(pDX, IDC_DIFFIMG_TYPE, m_iDiffImgType);
	DDX_Text(pDX, IDC_EDIT_ALPHA, m_iAnpha);
	DDX_Text(pDX, IDC_EDIT_BETA, m_iBeta);
	DDX_Text(pDX, IDC_EDIT_MIN_THR, m_iMinThr);
	DDX_Text(pDX, IDC_EDIT_ACCUM, m_iAccum);
}


BEGIN_MESSAGE_MAP(CFormDiffImage, CDialogEx)
END_MESSAGE_MAP()


// CFormDiffImage message handlers
void CFormDiffImage::SetOperation(COperation* pOperation)
{
	m_pDiffImage = (COpDiffImage*)pOperation;

	m_iDir			= m_pDiffImage->m_iDir;
	m_iDiffImgType	= m_pDiffImage->m_iDiffImgType;
	m_iAnpha		= m_pDiffImage->m_iAnpha;
	m_iBeta			= m_pDiffImage->m_iBeta;
	m_iMinThr		= m_pDiffImage->m_iMinThr;
	m_iAccum		= m_pDiffImage->m_iAccum;
	UpdateData(FALSE);
}

void CFormDiffImage::ApplyChanges()
{
	UpdateData(TRUE);
	m_pDiffImage->m_iDir			= m_iDir;
	m_pDiffImage->m_iDiffImgType	= m_iDiffImgType;
	m_pDiffImage->m_iAnpha			= m_iAnpha;
	m_pDiffImage->m_iBeta			= m_iBeta;
	m_pDiffImage->m_iMinThr			= m_iMinThr;
	m_pDiffImage->m_iAccum			= m_iAccum;
}

BOOL CFormDiffImage::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
