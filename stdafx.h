// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ����Դϴ�.
#include <afxext.h>         // MFC Ȯ���Դϴ�.


#include <afxdisp.h>        // MFC �ڵ�ȭ Ŭ�����Դϴ�.



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC�� ���� �� ��Ʈ�� ���� ����
#include <afx.h>

#define		OP_NA					0
#define		OP_OPENIMAGE			101
#define		OP_CAPTURECAM			102
#define		OP_ARITHMETIC			110
#define		OP_CVTCOLOR				201
#define		OP_FLIP					202
#define		OP_ROTATE				203
#define		OP_BINARIZE				204
#define		OP_RESIZE				205
#define		OP_CROP					206
#define		OP_SPLIT				207
#define		OP_PYRAMID				208
#define		OP_DFT					209
#define		OP_ADAPTIVETHRESHOLD	210
#define     OP_JPTHRESHOLD			211
#define     OP_JPTHRESHOLDAUTO		212
#define		OP_ADAPTIVETHRESHOLDISH 213
#define		OP_MAPPINGIMAGE			214
#define		OP_DISTANCETRANSFORM	215
#define		OP_WARTERSHED			216
#define		OP_CONTRAST				217
#define     OP_FARSHIDTHR			218

#define		OP_FILTER2D				301
#define		OP_MORPHOLOGY			302
#define		OP_BLUR					303
#define		OP_EDGE					304
#define		OP_FLOODFILL			305
#define		OP_HISTOGRAM			306
#define		OP_EQUALHIST			307
#define		OP_MATCHTEMPLATE		308
#define		OP_PSM					309
#define		OP_REMOVEBLOBS			310
#define     OP_MARKED_AVG           311
#define     OP_MARKEDADAPTHRESOLD   312
#define     OP_DIFFIMAGE			313

#define		OP_CANNY				401
#define		OP_CONTOUR				402
#define		OP_BLOB					403
#define		OP_HOUGHLINE			404
#define		OP_HOUGHCIRCLE			405
#define		OP_HARRISCORNER			406
#define		OP_SHITOMASICORNER		407
#define		OP_FAST					408

#define		OP_TIMEDELAY			501
#define		OP_SERIAL				502
#define		OP_DIO					503
#define		OP_CHECKCONDITION		504

#define		OP_OFFSETTEMPLATE		603

#define		OP_CUSTOMFUNC1			701
#define		OP_CUSTOMFUNC2			702

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


