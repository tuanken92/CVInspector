#pragma once
#include "AllOperations.h"

// CFormWatershed dialog

class CFormWatershed : public CDialogEx
{
	DECLARE_DYNAMIC(CFormWatershed)

public:
	CFormWatershed(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormWatershed();

// Dialog Data
	enum { IDD = IDD_FORM_WATERSHED };
protected:
	COpWatershed* m_pWatershed;
	int m_iImgNo;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
};
