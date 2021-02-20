#pragma once

#include "AllOperations.h"
// CFormContour 대화 상자입니다.

class CFormContour : public CDialogEx
{
	DECLARE_DYNAMIC(CFormContour)

public:
	CFormContour(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormContour();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_CONTOUR };
protected:
	COpContour* m_pContour;
	int m_iMode;
	int m_iMethod;
	int m_iLineWidth;
	int m_iLineType;
	int m_iMaxValue;
	int m_iBGImageNo;
	BOOL m_bUseConvexHull;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
	
};
