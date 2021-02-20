#pragma once

#include "AllOperations.h"
// CFormAdaptiveThreshold 대화 상자입니다.

class CFormAdaptiveThreshold : public CDialogEx
{
	DECLARE_DYNAMIC(CFormAdaptiveThreshold)

public:
	CFormAdaptiveThreshold(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormAdaptiveThreshold();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_ADAPTIVETHR };
protected:
	COpAdaptiveThreshold* m_pAdaptiveThreshold;
	double m_dConstant;
	int m_iBlockSize;
	int m_iType;
	int m_iAdaptiveMethod;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
