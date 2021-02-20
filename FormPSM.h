#pragma once

#include "AllOperations.h"
// CFormPSM 대화 상자입니다.

class CFormPSM : public CDialogEx
{
	DECLARE_DYNAMIC(CFormPSM)

public:
	CFormPSM(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormPSM();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_PSM };

protected:
	COpPSM* m_pPSM;
	int m_iSubtractType;
	int m_iDir;
	int m_iXOffset;
	int m_iYOffset;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
