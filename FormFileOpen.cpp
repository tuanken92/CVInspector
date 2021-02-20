// FormFileOpen.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "FormFileOpen.h"
#include "afxdialogex.h"


// CFormFileOpen ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFormFileOpen, CDialogEx)

CFormFileOpen::CFormFileOpen(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormFileOpen::IDD, pParent)
	, m_strPathName(_T(""))
	, m_iReadType(0)
{

}

CFormFileOpen::~CFormFileOpen()
{
}

void CFormFileOpen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILE_PATH, m_strPathName);
	DDX_Radio(pDX, IDC_RADIO_READTYPE, m_iReadType);
}


BEGIN_MESSAGE_MAP(CFormFileOpen, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT_PATH, &CFormFileOpen::OnBnClickedSelectPath)
END_MESSAGE_MAP()


// CFormFileOpen �޽��� ó�����Դϴ�.
void CFormFileOpen::SetOperation(COperation* pOperation)
{
	m_pOpenImage = (COpOpenImage*)pOperation;
	m_strPathName = m_pOpenImage->m_strFileName;
	m_iReadType = m_pOpenImage->m_iReadType + 1;
	
	UpdateData(FALSE);
}


void CFormFileOpen::ApplyChanges()
{
	UpdateData(TRUE);

	m_pOpenImage->m_strFileName = m_strPathName;
	m_pOpenImage->m_iReadType = m_iReadType - 1;
}

void CFormFileOpen::OnBnClickedSelectPath()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TCHAR BASED_CODE szFilter[] = _T("Image Files (*.bmp;*.jpg;*.png;*.jp2; *.tiff)|*.bmp; *.jpg; *.png; *.jp2; *.tiff|All Files (*.*)|*.*||");

	CFileDialog FileDlg(TRUE, _T("bmp"), _T(""), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);

	if (FileDlg.DoModal() == IDOK)
	{
		m_strPathName = FileDlg.GetPathName();
	}

	UpdateData(FALSE);
}



BOOL CFormFileOpen::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
