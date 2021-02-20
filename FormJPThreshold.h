#pragma once

#include "AllOperations.h"

// CFormJPThreshold dialog

class CFormJPThreshold : public CDialogEx
{
	DECLARE_DYNAMIC(CFormJPThreshold)

public:
	CFormJPThreshold(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormJPThreshold();

// Dialog Data
	enum { IDD = IDD_FORM_JPTHRESHOLD };

protected:
	COpJPThreshold* m_pJPThreshold;
	int m_iThrUpper;
	int m_iThrLower;
	int m_iTypeThr;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
