#pragma once

#include "AllOperations.h"
// CFormMeasureTemplateOffset 대화 상자입니다.

class CFormMeasureTemplateOffset : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMeasureTemplateOffset)

public:
	CFormMeasureTemplateOffset(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormMeasureTemplateOffset();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_OFFSETTEMPLATE };
protected:
	COpOffsetTemplate* m_pOffsetTemplate;
	int m_iMethod;
	double m_dScaleX;
	double m_dScaleY;
	double m_dOffsetX;
	double m_dOffsetY;
	CString m_strRefFilePath;
	double m_dMatchingScoreThr;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedSetRoi();
};
