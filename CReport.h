#pragma once


// CReport dialog

class CReport : public CDialog
{
	DECLARE_DYNAMIC(CReport)

public:
	CReport(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CReport();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = REPORT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
