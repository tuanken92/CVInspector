// FormCaptureCam.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormCaptureCam.h"
#include "afxdialogex.h"


// CFormCaptureCam 대화 상자입니다.

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


// CFormCaptureCam 메시지 처리기입니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
