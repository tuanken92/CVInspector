// OpManager.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CVInspector.h"
#include "OpManager.h"
#include "XmlNodeWrapper.h"

// COpManager

COpManager::COpManager()
{
	m_strFilePath.Empty();
}

COpManager::~COpManager()
{
	ClearAll();
}


// COpManager 멤버 함수
CString COpManager::GetFilePath()
{
	return m_strFilePath;
}

void COpManager::SetFilePath(CString strFilePath)
{
	m_strFilePath = strFilePath;
}

void COpManager::ClearAll()
{
	int iOpSize = m_OpArray.GetSize();

	for (int i = 0; i < iOpSize; i++)
	{
		COperation* pOp = m_OpArray.GetAt(i);
		delete pOp;
	}

	m_OpArray.RemoveAll();

	m_strFilePath.Empty();
}

int COpManager::GetCount()
{
	return m_OpArray.GetSize();
}

COperation* COpManager::GetOperation(int iOpNo)
{
	int iOpSize = m_OpArray.GetSize();

	if (iOpNo < 0 || iOpNo >= iOpSize)
	{
		return NULL;
	}

	return m_OpArray.GetAt(iOpNo);
}

void COpManager::AddOperation(COperation* pOp, int iInsertAt)
{
	int iOpSize = m_OpArray.GetSize();

	if (iInsertAt < 0)	// Add tail
	{
		m_OpArray.Add(pOp);
	}
	else
	{
		if (iInsertAt < iOpSize)
		{
			m_OpArray.InsertAt(iInsertAt, pOp);
		}
		else
		{
			m_OpArray.Add(pOp);
		}
	}
}

void COpManager::RemoveOperation(int iRemoveAt)
{
	int iOpSize = m_OpArray.GetSize();

	if (iRemoveAt < 0)	// Remove tail
	{
		m_OpArray.RemoveAt(iOpSize-1);
	}
	else
	{
		if (iRemoveAt < iOpSize)
		{
			m_OpArray.RemoveAt(iRemoveAt);
		}
	}
}

