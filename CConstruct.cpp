// CConstruct.cpp : implementation file
//

#include "stdafx.h"
#include "CRHM_GUI.h"
#include "CConstruct.h"
#include "afxdialogex.h"
#include "TStringList.h"
#include "CRHMmain.h"


// CConstruct dialog

IMPLEMENT_DYNAMIC(CConstruct, CDialog)

CConstruct::CConstruct(CWnd* pParent /*=nullptr*/)
	: CDialog(CONSTRUCT_DLG, pParent)
{

}

CConstruct::~CConstruct()
{
}

void CConstruct::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, listbox_all_modules);
	DDX_Control(pDX, IDC_LIST1, listbox_selected_modules);
}


BEGIN_MESSAGE_MAP(CConstruct, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON8, &CConstruct::OnBnClickedButton8)
END_MESSAGE_MAP()


// CConstruct message handlers



BOOL CConstruct::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	TStringList* all_modules = CRHMmain::getInstance()->getAllmodules();

	for (int ii = 0; ii <all_modules->Count; ii++) {
		//string s = variables->Strings[ii];
		std::string s = all_modules->Strings[ii];
		CString c_all_modules(s.c_str());
		listbox_all_modules.AddString(c_all_modules);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CConstruct::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here

	CString str;

	int index = listbox_all_modules.GetCurSel();
	listbox_all_modules.GetText(index, str);
	listbox_selected_modules.AddString(str);

}
