#pragma once

#include "AllOperations.h"
// CFormEqualHist 대화 상자입니다.

class CFormEqualHist : public CDialogEx
{
	DECLARE_DYNAMIC(CFormEqualHist)

public:
	CFormEqualHist(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormEqualHist();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_EQUALHIST };
protected:
	COpEqualHist* m_pEqualHist;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
