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

// CVInspectorView.cpp : CCVInspectorView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CVInspector.h"
#endif

#include "CVInspectorDoc.h"
#include "CVInspectorView.h"

#include "ParameterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCVInspectorView

IMPLEMENT_DYNCREATE(CCVInspectorView, CFormView)

BEGIN_MESSAGE_MAP(CCVInspectorView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_OPEN, &CCVInspectorView::OnFileOpen)
	ON_COMMAND(ID_CONVERT_COLOR, &CCVInspectorView::OnConvertColor)
	ON_LBN_SELCHANGE(IDC_OP_LIST, &CCVInspectorView::OnLbnSelchangeOpList)	
	ON_BN_CLICKED(IDC_BUTTON_APPLY, &CCVInspectorView::OnBnClickedButtonApply)
	ON_COMMAND(ID_BINARIZE, &CCVInspectorView::OnBinarize)
	ON_COMMAND(ID_ARITHMETIC, &CCVInspectorView::OnArithmetic)
	ON_COMMAND(ID_MORPHOLOGY, &CCVInspectorView::OnMorphology)
	ON_COMMAND(ID_BLUR, &CCVInspectorView::OnBlur)
	ON_COMMAND(ID_RESIZE, &CCVInspectorView::OnResize)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CURRENT_IMAGE, &CCVInspectorView::OnBnClickedButtonSaveCurrentImage)
	ON_COMMAND(ID_FILE_SAVE_AS, &CCVInspectorView::OnFileSaveAs)
	ON_COMMAND(ID_OPENIMAGEFILE, &CCVInspectorView::OnOpenimagefile)
	ON_COMMAND(ID_FILE_SAVE, &CCVInspectorView::OnFileSave)
	ON_COMMAND(ID_EDGE, &CCVInspectorView::OnEdge)
	ON_COMMAND(ID_CANNY, &CCVInspectorView::OnCanny)
	ON_COMMAND(ID_CROP, &CCVInspectorView::OnCrop)
	ON_BN_CLICKED(IDC_BUTTON_PROCESS_ALL, &CCVInspectorView::OnBnClickedButtonProcessAll)
	ON_COMMAND(ID_SPLIT, &CCVInspectorView::OnSplit)
	ON_COMMAND(ID_CONTOUR, &CCVInspectorView::OnContour)
	ON_COMMAND(ID_CAPTURE_CAM, &CCVInspectorView::OnCaptureCam)
	ON_COMMAND(ID_FLOODFILL, &CCVInspectorView::OnFloodfill)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_SELECTED_OP, &CCVInspectorView::OnBnClickedButtonDeleteSelectedOp)
	ON_COMMAND(ID_PYRAMID, &CCVInspectorView::OnPyramid)
	ON_COMMAND(ID_BLOB, &CCVInspectorView::OnBlob)
	ON_COMMAND(ID_HISTOGRAM, &CCVInspectorView::OnHistogram)
	ON_COMMAND(ID_EQUAL_HIST, &CCVInspectorView::OnEqualHist)
	ON_COMMAND(ID_HOUGH_LINE, &CCVInspectorView::OnHoughLine)
	ON_COMMAND(ID_HOUGH_CIRCLE, &CCVInspectorView::OnHoughCircle)
	ON_COMMAND(ID_HARRIS_CORNER, &CCVInspectorView::OnHarrisCorner)
	ON_COMMAND(ID_DFT, &CCVInspectorView::OnDft)
	ON_COMMAND(ID_MATCH_TEMPLATE, &CCVInspectorView::OnMatchTemplate)
	ON_COMMAND(ID_PATTERN_SHIFT, &CCVInspectorView::OnPatternShift)
	ON_COMMAND(ID_ADAPTIVE_THRESHOLD, &CCVInspectorView::OnAdaptiveThreshold)
	ON_COMMAND(ID_FILE_NEW, &CCVInspectorView::OnFileNew)
	ON_COMMAND(ID_REMOVE_BLOBS, &CCVInspectorView::OnRemoveBlobs)
	ON_COMMAND(ID_TIME_DELAY, &CCVInspectorView::OnTimeDelay)
	ON_COMMAND(ID_FLIP, &CCVInspectorView::OnFlip)
	ON_COMMAND(ID_SHITOMASI_CORNER, &CCVInspectorView::OnShitomasiCorner)
	ON_COMMAND(ID_ROTATE, &CCVInspectorView::OnRotate)
	ON_COMMAND(ID_FILTER, &CCVInspectorView::OnFilter)
	ON_COMMAND(ID_OFFSET_TEMPLATE, &CCVInspectorView::OnOffsetTemplate)
	ON_COMMAND(ID_FUNC1, &CCVInspectorView::OnFunc1)
	ON_COMMAND(ID_FUNC2, &CCVInspectorView::OnFunc2)
	ON_COMMAND(ID_FAST, &CCVInspectorView::OnFast)
	ON_COMMAND(ID_MARKED_AVG, &CCVInspectorView::OnMarkedAvg)
	ON_COMMAND(ID_MARKED_ADAP_THR, &CCVInspectorView::OnMarkedAdaptiveThreshold)
	ON_COMMAND(ID_JPTHRESHOLD, &CCVInspectorView::OnJpthreshold)
	ON_COMMAND(ID_DIFFIMAGE, &CCVInspectorView::OnDiffimage)
	ON_COMMAND(ID_JPTHRESAUTO, &CCVInspectorView::OnJpthresauto)
	ON_COMMAND(ID_DRAW_LINE, &CCVInspectorView::OnDrawLine)
	ON_COMMAND(ID_ADAPTIVETHR_ISH, &CCVInspectorView::OnAdaptivethrIsh)
	ON_COMMAND(ID_MAPPING_IMAGE, &CCVInspectorView::OnMappingImage)
	ON_COMMAND(ID_DISTANCETRANSFORM, &CCVInspectorView::OnDistancetransform)
	ON_COMMAND(ID_WATERSHED, &CCVInspectorView::OnWatershed)
	ON_COMMAND(ID_CONTRAST, &CCVInspectorView::OnContrast)
	ON_COMMAND(ID_FARSHID, &CCVInspectorView::OnFarshidThr)
END_MESSAGE_MAP()

// CCVInspectorView 생성/소멸

CCVInspectorView::CCVInspectorView()
	: CFormView(CCVInspectorView::IDD)
	, m_iInputImgNo(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bFormInit = FALSE;
}

CCVInspectorView::~CCVInspectorView()
{
	
}

void CCVInspectorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGEPANEL, m_ImagePanel);
	DDX_Control(pDX, IDC_PARAMETER_PANEL, m_ctrlParamerPanel);
	DDX_Control(pDX, IDC_OP_LIST, m_ctrlOpList);
	DDX_Text(pDX, IDC_INPUT_IMG_NO, m_iInputImgNo);
}

