#pragma once

#include "AllOperations.h"
// CFormHarrisCorner ��ȭ �����Դϴ�.

class CFormHarrisCorner : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHarrisCorner)

public:
	CFormHarrisCorner(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormHarrisCorner();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_HARRISCORNER };
protected:
	COpHarrisCorner* m_pHarrisCorner;
	int m_iNeighbor;
	int m_iAperture;
	double m_dParameterK;
	int m_iNonMaxSize;

	int m_iMarkerColorR;
	int m_iMarkerColorG;
	int m_iMarkerColorB;
	int m_iMarkerSize;
	int m_iBGImageNo;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
