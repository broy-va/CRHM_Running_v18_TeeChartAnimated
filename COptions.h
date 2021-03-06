#pragma once
#include "CTChart.h"

// COptions dialog

class COptions : public CDialogEx
{
	DECLARE_DYNAMIC(COptions)

public:
	COptions(CWnd* pParent = nullptr);   // standard constructor
	virtual ~COptions();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = MAIN_DLG };
#endif

protected:
	// DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
public:
	CTChart mChart1;
	void initChart();
	afx_msg void OnFileOpen();
};
