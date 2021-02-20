#pragma once

#include "AllOperations.h"
// CFormCaptureCam ��ȭ �����Դϴ�.

class CFormCaptureCam : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCaptureCam)

public:
	CFormCaptureCam(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormCaptureCam();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_CAPTURECAM };
protected:
	COpCaptureCam *m_pCaptureCam;
	int m_iCamNo;
	int m_iImgWidth;
	int m_iImgHeight;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
