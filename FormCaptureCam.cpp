// FormCaptureCam.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormCaptureCam.h"
#include "afxdialogex.h"


// CFormCaptureCam ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormCaptureCam, CDialogEx)

CFormCaptureCam::CFormCaptureCam(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormCaptureCam::IDD, pParent)
	, m_iCamNo(0)
	, m_iImgWidth(0)
	, m_iImgHeight(0)
{

}

CFormCaptureCam::~CFormCaptureCam()
{
}

void CFormCaptureCam::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAMERANO, m_iCamNo);
	DDX_Text(pDX, IDC_EDIT_IMGWIDTH, m_iImgWidth);
	DDX_Text(pDX, IDC_EDIT_IMGHEIGHT, m_iImgHeight);
}


BEGIN_MESSAGE_MAP(CFormCaptureCam, CDialogEx)
END_MESSAGE_MAP()


// CFormCaptureCam �޽��� ó�����Դϴ�.
void CFormCaptureCam::SetOperation(COperation* pOperation)
{
	m_pCaptureCam = (COpCaptureCam*)pOperation;

	m_iCamNo = m_pCaptureCam->m_iCamNo;
	m_iImgWidth = m_pCaptureCam->m_iImgWidth;
	m_iImgHeight = m_pCaptureCam->m_iImgHeight;
	
	UpdateData(FALSE);
}

void CFormCaptureCam::ApplyChanges()
{
	UpdateData(TRUE);

	m_pCaptureCam->m_iCamNo = m_iCamNo;
	m_pCaptureCam->m_iImgWidth = m_iImgWidth;
	m_pCaptureCam->m_iImgHeight = m_iImgHeight;
}

BOOL CFormCaptureCam::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
