#pragma once

#include "AllOperations.h"
// CFormBinarize ��ȭ �����Դϴ�.

class CFormBinarize : public CDialogEx
{
	DECLARE_DYNAMIC(CFormBinarize)

public:
	CFormBinarize(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormBinarize();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