BOOL CCVInspectorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CCVInspectorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	if (!m_bFormInit)	// OnNewDocument 호출 시 이부분이 재호출되므로 한 번만 실행되게 Flag 처리
	{
		CRect rect;
		m_ctrlParamerPanel.GetWindowRect(rect);
		ScreenToClient(rect);

		m_NAForm.Create(IDD_FORM_NA, this);
		m_NAForm.MoveWindow(rect);
		m_NAForm.ShowWindow(SW_SHOW);

		m_ArithmeticForm.Create(IDD_FORM_ARITHMETIC, this);
		m_ArithmeticForm.MoveWindow(rect);
		m_ArithmeticForm.ShowWindow(SW_HIDE);

		m_FileOpenForm.Create(IDD_FORM_OPENFILE, this);
		m_FileOpenForm.MoveWindow(rect);
		m_FileOpenForm.ShowWindow(SW_HIDE);

		m_CaptureCamForm.Create(IDD_FORM_CAPTURECAM, this);
		m_CaptureCamForm.MoveWindow(rect);
		m_CaptureCamForm.ShowWindow(SW_HIDE);

		m_CvtColorForm.Create(IDD_FORM_CVTCOLOR, this);
		m_CvtColorForm.MoveWindow(rect);
		m_CvtColorForm.ShowWindow(SW_HIDE);

		m_FlipForm.Create(IDD_FORM_FLIP, this);
		m_FlipForm.MoveWindow(rect);
		m_FlipForm.ShowWindow(SW_HIDE);

		m_RotateForm.Create(IDD_FORM_ROTATE, this);
		m_RotateForm.MoveWindow(rect);
		m_RotateForm.ShowWindow(SW_HIDE);

		m_BinarizeForm.Create(IDD_FORM_BINARIZE, this);
		m_BinarizeForm.MoveWindow(rect);
		m_BinarizeForm.ShowWindow(SW_HIDE);

		m_JPThresholdForm.Create(IDD_FORM_JPTHRESHOLD, this);
		m_JPThresholdForm.MoveWindow(rect);
		m_JPThresholdForm.ShowWindow(SW_HIDE);

		m_JPThresholdAutoForm.Create(IDD_FORM_JPTHRESHOLD_AUTO, this);
		m_JPThresholdAutoForm.MoveWindow(rect);
		m_JPThresholdAutoForm.ShowWindow(SW_HIDE);

		m_MappingImageForm.Create(IDD_FORM_MAPPING_IMG, this);
		m_MappingImageForm.MoveWindow(rect);
		m_MappingImageForm.ShowWindow(SW_HIDE);

		m_ResizeForm.Create(IDD_FORM_RESIZE, this);
		m_ResizeForm.MoveWindow(rect);
		m_ResizeForm.ShowWindow(SW_HIDE);

		m_CropForm.Create(IDD_FORM_CROP, this);
		m_CropForm.MoveWindow(rect);
		m_CropForm.ShowWindow(SW_HIDE);

		m_SplitForm.Create(IDD_FORM_SPLIT, this);
		m_SplitForm.MoveWindow(rect);
		m_SplitForm.ShowWindow(SW_HIDE);

		m_PyramidForm.Create(IDD_FORM_PYRAMID, this);
		m_PyramidForm.MoveWindow(rect);
		m_PyramidForm.ShowWindow(SW_HIDE);

		m_DFTForm.Create(IDD_FORM_DFT, this);
		m_DFTForm.MoveWindow(rect);
		m_DFTForm.ShowWindow(SW_HIDE);

		m_AdaptiveThrForm.Create(IDD_FORM_ADAPTIVETHR, this);
		m_AdaptiveThrForm.MoveWindow(rect);
		m_AdaptiveThrForm.ShowWindow(SW_HIDE);

		m_AdaptiveThrISHForm.Create(IDD_FORM_ADAPTIVETHR_ISH, this);
		m_AdaptiveThrISHForm.MoveWindow(rect);
		m_AdaptiveThrISHForm.ShowWindow(SW_HIDE);

		m_Filter2DForm.Create(IDD_FORM_FILTER2D, this);
		m_Filter2DForm.MoveWindow(rect);
		m_Filter2DForm.ShowWindow(SW_HIDE);

		m_MorphologyForm.Create(IDD_FORM_MORPHOLOGY, this);
		m_MorphologyForm.MoveWindow(rect);
		m_MorphologyForm.ShowWindow(SW_HIDE);
		
		m_BlurForm.Create(IDD_FORM_BLUR, this);
		m_BlurForm.MoveWindow(rect);
		m_BlurForm.ShowWindow(SW_HIDE);

		m_EdgeForm.Create(IDD_FORM_EDGE, this);
		m_EdgeForm.MoveWindow(rect);
		m_EdgeForm.ShowWindow(SW_HIDE);

		m_FloodFillForm.Create(IDD_FORM_FLOODFILL, this);
		m_FloodFillForm.MoveWindow(rect);
		m_FloodFillForm.ShowWindow(SW_HIDE);

		m_DistanceForm.Create(IDD_FORM_DISTANCE, this);
		m_DistanceForm.MoveWindow(rect);
		m_DistanceForm.ShowWindow(SW_HIDE);

		m_HistogramForm.Create(IDD_FORM_HISTOGRAM, this);
		m_HistogramForm.MoveWindow(rect);
		m_HistogramForm.ShowWindow(SW_HIDE);

		m_EqualHistForm.Create(IDD_FORM_EQUALHIST, this);
		m_EqualHistForm.MoveWindow(rect);
		m_EqualHistForm.ShowWindow(SW_HIDE);

		m_MatchTemplateForm.Create(IDD_FORM_MATCHTEMPLATE, this);
		m_MatchTemplateForm.MoveWindow(rect);
		m_MatchTemplateForm.ShowWindow(SW_HIDE);

		m_PSMForm.Create(IDD_FORM_PSM, this);
		m_PSMForm.MoveWindow(rect);
		m_PSMForm.ShowWindow(SW_HIDE);

		m_RemoveBlobsForm.Create(IDD_FORM_REMOVEBLOBS, this);
		m_RemoveBlobsForm.MoveWindow(rect);
		m_RemoveBlobsForm.ShowWindow(SW_HIDE);

		m_MarkedAverageForm.Create(IDD_FORM_MARKED_AVG, this);
		m_MarkedAverageForm.MoveWindow(rect);
		m_MarkedAverageForm.ShowWindow(SW_HIDE);

		m_MarkedAdaptiveThresholdForm.Create(IDD_FORM_MARKED_ADAP_THRESHOLD, this);
		m_MarkedAdaptiveThresholdForm.MoveWindow(rect);
		m_MarkedAdaptiveThresholdForm.ShowWindow(SW_HIDE);

		m_DiffImageForm.Create(IDD_FORM_DIFFIMAGE, this);
		m_DiffImageForm.MoveWindow(rect);
		m_DiffImageForm.ShowWindow(SW_HIDE);

		m_CannyForm.Create(IDD_FORM_CANNY, this);
		m_CannyForm.MoveWindow(rect);
		m_CannyForm.ShowWindow(SW_HIDE);

		m_ContourForm.Create(IDD_FORM_CONTOUR, this);
		m_ContourForm.MoveWindow(rect);
		m_ContourForm.ShowWindow(SW_HIDE);

		m_BlobForm.Create(IDD_FORM_BLOB, this);
		m_BlobForm.MoveWindow(rect);
		m_BlobForm.ShowWindow(SW_HIDE);

		m_HoughLineForm.Create(IDD_FORM_HOUGHLINE, this);
		m_HoughLineForm.MoveWindow(rect);
		m_HoughLineForm.ShowWindow(SW_HIDE);

		m_HoughCircleForm.Create(IDD_FORM_HOUGHCIRCLE, this);
		m_HoughCircleForm.MoveWindow(rect);
		m_HoughCircleForm.ShowWindow(SW_HIDE);

		m_HarrisCornerForm.Create(IDD_FORM_HARRISCORNER, this);
		m_HarrisCornerForm.MoveWindow(rect);
		m_HarrisCornerForm.ShowWindow(SW_HIDE);

		m_ShiTomasiCornerForm.Create(IDD_FORM_SHITOMASICORNER, this);
		m_ShiTomasiCornerForm.MoveWindow(rect);
		m_ShiTomasiCornerForm.ShowWindow(SW_HIDE);

		m_FASTForm.Create(IDD_FORM_FAST, this);
		m_FASTForm.MoveWindow(rect);
		m_FASTForm.ShowWindow(SW_HIDE);

		m_TimeDelayForm.Create(IDD_FORM_TIMEDELAY, this);
		m_TimeDelayForm.MoveWindow(rect);
		m_TimeDelayForm.ShowWindow(SW_HIDE);

		m_MeasureTemplateOffset.Create(IDD_FORM_OFFSETTEMPLATE, this);
		m_MeasureTemplateOffset.MoveWindow(rect);
		m_MeasureTemplateOffset.ShowWindow(SW_HIDE);

		m_Contrast.Create(IDD_FORM_CONTRAST, this);
		m_Contrast.MoveWindow(rect);
		m_Contrast.ShowWindow(SW_HIDE);

		m_Watershed.Create(IDD_FORM_WATERSHED, this);
		m_Watershed.MoveWindow(rect);
		m_Watershed.ShowWindow(SW_HIDE);

		m_FarshidThr.Create(IDD_FORM_FARSHIDTHR, this);
		m_FarshidThr.MoveWindow(rect);
		m_FarshidThr.ShowWindow(SW_HIDE);

		SaveControlInitialPos();
		m_bFormInit = TRUE;
	}

	// Rect tracker
	cv::Rect m_ROI = cv::Rect(0, 0, 100, 100);
	CRect roiRect = cvRect2CRect(m_ROI);

	m_ImagePanel.SetRectTrackerImage(roiRect);
	m_ImagePanel.SetUseRectTracker(FALSE);
	m_ImagePanel.UpdateDisplay();

	// Image Panel의 속성 설정
	m_ImagePanel.SetROIShow(TRUE);

	//this->ShowWindow(WS_MAXIMIZE);
}

