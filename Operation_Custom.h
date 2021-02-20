#pragma once

#include "afxwin.h"
#include "Operation.h"

class COpCustomFunc1 : public COperation
{
public:
	COpCustomFunc1();
	virtual ~COpCustomFunc1();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	
};

class COpCustomFunc2 : public COperation
{
public:
	COpCustomFunc2();
	virtual ~COpCustomFunc2();

public:
	virtual BOOL Process(COperation* pPrevOp, COperation* pPrevOp2 = NULL);
	BOOL Process2(COperation* pPrevOp, COperation* pPrevOp2 = NULL);

};