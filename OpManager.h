#pragma once

#include "AllOperations.h"
typedef CTypedPtrArray<CObArray, COperation*> OpArray;
// COpManager 명령 대상입니다.

class COpManager : public CObject
{
public:
	COpManager();
	virtual ~COpManager();

	CString GetFilePath();
	void SetFilePath(CString strFilePath);

	int GetCount();
	COperation* GetOperation(int iOpNo);
	void AddOperation(COperation* pOp, int iInsertAt = -1);
	void RemoveOperation(int iRemoveAt = -1);

	BOOL SaveToFile(CString strFileName);
	BOOL LoadFromFile(CString strFileName);

	void ClearAll();

protected:
	OpArray	m_OpArray;
	CString m_strFilePath;
};


