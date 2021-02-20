#pragma once

#include "AllOperations.h"
// CFormHarrisCorner 대화 상자입니다.

class CFormHarrisCorner : public CDialogEx
{
	DECLARE_DYNAMIC(CFormHarrisCorner)

public:
	CFormHarrisCorner(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormHarrisCorner();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_HARRISCORNER };
protected:
	COpHarrisCorner* m_pHarrisCorner;
	int m_iNeighbor;
	int m_iAperture;
	double m_dParameterK;
	int m_iNonMaxSize;

	int m_iMarkerColorR;
	int m_iMarkerColorG;
	int m_iMarkerColorB;
	int m_iMarkerSize;
	int m_iBGImageNo;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
