// FormMorphology.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormMorphology.h"
#include "afxdialogex.h"


// CFormMorphology 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFormMorphology, CDialogEx)

CFormMorphology::CFormMorphology(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormMorphology::IDD, pParent)
	, m_iMorphType(0)
	, m_iKernelSizeX(0)
	, m_iKernelSizeY(0)
	, m_iAnchorX(-1)
	, m_iAnchorY(-1)
	, m_iIterNo(1)
	, m_iComboShapeStructure(0)
{

}

CFormMorphology::~CFormMorphology()
{
}

void CFormMorphology::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_MORPH_TYPE1, m_iMorphType);
	DDX_Text(pDX, IDC_EDIT_KERNEL_SIZE, m_iKernelSizeX);
	DDX_Text(pDX, IDC_EDIT_KERNEL_SIZEY, m_iKernelSizeY);
	DDX_Text(pDX, IDC_EDIT_ANCHOR_X, m_iAnchorX);
	DDX_Text(pDX, IDC_EDIT_ANCHOR_Y, m_iAnchorY);
	DDX_Text(pDX, IDC_EDIT_ITERATION_NO, m_iIterNo);
	DDX_CBIndex(pDX, IDC_COMBO_SHAPE_STRUCTUE, m_iComboShapeStructure);
}


BEGIN_MESSAGE_MAP(CFormMorphology, CDialogEx)
END_MESSAGE_MAP()


// CFormMorphology 메시지 처리기입니다.
void CFormMorphology::SetOperation(COperation* pOperation)
{
	m_pMorphology = (COpMorphology*)pOperation;

	m_iMorphType = m_pMorphology->m_iMorphologyType;
	m_iKernelSizeX = m_pMorphology->m_iKernelSizeX;
	m_iKernelSizeY = m_pMorphology->m_iKernelSizeY;
	m_iAnchorX = m_pMorphology->m_AnchorPos.x;
	m_iAnchorY = m_pMorphology->m_AnchorPos.y;
	m_iIterNo = m_pMorphology->m_iIterationNo;
	m_iComboShapeStructure = m_pMorphology->m_iShapeStructure;
	UpdateData(FALSE);
}


void CFormMorphology::ApplyChanges()
{
	UpdateData(TRUE);

	m_pMorphology->m_iMorphologyType = m_iMorphType;
	m_pMorphology->m_iKernelSizeX = m_iKernelSizeX;
	m_pMorphology->m_iKernelSizeY = m_iKernelSizeY;
	m_pMorphology->m_AnchorPos = CPoint(m_iAnchorX, m_iAnchorY);
	m_pMorphology->m_iIterationNo = m_iIterNo;
	m_pMorphology->m_iShapeStructure = m_iComboShapeStructure;
}

BOOL CFormMorphology::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
