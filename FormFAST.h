#pragma once

#include "AllOperations.h"
// CFormFAST 대화 상자입니다.

class CFormFAST : public CDialogEx
{
	DECLARE_DYNAMIC(CFormFAST)

public:
	CFormFAST(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormFAST();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_FAST };

protected:
	COpFAST* m_pFAST;


public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
