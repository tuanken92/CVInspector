#pragma once

#include "AllOperations.h"
// CFormRotate ��ȭ �����Դϴ�.

class CFormRotate : public CDialogEx
{
	DECLARE_DYNAMIC(CFormRotate)

public:
	CFormRotate(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormRotate();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_ROTATE };
protected:
	COpRotate* m_pRotate;
	double m_dAngle;
	
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
