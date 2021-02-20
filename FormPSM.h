#pragma once

#include "AllOperations.h"
// CFormPSM ��ȭ �����Դϴ�.

class CFormPSM : public CDialogEx
{
	DECLARE_DYNAMIC(CFormPSM)

public:
	CFormPSM(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormPSM();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_PSM };

protected:
	COpPSM* m_pPSM;
	int m_iSubtractType;
	int m_iDir;
	int m_iXOffset;
	int m_iYOffset;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
