#pragma once

#include "AllOperations.h"
// CFormHistogram ��ȭ �����Դϴ�.

class CFormHistogram : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHistogram)

public:
	CFormHistogram(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormHistogram();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_HISTOGRAM };
protected:
	COpHistogram* m_pHistogram;
	int m_iHistSize;
	float m_fHistRangeL;
	float m_fHistRangeH;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
