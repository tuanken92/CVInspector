#pragma once

#include "afxwin.h"
#include "Operation.h"

class COpCvtColor : public COperation
{
public:
	COpCvtColor();
	virtual ~COpCvtColor();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iConvertType;
};

class COpFlip : public COperation
{
public:
	COpFlip();
	virtual ~COpFlip();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iFlipCode;
};

class COpRotate : public COperation
{
public:
	COpRotate();
	virtual ~COpRotate();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	double m_dAngle;
};

class COpBinarize : public COperation
{
public:
	COpBinarize();
	virtual ~COpBinarize();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iBinarizeType;
	double m_dThr;
	BOOL m_bUseOtsu;
};

class COpJPThreshold : public COperation
{
public:
	COpJPThreshold();
	virtual ~COpJPThreshold();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iThrUpper;
	int m_iThrLower;
	int m_iTypeThr;
};

class COpJPThresholdAuto : public COperation
{
public:
	COpJPThresholdAuto();
	virtual ~COpJPThresholdAuto();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iDir;
	int m_iStdDev;
};

class COpResize : public COperation
{
public:
	COpResize();
	virtual ~COpResize();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iInterpolationType;
	int m_iNewSizeX;
	int m_iNewSizeY;
	double m_dNewRatioX;
	double m_dNewRatioY;
};

class COpCrop : public COperation
{
public:
	COpCrop();
	virtual ~COpCrop();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	CRect m_CropRect;
};

class COpSplit : public COperation
{
public:
	COpSplit();
	virtual ~COpSplit();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iTargetChannel;
};

class COpPyramid : public COperation
{
public:
	COpPyramid();
	virtual ~COpPyramid();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	BOOL m_bDownOrUp;	// true down, false up
	int m_iSizeX;
	int m_iSizeY;
};

class COpDFT : public COperation
{
public:
	COpDFT();
	virtual ~COpDFT();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	BOOL m_bInverse;	// inverse
};

class COpAdaptiveThreshold : public COperation
{
public:
	COpAdaptiveThreshold();
	virtual ~COpAdaptiveThreshold();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	double	m_dMaxValue;
	int		m_iAdaptiveMethod;
	int		m_iThresholdType;
	int		m_iBlockSize;
	double	m_dConstant;
};

class COpAdaptiveThresholdISH : public COperation
{
public:
	COpAdaptiveThresholdISH();
	virtual ~COpAdaptiveThresholdISH();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int		m_iThr;;
	int		m_iBlockSize;
	double	m_dOffset;
	double	m_dScale;
};


class COpMappingImage : public COperation
{
public:
	COpMappingImage();
	virtual ~COpMappingImage();

protected:
	uchar GetPixel(cv::Mat & srcImg, cv::Point pt);
	void SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value);

	void MakeMapImgX_Dark(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta);
	void MakeMapImgX_Bright(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta);
	void MakeMapImgY_Dark(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta);
	void MakeMapImgY_Bright(cv::Mat & srcImg, cv::Mat & mapImg, int iDist, double dThr, double alpha, double beta);

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iDir;
	int m_iDist;
	double m_dThr;
	double m_dAlpha;
	double m_dBeta;

	CString m_strComboLight;

};

class COpDistance : public COperation
{
public:
	COpDistance();
	virtual ~COpDistance();

protected:
	uchar GetPixel(cv::Mat & srcImg, cv::Point pt);
	void SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value);

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iMarkSize;
	int m_iDistanceType;
};

class COpWatershed : public COperation
{
public:
	COpWatershed();
	virtual ~COpWatershed();

protected:
	uchar GetPixel(cv::Mat & srcImg, cv::Point pt);
	void SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value);

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iMarkImgNo;
};

class COpContrast: public COperation
{
public:
	COpContrast();
	virtual ~COpContrast();

protected:
	uchar GetPixel(cv::Mat & srcImg, cv::Point pt);
	void SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value);

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iAlpha;
	int m_iBeta;
};

class COpFarshidThr: public COperation
{
public:
	COpFarshidThr();
	virtual ~COpFarshidThr();

protected:
	//uchar GetPixel(cv::Mat & srcImg, cv::Point pt);
	//void SetPixel(cv::Mat & srcImg, cv::Point pt, uchar value);

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	//int m_iAlpha;
	//int m_iBeta;
};