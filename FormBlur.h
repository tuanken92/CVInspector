#pragma once

#include "AllOperations.h"
// CFormBlur ��ȭ �����Դϴ�.

class CFormBlur : public CDialogEx
{
	DECLARE_DYNAMIC(CFormBlur)

public:
	CFormBlur(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormBlur();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
