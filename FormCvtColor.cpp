// FormCvtColor.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormCvtColor.h"
#include "afxdialogex.h"


// CFormCvtColor 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormCvtColor, CDialogEx)

CFormCvtColor::CFormCvtColor(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormCvtColor::IDD, pParent)
	, m_iCvtColorTypeNo(0)
{
	m_pCvtColor = NULL;
}

CFormCvtColor::~CFormCvtColor()
{
}

void CFormCvtColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_CVT_TYPE1, m_iCvtColorTypeNo);
}


BEGIN_MESSAGE_MAP(CFormCvtColor, CDialogEx)
END_MESSAGE_MAP()


// CFormCvtColor 메시지 처리기입니다.
void CFormCvtColor::SetOperation(COperation* pOperation)
{
	m_pCvtColor = (COpCvtColor*)pOperation;	
	
	int iCvtColorTypeNo = m_pCvtColor->m_iConvertType;

	switch (iCvtColorTypeNo)
	{
	case CV_BGR2GRAY:
		m_iCvtColorTypeNo = 0;
		break;

	case CV_GRAY2BGR:
		m_iCvtColorTypeNo = 1;
		break;

	case CV_BGR2HSV:
		m_iCvtColorTypeNo = 2;
		break;
	default:
		m_iCvtColorTypeNo = 0;
		break;
	}

	UpdateData(FALSE);
}


void CFormCvtColor::ApplyChanges()
{
	UpdateData(TRUE);
	
	int iCvtColorTypeNo = CV_BGR2GRAY;
	switch (m_iCvtColorTypeNo)
	{
	case 0:
		iCvtColorTypeNo = CV_BGR2GRAY;
		break;

	case 1:
		iCvtColorTypeNo = CV_GRAY2BGR;
		break;

	case 2:
		iCvtColorTypeNo = CV_BGR2HSV;
		break;

	default:
		iCvtColorTypeNo = CV_BGR2GRAY;
		break;

	}
	m_pCvtColor->m_iConvertType = iCvtColorTypeNo;
}

BOOL CFormCvtColor::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
