#pragma once

#include "afxwin.h"
#include "Operation.h"

class COpFilter2D : public COperation
{
public:
	COpFilter2D();
	virtual ~COpFilter2D();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	void ParseString(CString strInput);
	int m_iDepth;
	double m_dDelta;
	int m_iBorderType;
	CPoint m_AnchorPos;
	Mat m_Kernel;
	CString m_strKernel;
};

class COpMorphology : public COperation
{
public:
	COpMorphology();
	virtual ~COpMorphology();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iMorphologyType;
	int m_iKernelSizeX;
	int m_iKernelSizeY;
	int m_iIterationNo;
	int m_iShapeStructure;
	CPoint m_AnchorPos;
};

class COpBlur : public COperation
{
public:
	COpBlur();
	virtual ~COpBlur();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iBlurType;
	int m_iKernelX;
	int m_iKernelY;
	CPoint m_AnchorPos;
	double m_dGaussianSigma;
	double m_dBilateralSigmaColor;
	double m_dBilateralSigmaSpace;
};

class COpEdge : public COperation
{
public:
	COpEdge();
	virtual ~COpEdge();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iEdgeType;
	int m_iKernelSize;
	double m_dScale;
	double m_dDelta;
	int m_iDx;
	int m_iDy;
};

class COpFloodFill : public COperation
{
public:
	COpFloodFill();
	virtual ~COpFloodFill();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int		m_iLowerDiff;
	int		m_iUpperDiff;
	int		m_iNeighbor;
	BOOL	m_bUseFixedRange;
};

class COpHistogram : public COperation
{
public:
	COpHistogram();
	virtual ~COpHistogram();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int		m_iHistSize;
	float	m_fHistRangeL;
	float	m_fHistRangeH;
};

class COpEqualHist : public COperation
{
public:
	COpEqualHist();
	virtual ~COpEqualHist();

protected:

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
};

class COpMatchTemplate : public COperation
{
public:
	COpMatchTemplate();
	virtual ~COpMatchTemplate();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iMethod;
	int m_iTemplateImageNo;
};

class COpPSM : public COperation
{
public:
	COpPSM();
	virtual ~COpPSM();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iSubtractType;	// 0 : Subtract, 1 : abs diff, 2 : Xor
	int m_iDir;
	int m_iXOffset;
	int m_iYOffset;
};

class COpRemoveBlobs : public COperation
{
public:
	COpRemoveBlobs();
	virtual ~COpRemoveBlobs();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iMinArea;
	int m_iMaxArea;
	int m_iMinWidth;
	int m_iMinHeight;
	int m_iMaxWidth;
	int m_iMaxHeight;
};

class COpMarkedAgv : public COperation
{
public:
	COpMarkedAgv();
	virtual ~COpMarkedAgv();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iKernelX;
	int m_iKernelY;
	int m_iMarkImgNo;
};

class COpMarkedAdaptiveThreshold : public COperation
{
public:
	COpMarkedAdaptiveThreshold();
	virtual ~COpMarkedAdaptiveThreshold();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iKernelX;
	int m_iKernelY;
	int m_iCValue;
	int m_Type;
	int m_iMarkImgNo;
};

class COpDiffImage : public COperation
{
public:
	COpDiffImage();
	virtual ~COpDiffImage();
protected:
	uchar GetPixel(cv::Mat & srcImg, cv::Point pt);
	void SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value);
	
public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iDir;
	int m_iDiffImgType;
	int m_iAnpha;
	int m_iBeta;
	int m_iMinThr;
	int m_iAccum;
};