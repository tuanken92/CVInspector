#pragma once

#include "AllOperations.h"
// CFormCanny ��ȭ �����Դϴ�.

class CFormCanny : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCanny)

public:
	CFormCanny(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormCanny();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_CANNY };
protected:
	COpCanny*	m_pCanny;
	double m_dThreshold1;
	double m_dThreshold2;
	int m_iApertureSize;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
