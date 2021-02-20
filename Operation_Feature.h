#pragma once

#include "afxwin.h"
#include "Operation.h"


class COpCanny : public COperation
{
public:
	COpCanny();
	virtual ~COpCanny();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	double m_dThr1;
	double m_dThr2;
	int m_iApertureSize;
};

class COpContour : public COperation
{
public:
	COpContour();
	virtual ~COpContour();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iMode;
	int m_iMethod;
	int m_iLineWidth;
	int m_iLineType;
	int m_iMaxLevel;
	BOOL m_bConvexHull;
};

class COpBlob : public COperation
{
public:
	COpBlob();
	virtual ~COpBlob();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	float	m_fThresholdStep;
	float	m_fMinThreshold;
	float	m_fMaxThreshold;
	int		m_iMinRepeatability;
	float	m_fMinDistBetweenBlobs;
	BOOL	m_bFilterByColor;
	int		m_iBlobColor;
	BOOL	m_bFilterByArea;
	float	m_fMinArea;
	float	m_fMaxArea;
	BOOL	m_bFilterByCircularity;
	float	m_fMinCircularity;
	float	m_fMaxCircularity;
	BOOL	m_bFilterByInertia;
	float	m_fMinInertiaRatio;
	float	m_fMaxInertiaRatio;
	BOOL	m_bFilterByConvexity;
	float	m_fMinConvexity;
	float	m_fMaxConvexity;
};

class COpHoughLine : public COperation
{
public:
	COpHoughLine();
	virtual ~COpHoughLine();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	double	m_dRho;
	double	m_dTheta;
	int		m_iThreshold;
	double	m_dMinLineLength;
	double	m_dMaxLineGap;
};

class COpHoughCircle : public COperation
{
public:
	COpHoughCircle();
	virtual ~COpHoughCircle();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	double	m_dAccuRes;
	double	m_dMinDist;
	double	m_dParam1;
	double	m_dParam2;
	int		m_iMinRadius;
	int		m_iMaxRadius;
};

class COpHarrisCorner : public COperation
{
public:
	COpHarrisCorner();
	virtual ~COpHarrisCorner();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int		m_iNeighbor;
	int		m_iAperture;
	double	m_dParameterK;
	int		m_iNonMaxSize;
};

class COpShiTomasiCorner : public COperation
{
public:
	COpShiTomasiCorner();
	virtual ~COpShiTomasiCorner();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int		m_iMaxCorners;
	double	m_dQualityLevel;
	double	m_dMinDist;
	int		m_iBlockSize;
	bool	m_bUseHarris;
	double	m_dK;				// free parameter for harris corner

};

class COpFAST : public COperation
{
public:
	COpFAST();
	virtual ~COpFAST();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int		m_iThreshold;
	bool	m_bNonMaximaSupression;
	int		m_iDetectorType;
};