#pragma once

#include "AllOperations.h"
// CFormHoughCircle ��ȭ �����Դϴ�.

class CFormHoughCircle : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHoughCircle)

public:
	CFormHoughCircle(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormHoughCircle();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_HOUGHCIRCLE };
protected:
	COpHoughCircle* m_pHoughCircle;
	double m_dAccuRes;
	double m_dMinDist;
	double m_dParameter1;
	double m_dParameter2;
	int m_iMinRadius;
	int m_iMaxRadius;
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
