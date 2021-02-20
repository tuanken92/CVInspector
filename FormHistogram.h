#pragma once

#include "AllOperations.h"
// CFormHistogram 대화 상자입니다.

class CFormHistogram : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHistogram)

public:
	CFormHistogram(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormHistogram();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_HISTOGRAM };
protected:
	COpHistogram* m_pHistogram;
	int m_iHistSize;
	float m_fHistRangeL;
	float m_fHistRangeH;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