void CCVInspectorView::ChangeForm(COperation* pOp)
{
	int iFormID;

	if (NULL == pOp)
	{
		iFormID = OP_NA;
	}
	else
	{
		iFormID = pOp->GetTypeID();
	}

	m_NAForm.ShowWindow(SW_HIDE);
	m_ArithmeticForm.ShowWindow(SW_HIDE);
	m_FileOpenForm.ShowWindow(SW_HIDE);
	m_CaptureCamForm.ShowWindow(SW_HIDE);
	m_CvtColorForm.ShowWindow(SW_HIDE);
	m_FlipForm.ShowWindow(SW_HIDE);
	m_RotateForm.ShowWindow(SW_HIDE);
	m_BinarizeForm.ShowWindow(SW_HIDE);
	m_JPThresholdForm.ShowWindow(SW_HIDE);
	m_JPThresholdAutoForm.ShowWindow(SW_HIDE);
	m_MappingImageForm.ShowWindow(SW_HIDE);
	m_ResizeForm.ShowWindow(SW_HIDE);
	m_CropForm.ShowWindow(SW_HIDE);
	m_SplitForm.ShowWindow(SW_HIDE);
	m_PyramidForm.ShowWindow(SW_HIDE);
	m_DFTForm.ShowWindow(SW_HIDE);
	m_AdaptiveThrForm.ShowWindow(SW_HIDE);
	m_AdaptiveThrISHForm.ShowWindow(SW_HIDE);
	m_Filter2DForm.ShowWindow(SW_HIDE);
	m_MorphologyForm.ShowWindow(SW_HIDE);	
	m_BlurForm.ShowWindow(SW_HIDE);
	m_EdgeForm.ShowWindow(SW_HIDE);
	m_FloodFillForm.ShowWindow(SW_HIDE);
	m_DistanceForm.ShowWindow(SW_HIDE);
	m_HistogramForm.ShowWindow(SW_HIDE);
	m_EqualHistForm.ShowWindow(SW_HIDE);
	m_MatchTemplateForm.ShowWindow(SW_HIDE);
	m_PSMForm.ShowWindow(SW_HIDE);
	m_MarkedAverageForm.ShowWindow(SW_HIDE);
	m_MarkedAdaptiveThresholdForm.ShowWindow(SW_HIDE);
	m_DiffImageForm.ShowWindow(SW_HIDE);
	m_RemoveBlobsForm.ShowWindow(SW_HIDE);
	m_CannyForm.ShowWindow(SW_HIDE);
	m_ContourForm.ShowWindow(SW_HIDE);
	m_BlobForm.ShowWindow(SW_HIDE);
	m_HoughLineForm.ShowWindow(SW_HIDE);
	m_HoughCircleForm.ShowWindow(SW_HIDE);
	m_HarrisCornerForm.ShowWindow(SW_HIDE);
	m_ShiTomasiCornerForm.ShowWindow(SW_HIDE);
	m_FASTForm.ShowWindow(SW_HIDE);
	m_TimeDelayForm.ShowWindow(SW_HIDE);
	m_MeasureTemplateOffset.ShowWindow(SW_HIDE);
	m_Contrast.ShowWindow(SW_HIDE);
	m_Watershed.ShowWindow(SW_HIDE);
	m_FarshidThr.ShowWindow(SW_HIDE);

	switch (iFormID)
	{
	case OP_NA:// No Operation
		m_NAForm.ShowWindow(SW_SHOW);
		break;	

	case OP_OPENIMAGE:	// File Open Form
		m_FileOpenForm.SetOperation(pOp);
		m_FileOpenForm.ShowWindow(SW_SHOW);
		break;

	case OP_CAPTURECAM:	// Capture from Camera Form
		m_CaptureCamForm.SetOperation(pOp);
		m_CaptureCamForm.ShowWindow(SW_SHOW);
		break;

	case OP_ARITHMETIC:// Simple Arithmatic Form
		m_ArithmeticForm.SetOperation(pOp);
		m_ArithmeticForm.ShowWindow(SW_SHOW);
		break;

	case OP_CVTCOLOR:	// Convert Color Form
		m_CvtColorForm.SetOperation(pOp);
		m_CvtColorForm.ShowWindow(SW_SHOW);		
		break;

	case OP_FLIP:
		m_FlipForm.SetOperation(pOp);
		m_FlipForm.ShowWindow(SW_SHOW);
		break;

	case OP_ROTATE:
		m_RotateForm.SetOperation(pOp);
		m_RotateForm.ShowWindow(SW_SHOW);
		break;

	case OP_BINARIZE:
		m_BinarizeForm.SetOperation(pOp);
		m_BinarizeForm.ShowWindow(SW_SHOW);
		break;

	case OP_JPTHRESHOLD:
		m_JPThresholdForm.SetOperation(pOp);
		m_JPThresholdForm.ShowWindow(SW_SHOW);
		break;

	case OP_JPTHRESHOLDAUTO:
		m_JPThresholdAutoForm.SetOperation(pOp);
		m_JPThresholdAutoForm.ShowWindow(SW_SHOW);
		break;

	case OP_MAPPINGIMAGE:
		m_MappingImageForm.SetOperation(pOp);
		m_MappingImageForm.ShowWindow(SW_SHOW);
		break;

	case OP_RESIZE:
		m_ResizeForm.SetOperation(pOp);
		m_ResizeForm.ShowWindow(SW_SHOW);
		break;

	case OP_CROP:
		m_CropForm.SetOperation(pOp);
		m_CropForm.ShowWindow(SW_SHOW);
		break;

	case OP_SPLIT:
		m_SplitForm.SetOperation(pOp);
		m_SplitForm.ShowWindow(SW_SHOW);
		break;

	case OP_PYRAMID:
		m_PyramidForm.SetOperation(pOp);
		m_PyramidForm.ShowWindow(SW_SHOW);
		break;

	case OP_DFT:
		m_DFTForm.SetOperation(pOp);
		m_DFTForm.ShowWindow(SW_SHOW);
		break;

	case OP_ADAPTIVETHRESHOLD:
		m_AdaptiveThrForm.SetOperation(pOp);
		m_AdaptiveThrForm.ShowWindow(SW_SHOW);
		break;

	case OP_ADAPTIVETHRESHOLDISH:
		m_AdaptiveThrISHForm.SetOperation(pOp);
		m_AdaptiveThrISHForm.ShowWindow(SW_SHOW);
		break;

	case OP_MORPHOLOGY:
		m_MorphologyForm.SetOperation(pOp);
		m_MorphologyForm.ShowWindow(SW_SHOW);
		break;

	case OP_FILTER2D:
		m_Filter2DForm.SetOperation(pOp);
		m_Filter2DForm.ShowWindow(SW_SHOW);
		break;

	case OP_BLUR:
		m_BlurForm.SetOperation(pOp);
		m_BlurForm.ShowWindow(SW_SHOW);
		break;

	case OP_EDGE:
		m_EdgeForm.SetOperation(pOp);
		m_EdgeForm.ShowWindow(SW_SHOW);
		break;

	case OP_FLOODFILL:
		m_FloodFillForm.SetOperation(pOp);
		m_FloodFillForm.ShowWindow(SW_SHOW);
		break;

	case OP_DISTANCETRANSFORM:
		m_DistanceForm.SetOperation(pOp);
		m_DistanceForm.ShowWindow(SW_SHOW);
		break;

	case OP_HISTOGRAM:
		m_HistogramForm.SetOperation(pOp);
		m_HistogramForm.ShowWindow(SW_SHOW);
		break;

	case OP_EQUALHIST:
		m_EqualHistForm.SetOperation(pOp);
		m_EqualHistForm.ShowWindow(SW_SHOW);
		break;

	case OP_MATCHTEMPLATE:
		m_MatchTemplateForm.SetOperation(pOp);
		m_MatchTemplateForm.ShowWindow(SW_SHOW);
		break;

	case OP_PSM:
		m_PSMForm.SetOperation(pOp);
		m_PSMForm.ShowWindow(SW_SHOW);
		break;

	case OP_REMOVEBLOBS:
		m_RemoveBlobsForm.SetOperation(pOp);
		m_RemoveBlobsForm.ShowWindow(SW_SHOW);
		break;

	case OP_MARKED_AVG:
		m_MarkedAverageForm.SetOperation(pOp);
		m_MarkedAverageForm.ShowWindow(SW_SHOW);
		break;

	case OP_MARKEDADAPTHRESOLD:
		m_MarkedAdaptiveThresholdForm.SetOperation(pOp);
		m_MarkedAdaptiveThresholdForm.ShowWindow(SW_SHOW);
		break;

	case OP_DIFFIMAGE:
		m_DiffImageForm.SetOperation(pOp);
		m_DiffImageForm.ShowWindow(SW_SHOW);
		break;

	case OP_CONTRAST:
		m_Contrast.SetOperation(pOp);
		m_Contrast.ShowWindow(SW_SHOW);
		break;

	case OP_CANNY:
		m_CannyForm.SetOperation(pOp);
		m_CannyForm.ShowWindow(SW_SHOW);
		break;

	case OP_CONTOUR:
		m_ContourForm.SetOperation(pOp);
		m_ContourForm.ShowWindow(SW_SHOW);
		break;

	case OP_BLOB:
		m_BlobForm.SetOperation(pOp);
		m_BlobForm.ShowWindow(SW_SHOW);
		break;

	case OP_HOUGHLINE:
		m_HoughLineForm.SetOperation(pOp);
		m_HoughLineForm.ShowWindow(SW_SHOW);
		break;

	case OP_HOUGHCIRCLE:
		m_HoughCircleForm.SetOperation(pOp);
		m_HoughCircleForm.ShowWindow(SW_SHOW);
		break;

	case OP_HARRISCORNER:
		m_HarrisCornerForm.SetOperation(pOp);
		m_HarrisCornerForm.ShowWindow(SW_SHOW);
		break;

	case OP_SHITOMASICORNER:
		m_ShiTomasiCornerForm.SetOperation(pOp);
		m_ShiTomasiCornerForm.ShowWindow(SW_SHOW);
		break;

	case OP_FAST:
		m_FASTForm.SetOperation(pOp);
		m_FASTForm.ShowWindow(SW_SHOW);
		break;

	case OP_TIMEDELAY:
		m_TimeDelayForm.SetOperation(pOp);
		m_TimeDelayForm.ShowWindow(SW_SHOW);
		break;

	case OP_OFFSETTEMPLATE:
		m_MeasureTemplateOffset.SetOperation(pOp);
		m_MeasureTemplateOffset.ShowWindow(SW_SHOW);
		break;

	case OP_CUSTOMFUNC1:
		m_NAForm.ShowWindow(SW_SHOW);
		break;

	case OP_CUSTOMFUNC2:
		m_NAForm.ShowWindow(SW_SHOW);
		break;

	case OP_WARTERSHED:
		m_Watershed.SetOperation(pOp);
		m_Watershed.ShowWindow(SW_SHOW);
		break;

	case OP_FARSHIDTHR:
		m_FarshidThr.SetOperation(pOp);
		m_FarshidThr.ShowWindow(SW_SHOW);

	default:
		break;
	}

	if (NULL != pOp)
	{
		m_iInputImgNo = pOp->GetInputImgIndex();
	}

	UpdateData(FALSE);
}

void CCVInspectorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCVInspectorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

void CCVInspectorView::SaveControlInitialPos()
{
	CRect rect;
	TCHAR sz[256];

	GetClientRect(rect);
	m_PositionArray.Add(rect);

	CWnd* pWnd = GetTopWindow();

	pWnd->GetWindowText(sz, 256);
	pWnd->GetWindowRect(rect);
	ScreenToClient(rect);
	m_PositionArray.Add(rect);

	CWnd* tmpWnd = pWnd->GetNextWindow(GW_HWNDNEXT);

	while (tmpWnd != NULL)
	{
		tmpWnd->GetWindowText(sz, 256);
		tmpWnd->GetWindowRect(rect);
		ScreenToClient(rect);
		m_PositionArray.Add(rect);
		tmpWnd = tmpWnd->GetNextWindow(GW_HWNDNEXT);
	}

	int iSize = m_PositionArray.GetSize();
}

void CCVInspectorView::ChangeControlPosition()
{
	if (m_PositionArray.GetSize() <= 0)
		return;

	CRect rect, rect_org;
	int i = 0;

	rect_org = m_PositionArray.GetAt(i);
	i++;

	GetClientRect(rect);

	double dXRatio = ((double)rect.Width()) / ((double)rect_org.Width());
	double dYRatio = ((double)rect.Height()) / ((double)rect_org.Height());

	CWnd* pWnd = GetTopWindow();

	rect = m_PositionArray.GetAt(i);
	i++;
	pWnd->MoveWindow((int)(rect.left*dXRatio),
		(int)(rect.top*dYRatio),
		(int)(rect.Width()*dXRatio),
		(int)(rect.Height()*dYRatio));

	CWnd* tmpWnd = pWnd->GetNextWindow(GW_HWNDNEXT);

	while (tmpWnd != NULL)
	{
		rect = m_PositionArray.GetAt(i);
		i++;
		tmpWnd->MoveWindow((int)(rect.left*dXRatio),
			(int)(rect.top*dYRatio),
			(int)(rect.Width()*dXRatio),
			(int)(rect.Height()*dYRatio));

		tmpWnd = tmpWnd->GetNextWindow(GW_HWNDNEXT);
	}
}

