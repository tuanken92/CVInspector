#pragma once

#include "AllOperations.h"
// CFormTimeDelay 대화 상자입니다.

class CFormTimeDelay : public CDialogEx
{
	DECLARE_DYNAMIC(CFormTimeDelay)

public:
	CFormTimeDelay(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormTimeDelay();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_TIMEDELAY };
protected:
	COpTimeDelay* m_pTimeDelay;
	int m_iDelayTime;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
