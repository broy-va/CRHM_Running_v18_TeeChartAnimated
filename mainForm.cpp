// mainForm.cpp : implementation file
//

#include "stdafx.h"
#include "CRHM_GUI.h"
#include "mainForm.h"
#include "afxdialogex.h"


// mainForm dialog

IMPLEMENT_DYNAMIC(mainForm, CDialogEx)

mainForm::mainForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(MAIN_DLG, pParent)
{

}

mainForm::~mainForm()
{
}

void mainForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mainForm, CDialogEx)
END_MESSAGE_MAP()


// mainForm message handlers
