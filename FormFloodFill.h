#pragma once

#include "AllOperations.h"
// CFormFloodFill ��ȭ �����Դϴ�.

class CFormFloodFill : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFloodFill)

public:
	CFormFloodFill(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormFloodFill();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
