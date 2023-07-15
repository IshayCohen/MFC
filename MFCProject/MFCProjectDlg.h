
// MFCProjectDlg.h : header file
//

#pragma once
#include <stack>
#include "Figure2D.h"

using namespace std;
// CMFCProjectDlg dialog
class CMFCProjectDlg : public CDialogEx
{
// Construction
public:
	CMFCProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	
	boolean lButtonPressed = false;
	boolean rButtonPressed = false;
	int indexToResize=-1;
	CPoint startPoint;
	CPoint endPoint;
	CTypedPtrArray<CObArray, Figure2D*> figures;
	stack<Figure2D*>undone;
	




// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	enum FigureTypes { Rectangle, Square, Circle, Ellipse, Line, Diamond };
	

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButton3();
	CButton button3Var;
	afx_msg void OnBnClickedButton1();
	CButton stamBtn1;
	FigureTypes figureType=Line;
	COLORREF currentLineColor,currentShapeBackgroundColor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedDeleteall();
	afx_msg void OnBnClickedSavebutton();
	afx_msg void OnBnClickedLoadbutton();
	afx_msg void OnBnClickedChangecolor();
	afx_msg void OnBnClickedChangelinecolor();
	afx_msg void OnBnClickedLinecolor();
	afx_msg void OnBnClickedBackgroundcolor();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedMoveobjectbutton();
};
