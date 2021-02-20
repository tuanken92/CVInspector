#pragma once
#include "AllOperations.h"

// CFormFarshidThr dialog

class CFormFarshidThr : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFarshidThr)

public:
	CFormFarshidThr(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormFarshidThr();

// Dialog Data
	enum { IDD = IDD_FORM_FARSHIDTHR };

protected:
	COpFarshidThr* m_pFarshidThr;


public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
