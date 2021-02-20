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

// CVInspectorView.h : CCVInspectorView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "ImagePanel.h"
//#include "ImAdvPanel.h"
#include <opencv2\opencv.hpp>
#include "FormHeader.h"

#include "afxwin.h"

#include "OpManager.h"


using namespace cv;

class CCVInspectorView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CCVInspectorView();
	DECLARE_DYNCREATE(CCVInspectorView)

	CArray<CRect, CRect>	m_PositionArray;
	void ChangeControlPosition();
	void SaveControlInitialPos();

	void ChangeForm(COperation* pOp);

	inline CRect cvRect2CRect(cv::Rect cvrect)
	{
		CRect crect = CRect(cvrect.x, cvrect.y, cvrect.x + cvrect.width, cvrect.y + cvrect.height);
		return crect;
	}

	BOOL m_bFormInit;

	CFormArithmetic	m_ArithmeticForm;
	CFormNA			m_NAForm;
	CFormFileOpen	m_FileOpenForm;
	CFormCaptureCam	m_CaptureCamForm;
	CFormCvtColor	m_CvtColorForm;
	CFormFlip		m_FlipForm;
	CFormRotate		m_RotateForm;
	CFormBinarize	m_BinarizeForm;
	CFormJPThreshold m_JPThresholdForm;
	CFormJPThresholdAuto m_JPThresholdAutoForm;
	CFormMappingImage m_MappingImageForm;
	CFormResize		m_ResizeForm;
	CFormCrop		m_CropForm;
	CFormSplit		m_SplitForm;
	CFormPyramid	m_PyramidForm;
	CFormDFT		m_DFTForm;
	CFormAdaptiveThreshold	m_AdaptiveThrForm;
	CFormAdaptiveThresholdISH m_AdaptiveThrISHForm;
	CFormFilter2D	m_Filter2DForm;
	CFormMorphology	m_MorphologyForm;
	CFormBlur		m_BlurForm;
	CFormEdge		m_EdgeForm;
	CFormFloodFill	m_FloodFillForm;
	CFormDistanceTransform m_DistanceForm;
	CFormHistogram	m_HistogramForm;
	CFormEqualHist	m_EqualHistForm;
	CFormMatchTemplate	m_MatchTemplateForm;
	CFormPSM		m_PSMForm;
	CFormRemoveBlobs	m_RemoveBlobsForm;
	CFormCanny		m_CannyForm;
	CFormContour	m_ContourForm;
	CFormBlob		m_BlobForm;
	CFormMarkedAverage m_MarkedAverageForm;
	CFormMarkedAdaptiveThreshold m_MarkedAdaptiveThresholdForm; 
	CFormDiffImage	m_DiffImageForm;
	CFormHoughLine	m_HoughLineForm;
	CFormHoughCircle	m_HoughCircleForm;
	CFormHarrisCorner	m_HarrisCornerForm;
	CFormShiTomasiCorner	m_ShiTomasiCornerForm;
	CFormFAST		m_FASTForm;
	CFormTimeDelay	m_TimeDelayForm;
	CFormMeasureTemplateOffset	m_MeasureTemplateOffset;
	COpManager	m_OpManager;
	CFormContrast m_Contrast;
	CFormWatershed m_Watershed;
	CFormFarshidThr m_FarshidThr;
	

public:
	enum{ IDD = IDD_CVINSPECTOR_FORM };

// Ư���Դϴ�.
public:
	CCVInspectorDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CCVInspectorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	Mat m_SourceImage;
	Mat m_DispImage;
	int m_iInputImgNo;

	void UpdateView(int iOpNo);
	void DisplayImage();
	void UpdateList(int iCurOpNo);
	template <typename T> void ProcessOperation(T* pOp, BOOL bCheckPrevOp = TRUE);
	void ProcessAll();

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

public:	
	
	CImagePanel m_ImagePanel;
	//CImagePanel m_ImagePanel;
	CStatic m_ctrlParamerPanel;
	CListBox m_ctrlOpList;

	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnLbnSelchangeOpList();
	afx_msg void OnBnClickedButtonApply();

	afx_msg void OnFileOpen();
	afx_msg void OnConvertColor();	
	afx_msg void OnBinarize();	
	afx_msg void OnArithmetic();
	afx_msg void OnMorphology();
	afx_msg void OnBlur();
	afx_msg void OnResize();
	afx_msg void OnBnClickedButtonSaveCurrentImage();
	afx_msg void OnFileSaveAs();
	afx_msg void OnOpenimagefile();
	afx_msg void OnFileSave();
	afx_msg void OnEdge();
	afx_msg void OnCanny();
	afx_msg void OnCrop();
	afx_msg void OnBnClickedButtonProcessAll();
	afx_msg void OnSplit();
	afx_msg void OnContour();
	afx_msg void OnCaptureCam();
	afx_msg void OnFloodfill();
	afx_msg void OnBnClickedButtonDeleteSelectedOp();
	afx_msg void OnPyramid();
	afx_msg void OnBlob();
	afx_msg void OnHistogram();
	afx_msg void OnEqualHist();
	afx_msg void OnHoughLine();
	afx_msg void OnHoughCircle();
	afx_msg void OnHarrisCorner();
	afx_msg void OnDft();
	afx_msg void OnMatchTemplate();
	afx_msg void OnPatternShift();
	afx_msg void OnAdaptiveThreshold();
	afx_msg void OnFileNew();
	afx_msg void OnRemoveBlobs();
	afx_msg void OnTimeDelay();
	afx_msg void OnFlip();
	afx_msg void OnShitomasiCorner();
	afx_msg void OnRotate();
	afx_msg void OnFilter();	
	afx_msg void OnOffsetTemplate();
	afx_msg void OnFunc1();
	afx_msg void OnFunc2();
	afx_msg void OnFast();
	afx_msg void OnMarkedAvg();
	afx_msg void OnMarkedAdaptiveThreshold();
	afx_msg void OnJpthreshold();
	afx_msg void OnDiffimage();
	afx_msg void OnJpthresauto();
	afx_msg void OnDrawLine();
	afx_msg void OnAdaptivethrIsh();
	afx_msg void OnMappingImage();
	afx_msg void OnDistancetransform();
	afx_msg void OnWatershed();
	afx_msg void OnContrast();
	afx_msg void OnFarshidThr();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#ifndef _DEBUG  // CVInspectorView.cpp�� ����� ����
inline CCVInspectorDoc* CCVInspectorView::GetDocument() const
   { return reinterpret_cast<CCVInspectorDoc*>(m_pDocument); }
#endif

