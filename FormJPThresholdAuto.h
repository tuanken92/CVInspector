#pragma once
#include "AllOperations.h"

// CFormJPThresholdAuto dialog

class CFormJPThresholdAuto : public CDialogEx
{
	DECLARE_DYNAMIC(CFormJPThresholdAuto)

public:
	CFormJPThresholdAuto(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormJPThresholdAuto();

// Dialog Data
	enum { IDD = IDD_FORM_JPTHRESHOLD_AUTO };

protected:
	COpJPThresholdAuto* m_pJPThresholdAuto;
	int m_iStdDev;
	int m_iDir;
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
};
