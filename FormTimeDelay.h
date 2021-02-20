#pragma once

#include "AllOperations.h"
// CFormTimeDelay ��ȭ �����Դϴ�.

class CFormTimeDelay : public CDialogEx
{
	DECLARE_DYNAMIC(CFormTimeDelay)

public:
	CFormTimeDelay(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormTimeDelay();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_TIMEDELAY };
protected:
	COpTimeDelay* m_pTimeDelay;
	int m_iDelayTime;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
