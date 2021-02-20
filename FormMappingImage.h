#pragma once
#include "AllOperations.h"
#include "afxwin.h"

// CFormMappingImage dialog

class CFormMappingImage : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMappingImage)

public:
	CFormMappingImage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormMappingImage();

// Dialog Data
	enum { IDD = IDD_FORM_MAPPING_IMG };

protected:
	COpMappingImage* m_pMappingImage;
	int m_iDir;
	int m_iDist;
	double m_dThr;
	double m_dAlpha;
	double m_dBeta;
	CComboBox m_combo_light;
	CString m_combo_str;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	

	
	
	virtual BOOL OnInitDialog();
};
