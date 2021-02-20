#pragma once

#include "AllOperations.h"
// CFormAdaptiveThreshold ��ȭ �����Դϴ�.

class CFormAdaptiveThreshold : public CDialogEx
{
	DECLARE_DYNAMIC(CFormAdaptiveThreshold)

public:
	CFormAdaptiveThreshold(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormAdaptiveThreshold();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_ADAPTIVETHR };
protected:
	COpAdaptiveThreshold* m_pAdaptiveThreshold;
	double m_dConstant;
	int m_iBlockSize;
	int m_iType;
	int m_iAdaptiveMethod;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
