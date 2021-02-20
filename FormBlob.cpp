// FormBlob.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormBlob.h"
#include "afxdialogex.h"


// CFormBlob 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormBlob, CDialogEx)

CFormBlob::CFormBlob(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormBlob::IDD, pParent)
	, m_dThresholdStep(0)
	, m_dMinThreshold(0)
	, m_dMaxThreshold(0)
	, m_iMinRepeatability(0)
	, m_dMinDistBetweenBlobs(0)
	, m_bFilterByColor(FALSE)
	, m_iBlobColor(0)
	, m_bFilterByArea(FALSE)
	, m_dMinArea(0)
	, m_dMaxArea(0)
	, m_bFilterByCircularity(FALSE)
	, m_dMinCircularity(0)
	, m_dMaxCircularity(0)
	, m_bFilterByInertia(FALSE)
	, m_dMinInertiaRatio(0)
	, m_dMaxInertiaRatio(0)
{

}

CFormBlob::~CFormBlob()
{
}

void CFormBlob::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THR_STEP, m_dThresholdStep);
	DDX_Text(pDX, IDC_EDIT_MIN_THR, m_dMinThreshold);
	DDX_Text(pDX, IDC_EDIT_MAX_THR, m_dMaxThreshold);
	DDX_Text(pDX, IDC_EDIT_MIN_REPEATABILITY, m_iMinRepeatability);
	DDX_Text(pDX, IDC_EDIT_MIN_DIST, m_dMinDistBetweenBlobs);
	DDX_Check(pDX, IDC_FILTER_BY_COLOR, m_bFilterByColor);
	DDX_Text(pDX, IDC_EDIT_MIN_REPEATABILITY2, m_iBlobColor);
	DDX_Check(pDX, IDC_FILTER_BY_AREA, m_bFilterByArea);
	DDX_Text(pDX, IDC_EDIT_MIN_AREA, m_dMinArea);
	DDX_Text(pDX, IDC_EDIT_MAX_AREA, m_dMaxArea);
	DDX_Check(pDX, IDC_FILTER_BY_CIRCULARITY, m_bFilterByCircularity);
	DDX_Text(pDX, IDC_EDIT_MIN_CIRCULARITY, m_dMinCircularity);
	DDX_Text(pDX, IDC_EDIT_MAX_CIRCULARITY, m_dMaxCircularity);
	DDX_Check(pDX, IDC_FILTER_BY_CIRCULARITY2, m_bFilterByInertia);
	DDX_Text(pDX, IDC_EDIT_MIN_INERTIA, m_dMinInertiaRatio);
	DDX_Text(pDX, IDC_EDIT_MAX_INERTIA, m_dMaxInertiaRatio);
}


BEGIN_MESSAGE_MAP(CFormBlob, CDialogEx)
END_MESSAGE_MAP()


// CFormBlob 메시지 처리기입니다.
void CFormBlob::SetOperation(COperation* pOperation)
{
	m_pBlob = (COpBlob*)pOperation;

	m_dThresholdStep = m_pBlob->m_fThresholdStep;
	m_dMinThreshold = m_pBlob->m_fMinThreshold;
	m_dMaxThreshold = m_pBlob->m_fMaxThreshold;
	m_iMinRepeatability = m_pBlob->m_iMinRepeatability;
	m_dMinDistBetweenBlobs = m_pBlob->m_fMinDistBetweenBlobs;
	m_bFilterByColor = m_pBlob->m_bFilterByColor;
	m_iBlobColor = m_pBlob->m_iBlobColor;
	m_bFilterByArea = m_pBlob->m_bFilterByArea;
	m_dMinArea = m_pBlob->m_fMinArea;
	m_dMaxArea = m_pBlob->m_fMaxArea;
	m_bFilterByCircularity = m_pBlob->m_bFilterByCircularity;
	m_dMinCircularity = m_pBlob->m_fMinCircularity;
	m_dMaxCircularity = m_pBlob->m_fMaxCircularity;
	m_bFilterByInertia = m_pBlob->m_bFilterByInertia;
	m_dMinInertiaRatio = m_pBlob->m_fMinInertiaRatio;
	m_dMaxInertiaRatio = m_pBlob->m_fMaxInertiaRatio;

	UpdateData(FALSE);
}


void CFormBlob::ApplyChanges()
{
	UpdateData(TRUE);

	m_pBlob->m_fThresholdStep = (float)m_dThresholdStep;
	m_pBlob->m_fMinThreshold = (float)m_dMinThreshold;
	m_pBlob->m_fMaxThreshold = (float)m_dMaxThreshold;
	m_pBlob->m_iMinRepeatability = m_iMinRepeatability;
	m_pBlob->m_fMinDistBetweenBlobs = (float)m_dMinDistBetweenBlobs;
	m_pBlob->m_bFilterByColor = m_bFilterByColor;
	m_pBlob->m_iBlobColor = m_iBlobColor;
	m_pBlob->m_bFilterByArea = m_bFilterByArea;
	m_pBlob->m_fMinArea = (float)m_dMinArea;
	m_pBlob->m_fMaxArea = (float)m_dMaxArea;
	m_pBlob->m_bFilterByCircularity = m_bFilterByCircularity;
	m_pBlob->m_fMinCircularity = (float)m_dMinCircularity;
	m_pBlob->m_fMaxCircularity = (float)m_dMaxCircularity;
	m_pBlob->m_bFilterByInertia = m_bFilterByInertia;
	m_pBlob->m_fMinInertiaRatio = (float)m_dMinInertiaRatio;
	m_pBlob->m_fMaxInertiaRatio = (float)m_dMaxInertiaRatio;
}

BOOL CFormBlob::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
