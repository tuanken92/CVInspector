#pragma once

#include "AllOperations.h"
// CFormArithmetic ��ȭ �����Դϴ�.

class CFormArithmetic : public CDialogEx
{
	DECLARE_DYNAMIC(CFormArithmetic)

public:
	CFormArithmetic(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormArithmetic();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	
};
