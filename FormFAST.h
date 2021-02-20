#pragma once

#include "AllOperations.h"
// CFormFAST ��ȭ �����Դϴ�.

class CFormFAST : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFAST)

public:
	CFormFAST(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormFAST();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_FAST };

protected:
	COpFAST* m_pFAST;


public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_iThreshold;
	int m_iDetectorType;
	BOOL m_bNonMaximaSupression;
	int m_iBGImageNo;
	int m_iMarkerColorR;
	int m_iMarkerColorG;
	int m_iMarkerColorB;
	int m_iMarkerSize;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
