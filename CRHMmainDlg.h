#include "CTChart.h"

#pragma once


// CRHMmainDlg dialog

class CRHMmainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRHMmainDlg)

public:
	CRHMmainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRHMmainDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = CRHMmainDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	CListBox listbox_varaiables_all;
	CListBox list_box_variables_selected;
	void loadGuiComponents();
	CListBox listbox_observations;
	void FormActivate();
	afx_msg void OnRun32811();
	CTChart tchart;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	virtual BOOL OnInitDialog();
	CDateTimeCtrl DateTimePicker1;
	CDateTimeCtrl DateTimePicker2;
	afx_msg void OnLbnSelchangeList5();
	afx_msg void OnLbnSelchangeList2();
	CListBox listbox_observations_selected;
	afx_msg void OnBuildConstruct();
	afx_msg void OnRunRunmodel();
	afx_msg void OnFileSave();
};
