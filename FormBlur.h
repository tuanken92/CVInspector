#pragma once

#include "AllOperations.h"
// CFormBlur 대화 상자입니다.

class CFormBlur : public CDialogEx
{
	DECLARE_DYNAMIC(CFormBlur)

public:
	CFormBlur(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormBlur();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_BLUR };
protected:
	COpBlur* m_pBlur;
	int m_iBlurType;
	int m_iKernelX;
	int m_iKernelY;
	int m_iAnchorX;
	int m_iAnchorY;
	double m_dGaussianSigma;
	double m_dBilateralSigmaColor;
	double m_dBilateralSigmaSpace;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