BOOL COpManager::SaveToFile(CString strFileName)
{
	if (!strFileName.IsEmpty())
	{
		m_strFilePath = strFileName;
	}

	xml::CXmlDocumentWrapper xmlDoc;
	if (!xmlDoc.LoadXML(_T("<Param></Param>")))
	{
		return FALSE;
	}
	xml::CXmlNodeWrapper rootNode(xmlDoc.AsNode());

	int iOpSize = m_OpArray.GetSize();

	rootNode.SetValue(_T("Operation_Count"), iOpSize);

	for (int i = 0; i < iOpSize; i++)
	{
		CString strNodeName;
		strNodeName.Format(_T("Operation%02d"), i);
		xml::CXmlNodeWrapper childNode = rootNode.InsertNode(rootNode.NumNodes(), strNodeName);
		
		COperation* pOp = m_OpArray.GetAt(i);

		childNode.SetValue(_T("Op_Type"), pOp->GetTypeID());
		childNode.SetValue(_T("Input_Image_No"), pOp->GetInputImgIndex());
		childNode.SetValue(_T("Mask_Image_No"), pOp->GetSecondImgIndex());
		childNode.SetValue(_T("Show_Display_Image"), pOp->GetShowDisplayImage());

		childNode.SetValue(_T("Marker_Color_R"), pOp->GetMarkerColor(0));
		childNode.SetValue(_T("Marker_Color_G"), pOp->GetMarkerColor(1));
		childNode.SetValue(_T("Marker_Color_B"), pOp->GetMarkerColor(2));
		childNode.SetValue(_T("Marker_Size"), pOp->GetMarkerSize());

		if (pOp->GetTypeID() == OP_OPENIMAGE)	// COpOpenImage
		{
			COpOpenImage* pTmpOp = (COpOpenImage*)pOp;
			childNode.SetValue(_T("FileName"), pTmpOp->m_strFileName);
			childNode.SetValue(_T("ReadType"), pTmpOp->m_iReadType);
		}
		else if (pOp->GetTypeID() == OP_CAPTURECAM)	// COpCaptureCam
		{
			COpCaptureCam* pTmpOp = (COpCaptureCam*)pOp;
			childNode.SetValue(_T("CamNo"), pTmpOp->m_iCamNo);
			childNode.SetValue(_T("ExpTime"), pTmpOp->m_iExpTime);
			childNode.SetValue(_T("Gain"), pTmpOp->m_iGain);
			childNode.SetValue(_T("Image_Width"), pTmpOp->m_iImgWidth);
			childNode.SetValue(_T("Image_Height"), pTmpOp->m_iImgHeight);
		}
		else if (pOp->GetTypeID() == OP_ARITHMETIC)	// COpArithmetic
		{
			COpArithmetic* pTmpOp = (COpArithmetic*)pOp;
			childNode.SetValue(_T("Operator_Type"), pTmpOp->m_iOperatorType);
			childNode.SetValue(_T("Second_Image_Index"), pTmpOp->GetSecondImgIndex());
		}
		else if (pOp->GetTypeID() == OP_CVTCOLOR)	// COpCvtColor
		{
			COpCvtColor* pTmpOp = (COpCvtColor*)pOp;
			childNode.SetValue(_T("Convert_Type"), pTmpOp->m_iConvertType);			
		}
		else if (pOp->GetTypeID() == OP_BINARIZE)	// COpBinarize
		{
			COpBinarize* pTmpOp = (COpBinarize*)pOp;
			childNode.SetValue(_T("Binarize_Type"), pTmpOp->m_iBinarizeType);
			childNode.SetValue(_T("Binarize_Threshold"), pTmpOp->m_dThr);
			childNode.SetValue(_T("Use_Otsu"), pTmpOp->m_bUseOtsu);
		}
		else if (pOp->GetTypeID() == OP_RESIZE)	// COpResize
		{
			COpResize* pTmpOp = (COpResize*)pOp;
			childNode.SetValue(_T("Interpolation_Type"), pTmpOp->m_iInterpolationType);
			childNode.SetValue(_T("New_SizeX"), pTmpOp->m_iNewSizeX);
			childNode.SetValue(_T("New_SizeY"), pTmpOp->m_iNewSizeY);
			childNode.SetValue(_T("New_RatioX"), pTmpOp->m_dNewRatioX);
			childNode.SetValue(_T("New_RatioY"), pTmpOp->m_dNewRatioY);
		}
		else if (pOp->GetTypeID() == OP_CROP)	// COpCrop
		{
			COpCrop* pTmpOp = (COpCrop*)pOp;
			CRect tmpRect = pTmpOp->m_CropRect;
			childNode.SetValue(_T("Left"), tmpRect.left);
			childNode.SetValue(_T("Top"), tmpRect.top);
			childNode.SetValue(_T("Right"), tmpRect.right);
			childNode.SetValue(_T("Bottom"), tmpRect.bottom);

			childNode.SetValue(_T("Show_Display_Image"), pTmpOp->GetShowDisplayImage());
		}
		else if (pOp->GetTypeID() == OP_SPLIT)	// COpSplit
		{
			COpSplit* pTmpOp = (COpSplit*)pOp;			
			childNode.SetValue(_T("Target_Channel"), pTmpOp->m_iTargetChannel);			
		}
		else if (pOp->GetTypeID() == OP_PYRAMID)	// COpPyramid
		{
			COpPyramid* pTmpOp = (COpPyramid*)pOp;			
			childNode.SetValue(_T("Down_Or_Up"), pTmpOp->m_bDownOrUp);
			childNode.SetValue(_T("SizeX"), pTmpOp->m_iSizeX);
			childNode.SetValue(_T("SizeY"), pTmpOp->m_iSizeY);
		}
		else if (pOp->GetTypeID() == OP_DFT)	// COpDFT
		{
			COpDFT* pTmpOp = (COpDFT*)pOp;
			
			childNode.SetValue(_T("Inverse"), pTmpOp->m_bInverse);
			childNode.SetValue(_T("Show_Display_Image"), pTmpOp->GetShowDisplayImage());
		}
		else if (pOp->GetTypeID() == OP_ADAPTIVETHRESHOLD)
		{
			COpAdaptiveThreshold* pTmpOp = (COpAdaptiveThreshold*)pOp;

			childNode.SetValue(_T("Max_Value"), pTmpOp->m_dMaxValue);
			childNode.SetValue(_T("Adaptive_Method"), pTmpOp->m_iAdaptiveMethod);
			childNode.SetValue(_T("Threshold_Type"), pTmpOp->m_iThresholdType);
			childNode.SetValue(_T("Block_Size"), pTmpOp->m_iBlockSize);
			childNode.SetValue(_T("Constant"), pTmpOp->m_dConstant);
		}
		else if (pOp->GetTypeID() == OP_FILTER2D)	// COpFilter2D
		{
			COpFilter2D* pTmpOp = (COpFilter2D*)pOp;
			childNode.SetValue(_T("Depth"), pTmpOp->m_iDepth);
			childNode.SetValue(_T("Delta"), pTmpOp->m_dDelta);
			childNode.SetValue(_T("Border_Type"), pTmpOp->m_iBorderType);
			childNode.SetValue(_T("Anchor_PosX"), pTmpOp->m_AnchorPos.x);
			childNode.SetValue(_T("Anchor_PosY"), pTmpOp->m_AnchorPos.y);

			CString strTmp = pTmpOp->m_strKernel;
			strTmp.Replace(_T("\r\n"), _T("##"));
			childNode.SetValue(_T("Kernel_String"), strTmp);
		}
		else if (pOp->GetTypeID() == OP_MORPHOLOGY)	// COpMorphology
		{
			COpMorphology* pTmpOp = (COpMorphology*)pOp;
			childNode.SetValue(_T("Interpolation_Type"), pTmpOp->m_iMorphologyType);
			childNode.SetValue(_T("Kernel_SizeX"), pTmpOp->m_iKernelSizeX);
			childNode.SetValue(_T("Kernel_SizeY"), pTmpOp->m_iKernelSizeY);
			childNode.SetValue(_T("Interation_No"), pTmpOp->m_iIterationNo);
			childNode.SetValue(_T("Shape_Structure"), pTmpOp->m_iShapeStructure);
			childNode.SetValue(_T("Anchor_PosX"), pTmpOp->m_AnchorPos.x);
			childNode.SetValue(_T("Anchor_PosY"), pTmpOp->m_AnchorPos.y);
		}
		else if (pOp->GetTypeID() == OP_BLUR)	// COpBlur
		{
			COpBlur* pTmpOp = (COpBlur*)pOp;
			childNode.SetValue(_T("Blur_Type"), pTmpOp->m_iBlurType);
			childNode.SetValue(_T("Kernel_X"), pTmpOp->m_iKernelX);
			childNode.SetValue(_T("Kernel_Y"), pTmpOp->m_iKernelY);
			childNode.SetValue(_T("Anchor_PosX"), pTmpOp->m_AnchorPos.x);
			childNode.SetValue(_T("Anchor_PosY"), pTmpOp->m_AnchorPos.y);
			childNode.SetValue(_T("Gaussian_Sigma"), pTmpOp->m_dGaussianSigma);
			childNode.SetValue(_T("Bilateral_Sigma_Color"), pTmpOp->m_dBilateralSigmaColor);
			childNode.SetValue(_T("Bilateral_Sigma_Space"), pTmpOp->m_dBilateralSigmaSpace);
		}
		else if (pOp->GetTypeID() == OP_EDGE)	// COpEdge
		{
			COpEdge* pTmpOp = (COpEdge*)pOp;
			childNode.SetValue(_T("Edge_Type"), pTmpOp->m_iEdgeType);
			childNode.SetValue(_T("Kernel_Size"), pTmpOp->m_iKernelSize);
			childNode.SetValue(_T("Scale"), pTmpOp->m_dScale);
			childNode.SetValue(_T("Delta"), pTmpOp->m_dDelta);
			childNode.SetValue(_T("Dx"), pTmpOp->m_iDx);
			childNode.SetValue(_T("Dy"), pTmpOp->m_iDy);			
		}
		else if (pOp->GetTypeID() == OP_FLOODFILL)	// COpFloodFill
		{
			COpFloodFill* pTmpOp = (COpFloodFill*)pOp;
			childNode.SetValue(_T("Use_Fixed_Range"), pTmpOp->m_bUseFixedRange);
			childNode.SetValue(_T("Lower_Diff"), pTmpOp->m_iLowerDiff);
			childNode.SetValue(_T("Upper_Diff"), pTmpOp->m_iUpperDiff);
			childNode.SetValue(_T("Neighbor"), pTmpOp->m_iNeighbor);			
		}
		else if (pOp->GetTypeID() == OP_HISTOGRAM)	// COpHistogram
		{

		}
		else if (pOp->GetTypeID() == OP_EQUALHIST)	// CEqualHistogram
		{

		}
		else if (pOp->GetTypeID() == OP_MATCHTEMPLATE)	// COpMatchTemplate
		{
			COpMatchTemplate* pTmpOp = (COpMatchTemplate*)pOp;
			
			childNode.SetValue(_T("Method"), pTmpOp->m_iMethod);
			childNode.SetValue(_T("Template_Image_No"), pTmpOp->m_iTemplateImageNo);
		}
		else if (pOp->GetTypeID() == OP_PSM)
		{
			COpPSM* pTmpOp = (COpPSM*)pOp;

			childNode.SetValue(_T("Dir"), pTmpOp->m_iDir);
			childNode.SetValue(_T("Subtract_Type"), pTmpOp->m_iSubtractType);
			childNode.SetValue(_T("X_Offset"), pTmpOp->m_iXOffset);
			childNode.SetValue(_T("Y_Offset"), pTmpOp->m_iYOffset);
		}
		else if (pOp->GetTypeID() == OP_REMOVEBLOBS)
		{
			COpRemoveBlobs* pTmpOp = (COpRemoveBlobs*)pOp;

			childNode.SetValue(_T("MinArea"), pTmpOp->m_iMinArea);
			childNode.SetValue(_T("MaxArea"), pTmpOp->m_iMaxArea);
			childNode.SetValue(_T("MinWidth"), pTmpOp->m_iMinWidth);
			childNode.SetValue(_T("MinHeight"), pTmpOp->m_iMinHeight);
			childNode.SetValue(_T("MaxWidth"), pTmpOp->m_iMaxWidth);			
			childNode.SetValue(_T("MaxHeight"), pTmpOp->m_iMaxHeight);			
		}
		else if (pOp->GetTypeID() == OP_CANNY)	// COpCanny
		{
			COpCanny* pTmpOp = (COpCanny*)pOp;
			childNode.SetValue(_T("Threshold1"), pTmpOp->m_dThr1);
			childNode.SetValue(_T("Threshold2"), pTmpOp->m_dThr2);
			childNode.SetValue(_T("Aperture_Size"), pTmpOp->m_iApertureSize);			
		}
		else if (pOp->GetTypeID() == OP_CONTOUR)	// COpContour
		{
			COpContour* pTmpOp = (COpContour*)pOp;
			childNode.SetValue(_T("Mode"), pTmpOp->m_iMode);
			childNode.SetValue(_T("Method"), pTmpOp->m_iMethod);
			childNode.SetValue(_T("Line_Width"), pTmpOp->m_iLineWidth);
			childNode.SetValue(_T("Line_Type"), pTmpOp->m_iLineType);
			childNode.SetValue(_T("Max_Level"), pTmpOp->m_iMaxLevel);
			childNode.SetValue(_T("Use_ConvexHull"), pTmpOp->m_bConvexHull);
		}
		else if (pOp->GetTypeID() == OP_BLOB)	// COpBlob
		{
			COpBlob* pTmpOp = (COpBlob*)pOp;

			childNode.SetValue(_T("Threshold_Step"), pTmpOp->m_fThresholdStep);
			childNode.SetValue(_T("Min_Threshold"), pTmpOp->m_fMinThreshold);
			childNode.SetValue(_T("Max_Threshold"), pTmpOp->m_fMaxThreshold);
			childNode.SetValue(_T("Min_Repeatability"), pTmpOp->m_iMinRepeatability);
			childNode.SetValue(_T("Min_Dist_Between_Blobs"), pTmpOp->m_fMinDistBetweenBlobs);
			childNode.SetValue(_T("Filter_By_Color"), pTmpOp->m_bFilterByColor);
			childNode.SetValue(_T("Blob_Color"), pTmpOp->m_iBlobColor);
			childNode.SetValue(_T("Filter_By_Area"), pTmpOp->m_bFilterByArea);
			childNode.SetValue(_T("Min_Area"), pTmpOp->m_fMinArea);
			childNode.SetValue(_T("Max_Area"), pTmpOp->m_fMaxArea);
			childNode.SetValue(_T("Filter_By_Circularity"), pTmpOp->m_bFilterByCircularity);
			childNode.SetValue(_T("Min_Circularity"), pTmpOp->m_fMinCircularity);
			childNode.SetValue(_T("Max_Circularity"), pTmpOp->m_fMaxCircularity);
			childNode.SetValue(_T("Filter_By_Inertia"), pTmpOp->m_bFilterByInertia);
			childNode.SetValue(_T("Min_Inertia_Ratio"), pTmpOp->m_fMinInertiaRatio);
			childNode.SetValue(_T("Max_Inertia_Ratio"), pTmpOp->m_fMaxInertiaRatio);
		}
		else if (pOp->GetTypeID() == OP_HOUGHLINE)	// COpHoughLine
		{
			COpHoughLine* pTmpOp = (COpHoughLine*)pOp;

			childNode.SetValue(_T("Rho"), pTmpOp->m_dRho);
			childNode.SetValue(_T("Theta"), pTmpOp->m_dTheta);
			childNode.SetValue(_T("Threshold"), pTmpOp->m_iThreshold);
			childNode.SetValue(_T("Min_Line_Length"), pTmpOp->m_dMinLineLength);
			childNode.SetValue(_T("Max_Line_Gap"), pTmpOp->m_dMaxLineGap);			
		}
		else if (pOp->GetTypeID() == OP_HOUGHCIRCLE)	// COpHoughCircle
		{
			COpHoughCircle* pTmpOp = (COpHoughCircle*)pOp;

			childNode.SetValue(_T("Accu_Res"), pTmpOp->m_dAccuRes);
			childNode.SetValue(_T("Min_Dist"), pTmpOp->m_dMinDist);
			childNode.SetValue(_T("Parameter1"), pTmpOp->m_dParam1);
			childNode.SetValue(_T("Parameter2"), pTmpOp->m_dParam2);
			childNode.SetValue(_T("Min_Radius"), pTmpOp->m_iMinRadius);
			childNode.SetValue(_T("Max_Radius"), pTmpOp->m_iMaxRadius);
		}
		else if (pOp->GetTypeID() == OP_HARRISCORNER)	// COpHarrisCorner
		{
			COpHarrisCorner* pTmpOp = (COpHarrisCorner*)pOp;

			childNode.SetValue(_T("Neighbor"), pTmpOp->m_iNeighbor);
			childNode.SetValue(_T("Aperture"), pTmpOp->m_iAperture);
			childNode.SetValue(_T("ParameterK"), pTmpOp->m_dParameterK);
			childNode.SetValue(_T("Non_Max_Size"), pTmpOp->m_iNonMaxSize);
		}
		else if (pOp->GetTypeID() == OP_SHITOMASICORNER)
		{
			COpShiTomasiCorner* pTmpOp = (COpShiTomasiCorner*)pOp;
			
			childNode.SetValue(_T("MaxCorner"), pTmpOp->m_iMaxCorners);
			childNode.SetValue(_T("QualityLevel"), pTmpOp->m_dQualityLevel);
			childNode.SetValue(_T("MinDist"), pTmpOp->m_dMinDist);
			childNode.SetValue(_T("BlockSize"), pTmpOp->m_iBlockSize);
			childNode.SetValue(_T("UseHarris"), pTmpOp->m_bUseHarris);
			childNode.SetValue(_T("K"), pTmpOp->m_dK);
		}
		else if (pOp->GetTypeID() == OP_CUSTOMFUNC1)
		{
			COpCustomFunc1* pTmpOp = (COpCustomFunc1*)pOp;
		}
		else if (pOp->GetTypeID() == OP_CUSTOMFUNC2)
		{
			COpCustomFunc2* pTmpOp = (COpCustomFunc2*)pOp;
		}
	}

	xmlDoc.Save(m_strFilePath);

	return FALSE;
}

