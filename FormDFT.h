#pragma once

#include "AllOperations.h"
// CFormDFT ��ȭ �����Դϴ�.

class CFormDFT : public CDialogEx
{
	DECLARE_DYNAMIC(CFormDFT)

public:
	CFormDFT(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormDFT();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_DFT };
protected:
	COpDFT* m_pDFT;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	BOOL m_bShowScaledImage;
	BOOL m_bInv;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
