#pragma once

#include "AllOperations.h"
// CFormShiTomasiCorner ��ȭ �����Դϴ�.

class CFormShiTomasiCorner : public CDialogEx
{
	DECLARE_DYNAMIC(CFormShiTomasiCorner)

public:
	CFormShiTomasiCorner(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormShiTomasiCorner();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
};