void CCVInspectorView::DisplayImage()
{
	if (m_DispImage.total() != 0)
	{
		if (m_DispImage.cols % 4 != 0)
		{
			int iNewCols = ((m_DispImage.cols / 4) + 1) * 4;
			Mat tmpImage, roiImage;
			tmpImage = Mat::zeros(m_DispImage.rows, iNewCols, m_DispImage.type());				

			roiImage = tmpImage(cv::Rect(0, 0, m_DispImage.cols, m_DispImage.rows));
			
			cv::add(roiImage, m_DispImage, roiImage);

			m_ImagePanel.SetImage((char*)tmpImage.data, tmpImage.cols, tmpImage.rows, tmpImage.channels(), TRUE);
		}
		else
		{
			m_ImagePanel.SetImage((char*)m_DispImage.data, m_DispImage.cols, m_DispImage.rows, m_DispImage.channels(), TRUE);
		}		
	}
}


void CCVInspectorView::UpdateList(int iCurOpNo)
{
	// Delete every other item from the list box.
	int iListCnt = m_ctrlOpList.GetCount();
	for (int i = 0; i < iListCnt; i++)
	{
		m_ctrlOpList.DeleteString(0);
	}

	int iOpCount = m_OpManager.GetCount();
	for (int i = 0; i < iOpCount; i++)
	{
		COperation* pOp = m_OpManager.GetOperation(i);
		CString strOpName;
		strOpName.Format(_T("%d "), i);
		strOpName += pOp->GetName();
		m_ctrlOpList.AddString(strOpName);
	}
	m_ctrlOpList.SetCurSel(iCurOpNo);
}


void CCVInspectorView::UpdateView(int iOpNo)
{
	DisplayImage();
	UpdateList(iOpNo);
}

// CCVInspectorView 진단

#ifdef _DEBUG
void CCVInspectorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCVInspectorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCVInspectorDoc* CCVInspectorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCVInspectorDoc)));
	return (CCVInspectorDoc*)m_pDocument;
}
#endif //_DEBUG


// CCVInspectorView 메시지 처리기
void CCVInspectorView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	ChangeControlPosition();
}


void CCVInspectorView::OnLbnSelchangeOpList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iCurSel = m_ctrlOpList.GetCurSel();

	COperation* pOp = m_OpManager.GetOperation(iCurSel);
	m_DispImage = pOp->GetDisplayImage();

	DisplayImage();
	ChangeForm(pOp);
}

