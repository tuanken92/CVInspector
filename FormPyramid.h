#pragma once

#include "AllOperations.h"
// CFormPyramid ��ȭ �����Դϴ�.

class CFormPyramid : public CDialogEx
{
	DECLARE_DYNAMIC(CFormPyramid)

public:
	CFormPyramid(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormPyramid();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_PYRAMID };
protected:
	COpPyramid* m_pPyramid;
	BOOL m_bPyrType;
	int m_iSizeX;
	int m_iSizeY;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
