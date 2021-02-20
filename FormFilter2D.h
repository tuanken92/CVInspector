#pragma once

#include "AllOperations.h"
// CFormFilter2D ��ȭ �����Դϴ�.

class CFormFilter2D : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFilter2D)

public:
	CFormFilter2D(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormFilter2D();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_FILTER2D };
protected:
	COpFilter2D* m_pFilter2D;
	int m_iAnchorX;
	int m_iAnchorY;
	double m_dDelta;
	CString m_strKernel;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
};
