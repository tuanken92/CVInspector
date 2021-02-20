#pragma once

#include "AllOperations.h"
// CFormSplit ��ȭ �����Դϴ�.

class CFormSplit : public CDialogEx
{
	DECLARE_DYNAMIC(CFormSplit)

public:
	CFormSplit(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormSplit();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_SPLIT };
protected:
	COpSplit* m_pSplit;
	int m_iTargetChannel;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
