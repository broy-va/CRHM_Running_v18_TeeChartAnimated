#pragma once


// ResourceDlg dialog

class ResourceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ResourceDlg)

public:
	ResourceDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ResourceDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = MAIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
