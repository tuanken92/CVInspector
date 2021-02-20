#pragma once

#include "AllOperations.h"
// CFormMorphology 대화 상자입니다.

class CFormMorphology : public CDialogEx
{
	DECLARE_DYNAMIC(CFormMorphology)

public:
	CFormMorphology(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFormMorphology();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_iComboShapeStructure;
};