template <typename T> void CCVInspectorView::ProcessOperation(T* pOp, BOOL bCheckPrevOp)
{
	int iLastIndex = m_OpManager.GetCount() - 1;
	if (iLastIndex < 0 && bCheckPrevOp)
	{
		AfxMessageBox(_T("No previous operation!"));
		return;
	}

	// Parameter Dlg을 띄워 속성 설정
	CParameterDlg tmpParameterDlg;

	tmpParameterDlg.SetOperation((COperation*)pOp);
	if (IDOK != tmpParameterDlg.DoModal())
	{
		delete pOp;
		return;
	}

	if (tmpParameterDlg.m_bInsertAfter)
	{
		iLastIndex = m_ctrlOpList.GetCurSel();
		if (iLastIndex < 0)
		{
			AfxMessageBox(_T("No previous operation!"));
			delete pOp;
			return;
		}
	}

	// 만약 input image index가 -1이 아니면 
	int iInputImgIndex = pOp->GetInputImgIndex();
	if (iInputImgIndex < 0)
	{
		iInputImgIndex = iLastIndex;
	}

	// 필요 시 두 번째 이미지 가져오기
	int iSecondIndex = pOp->GetSecondImgIndex();

	// 이전 Operation의 결과 이미지 얻어오기
	COperation* pPrevOp = m_OpManager.GetOperation(iInputImgIndex);
	COperation* pPrevOp2 = m_OpManager.GetOperation(iSecondIndex);

	if (!pOp->Process(pPrevOp, pPrevOp2))
	{
		delete pOp;
		return;
	}	

	if (tmpParameterDlg.m_bInsertAfter)
	{
		m_OpManager.AddOperation((COperation*)pOp, iLastIndex + 1);
	}
	else
	{
		m_OpManager.AddOperation((COperation*)pOp);
	}

	m_DispImage = pOp->GetDisplayImage();
	UpdateView(iLastIndex + 1);

	ChangeForm((COperation*)pOp);
}

void CCVInspectorView::OnOpenimagefile()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpOpenImage* pOpenImage = new COpOpenImage;
	ProcessOperation(pOpenImage, FALSE);
}

void CCVInspectorView::OnCaptureCam()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpCaptureCam* pCaptureCam = new COpCaptureCam;
	ProcessOperation(pCaptureCam, FALSE);
}

void CCVInspectorView::OnArithmetic()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpArithmetic* pArithmetic = new COpArithmetic;
	ProcessOperation(pArithmetic);
}

void CCVInspectorView::OnConvertColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpCvtColor* pCvtColor = new COpCvtColor;
	ProcessOperation(pCvtColor);
}

void CCVInspectorView::OnFlip()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpFlip* pFlip = new COpFlip;
	ProcessOperation(pFlip);
}

void CCVInspectorView::OnRotate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpRotate* pRotate = new COpRotate;
	ProcessOperation(pRotate);
}

void CCVInspectorView::OnBinarize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpBinarize* pBinarize = new COpBinarize;
	ProcessOperation(pBinarize);
}

void CCVInspectorView::OnJpthreshold()
{
	// TODO: Add your command handler code here
	COpJPThreshold* pJPThreshold = new COpJPThreshold;
	ProcessOperation(pJPThreshold);
}


void CCVInspectorView::OnJpthresauto()
{
	// TODO: Add your command handler code here
	COpJPThresholdAuto* pJPThresholdAuto = new COpJPThresholdAuto;
	ProcessOperation(pJPThresholdAuto);
}


void CCVInspectorView::OnResize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpResize* pResize = new COpResize;
	ProcessOperation(pResize);
}

void CCVInspectorView::OnCrop()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpCrop* pCrop = new COpCrop;
	ProcessOperation(pCrop);
}

void CCVInspectorView::OnSplit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpSplit* pSplit = new COpSplit;
	ProcessOperation(pSplit);
}

void CCVInspectorView::OnPyramid()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpPyramid* pPyramid = new COpPyramid;
	ProcessOperation(pPyramid);
}

void CCVInspectorView::OnDft()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpDFT* pDFT = new COpDFT;
	ProcessOperation(pDFT);
}

void CCVInspectorView::OnAdaptiveThreshold()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpAdaptiveThreshold* pAdaptiveThr = new COpAdaptiveThreshold;
	ProcessOperation(pAdaptiveThr);
}

void CCVInspectorView::OnAdaptivethrIsh()
{
	// TODO: Add your command handler code here
	COpAdaptiveThresholdISH* pAdaptiveThrISH = new COpAdaptiveThresholdISH;
	ProcessOperation(pAdaptiveThrISH);
}

void CCVInspectorView::OnMappingImage()
{
	// TODO: Add your command handler code here
	COpMappingImage* pMappingImage = new COpMappingImage;
	ProcessOperation(pMappingImage);
}


void CCVInspectorView::OnFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpFilter2D* pFilter2D = new COpFilter2D;
	ProcessOperation(pFilter2D);
}

void CCVInspectorView::OnMorphology()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpMorphology* pMorphology = new COpMorphology;
	ProcessOperation(pMorphology);
}

void CCVInspectorView::OnBlur()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpBlur* pBlur = new COpBlur;
	ProcessOperation(pBlur);
}

void CCVInspectorView::OnEdge()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpEdge* pEdge = new COpEdge;
	ProcessOperation(pEdge);
}

void CCVInspectorView::OnFloodfill()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpFloodFill* pFloodFill = new COpFloodFill;
	ProcessOperation(pFloodFill);
}


void CCVInspectorView::OnDistancetransform()
{
	// TODO: Add your command handler code here
	COpDistance* pDistance = new COpDistance;
	ProcessOperation(pDistance);
}


void CCVInspectorView::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpHistogram* pHistogram = new COpHistogram;
	ProcessOperation(pHistogram);
}

void CCVInspectorView::OnEqualHist()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpEqualHist* pEqualHist = new COpEqualHist;
	ProcessOperation(pEqualHist);
}

void CCVInspectorView::OnMatchTemplate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpMatchTemplate* pMatchTemplate = new COpMatchTemplate;
	ProcessOperation(pMatchTemplate);
}

void CCVInspectorView::OnPatternShift()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpPSM* pPSM = new COpPSM;
	ProcessOperation(pPSM);
}

void CCVInspectorView::OnRemoveBlobs()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpRemoveBlobs* pRemoveBlobs = new COpRemoveBlobs;
	ProcessOperation(pRemoveBlobs);
}


void CCVInspectorView::OnMarkedAvg()
{
	// TODO: Add your command handler code here
	COpMarkedAgv* pMarkedAvg = new COpMarkedAgv;
	ProcessOperation(pMarkedAvg);
}


void CCVInspectorView::OnMarkedAdaptiveThreshold()
{
	// TODO: Add your command handler code here
	COpMarkedAdaptiveThreshold* pMarkedAdaptiveThreshold = new COpMarkedAdaptiveThreshold;
	ProcessOperation(pMarkedAdaptiveThreshold);
}

void CCVInspectorView::OnDiffimage()
{
	// TODO: Add your command handler code here
	COpDiffImage* pDiffImage = new COpDiffImage;
	ProcessOperation(pDiffImage);
}

