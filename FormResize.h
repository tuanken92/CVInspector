#pragma once

#include "AllOperations.h"
// CFormResize 대화 상자입니다.

class CFormResize : public CDialogEx
{
	DECLARE_DYNAMIC(CFormResize)

public:
	CFormResize(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormResize();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
