#pragma once

#include "AllOperations.h"
// CFormResize ��ȭ �����Դϴ�.

class CFormResize : public CDialogEx
{
	DECLARE_DYNAMIC(CFormResize)

public:
	CFormResize(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormResize();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_RESIZE };
protected:
	COpResize* m_pResize;
	int m_iInterpolationType;
	int m_iNewSizeX;
	int m_iNewSizeY;
	double m_dNewRatioX;
	double m_dNewRatioY;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
