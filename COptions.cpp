// COptions.cpp : implementation file
//

#include "stdafx.h"
#include "CRHM_GUI.h"
#include "COptions.h"
#include "afxdialogex.h"

#include "CTitles.h"
#include "CAspect.h"
#include "CLegend.h"
#include "CSeries.h"
#include "CColorGridSeries.h"
#include "CPen0.h"

#include <tchar.h>
/*
TCHAR var1[] = _T("1");
TCHAR var2[] = _T("2");
TCHAR var3[] = _T("3");
TCHAR var4[] = _T("4");
TCHAR var5[] = _T("5");
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct points {
	//vector <const wchar_t *> x;
	//vector <double> y;

	int add(CSeries chart_series, const wchar_t * point_x, double point_y) {
		//x.push_back(point_x);
		//y.push_back(point_y);
		chart_series.Add(point_y, point_x, 1);
		return 0;
	}
} chart1;

//#define _UNICODE

// COptions dialog

IMPLEMENT_DYNAMIC(COptions, CDialogEx)

COptions::COptions(CWnd* pParent /*=nullptr*/)
	: CDialogEx(MAIN_DLG, pParent)
	, mChart1()
{

}

COptions::~COptions()
{
}


void COptions::initChart()
{
	
}



BEGIN_MESSAGE_MAP(COptions, CDialogEx)
	ON_COMMAND(ID_FILE_OPEN, &COptions::OnFileOpen)
END_MESSAGE_MAP()


// COptions message handlers


void COptions::OnFileOpen()
{
	// TODO: Add your command handler code here

	AfxMessageBox(_T("message test"));
}
