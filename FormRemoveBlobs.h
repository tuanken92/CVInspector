#pragma once

#include "AllOperations.h"
// CFormRemoveBlobs 대화 상자입니다.

class CFormRemoveBlobs : public CDialogEx
{
	DECLARE_DYNAMIC(CFormRemoveBlobs)

public:
	CFormRemoveBlobs(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormRemoveBlobs();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
