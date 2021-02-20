#pragma once

#include "AllOperations.h"
// CFormFileOpen ��ȭ �����Դϴ�.

class CFormFileOpen : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFileOpen)

public:
	CFormFileOpen(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormFileOpen();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_OPENFILE };
protected:
	COpOpenImage* m_pOpenImage;
	CString m_strPathName;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelectPath();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_iReadType;
};
