#pragma once

#include "AllOperations.h"
// CFormHoughLine ��ȭ �����Դϴ�.

class CFormHoughLine : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHoughLine)

public:
	CFormHoughLine(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormHoughLine();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_HOUGHLINE };

protected:
	COpHoughLine* m_pHoughLine;
	double m_dRho;
	double m_dTheta;
	int m_iThreshold;
	double m_dMinLineLength;
	double m_dMaxLineGap;
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
