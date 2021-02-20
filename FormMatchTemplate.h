#pragma once

#include "AllOperations.h"
// CFormMatchTemplate 대화 상자입니다.

class CFormMatchTemplate : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMatchTemplate)

public:
	CFormMatchTemplate(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormMatchTemplate();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_MATCHTEMPLATE };
protected:
	COpMatchTemplate* m_pMatchTemplate;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	int m_iMethod;
	int m_iTemplateImgNo;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	BOOL m_bShowMatchedResult;
};
