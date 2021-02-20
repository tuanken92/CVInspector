#pragma once

#include "AllOperations.h"
// CFormBlob ��ȭ �����Դϴ�.

class CFormBlob : public CDialogEx
{
	DECLARE_DYNAMIC(CFormBlob)

public:
	CFormBlob(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormBlob();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_BLOB };
protected:
	COpBlob* m_pBlob;
	double m_dThresholdStep;
	double m_dMinThreshold;
	double m_dMaxThreshold;
	int m_iMinRepeatability;
	double m_dMinDistBetweenBlobs;
	BOOL m_bFilterByColor;
	int m_iBlobColor;
	BOOL m_bFilterByArea;
	double m_dMinArea;
	double m_dMaxArea;
	BOOL m_bFilterByCircularity;
	double m_dMinCircularity;
	double m_dMaxCircularity;
	BOOL m_bFilterByInertia;
	double m_dMinInertiaRatio;
	double m_dMaxInertiaRatio;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
