#pragma once

#include "AllOperations.h"
// CFormFilter2D 대화 상자입니다.

class CFormFilter2D : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFilter2D)

public:
	CFormFilter2D(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormFilter2D();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_FILTER2D };
protected:
	COpFilter2D* m_pFilter2D;
	int m_iAnchorX;
	int m_iAnchorY;
	double m_dDelta;
	CString m_strKernel;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
};
