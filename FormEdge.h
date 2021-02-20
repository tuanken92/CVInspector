#pragma once

#include "AllOperations.h"
// CFormEdge 대화 상자입니다.

class CFormEdge : public CDialogEx
{
	DECLARE_DYNAMIC(CFormEdge)

public:
	CFormEdge(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormEdge();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
