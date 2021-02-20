#pragma once

#include "AllOperations.h"
// CFormMarkedAverage dialog

class CFormMarkedAverage : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMarkedAverage)

public:
	CFormMarkedAverage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormMarkedAverage();

// Dialog Data
	enum { IDD = IDD_FORM_MARKED_AVG };
protected:
	COpMarkedAgv* m_pMarkedAverage;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_iBlockSizeX;
	int m_iBlockSizeY;
	int m_iMarkImgNo;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
