#pragma once


// MainCRHMForm dialog

class MainCRHMForm : public CDialogEx
{
	DECLARE_DYNAMIC(MainCRHMForm)

public:
	MainCRHMForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MainCRHMForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = MAIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
