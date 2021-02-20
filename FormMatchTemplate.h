#pragma once

#include "AllOperations.h"
// CFormMatchTemplate ��ȭ �����Դϴ�.

class CFormMatchTemplate : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMatchTemplate)

public:
	CFormMatchTemplate(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormMatchTemplate();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_MATCHTEMPLATE };
protected:
	COpMatchTemplate* m_pMatchTemplate;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	int m_iMethod;
	int m_iTemplateImgNo;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	BOOL m_bShowMatchedResult;
};
