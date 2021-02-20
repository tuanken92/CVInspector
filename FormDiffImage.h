#pragma once
#include "AllOperations.h"

// CFormDiffImage dialog

class CFormDiffImage : public CDialogEx
{
	DECLARE_DYNAMIC(CFormDiffImage)

public:
	CFormDiffImage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormDiffImage();

// Dialog Data
	enum { IDD = IDD_FORM_DIFFIMAGE };
protected:
	COpDiffImage* m_pDiffImage;
	int m_iDir;
	int m_iDiffImgType;
	int m_iAnpha;
	int m_iBeta;
	int m_iMinThr;
	int m_iAccum;
public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
