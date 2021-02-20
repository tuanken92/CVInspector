#pragma once

#include "AllOperations.h"
// CFormCaptureCam 대화 상자입니다.

class CFormCaptureCam : public CDialogEx
{
	DECLARE_DYNAMIC(CFormCaptureCam)

public:
	CFormCaptureCam(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormCaptureCam();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
