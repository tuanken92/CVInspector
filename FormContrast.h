#pragma once

#include "AllOperations.h"
// CFormContrast dialog

class CFormContrast : public CDialogEx
{
	DECLARE_DYNAMIC(CFormContrast)

public:
	CFormContrast(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormContrast();

// Dialog Data
	enum { IDD = IDD_FORM_CONTRAST };
protected:
	COpContrast*	m_pContrast;
	int iAlpha;
	int iBeta;
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
};
