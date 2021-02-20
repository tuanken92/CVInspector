#pragma once
#include "AllOperations.h"

// CFormAdaptiveThresholdISH dialog

class CFormAdaptiveThresholdISH : public CDialogEx
{
	DECLARE_DYNAMIC(CFormAdaptiveThresholdISH)

public:
	CFormAdaptiveThresholdISH(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormAdaptiveThresholdISH();

// Dialog Data
	enum { IDD = IDD_FORM_ADAPTIVETHR_ISH };
protected:
	COpAdaptiveThresholdISH* m_pAdaptiveThresholdISH;
	int m_iThr;
	int m_iBlockSize;
	double m_dOffset;
	double m_dScale;
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
};
