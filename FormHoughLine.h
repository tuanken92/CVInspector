#pragma once

#include "AllOperations.h"
// CFormHoughLine 대화 상자입니다.

class CFormHoughLine : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHoughLine)

public:
	CFormHoughLine(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormHoughLine();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
