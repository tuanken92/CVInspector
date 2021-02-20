// ParameterDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "ParameterDlg.h"
#include "afxdialogex.h"


// CParameterDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CParameterDlg, CDialogEx)

CParameterDlg::CParameterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CParameterDlg::IDD, pParent)
	, m_bInsertAfter(FALSE)
	, m_iInputImgNo(0)
{
	m_pOp = NULL;
	m_iOpID = 0;
}

CParameterDlg::~CParameterDlg()
{
}

void CParameterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PARAMETER_PANEL, m_ctrlParameterPanel);
	DDX_Check(pDX, IDC_CHECK_INSERT, m_bInsertAfter);
	DDX_Text(pDX, IDC_INPUT_IMG_NO, m_iInputImgNo);
}


BEGIN_MESSAGE_MAP(CParameterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CParameterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CParameterDlg 메시지 처리기입니다.
void CParameterDlg::SetOperation(COperation* pOp)
{
	m_pOp = pOp;
	m_iInputImgNo = m_pOp->GetInputImgIndex();
}


BOOL CParameterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect;
	m_ctrlParameterPanel.GetWindowRect(rect);
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

	m_MappingImageForm.Create(IDD_FORM_MAPPING_IMG, this);
	m_MappingImageForm.MoveWindow(rect);
	m_MappingImageForm.ShowWindow(SW_HIDE);

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

	SetParameterPanel();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CParameterDlg::SetParameterPanel()
{
	if (NULL == m_pOp)
		return;

	int iFormID = m_pOp->GetTypeID();

	m_NAForm.ShowWindow(SW_HIDE);
	m_ArithmeticForm.ShowWindow(SW_HIDE);
	m_FileOpenForm.ShowWindow(SW_HIDE);
	m_CaptureCamForm.ShowWindow(SW_HIDE);
	m_CvtColorForm.ShowWindow(SW_HIDE);
	m_FlipForm.ShowWindow(SW_HIDE);
	m_RotateForm.ShowWindow(SW_HIDE);
	m_JPThresholdForm.ShowWindow(SW_HIDE);
	m_JPThresholdAutoForm.ShowWindow(SW_HIDE);
	m_MappingImageForm.ShowWindow(SW_HIDE);
	m_BinarizeForm.ShowWindow(SW_HIDE);
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
	m_RemoveBlobsForm.ShowWindow(SW_HIDE);
	m_MarkedAverageForm.ShowWindow(SW_HIDE);
	m_MarkedAdaptiveThresholdForm.ShowWindow(SW_HIDE);
	m_DiffImageForm.ShowWindow(SW_HIDE);
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

	switch (iFormID)
	{
	case OP_NA:// No Operation
		m_NAForm.ShowWindow(SW_SHOW);
		break;
		
	case OP_OPENIMAGE:	// File Open Form
		m_FileOpenForm.SetOperation(m_pOp);
		m_FileOpenForm.ShowWindow(SW_SHOW);
		break;

	case OP_CAPTURECAM:	// Capture from Camera Form Form
		m_CaptureCamForm.SetOperation(m_pOp);
		m_CaptureCamForm.ShowWindow(SW_SHOW);
		break;

	case OP_ARITHMETIC:// Simple Arithmatic Form
		m_ArithmeticForm.SetOperation(m_pOp);
		m_ArithmeticForm.ShowWindow(SW_SHOW);
		break;

	case OP_CVTCOLOR:	// Convert Color Form
		m_CvtColorForm.SetOperation(m_pOp);
		m_CvtColorForm.ShowWindow(SW_SHOW);
		break;

	case OP_FLIP:	// Flip Image
		m_FlipForm.SetOperation(m_pOp);
		m_FlipForm.ShowWindow(SW_SHOW);
		break;

	case OP_ROTATE:
		m_RotateForm.SetOperation(m_pOp);
		m_RotateForm.ShowWindow(SW_SHOW);
		break;

	case OP_BINARIZE:	// Binarize Form
		m_BinarizeForm.SetOperation(m_pOp);
		m_BinarizeForm.ShowWindow(SW_SHOW);		
		break;

	case OP_JPTHRESHOLD:
		m_JPThresholdForm.SetOperation(m_pOp);
		m_JPThresholdForm.ShowWindow(SW_SHOW);
		break;

	case OP_JPTHRESHOLDAUTO:
		m_JPThresholdAutoForm.SetOperation(m_pOp);
		m_JPThresholdAutoForm.ShowWindow(SW_SHOW);
		break;

	case OP_MAPPINGIMAGE:
		m_MappingImageForm.SetOperation(m_pOp);
		m_MappingImageForm.ShowWindow(SW_SHOW);
		break;

	case OP_RESIZE:	// Resize Form
		m_ResizeForm.SetOperation(m_pOp);
		m_ResizeForm.ShowWindow(SW_SHOW);
		break;

	case OP_CROP:	// Crop Form
		m_CropForm.SetOperation(m_pOp);
		m_CropForm.ShowWindow(SW_SHOW);
		break;

	case OP_SPLIT:	// Split Form
		m_SplitForm.SetOperation(m_pOp);
		m_SplitForm.ShowWindow(SW_SHOW);
		break;

	case OP_PYRAMID:
		m_PyramidForm.SetOperation(m_pOp);
		m_PyramidForm.ShowWindow(SW_SHOW);
		break;

	case OP_DFT:
		m_DFTForm.SetOperation(m_pOp);
		m_DFTForm.ShowWindow(SW_SHOW);
		break;

	case OP_ADAPTIVETHRESHOLD:
		m_AdaptiveThrForm.SetOperation(m_pOp);
		m_AdaptiveThrForm.ShowWindow(SW_SHOW);
		break;

	case OP_ADAPTIVETHRESHOLDISH:
		m_AdaptiveThrISHForm.SetOperation(m_pOp);
		m_AdaptiveThrISHForm.ShowWindow(SW_SHOW);
		break;

	case OP_FILTER2D:
		m_Filter2DForm.SetOperation(m_pOp);
		m_Filter2DForm.ShowWindow(SW_SHOW);
		break;

	case OP_MORPHOLOGY:
		m_MorphologyForm.SetOperation(m_pOp);
		m_MorphologyForm.ShowWindow(SW_SHOW);
		break;

	case OP_BLUR:
		m_BlurForm.SetOperation(m_pOp);
		m_BlurForm.ShowWindow(SW_SHOW);
		break;

	case OP_EDGE:
		m_EdgeForm.SetOperation(m_pOp);
		m_EdgeForm.ShowWindow(SW_SHOW);
		break;

	case OP_FLOODFILL:
		m_FloodFillForm.SetOperation(m_pOp);
		m_FloodFillForm.ShowWindow(SW_SHOW);
		break;

	case OP_DISTANCETRANSFORM:
		m_DistanceForm.SetOperation(m_pOp);
		m_DistanceForm.ShowWindow(SW_SHOW);
		break;

	case OP_HISTOGRAM:
		m_HistogramForm.SetOperation(m_pOp);
		m_HistogramForm.ShowWindow(SW_SHOW);
		break;

	case OP_EQUALHIST:
		m_EqualHistForm.SetOperation(m_pOp);
		m_EqualHistForm.ShowWindow(SW_SHOW);
		break;

	case OP_MATCHTEMPLATE:
		m_MatchTemplateForm.SetOperation(m_pOp);
		m_MatchTemplateForm.ShowWindow(SW_SHOW);
		break;

	case OP_PSM:
		m_PSMForm.SetOperation(m_pOp);
		m_PSMForm.ShowWindow(SW_SHOW);
		break;

	case OP_REMOVEBLOBS:
		m_RemoveBlobsForm.SetOperation(m_pOp);
		m_RemoveBlobsForm.ShowWindow(SW_SHOW);
		break;

	case OP_MARKED_AVG:
		m_MarkedAverageForm.SetOperation(m_pOp);
		m_MarkedAverageForm.ShowWindow(SW_SHOW);
		break;

	case OP_MARKEDADAPTHRESOLD:
		m_MarkedAdaptiveThresholdForm.SetOperation(m_pOp);
		m_MarkedAdaptiveThresholdForm.ShowWindow(SW_SHOW);
		break;

	case OP_DIFFIMAGE:
		m_DiffImageForm.SetOperation(m_pOp);
		m_DiffImageForm.ShowWindow(SW_SHOW);
		break;

	case OP_CONTRAST:
		m_Contrast.SetOperation(m_pOp);
		m_Contrast.ShowWindow(SW_SHOW);
		break;

	case OP_WARTERSHED:
		m_Watershed.SetOperation(m_pOp);
		m_Watershed.ShowWindow(SW_SHOW);
		break;

	case OP_CANNY:
		m_CannyForm.SetOperation(m_pOp);
		m_CannyForm.ShowWindow(SW_SHOW);
		break;

	case OP_CONTOUR:
		m_ContourForm.SetOperation(m_pOp);
		m_ContourForm.ShowWindow(SW_SHOW);
		break;

	case OP_BLOB:
		m_BlobForm.SetOperation(m_pOp);
		m_BlobForm.ShowWindow(SW_SHOW);
		break;

	case OP_HOUGHLINE:
		m_HoughLineForm.SetOperation(m_pOp);
		m_HoughLineForm.ShowWindow(SW_SHOW);
		break;

	case OP_HOUGHCIRCLE:
		m_HoughCircleForm.SetOperation(m_pOp);
		m_HoughCircleForm.ShowWindow(SW_SHOW);
		break;

	case OP_HARRISCORNER:
		m_HarrisCornerForm.SetOperation(m_pOp);
		m_HarrisCornerForm.ShowWindow(SW_SHOW);
		break;

	case OP_SHITOMASICORNER:
		m_ShiTomasiCornerForm.SetOperation(m_pOp);
		m_ShiTomasiCornerForm.ShowWindow(SW_SHOW);
		break;

	case OP_FAST:
		m_FASTForm.SetOperation(m_pOp);
		m_FASTForm.ShowWindow(SW_SHOW);
		break;

	case OP_TIMEDELAY:
		m_TimeDelayForm.SetOperation(m_pOp);
		m_TimeDelayForm.ShowWindow(SW_SHOW);
		break;

	case OP_OFFSETTEMPLATE:
		m_MeasureTemplateOffset.SetOperation(m_pOp);
		m_MeasureTemplateOffset.ShowWindow(SW_SHOW);
		break;

	case OP_CUSTOMFUNC1:
		m_NAForm.ShowWindow(SW_SHOW);
		break;

	case OP_CUSTOMFUNC2:
		m_NAForm.ShowWindow(SW_SHOW);
		break;

	case OP_FARSHIDTHR:
		m_FarshidThr.ShowWindow(SW_SHOW);
		break;

	default:
		break;
	}
}

void CParameterDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (NULL == m_pOp)
		return;

	UpdateData(TRUE);
	m_pOp->SetInputImgIndex(m_iInputImgNo);

	int iFormID = m_pOp->GetTypeID();

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

	case OP_BINARIZE:	// Binarize Form
		m_BinarizeForm.ApplyChanges();
		break;

	case OP_JPTHRESHOLD:	// JPThreshold Form
		m_JPThresholdForm.ApplyChanges();
		break;

	case OP_JPTHRESHOLDAUTO:	// JPThresholdAuto Form
		m_JPThresholdAutoForm.ApplyChanges();
		break;

	case OP_MAPPINGIMAGE:	// Mapping Image Form
		m_MappingImageForm.ApplyChanges();
		break;

	case OP_CONTRAST:	// Contrast Image Form
		m_Contrast.ApplyChanges();
		break;

	case OP_RESIZE:	// Resize Form
		m_ResizeForm.ApplyChanges();
		break;

	case OP_CROP:	// Crop Form
		m_CropForm.ApplyChanges();
		break;

	case OP_SPLIT:	// Split Form
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

	case OP_ADAPTIVETHRESHOLDISH:
		m_AdaptiveThrISHForm.ApplyChanges();
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

	case OP_MARKEDADAPTHRESOLD:
		m_MarkedAdaptiveThresholdForm.ApplyChanges();
		break;

	case OP_DIFFIMAGE:
		m_DiffImageForm.ApplyChanges();
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

	case OP_WARTERSHED:
		m_Watershed.ApplyChanges();
		break;

	default:
		break;
	}

	CDialogEx::OnOK();
}


BOOL CParameterDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedOk();
			return TRUE;
		}
		else if (pMsg->wParam == VK_ESCAPE)
		{
			OnCancel();
			return TRUE;
		}

	default:
		break;
	}
	
	
	return CDialogEx::PreTranslateMessage(pMsg);
}
