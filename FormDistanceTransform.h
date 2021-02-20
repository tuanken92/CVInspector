#pragma once
#include "AllOperations.h"

// CFormDistanceTransform dialog

class CFormDistanceTransform : public CDialogEx
{
	DECLARE_DYNAMIC(CFormDistanceTransform)

public:
	CFormDistanceTransform(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormDistanceTransform();

// Dialog Data
	enum { IDD = IDD_FORM_DISTANCE };
protected:
	COpDistance* m_pDistance;
	int m_iDistanceType;
	int m_iMarkSize;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);


};
