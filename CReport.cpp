// CReport.cpp : implementation file
//

#include "stdafx.h"
#include "CRHM_GUI.h"
#include "CReport.h"
#include "afxdialogex.h"


// CReport dialog

IMPLEMENT_DYNAMIC(CReport, CDialog)

CReport::CReport(CWnd* pParent /*=nullptr*/)
	: CDialog(REPORT_DLG, pParent)
{

}

CReport::~CReport()
{
}

void CReport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CReport, CDialog)
END_MESSAGE_MAP()


// CReport message handlers
