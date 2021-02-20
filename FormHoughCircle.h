#pragma once

#include "AllOperations.h"
// CFormHoughCircle 대화 상자입니다.

class CFormHoughCircle : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHoughCircle)

public:
	CFormHoughCircle(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormHoughCircle();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
