#pragma once

#include "AllOperations.h"
// CFormFlip 대화 상자입니다.

class CFormFlip : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFlip)

public:
	CFormFlip(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormFlip();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_FLIP };
protected:
	COpFlip* m_pFlip;
	int m_iFlipCode;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()


public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
