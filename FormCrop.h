#pragma once

#include "AllOperations.h"
#include "afxcmn.h"
// CFormCrop ��ȭ �����Դϴ�.

class CFormCrop : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCrop)

public:
	CFormCrop(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormCrop();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_CROP };
protected:
	COpCrop* m_pCrop;
	int m_iLeft;
	int m_iTop;
	int m_iRight;
	int m_iBottom;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_ctrlLeft;
	CSpinButtonCtrl m_ctrlTop;
	CSpinButtonCtrl m_ctrlRight;
	CSpinButtonCtrl m_ctrlBottom;
protected:
	BOOL m_bMagnifyCropArea;
public:
	afx_msg void OnDeltaposSpinMoveLr(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinMoveUd(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
