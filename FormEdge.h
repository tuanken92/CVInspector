#pragma once

#include "AllOperations.h"
// CFormEdge ��ȭ �����Դϴ�.

class CFormEdge : public CDialogEx
{
	DECLARE_DYNAMIC(CFormEdge)

public:
	CFormEdge(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormEdge();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_EDGE };
protected:
	COpEdge* m_pEdge;
	int m_iEdgeType;
	int m_iKernelSize;
	double m_dScale;
	double m_dDelta;
	int m_iDx;
	int m_iDy;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
