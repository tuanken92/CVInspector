#pragma once

#include "afxwin.h"
#include "Operation.h"

class COpOffsetTemplate : public COperation
{
public:
	COpOffsetTemplate();
	virtual ~COpOffsetTemplate();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);

	int		m_iMethod;
	double	m_dMatchingScoreThr;

	int		m_iSearchAreaOffset;
	
	int		m_iRefPointX;
	int		m_iRefPointY;

	double	m_dScaleX;
	double	m_dScaleY;
	double	m_dOffsetX;
	double	m_dOffsetY;

	CString	m_strRefFilePath;

	double m_dResultOffsetX;
	double m_dResultOffsetY;

protected:
	Mat		m_TemplateImage;
};