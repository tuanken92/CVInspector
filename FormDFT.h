#pragma once

#include "AllOperations.h"
// CFormDFT 대화 상자입니다.

class CFormDFT : public CDialogEx
{
	DECLARE_DYNAMIC(CFormDFT)

public:
	CFormDFT(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormDFT();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_DFT };
protected:
	COpDFT* m_pDFT;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	BOOL m_bShowScaledImage;
	BOOL m_bInv;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
