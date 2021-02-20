#pragma once
#include "AllOperations.h"

// CFormMarkedAdaptiveThreshold dialog

class CFormMarkedAdaptiveThreshold : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMarkedAdaptiveThreshold)

public:
	CFormMarkedAdaptiveThreshold(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormMarkedAdaptiveThreshold();

// Dialog Data
	enum { IDD = IDD_FORM_MARKED_ADAP_THRESHOLD };

protected:
	COpMarkedAdaptiveThreshold* m_pMarkedAdaptiveThreshold;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_iType;
	int m_iBlockSizeX;
	int m_iBlockSizeY;
	int m_iMarkImgNo;
	int m_iCValue;
};
