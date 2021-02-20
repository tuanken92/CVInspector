#pragma once

#include "AllOperations.h"
// CFormContour ��ȭ �����Դϴ�.

class CFormContour : public CDialogEx
{
	DECLARE_DYNAMIC(CFormContour)

public:
	CFormContour(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormContour();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_CONTOUR };
protected:
	COpContour* m_pContour;
	int m_iMode;
	int m_iMethod;
	int m_iLineWidth;
	int m_iLineType;
	int m_iMaxValue;
	int m_iBGImageNo;
	BOOL m_bUseConvexHull;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
	
};
