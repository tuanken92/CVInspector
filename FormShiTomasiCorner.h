#pragma once

#include "AllOperations.h"
// CFormShiTomasiCorner 대화 상자입니다.

class CFormShiTomasiCorner : public CDialogEx
{
	DECLARE_DYNAMIC(CFormShiTomasiCorner)

public:
	CFormShiTomasiCorner(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormShiTomasiCorner();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_SHITOMASICORNER };
protected:
	COpShiTomasiCorner* m_pShiTomasiCorner;

	int		m_iMaxCorner;
	double	m_dQualityLevel;
	double	m_dMinDist;
	int		m_iBlockSize;
	BOOL	m_bUseHarris;
	int		m_iMarkerColorR;
	int		m_iMarkerColorG;
	int		m_iMarkerColorB;
	int		m_iMarkerSize;
	int		m_iBGImageNo;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
};
