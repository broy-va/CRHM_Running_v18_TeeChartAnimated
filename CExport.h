#pragma once


// CExport dialog

class CExport : public CDialog
{
	DECLARE_DYNAMIC(CExport)

public:
	CExport(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CExport();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EXPORT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
