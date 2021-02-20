#pragma once

#include "AllOperations.h"
// CFormFileOpen 대화 상자입니다.

class CFormFileOpen : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFileOpen)

public:
	CFormFileOpen(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormFileOpen();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_OPENFILE };
protected:
	COpOpenImage* m_pOpenImage;
	CString m_strPathName;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelectPath();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_iReadType;
};
