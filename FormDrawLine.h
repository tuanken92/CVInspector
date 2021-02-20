#pragma once


// CFormDrawLine dialog

class CFormDrawLine : public CDialogEx
{
	DECLARE_DYNAMIC(CFormDrawLine)

public:
	CFormDrawLine(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormDrawLine();

// Dialog Data
	enum { IDD = IDD_FORM_DRAW_LINE };
protected:
	int m_iStartX;
	int m_iStartY;
	int m_iEndX;
	int m_iEndY;
	int m_iWidth;
	int m_iB, m_iG, m_iR;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
};
