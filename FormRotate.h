#pragma once

#include "AllOperations.h"
// CFormRotate 대화 상자입니다.

class CFormRotate : public CDialogEx
{
	DECLARE_DYNAMIC(CFormRotate)

public:
	CFormRotate(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormRotate();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_ROTATE };
protected:
	COpRotate* m_pRotate;
	double m_dAngle;
	
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
