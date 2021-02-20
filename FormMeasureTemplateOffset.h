#pragma once

#include "AllOperations.h"
// CFormMeasureTemplateOffset ��ȭ �����Դϴ�.

class CFormMeasureTemplateOffset : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMeasureTemplateOffset)

public:
	CFormMeasureTemplateOffset(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormMeasureTemplateOffset();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedSetRoi();
};