void CCVInspectorView::OnCanny()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpCanny* pCanny = new COpCanny;
	ProcessOperation(pCanny);
}

void CCVInspectorView::OnContour()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpContour* pContour = new COpContour;
	ProcessOperation(pContour);
}

void CCVInspectorView::OnBlob()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpBlob* pBlob = new COpBlob;
	ProcessOperation(pBlob);
}

void CCVInspectorView::OnHoughLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpHoughLine* pHoughLine = new COpHoughLine;
	ProcessOperation(pHoughLine);
}

void CCVInspectorView::OnHoughCircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpHoughCircle* pHoughCircle = new COpHoughCircle;
	ProcessOperation(pHoughCircle);
}

void CCVInspectorView::OnHarrisCorner()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpHarrisCorner* pHarrisCorner = new COpHarrisCorner;
	ProcessOperation(pHarrisCorner);
}

void CCVInspectorView::OnShitomasiCorner()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpShiTomasiCorner* pShiTomasiCorner = new COpShiTomasiCorner;
	ProcessOperation(pShiTomasiCorner);
}

void CCVInspectorView::OnFast()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpFAST* pFAST = new COpFAST;
	ProcessOperation(pFAST);
}

void CCVInspectorView::OnTimeDelay()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpTimeDelay* pTimeDelay = new COpTimeDelay;
	ProcessOperation(pTimeDelay);
}

void CCVInspectorView::OnOffsetTemplate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpOffsetTemplate* pOffsetTemplate = new COpOffsetTemplate;
	ProcessOperation(pOffsetTemplate);
}

void CCVInspectorView::OnFunc1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpCustomFunc1* pCustomFunc1 = new COpCustomFunc1;
	ProcessOperation(pCustomFunc1);
}

void CCVInspectorView::OnFunc2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COpCustomFunc2* pCustomFunc2 = new COpCustomFunc2;
	ProcessOperation(pCustomFunc2);
}


void CCVInspectorView::OnBnClickedButtonApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iCurSel = m_ctrlOpList.GetCurSel();
	int iPrevIndex = iCurSel - 1;

	if (iCurSel < 0 || iCurSel >= m_OpManager.GetCount())
	{
		return;
	}

	COperation* pOp = m_OpManager.GetOperation(iCurSel);
	int iFormID = pOp->GetTypeID();

	UpdateData(TRUE);
	pOp->SetInputImgIndex(m_iInputImgNo);

	// 두 번째 이미지 가져오기
	int iSecondIndex = -1;
	
	switch (iFormID)
	{
	case OP_NA:// No Operation
		break;
		
	case OP_OPENIMAGE:	// File Open Form
		m_FileOpenForm.ApplyChanges();
		break;

	case OP_CAPTURECAM:	// Capture from Camera Form
		m_CaptureCamForm.ApplyChanges();
		break;

	case OP_ARITHMETIC:// Simple Arithmatic Form
		m_ArithmeticForm.ApplyChanges();		
		break;

	case OP_CVTCOLOR:	// Convert Color Form
		m_CvtColorForm.ApplyChanges();
		break;

	case OP_FLIP:
		m_FlipForm.ApplyChanges();
		break;

	case OP_ROTATE:
		m_RotateForm.ApplyChanges();
		break;

	case OP_BINARIZE:
		m_BinarizeForm.ApplyChanges();
		break;

	case OP_JPTHRESHOLD:
		m_JPThresholdForm.ApplyChanges();
		break;

	case OP_JPTHRESHOLDAUTO:
		m_JPThresholdAutoForm.ApplyChanges();
		break;

	case OP_RESIZE:
		m_ResizeForm.ApplyChanges();
		break;

	case OP_CROP:
		m_CropForm.ApplyChanges();
		break;

	case OP_SPLIT:
		m_SplitForm.ApplyChanges();
		break;

	case OP_PYRAMID:
		m_PyramidForm.ApplyChanges();
		break;

	case OP_DFT:
		m_DFTForm.ApplyChanges();
		break;

	case OP_ADAPTIVETHRESHOLD:
		m_AdaptiveThrForm.ApplyChanges();
		break;

	case OP_FILTER2D:
		m_Filter2DForm.ApplyChanges();
		break;

	case OP_MORPHOLOGY:
		m_MorphologyForm.ApplyChanges();
		break;

	case OP_BLUR:
		m_BlurForm.ApplyChanges();
		break;

	case OP_EDGE:
		m_EdgeForm.ApplyChanges();
		break;

	case OP_FLOODFILL:
		m_FloodFillForm.ApplyChanges();
		break;

	case OP_DISTANCETRANSFORM:
		m_DistanceForm.ApplyChanges();
		break;

	case OP_HISTOGRAM:
		m_HistogramForm.ApplyChanges();
		break;

	case OP_EQUALHIST:
		m_EqualHistForm.ApplyChanges();
		break;

	case OP_MATCHTEMPLATE:
		m_MatchTemplateForm.ApplyChanges();
		break;

	case OP_PSM:
		m_PSMForm.ApplyChanges();
		break;

	case OP_REMOVEBLOBS:
		m_RemoveBlobsForm.ApplyChanges();
		break;

	case OP_MARKED_AVG:
		m_MarkedAverageForm.ApplyChanges();
		break;

	case OP_MAPPINGIMAGE:
		m_MappingImageForm.ApplyChanges();
		break;

	case OP_MARKEDADAPTHRESOLD:
		m_MarkedAdaptiveThresholdForm.ApplyChanges();
		break;

	case OP_DIFFIMAGE:
		m_DiffImageForm.ApplyChanges();
		break;

	case OP_CONTRAST:
		m_Contrast.ApplyChanges();
		break;

	case OP_WARTERSHED:
		m_Watershed.ApplyChanges();
		break;

	case OP_CANNY:
		m_CannyForm.ApplyChanges();
		break;

	case OP_CONTOUR:
		m_ContourForm.ApplyChanges();
		break;

	case OP_BLOB:
		m_BlobForm.ApplyChanges();
		break;

	case OP_HOUGHLINE:
		m_HoughLineForm.ApplyChanges();
		break;
		
	case OP_HOUGHCIRCLE:
		m_HoughCircleForm.ApplyChanges();
		break;

	case OP_HARRISCORNER:
		m_HarrisCornerForm.ApplyChanges();
		break;

	case OP_SHITOMASICORNER:
		m_ShiTomasiCornerForm.ApplyChanges();
		break;

	case OP_FAST:
		m_FASTForm.ApplyChanges();
		break;

	case OP_TIMEDELAY:
		m_TimeDelayForm.ApplyChanges();
		break;

	case OP_OFFSETTEMPLATE:
		m_MeasureTemplateOffset.ApplyChanges();
		break;

	case OP_CUSTOMFUNC1:
		break;

	case OP_CUSTOMFUNC2:
		break;
	
	case OP_FARSHIDTHR:
		m_FarshidThr.ApplyChanges();
		break;
	default:
		break;
	}		
	
	if (m_iInputImgNo >= 0)
	{
		iPrevIndex = m_iInputImgNo;
	}

	iSecondIndex = pOp->GetSecondImgIndex();

	COperation* pPrevOp = m_OpManager.GetOperation(iPrevIndex);		
	COperation* pPrevOp2 = m_OpManager.GetOperation(iSecondIndex);
	
	if (!pOp->Process(pPrevOp, pPrevOp2))
	{
		AfxMessageBox(_T("Cannot process the image!"));
		return;
	}

	m_DispImage = pOp->GetDisplayImage();
	DisplayImage();
}

