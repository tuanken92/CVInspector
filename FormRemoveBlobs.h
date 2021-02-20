#pragma once

#include "AllOperations.h"
// CFormRemoveBlobs ��ȭ �����Դϴ�.

class CFormRemoveBlobs : public CDialogEx
{
	DECLARE_DYNAMIC(CFormRemoveBlobs)

public:
	CFormRemoveBlobs(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormRemoveBlobs();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_REMOVEBLOBS };
protected:
	COpRemoveBlobs* m_pRemoveBlobs;
	int m_iMinArea;
	int m_iMaxArea;
	int m_iMinWidth;
	int m_iMinHeight;
	int m_iMaxWidth;
	int m_iMaxHeight;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
