#pragma once

#include "AllOperations.h"
// CFormCanny 대화 상자입니다.

class CFormCanny : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCanny)

public:
	CFormCanny(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormCanny();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_CANNY };
protected:
	COpCanny*	m_pCanny;
	double m_dThreshold1;
	double m_dThreshold2;
	int m_iApertureSize;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
