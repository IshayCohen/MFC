
// MFCProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCProject.h"
#include "MFCProjectDlg.h"
#include "afxdialogex.h"
#include "Figure2D.h"
#include "myRectangle.h"
#include "myLine.h"
#include "myEllipse.h"
#include "mySquare.h"
#include "myDiamond.h"
#include "myCircle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCProjectDlg dialog



CMFCProjectDlg::CMFCProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCProjectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCProjectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCProjectDlg::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCProjectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCProjectDlg::OnBnClickedRadio2)
	
	ON_BN_CLICKED(IDC_RADIO3, &CMFCProjectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCProjectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCProjectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCProjectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_DELETEALL, &CMFCProjectDlg::OnBnClickedDeleteall)
	ON_BN_CLICKED(IDC_SAVEBUTTON, &CMFCProjectDlg::OnBnClickedSavebutton)
	ON_BN_CLICKED(IDC_LOADBUTTON, &CMFCProjectDlg::OnBnClickedLoadbutton)
	ON_BN_CLICKED(IDC_LineColor, &CMFCProjectDlg::OnBnClickedLinecolor)
	ON_BN_CLICKED(IDC_BackgroundColor, &CMFCProjectDlg::OnBnClickedBackgroundcolor)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CMFCProjectDlg message handlers

BOOL CMFCProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	// TODO: Add extra initialization here
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		for (int i = 0; i < figures.GetSize(); i++)
			figures[i]->draw(&dc);

		CDialogEx::OnPaint();
		
		
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCProjectDlg::OnBnClickedButton3()	
{
	//Redo Button
	if (!undone.empty())
	{
		Figure2D* figure = undone.top();
		figures.Add(figure);
		undone.pop();
		Invalidate();
	}

}
void CMFCProjectDlg::OnBnClickedButton1()
{
	//Undo Button
	if (figures.GetSize() >= 1)
	{
		Figure2D* figure = figures[figures.GetSize() - 1];
		figures.RemoveAt(figures.GetSize() - 1, 1);
		undone.push(figure);
		Invalidate();
	}
}



void CMFCProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	lButtonPressed = true;
	startPoint = endPoint = point;
	switch (figureType)
		{
		case Line:
		{
			figures.Add(new myLine(startPoint, endPoint));
			break;
		}

		case Rectangle:
		{
			figures.Add(new myRectangle(startPoint, endPoint));
			break;

		}
		case Ellipse:
		{
			figures.Add(new myEllipse(startPoint, endPoint));
			break;
		}
		case Square:
		{
			figures.Add(new mySquare(startPoint, endPoint));
			break;
		}
		case Diamond:
		{
			figures.Add(new myDiamond(startPoint, endPoint));
			break;
		}
		case Circle:
		{
			figures.Add(new myCircle(startPoint, endPoint));
			break;
		}
		}

		figures[figures.GetSize() - 1]->setShapeLineColor(currentLineColor);
		figures[figures.GetSize() - 1]->setShapeBackgroundColor(currentShapeBackgroundColor);
	
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CString str;
	CPoint temp;
	str.Format(_T("X:%d , y:%d"), point.x, point.y);
	dc.TextOutW(1176, 547, str);
	
	if (lButtonPressed)
	{
		figures[figures.GetSize() - 1]->setEnd(point);
		Invalidate();

	}
	if ((rButtonPressed) && (indexToResize!=-1))
	{
		figures[indexToResize]->setEnd(point);
		//figures[indexToResize]->setStartByXY(abs(point.x - startPoint.x), abs(point.y - startPoint.y));
		Invalidate();
	}
	
	


		
		CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//if lbutton=true
	// set the end of the line to the point of the mouse
	// set lbuttonpressed=false
	if (lButtonPressed)
	{
		endPoint = point;
		lButtonPressed = false;
		CDialogEx::OnLButtonUp(nFlags, point);

	}
}
void CMFCProjectDlg::OnBnClickedRadio1()
{

	figureType = Rectangle;
}


void CMFCProjectDlg::OnBnClickedRadio2()
{
	
	figureType = Line;

}
void CMFCProjectDlg::OnBnClickedRadio3()
{
	figureType = Ellipse;
}


void CMFCProjectDlg::OnBnClickedRadio4()
{
	//square
	figureType = Square;
}


void CMFCProjectDlg::OnBnClickedRadio5()
{
	//circle
	figureType = Circle;

}


void CMFCProjectDlg::OnBnClickedRadio6()
{
	//diamond
	figureType = Diamond;
}


void CMFCProjectDlg::OnBnClickedDeleteall()
{
		//DELETE ALL
	figures.RemoveAll();
	while (!undone.empty())
			undone.pop();
	Invalidate();
	
}


void CMFCProjectDlg::OnBnClickedSavebutton()
{
	//Save
	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*)|(*)|");
	CFileDialog fDialog (FALSE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	if (fDialog.DoModal() == IDOK) 
	{
		CString filename = fDialog.GetPathName();
		//TRACE(filename);
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figures.Serialize(ar);
		ar.Close();
		file.Close();

	}


}


void CMFCProjectDlg::OnBnClickedLoadbutton()
{
	//Load
	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*)|(*)|");
	CFileDialog fDialog(TRUE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	if (fDialog.DoModal() == IDOK)
	{
		CString filename = fDialog.GetPathName();
		//TRACE(filename);
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figures.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}








void CMFCProjectDlg::OnBnClickedLinecolor()
{
	// TODO: Add your control notification handler code here
	CColorDialog dcolor;
	if (dcolor.DoModal() == IDOK)
	{
		currentLineColor = dcolor.GetColor();
	}
}


void CMFCProjectDlg::OnBnClickedBackgroundcolor()
{
	// TODO: Add your control notification handler code here
	CColorDialog dcolor;
	if (dcolor.DoModal() == IDOK)
	{
		currentShapeBackgroundColor = dcolor.GetColor();
	}
}


void CMFCProjectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnRButtonDown(nFlags, point);
	int i;
	rButtonPressed = true;
	for (i = 0; i < figures.GetSize(); i++)
	{
		if (figures[i]->isInside(point))
		{
			indexToResize = i;
			startPoint = point;
		}
	}
}


void CMFCProjectDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (rButtonPressed)
	{
		endPoint = point;
		rButtonPressed = false;
		indexToResize = -1;
		Invalidate();
		CDialogEx::OnRButtonUp(nFlags, point);

	}
	
}


