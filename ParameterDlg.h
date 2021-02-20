#pragma once

#include "AllOperations.h"
#include "afxwin.h"
#include "FormHeader.h"

// CParameterDlg 대화 상자입니다.

class CParameterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CParameterDlg)

public:
	CParameterDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CParameterDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PARAMETER_DIALOG };


public:
	void SetOperation(COperation* pOp);

protected:
	COperation* m_pOp;
	int			m_iOpID;

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
	CFormResize		m_ResizeForm;
	CFormCrop		m_CropForm;
	CFormSplit		m_SplitForm;
	CFormPyramid	m_PyramidForm;
	CFormDFT		m_DFTForm;
	CFormAdaptiveThreshold	m_AdaptiveThrForm;
	CFormAdaptiveThresholdISH m_AdaptiveThrISHForm;
	CFormMappingImage m_MappingImageForm;
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
	CFormMarkedAverage  m_MarkedAverageForm;
	CFormMarkedAdaptiveThreshold m_MarkedAdaptiveThresholdForm;
	CFormDiffImage  m_DiffImageForm;
	CFormCanny		m_CannyForm;
	CFormContour	m_ContourForm;
	CFormBlob		m_BlobForm;
	CFormHoughLine	m_HoughLineForm;	
	CFormHoughCircle	m_HoughCircleForm;
	CFormHarrisCorner	m_HarrisCornerForm;
	CFormShiTomasiCorner	m_ShiTomasiCornerForm;
	CFormFAST		m_FASTForm;
	CFormTimeDelay	m_TimeDelayForm;
	CFormMeasureTemplateOffset	m_MeasureTemplateOffset;
	CFormContrast m_Contrast;
	CFormWatershed m_Watershed;
	CFormFarshidThr m_FarshidThr;

	void SetParameterPanel();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_ctrlParameterPanel;
	afx_msg void OnBnClickedOk();
	BOOL m_bInsertAfter;
	int m_iInputImgNo;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
