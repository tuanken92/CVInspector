#pragma once

#include "AllOperations.h"
// CFormBinarize 대화 상자입니다.

class CFormBinarize : public CDialogEx
{
	DECLARE_DYNAMIC(CFormBinarize)

public:
	CFormBinarize(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormBinarize();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_BINARIZE };
protected:
	COpBinarize* m_pBinarize;
	int m_iBinarizeType;
	double m_dThr;
	BOOL m_bUseOtsu;
	
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
