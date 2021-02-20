#pragma once


// CFormNA 대화 상자입니다.

class CFormNA : public CDialogEx
{
	DECLARE_DYNAMIC(CFormNA)

public:
	CFormNA(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormNA();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORM_NA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
