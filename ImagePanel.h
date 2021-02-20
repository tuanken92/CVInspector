#pragma once

#include "ImScrollHelper.h"
// CImagePanel



#define FIT_NONE		0
#define FIT_X			1
#define FIT_Y			2
#define FIT_XY			3
#define FIT_STRETCH		4


class CImagePanel : public CStatic
{
	DECLARE_DYNAMIC(CImagePanel)

public:
	CImagePanel();
	virtual ~CImagePanel();	

	// ǥ���� �̹��� ����
	void SetImage(char* pImageData, int iWidth, int iHeight, int iChannel, BOOL bDisplayUpdate = FALSE);

	// ��, ��� caption ǥ�ø� ���� ����
	void SetCaption(int iIndex, CString strText);
	void SetCaptionShow(BOOL bShow);
	void SetCaptionColor(int iRed, int iGreen, int iBlue);
	void DeleteAllCaptions();

	// ROI ǥ��
	void SetROIShow(BOOL bShow);

		// �̹��� �ٽ� ǥ���ϱ�
	void UpdateDisplay();

	// ROI ����
	void SetROI(int iROINo, CRect rect);
	void DrawROIArea(CDC* pDC);
		
private:
	int	m_iWidth;
	int m_iHeight;
	int m_iChannel;
	char* m_pImageData;

	CRect m_DisplayRect;
	CRect m_PanelRect;

	CStringArray	m_strTextArray;

	BOOL m_bShowCaption;
	BOOL m_bShowROI;

	COLORREF m_CaptionColor;

	CRect m_ROIRect[32];		

	int m_iPixelValue[3];	//  R, G, B ��
	
	void DrawImage(CDC* pDC);
	void DisplayCaption(CDC* pDC);
	void DisplayText(CDC* pDC, CPoint ptTextPosition, CString strText, COLORREF TextColor);

	void FillBitmapInfo(BITMAPINFO* bmi, int width, int height, int bpp);

	CPoint m_ptOld;

protected:
	DECLARE_MESSAGE_MAP()

	CPoint m_ptROIStart;
	CPoint m_ptROIEnd;
	void DrawZoomRect(CDC * pDC);


	
public:
	afx_msg void OnPaint();		
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);


	im::CImScrollHelper m_ScrollHelper;
	// rect tracker
	int m_iFitToScreen;
	BOOL m_bUseRectTracker;
	CRectTracker m_tracker;
	void SetRectTrackerScreen(CRect modelRect);
	CRect GetRectTrackerScreen(void);
	void SetRectTrackerImage(CRect modelrect);
	CRect GetRectTrackerImage(void);
	CRect GetviewSize(void);
	void SetUseRectTracker(BOOL bUse);
	CPoint ScreenPosToImagePos(CPoint ptScreen);
	CPoint ImagePosToScreenPos(CPoint ptImage);
};


