#pragma once


// CFormNA ��ȭ �����Դϴ�.

class CFormNA : public CDialogEx
{
	DECLARE_DYNAMIC(CFormNA)

public:
	CFormNA(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormNA();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_NA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
