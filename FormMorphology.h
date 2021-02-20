#pragma once

#include "AllOperations.h"
// CFormMorphology ��ȭ �����Դϴ�.

class CFormMorphology : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMorphology)

public:
	CFormMorphology(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFormMorphology();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FORM_MORPHOLOGY };
protected:
	COpMorphology* m_pMorphology;
	int m_iMorphType;
	int m_iKernelSizeX;
	int m_iKernelSizeY;
	int m_iAnchorX;
	int m_iAnchorY;
	int m_iIterNo;

public:
	void SetOperation(COperation* pOperation);
	void ApplyChanges();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_iComboShapeStructure;
};
