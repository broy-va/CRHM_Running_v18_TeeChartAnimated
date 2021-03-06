#pragma once


// CConstruct dialog

class CConstruct : public CDialog
{
	DECLARE_DYNAMIC(CConstruct)

public:
	CConstruct(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CConstruct();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = CONSTRUCT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	virtual BOOL OnInitDialog();
	CListBox listbox_all_modules;
	CListBox listbox_selected_modules;
	afx_msg void OnBnClickedButton8();
};
