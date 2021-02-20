// FormMappingImage.cpp : implementation file
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMappingImage.h"
#include "afxdialogex.h"


// CFormMappingImage dialog

IMPLEMENT_DYNAMIC(CFormMappingImage, CDialogEx)

CFormMappingImage::CFormMappingImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormMappingImage::IDD, pParent)
	, m_iDir(0)
	, m_iDist(0)
	, m_dThr(0)
	, m_dAlpha(0)
	, m_dBeta(0)
	, m_combo_str(_T("BRIGHT"))
{

}

CFormMappingImage::~CFormMappingImage()
{
}

void CFormMappingImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_MAPINGIMG_TYPE1, m_iDir);

	DDX_Text(pDX, IDC_EDIT_MAP_DIST, m_iDist);
	DDX_Text(pDX, IDC_EDIT_MAP_THR, m_dThr);
	DDX_Text(pDX, IDC_EDIT_MAP_ALPHA, m_dAlpha);
	DDX_Text(pDX, IDC_EDIT_MAP_BETA, m_dBeta);
	DDX_Control(pDX, IDC_COMBO_LIGHT, m_combo_light);
	DDX_CBString(pDX, IDC_COMBO_LIGHT, m_combo_str);
}


BEGIN_MESSAGE_MAP(CFormMappingImage, CDialogEx)
END_MESSAGE_MAP()


// CFormMappingImage message handlers
void CFormMappingImage::SetOperation(COperation* pOperation)
{
	m_pMappingImage = (COpMappingImage*)pOperation;

	m_iDir = m_pMappingImage->m_iDir;

	m_iDist = m_pMappingImage->m_iDist;
	m_dThr = m_pMappingImage->m_dThr;
	m_dAlpha = m_pMappingImage->m_dAlpha;
	m_dBeta = m_pMappingImage->m_dBeta;

	m_combo_str = m_pMappingImage->m_strComboLight;
	
	m_combo_light.SetCurSel(1);

	UpdateData(FALSE);
}


void CFormMappingImage::ApplyChanges()
{
	UpdateData(TRUE);
	m_pMappingImage->m_iDir = m_iDir;

	m_pMappingImage->m_iDist = m_iDist;
	m_pMappingImage->m_dThr = m_dThr;
	m_pMappingImage->m_dAlpha = m_dAlpha;
	m_pMappingImage->m_dBeta = m_dBeta;

	m_pMappingImage->m_strComboLight = m_combo_str;
}

BOOL CFormMappingImage::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CFormMappingImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	
	//m_combo_light.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
