#pragma once

#include "AllOperations.h"
// CFormArithmetic 대화 상자입니다.

class CFormArithmetic : public CDialogEx
{
	DECLARE_DYNAMIC(CFormArithmetic)

public:
	CFormArithmetic(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormArithmetic();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_ARITHMETIC };
protected:
	COpArithmetic* m_pArithmetic;
	int m_i2ndImageIndex;
	int m_iOperatorType;
	double m_dAlpha;
	double m_dBeta;
	double m_dGama;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	
};
