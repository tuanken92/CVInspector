#pragma once

#include "AllOperations.h"
// CFormSplit 대화 상자입니다.

class CFormSplit : public CDialogEx
{
	DECLARE_DYNAMIC(CFormSplit)

public:
	CFormSplit(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormSplit();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_SPLIT };
protected:
	COpSplit* m_pSplit;
	int m_iTargetChannel;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