void CCVInspectorView::OnBnClickedButtonSaveCurrentImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iCurSel = m_ctrlOpList.GetCurSel();
	int iPrevIndex = iCurSel - 1;

	if (iCurSel < 0 || iCurSel >= m_OpManager.GetCount())
	{
		return;
	}

	COperation* pOp = m_OpManager.GetOperation(iCurSel);

	TCHAR BASED_CODE szFilter[] = _T("Image Files (*.bmp;*.jpg;*.png;*.jp2)|*.bmp; *.jpg; *.png; *.jp2|All Files (*.*)|*.*||");

	CFileDialog FileDlg(FALSE, _T("bmp"), _T(""), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if (FileDlg.DoModal() == IDOK)
	{
		CString strFileName = FileDlg.GetPathName();

		CT2CA tmpStr(strFileName);
		std::string strFile(tmpStr);

		cv::imwrite(strFile, pOp->GetDisplayImage());
	}
}

void CCVInspectorView::ProcessAll()
{
	int iOpCount = m_OpManager.GetCount();

	if (iOpCount <= 0)
	{
		return;
	}

	COperation* pOp = NULL;

	for (int i = 0; i < iOpCount; i++)
	{
		pOp = m_OpManager.GetOperation(i);

		int iInputIndex = pOp->GetInputImgIndex();
		int iSecondIndex = pOp->GetSecondImgIndex();

		if (iInputIndex < 0)	iInputIndex = i - 1;

		COperation* pPrevOp = m_OpManager.GetOperation(iInputIndex);
		COperation* pPrevOp2 = m_OpManager.GetOperation(iSecondIndex);

		if (!pOp->Process(pPrevOp, pPrevOp2))
		{
			AfxMessageBox(_T("Cannot process the image!"));
			return;
		}
	}

	m_DispImage = pOp->GetDisplayImage();
	UpdateView(iOpCount - 1);
}

void CCVInspectorView::OnBnClickedButtonProcessAll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ProcessAll();

	int iOpCount = m_OpManager.GetCount();

	COperation* pOp = m_OpManager.GetOperation(iOpCount-1);
	ChangeForm((COperation*)pOp);
}

void CCVInspectorView::OnBnClickedButtonDeleteSelectedOp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iOpCount = m_OpManager.GetCount();

	if (iOpCount <= 0)
	{
		return;
	}

	int iCurSel = m_ctrlOpList.GetCurSel();
	if (iCurSel < 0 || iCurSel >= iOpCount)
	{
		return;
	}
	
	if (IDYES != AfxMessageBox(_T("Do you want to delete the selected operation?"), MB_YESNO))
	{
		return;
	}

	m_OpManager.RemoveOperation(iCurSel);

	int iPrevIndex = iCurSel - 1;

	if (iPrevIndex >= 0)
	{
		COperation* pOp = m_OpManager.GetOperation(iPrevIndex);
		m_DispImage = pOp->GetDisplayImage();
		UpdateView(iPrevIndex);
		ChangeForm((COperation*)pOp);
	}
	else
	{
		m_DispImage = Scalar::all(0);
		UpdateView(-1);
		ChangeForm(NULL);
	}
}


void CCVInspectorView::OnFileNew()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_OpManager.ClearAll();
	
	UpdateList(-1);
	m_DispImage = Scalar::all(0);
	UpdateView(-1);
	ChangeForm(NULL);

	GetDocument()->SetTitle(_T("No Title"));
}

void CCVInspectorView::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	TCHAR BASED_CODE szFilter[] = _T("Xml Files (*.xml)|*.xml|All Files (*.*)|*.*||");

	CFileDialog FileDlg(TRUE, _T("xml"), _T(""), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if (FileDlg.DoModal() == IDOK)
	{
		CString strFileName = FileDlg.GetPathName();
		m_OpManager.LoadFromFile(strFileName);
		GetDocument()->SetTitle(FileDlg.GetFileTitle());

		// Load 한 후 일괄 수행
		ProcessAll();
	}
}

void CCVInspectorView::OnFileSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_OpManager.GetFilePath().IsEmpty())	// 파일명이 지정되어 있지 않으면 Save As 호출
	{
		OnFileSaveAs();
	}
	else
	{
		m_OpManager.SaveToFile(_T(""));
	}
}


void CCVInspectorView::OnFileSaveAs()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	TCHAR BASED_CODE szFilter[] = _T("Xml Files (*.xml)|*.xml|All Files (*.*)|*.*||");

	CFileDialog FileDlg(FALSE, _T("xml"), _T(""), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if (FileDlg.DoModal() == IDOK)
	{
		CString strFileName = FileDlg.GetPathName();
		m_OpManager.SaveToFile(strFileName);
		GetDocument()->SetTitle(FileDlg.GetFileTitle());
	}
}


void CCVInspectorView::OnDrawLine()
{
	// TODO: Add your command handler code here
}



void CCVInspectorView::OnWatershed()
{
	COpWatershed* pWatershed = new COpWatershed;
	ProcessOperation(pWatershed);
}


void CCVInspectorView::OnContrast()
{
	COpContrast* pContrast = new COpContrast;
	ProcessOperation(pContrast);
}


void CCVInspectorView::OnFarshidThr()
{
	COpFarshidThr* pFarshidThr = new COpFarshidThr;
	ProcessOperation(pFarshidThr);
	// TODO: Add your command handler code here
}


BOOL CCVInspectorView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedButtonApply();
			return TRUE;
		}
		else if (pMsg->wParam == VK_DELETE)
		{
			OnBnClickedButtonDeleteSelectedOp();
			return TRUE;
		}
 		else if (pMsg->wParam == VK_F12 )
 		{
			OnBnClickedButtonSaveCurrentImage();
			return TRUE;
 		}

	default:
		break;
	}


	return CFormView::PreTranslateMessage(pMsg);
}


