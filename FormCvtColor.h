#pragma once

#include "AllOperations.h"
// CFormCvtColor ��ȭ �����Դϴ�.

class CFormCvtColor : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCvtColor)

public:
	CFormCvtColor(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormCvtColor();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_CVTCOLOR };
protected:
	COpCvtColor* m_pCvtColor;
	int m_iCvtColorTypeNo;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
