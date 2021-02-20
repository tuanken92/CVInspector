// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원
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


