#pragma once

#include "AllOperations.h"
// CFormEqualHist ��ȭ �����Դϴ�.

class CFormEqualHist : public CDialogEx
{
	DECLARE_DYNAMIC(CFormEqualHist)

public:
	CFormEqualHist(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormEqualHist();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_EQUALHIST };
protected:
	COpEqualHist* m_pEqualHist;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
