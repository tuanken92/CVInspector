#pragma once

#include "AllOperations.h"
// CFormFlip ��ȭ �����Դϴ�.

class CFormFlip : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFlip)

public:
	CFormFlip(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormFlip();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_FLIP };
protected:
	COpFlip* m_pFlip;
	int m_iFlipCode;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()


public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
