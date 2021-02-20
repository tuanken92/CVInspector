#pragma once

#include "afxwin.h"
#include "Operation.h"

class COpOpenImage : public COperation
{
public:
	COpOpenImage();
	virtual ~COpOpenImage();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	CString m_strFileName;
	int m_iReadType;
};

class COpCaptureCam : public COperation
{
public:
	COpCaptureCam();
	virtual ~COpCaptureCam();

protected:
	VideoCapture m_Camera;
	BOOL m_bOpened;

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iCamNo;
	int m_iImgWidth;
	int m_iImgHeight;
	int m_iGain;
	int m_iExpTime;
};

class COpArithmetic : public COperation
{
public:
	COpArithmetic();
	virtual ~COpArithmetic();

protected:
	BOOL Check2Images(Mat img1, Mat img2);

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iOperatorType;
	double m_dAlpha;
	double m_dBeta;
	double m_dGama;
};

class COpTimeDelay : public COperation
{
public:
	COpTimeDelay();
	virtual ~COpTimeDelay();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iDelayTime;
};

class COpCheckCondition : public COperation
{
public:
	COpCheckCondition();
	virtual ~COpCheckCondition();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	int m_iIterCount;
};