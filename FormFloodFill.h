#pragma once

#include "AllOperations.h"
// CFormFloodFill 대화 상자입니다.

class CFormFloodFill : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFloodFill)

public:
	CFormFloodFill(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormFloodFill();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_FLOODFILL };
protected:
	COpFloodFill* m_pFloodfill;
	int m_iUpperDiff;
	int m_iLowerDiff;
	int m_iNeighbor;
	BOOL m_bUseFixedRange;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