BOOL COpManager::LoadFromFile(CString strFileName)
{
	if (strFileName.IsEmpty())
	{
		return FALSE;
	}

	xml::CXmlDocumentWrapper xmlDoc;
	if (!xmlDoc.Load(strFileName))
	{
		return FALSE;
	}

	// 기존의 Op들을 지운다.
	ClearAll();

	xml::CXmlNodeWrapper rootNode(xmlDoc.AsNode());

	int iOpSize = rootNode.GetValueInt(_T("Operation_Count"), 0);

	for (int i = 0; i < iOpSize; i++)
	{
		CString strNodeName;
		strNodeName.Format(_T("Operation%02d"), i);

		xml::CXmlNodeWrapper childNode = rootNode.GetNode(strNodeName);

		int iOpType = childNode.GetValueInt(_T("Op_Type"));

		if (iOpType == OP_OPENIMAGE)	// COpOpenImage
		{
			COpOpenImage* pTmpOp = new COpOpenImage;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_strFileName = childNode.GetValue(_T("FileName"));
			pTmpOp->m_iReadType = childNode.GetValueInt(_T("ReadType"));
		}
		else if (iOpType == OP_CAPTURECAM)	// COpCaptureCam
		{
			COpCaptureCam* pTmpOp = new COpCaptureCam;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iCamNo = childNode.GetValueInt(_T("CamNo"), 0);
			pTmpOp->m_iExpTime = childNode.GetValueInt(_T("ExpTime"));
			pTmpOp->m_iGain = childNode.GetValueInt(_T("Gain"));
			pTmpOp->m_iImgWidth = childNode.GetValueInt(_T("Image_Width"));

			pTmpOp->m_iImgHeight = childNode.GetValueInt(_T("Image_Height"));
		}
		else if (iOpType == OP_ARITHMETIC)	// COpArithmetic
		{
			COpArithmetic* pTmpOp = new COpArithmetic;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iOperatorType = childNode.GetValueInt(_T("Operator_Type"));
			pTmpOp->SetSecondImgIndex(childNode.GetValueInt(_T("Second_Image_Index")));
		}
		else if (iOpType == OP_CVTCOLOR)	// COpCvtColor
		{
			COpCvtColor* pTmpOp = new COpCvtColor;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iConvertType = childNode.GetValueInt(_T("Convert_Type"));
		}
		else if (iOpType == OP_BINARIZE)	// COpBinarize
		{
			COpBinarize* pTmpOp = new COpBinarize;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iBinarizeType = childNode.GetValueInt(_T("Binarize_Type"));
			pTmpOp->m_dThr = childNode.GetValueDouble(_T("Binarize_Threshold"));
			pTmpOp->m_bUseOtsu = childNode.GetValueBool(_T("Use_Otsu"));
		}
		else if (iOpType == OP_RESIZE)	// COpResize
		{
			COpResize* pTmpOp = new COpResize;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iInterpolationType = childNode.GetValueInt(_T("Interpolation_Type"));
			pTmpOp->m_iNewSizeX = childNode.GetValueInt(_T("New_SizeX"));
			pTmpOp->m_iNewSizeY = childNode.GetValueInt(_T("New_SizeY"));
			pTmpOp->m_dNewRatioX = childNode.GetValueDouble(_T("New_RatioX"));
			pTmpOp->m_dNewRatioY = childNode.GetValueDouble(_T("New_RatioY"));
		}
		else if (iOpType == OP_CROP)	// COpCrop
		{
			COpCrop* pTmpOp = new COpCrop;
			m_OpArray.Add(pTmpOp);
			
			CRect tmpRect(childNode.GetValueInt(_T("Left")), childNode.GetValueInt(_T("Top")), childNode.GetValueInt(_T("Right")), childNode.GetValueInt(_T("Bottom")));
			pTmpOp->m_CropRect = tmpRect;
			pTmpOp->SetShowDisplayImage(childNode.GetValueBool(_T("Show_Display_Image")));
		}
		else if (iOpType == OP_SPLIT)	// COpSplit
		{
			COpSplit* pTmpOp = new COpSplit;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iTargetChannel = childNode.GetValueInt(_T("Target_Channel"));
		}
		else if (iOpType == OP_PYRAMID)	// COpPyramid
		{
			COpPyramid* pTmpOp = new COpPyramid;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_bDownOrUp = childNode.GetValueBool(_T("Down_Or_Up"));
			pTmpOp->m_iSizeX = childNode.GetValueInt(_T("SizeX"));
			pTmpOp->m_iSizeY = childNode.GetValueInt(_T("SizeY"));
		}
		else if (iOpType == OP_DFT)	// COpDFT
		{
			COpDFT* pTmpOp = new COpDFT;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_bInverse = childNode.GetValueBool(_T("Inverse"));
			pTmpOp->SetShowDisplayImage(childNode.GetValueBool(_T("Show_Display_Image")));
		}
		else if (iOpType == OP_ADAPTIVETHRESHOLD)
		{
			COpAdaptiveThreshold* pTmpOp = new COpAdaptiveThreshold;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_dMaxValue = childNode.GetValueDouble(_T("Max_Value"));
			pTmpOp->m_iAdaptiveMethod = childNode.GetValueInt(_T("Adaptive_Method"));
			pTmpOp->m_iThresholdType = childNode.GetValueInt(_T("Threshold_Type"));
			pTmpOp->m_iBlockSize = childNode.GetValueInt(_T("Block_Size"));
			pTmpOp->m_dConstant = childNode.GetValueDouble(_T("Constant"));
		}
		else if (iOpType == OP_FILTER2D)	// COpFilter2D
		{
			COpFilter2D* pTmpOp = new COpFilter2D;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iDepth = childNode.GetValueInt(_T("Depth"));
			pTmpOp->m_dDelta = childNode.GetValueDouble(_T("Delta"));
			pTmpOp->m_iBorderType = childNode.GetValueInt(_T("Border_Type"));

			CPoint anchorPos(0, 0);
			anchorPos.x = childNode.GetValueInt(_T("Anchor_PosX"));
			anchorPos.y = childNode.GetValueInt(_T("Anchor_PosY"));
			pTmpOp->m_AnchorPos = anchorPos;
			CString strTmp = childNode.GetValue(_T("Kernel_String"));
			strTmp.Replace(_T("##"), _T("\r\n"));
			pTmpOp->ParseString(strTmp);
		}
		else if (iOpType == OP_MORPHOLOGY)	// COpMorphology
		{
			COpMorphology* pTmpOp = new COpMorphology;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iMorphologyType = childNode.GetValueInt(_T("Interpolation_Type"));
			pTmpOp->m_iKernelSizeX = childNode.GetValueInt(_T("Kernel_SizeX"));
			pTmpOp->m_iKernelSizeY = childNode.GetValueInt(_T("Kernel_SizeY"));
			pTmpOp->m_iIterationNo = childNode.GetValueInt(_T("Interation_No"));
			pTmpOp->m_iShapeStructure = childNode.GetValueInt(_T("Shape_Structure"));
			CPoint anchorPos(0, 0);
			anchorPos.x = childNode.GetValueInt(_T("Anchor_PosX"));
			anchorPos.y = childNode.GetValueInt(_T("Anchor_PosY"));
			pTmpOp->m_AnchorPos = anchorPos;
		}
		else if (iOpType == OP_BLUR)	// COpBlur
		{
			COpBlur* pTmpOp = new COpBlur;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iBlurType = childNode.GetValueInt(_T("Blur_Type"));
			pTmpOp->m_iKernelX = childNode.GetValueInt(_T("Kernel_X"));
			pTmpOp->m_iKernelY = childNode.GetValueInt(_T("Kernel_Y"));
			
			CPoint anchorPos(0, 0);
			anchorPos.x = childNode.GetValueInt(_T("Anchor_PosX"));
			anchorPos.y = childNode.GetValueInt(_T("Anchor_PosY"));
			pTmpOp->m_AnchorPos = anchorPos;

			pTmpOp->m_dGaussianSigma = childNode.GetValueDouble(_T("Gaussian_Sigma"));
			pTmpOp->m_dBilateralSigmaColor = childNode.GetValueDouble(_T("Bilateral_Sigma_Color"));
			pTmpOp->m_dBilateralSigmaSpace = childNode.GetValueDouble(_T("Bilateral_Sigma_Space"));
		}
		else if (iOpType == OP_EDGE)	// COpEdge
		{
			COpEdge* pTmpOp = new COpEdge;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iEdgeType = childNode.GetValueInt(_T("Edge_Type"));
			pTmpOp->m_iKernelSize = childNode.GetValueInt(_T("Kernel_Size"), 1);
			pTmpOp->m_dScale = childNode.GetValueDouble(_T("Scale"), 1.0);
			pTmpOp->m_dDelta = childNode.GetValueDouble(_T("Delta"), 0.0);
			pTmpOp->m_iDx = childNode.GetValueInt(_T("Dx"), 1);
			pTmpOp->m_iDy = childNode.GetValueInt(_T("Dy"), 1);
		}
		else if (iOpType == OP_FLOODFILL)	// COpFloodFill
		{
			COpFloodFill* pTmpOp = new COpFloodFill;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_bUseFixedRange = childNode.GetValueBool(_T("Use_Fixed_Range"));
			pTmpOp->m_iLowerDiff = childNode.GetValueInt(_T("Lower_Diff"), 8);
			pTmpOp->m_iUpperDiff = childNode.GetValueInt(_T("Upper_Diff"), 8);
			pTmpOp->m_iNeighbor = childNode.GetValueInt(_T("Neighbor"), 8);
		}
		else if (iOpType == OP_HISTOGRAM)	// COpHistogram
		{
			COpHistogram* pTmpOp = new COpHistogram;
			m_OpArray.Add(pTmpOp);
		}
		else if (iOpType == OP_EQUALHIST)	// CEqualHistogram
		{
			COpEqualHist* pTmpOp = new COpEqualHist;
			m_OpArray.Add(pTmpOp);
		}
		else if (iOpType == OP_MATCHTEMPLATE)	// COpMatchTemplate
		{
			COpMatchTemplate* pTmpOp = new COpMatchTemplate;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iMethod = childNode.GetValueInt(_T("Method"));
			pTmpOp->m_iTemplateImageNo = childNode.GetValueInt(_T("Template_Image_No"));
		}
		else if (iOpType == OP_PSM)
		{
			COpPSM* pTmpOp = new COpPSM;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iDir = childNode.GetValueInt(_T("Dir"));
			pTmpOp->m_iSubtractType = childNode.GetValueInt(_T("Subtract_Type"));
			pTmpOp->m_iXOffset = childNode.GetValueInt(_T("X_Offset"));
			pTmpOp->m_iYOffset = childNode.GetValueInt(_T("Y_Offset"));
		}
		else if (iOpType == OP_REMOVEBLOBS)
		{
			COpRemoveBlobs* pTmpOp = new COpRemoveBlobs;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iMinArea = childNode.GetValueInt(_T("MinArea"));
			pTmpOp->m_iMaxArea = childNode.GetValueInt(_T("MaxArea"));
			pTmpOp->m_iMinWidth = childNode.GetValueInt(_T("MinWidth"));
			pTmpOp->m_iMinHeight = childNode.GetValueInt(_T("MinHeight"));
			pTmpOp->m_iMaxWidth = childNode.GetValueInt(_T("MaxWidth"));
			pTmpOp->m_iMaxHeight = childNode.GetValueInt(_T("MaxHeight"));
		}
		else if (iOpType == OP_CANNY)	// COpCanny
		{
			COpCanny* pTmpOp = new COpCanny;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_dThr1 = childNode.GetValueDouble(_T("Threshold1"));
			pTmpOp->m_dThr2 = childNode.GetValueDouble(_T("Threshold2"));
			pTmpOp->m_iApertureSize = childNode.GetValueInt(_T("Aperture_Size"));
		}
		else if (iOpType == OP_CONTOUR)	// COpContour
		{
			COpContour* pTmpOp = new COpContour;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iMode = childNode.GetValueInt(_T("Mode"));
			pTmpOp->m_iMethod = childNode.GetValueInt(_T("Method"));
			pTmpOp->m_iLineWidth = childNode.GetValueInt(_T("Line_Width"));
			pTmpOp->m_iLineType = childNode.GetValueInt(_T("Line_Type"));
			pTmpOp->m_iMaxLevel = childNode.GetValueInt(_T("Max_Level"));
			pTmpOp->m_bConvexHull = childNode.GetValueInt(_T("Use_ConvexHull"));
		}
		else if (iOpType == OP_BLOB)	// COpBlob
		{
			COpBlob* pTmpOp = new COpBlob;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_fThresholdStep = (float)childNode.GetValueDouble(_T("Threshold_Step"));
			pTmpOp->m_fMinThreshold = (float)childNode.GetValueDouble(_T("Min_Threshold"));
			pTmpOp->m_fMaxThreshold = (float)childNode.GetValueDouble(_T("Max_Threshold"));
			pTmpOp->m_iMinRepeatability = childNode.GetValueInt(_T("Min_Repeatability"));
			pTmpOp->m_fMinDistBetweenBlobs = (float)childNode.GetValueDouble(_T("Min_Dist_Between_Blobs"));
			pTmpOp->m_bFilterByColor = childNode.GetValueBool(_T("Filter_By_Color"));
			pTmpOp->m_iBlobColor = childNode.GetValueInt(_T("Blob_Color"));
			pTmpOp->m_bFilterByArea = childNode.GetValueBool(_T("Filter_By_Area"));
			pTmpOp->m_fMinArea = (float)childNode.GetValueDouble(_T("Min_Area"));
			pTmpOp->m_fMaxArea = (float)childNode.GetValueDouble(_T("Max_Area"));
			pTmpOp->m_bFilterByCircularity = childNode.GetValueBool(_T("Filter_By_Circularity"));
			pTmpOp->m_fMinCircularity = (float)childNode.GetValueDouble(_T("Min_Circularity"));
			pTmpOp->m_fMaxCircularity = (float)childNode.GetValueDouble(_T("Max_Circularity"));
			pTmpOp->m_bFilterByInertia = childNode.GetValueBool(_T("Filter_By_Inertia"));
			pTmpOp->m_fMinInertiaRatio = (float)childNode.GetValueDouble(_T("Min_Inertia_Ratio"));
			pTmpOp->m_fMaxInertiaRatio = (float)childNode.GetValueDouble(_T("Max_Inertia_Ratio"));
		}
		else if (iOpType == OP_HOUGHLINE)	// COpHoughLine
		{
			COpHoughLine* pTmpOp = new COpHoughLine;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_dRho = childNode.GetValueDouble(_T("Rho"));
			pTmpOp->m_dTheta = childNode.GetValueDouble(_T("Theta"));
			pTmpOp->m_iThreshold = childNode.GetValueInt(_T("Threshold"));
			pTmpOp->m_dMinLineLength = childNode.GetValueDouble(_T("Min_Line_Length"));
			pTmpOp->m_dMaxLineGap = childNode.GetValueDouble(_T("Max_Line_Gap"));
		}
		else if (iOpType == OP_HOUGHCIRCLE)	// COpHoughCircle
		{
			COpHoughCircle* pTmpOp = new COpHoughCircle;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_dAccuRes = childNode.GetValueDouble(_T("Accu_Res"));
			pTmpOp->m_dMinDist = childNode.GetValueDouble(_T("Min_Dist"));
			pTmpOp->m_dParam1 = childNode.GetValueDouble(_T("Parameter1"));
			pTmpOp->m_dParam2 = childNode.GetValueDouble(_T("Parameter2"));
			pTmpOp->m_iMinRadius = childNode.GetValueInt(_T("Min_Radius"));
			pTmpOp->m_iMaxRadius = childNode.GetValueInt(_T("Max_Radius"));
		}
		else if (iOpType == OP_HARRISCORNER)	// COpHarrisCorner
		{
			COpHarrisCorner* pTmpOp = new COpHarrisCorner;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iNeighbor = childNode.GetValueInt(_T("Neighbor"));
			pTmpOp->m_iAperture = childNode.GetValueInt(_T("Aperture"));
			pTmpOp->m_dParameterK = childNode.GetValueDouble(_T("ParameterK"));
			pTmpOp->m_iNonMaxSize = childNode.GetValueInt(_T("Non_Max_Size"));
		}
		else if (iOpType == OP_SHITOMASICORNER)
		{
			COpShiTomasiCorner* pTmpOp = new COpShiTomasiCorner;
			m_OpArray.Add(pTmpOp);

			pTmpOp->m_iMaxCorners = childNode.GetValueInt(_T("MaxCorner"));
			pTmpOp->m_dQualityLevel = childNode.GetValueDouble(_T("QualityLevel"));
			pTmpOp->m_dMinDist = childNode.GetValueDouble(_T("MinDist"));
			pTmpOp->m_iBlockSize = childNode.GetValueInt(_T("BlockSize"));
			if (childNode.GetValueBool(_T("UseHarris"))) pTmpOp->m_dK = true;
			else pTmpOp->m_dK = false;
			pTmpOp->m_dK = childNode.GetValueDouble(_T("K"));
		}
		else if (iOpType == OP_CUSTOMFUNC1)
		{
			COpCustomFunc1* pTmpOp = new COpCustomFunc1;
			m_OpArray.Add(pTmpOp);
		}
		else if (iOpType == OP_CUSTOMFUNC2)
		{
			COpCustomFunc2* pTmpOp = new COpCustomFunc2;
			m_OpArray.Add(pTmpOp);
		}

		int iLastIndex = m_OpArray.GetCount() - 1;
		COperation* pOp = m_OpArray.GetAt(iLastIndex);

		pOp->SetInputImgIndex(childNode.GetValueInt(_T("Input_Image_No")));
		pOp->SetSecondImgIndex(childNode.GetValueInt(_T("Mask_Image_No")));
		pOp->SetShowDisplayImage(childNode.GetValueBool(_T("Show_Display_Image")));		

		pOp->SetMarkerColor(childNode.GetValueInt(_T("Marker_Color_R"), 255), childNode.GetValueInt(_T("Marker_Color_G"), 255), childNode.GetValueInt(_T("Marker_Color_B"), 255));
		pOp->SetMarkerSize(childNode.GetValueInt(_T("Marker_Size"), 10));
	}

	return FALSE;
}

