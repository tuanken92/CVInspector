#pragma once

#include "AllOperations.h"
#include "afxcmn.h"
// CFormCrop 대화 상자입니다.

class CFormCrop : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCrop)

public:
	CFormCrop(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormCrop();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
