// CRHMmainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CRHM_GUI.h"
#include "CRHMmainDlg.h"
#include "afxdialogex.h"
#include "CRHMmain.h"
#include "CSeries.h"
#include "CConstruct.h"

// CRHMmainDlg dialog

IMPLEMENT_DYNAMIC(CRHMmainDlg, CDialogEx)

#define MAX_CFileDialog_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)

CRHMmainDlg::CRHMmainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CRHMmainDialog, pParent)
{
	CRHMmain *test = CRHMmain::getInstance();
	test->FormCreate();
	FormActivate();

}

CRHMmainDlg::~CRHMmainDlg()
{
}

void CRHMmainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST5, listbox_varaiables_all);
	DDX_Control(pDX, IDC_LIST3, list_box_variables_selected);
	DDX_Control(pDX, IDC_LIST2, listbox_observations);
	DDX_Control(pDX, IDC_TCHART1, tchart);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, DateTimePicker1);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, DateTimePicker2);
	DDX_Control(pDX, IDC_LIST4, listbox_observations_selected);
}


BEGIN_MESSAGE_MAP(CRHMmainDlg, CDialogEx)
	ON_COMMAND(ID_FILE_OPEN, &CRHMmainDlg::OnFileOpen)
	//ON_COMMAND(ID_RUN32811, &CRHMmainDlg::OnRun32811)
	ON_BN_CLICKED(IDC_BUTTON5, &CRHMmainDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CRHMmainDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CRHMmainDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CRHMmainDlg::OnBnClickedButton8)
	ON_LBN_SELCHANGE(IDC_LIST5, &CRHMmainDlg::OnLbnSelchangeList5)
	ON_LBN_SELCHANGE(IDC_LIST2, &CRHMmainDlg::OnLbnSelchangeList2)
	ON_COMMAND(ID_BUILD_CONSTRUCT, &CRHMmainDlg::OnBuildConstruct)
	ON_COMMAND(ID_RUN_RUNMODEL, &CRHMmainDlg::OnRunRunmodel)
	ON_COMMAND(ID_FILE_SAVE, &CRHMmainDlg::OnFileSave)
END_MESSAGE_MAP()


// CRHMmainDlg message handlers


void CRHMmainDlg::OnFileOpen()
{
	 //TODO: Add your command handler code here

	CFile theFile;
	TCHAR szFilters[] = _T("MyType Files (*.prj)|*.prj|All Files (*.*)|*.*||");

//	CFileDialog fileDlg = CFileDialog(TRUE, _T(".txt"), NULL, 0, strFilter);


	CString fileName;
	wchar_t* p = fileName.GetBuffer(FILE_LIST_BUFFER_SIZE);
//	CFileDialog fileDlg(TRUE);
//	OPENFILENAME& ofn = fileDlg.GetOFN();


	CFileDialog fileDlg(TRUE, _T("prj"), _T("*.prj"),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

//	ofn.Flags |= OFN_ALLOWMULTISELECT;
//	ofn.lpstrFile = p;
//	ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;

	//CFileDialog filedlg = CFileDialog(true;

	CRHMmain *test = CRHMmain::getInstance();

	// Display the file dialog. When user clicks OK, fileDlg.DoModal()
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		CString filepath = fileDlg.GetPathName();

		CString filename = fileDlg.GetFileName();
		//m_left.SetWindowText(m_strPathname);

		
		 string file_p = CT2A(filepath.GetString());
		 string file_n = CT2A(filename.GetString());

		 test->DoPrjOpen(file_p,file_n);
		 loadGuiComponents();

	}


}

void CRHMmainDlg::loadGuiComponents()
{

	std::string s = "Hello";

	// get temporary LPSTR (not really safe)
	LPSTR pst = &s[0];
	// get temporary LPCSTR (pretty safe)
	LPCSTR pcstr = s.c_str();


	CRHMmain* crhm_core = CRHMmain::getInstance();
	
	TStringList* variables = CRHMmain::getInstance()->getVariables();

	for (int ii = 0; ii < variables->Count; ii++) {

		//string s = variables->Strings[ii];


		std::string s = variables->Strings[ii];

		CString cvariables(s.c_str());

		listbox_varaiables_all.AddString(cvariables);
		
		
	}


	TStringList* observations = CRHMmain::getInstance()->getObservations();

	for (int ii = 0; ii <observations->Count; ii++) {
		//string s = variables->Strings[ii];
		std::string s = observations->Strings[ii];
		CString observations(s.c_str());
		listbox_observations.AddString(observations);
	}

	TStringList* sel_variables = CRHMmain::getInstance()->getSelectedVariables();

	for (int ii = 0; ii <sel_variables->Count; ii++) {
		//string s = variables->Strings[ii];
		std::string s = sel_variables->Strings[ii];
		CString observations(s.c_str());
		//listbox_variables_selected.AddString(observations);
		list_box_variables_selected.AddString(observations);
	}

	TStringList* sel_observations = CRHMmain::getInstance()->getSelectedObservatoions();

	for (int ii = 0; ii <sel_observations->Count; ii++) {
		//string s = variables->Strings[ii];
		std::string s = sel_observations->Strings[ii];
		CString observations(s.c_str());
		//listbox_o.AddString(observations);
		listbox_observations_selected.AddString(observations);
	}

	CRHMmain *test = CRHMmain::getInstance();

	COleDateTime oletimeTime(test->GetStartDate());
	VERIFY(DateTimePicker1.SetTime(oletimeTime));


	COleDateTime oletimeTime2(test->GetEndDate());
	VERIFY(DateTimePicker2.SetTime(oletimeTime2));


	////conversion mechanism
	//COleDateTime time = COleDateTime(1660,5,10,0,0,0);
	//double t = time; //encoding.
	//COleDateTime time2 = COleDateTime(t); //decoding.	

}

void CRHMmainDlg::FormActivate()
{
	//This is for the about box.


	//#ifdef CRHM_DLL
	//#ifdef NO_MODULES
	//	AboutBox->Label2->Caption = String("Version: CRHM_DLL_NONE ") + CurrentVersion;
	//#else CRHM_2
	//	AboutBox->Label2->Caption = String("Version: CRHM_DLL ") + CurrentVersion;
	//#endif
	//#elif defined CRHM_2
	//	AboutBox->Label2->Caption = String("Version: CRHM ") + CurrentVersion;
	//#elif defined QUINTON
	//	AboutBox->Label2->Caption = String("Version: CRHM_QUINTON ") + CurrentVersion;
	//#else
	//	AboutBox->Label2->Caption = String("Version: CRHM ") + Global::CurrentVersion;
	//#endif

	//Global::crhmLog = LogForm->Handle;

	//for (int pp = 0; pp < ParamCount(); ++pp) {
	//	String FileS = ParamStr(pp + 1);
	//	if (FileExistsSp(FileS)) {
	//		if (LowerCase(ExtractFileExt(FileS)) == ".prj") {

	//			CommandLine = true;  // handle autorun differently

	//			OpenDialogPrj->FileName = FileS;
	//			OpenDialogPrj->InitialDir = ExtractFilePath(AnsiReplaceStr(OpenDialogPrj->FileName, "/", "\\")); // Fix for "C:/Program files/CRHM/Examples
	//			if (OpenDialogPrj->InitialDir.IsEmpty())
	//				OpenDialogPrj->InitialDir = GetCurrentDir();

	//			SetCurrentDir(OpenDialogPrj->InitialDir);
	//			OpenDialogObs->InitialDir = OpenDialogPrj->InitialDir;

	//			FileDefaults(Sender);
	//			DoPrjOpen(Sender);
	//		}
	//		else if (LowerCase(ExtractFileExt(FileS)) == ".obs") {
	//			TDateTime Dt = TDateTime::CurrentDateTime();
	//			Chart->Title->Text->Clear();
	//			Chart->Title->Text->Add("Current Date: " + Dt.DateString() + FormatDateTime(" hh:mm", Dt));

	//			OpenDialogObs->FileName = FileS;
	//			String path = ExtractFilePath(AnsiReplaceStr(OpenDialogObs->FileName, "/", "\\")); // Fix for "C:/Program files/CRHM/Examples
	//			if (path.IsEmpty()) {
	//				path = GetCurrentDir();
	//				FileS = path + "\\" + FileS;
	//			}
	//			OpenDialogObs->InitialDir = path;
	//			OpenObsFile(Sender, FileS);

	//			int iFileHandle = FileOpen(FileS, fmOpenRead);
	//			int T = FileGetDate(iFileHandle);
	//			ProjectFileDate = FileDateToDateTime(T);
	//			char Buf[121];
	//			FileRead(iFileHandle, Buf, 120);
	//			String C(Buf);
	//			int n = C.Pos("\r");
	//			C.SetLength(n - 1);
	//			FileClose(iFileHandle);
	//			String SS = ProjectFileDate.DateString() + FormatDateTime(" hh:mm", ProjectFileDate);

	//			Chart->SubTitle->Text->Clear();
	//			Chart->SubTitle->Text->Add(FileS + " Last modified: " + SS);
	//			Chart->SubTitle->Text->Add("Description: " + C);
	//		}
	//		else if (LowerCase(ExtractFileExt(FileS)) == ".par") {
	//			if (!CommandLine) // cannot change parameters unless project loaded
	//				continue;

	//			ifstream DataFile;
	//			int c, Cols;
	//			string ss;

	//			bool TooFewHRUs = false;
	//			string module, param, Descrip, Line, S, s;
	//			ClassPar *thisPar;

	//			OpenDialogPar->FileName = FileS;
	//			String path = ExtractFilePath(AnsiReplaceStr(OpenDialogPar->FileName, "/", "\\")); // Fix for "C:/Program files/CRHM/Examples
	//			if (path.IsEmpty()) {
	//				path = GetCurrentDir();
	//				FileS = path + "\\" + FileS;
	//			}
	//			OpenDialogPar->InitialDir = path;

	//			DataFile.open(OpenDialogPar->FileName.c_str());
	//			if (!DataFile) {
	//				Application->MessageBox("cannot open file", "File Error", MB_OK);
	//				return;
	//			}

	//			getline(DataFile, Descrip);
	//			DataFile.ignore(80, '#');
	//			getline(DataFile, Line);

	//			RemoveSharedParams(); // change shared parameters to module parameters

	//			while (!DataFile.eof()) {
	//				DataFile.clear();

	//				DataFile >> module;
	//				if (module[1] == '#') break;
	//				DataFile >> param;
	//				if (DataFile.eof()) return; // final exit

	//				DataFile.ignore(80, '\n'); // need for character input, why?
	//				S = "";

	//				do {
	//					getline(DataFile, ss);
	//					S += ss + ' ';
	//					while (c = DataFile.peek(), iscntrl(c) || isspace(c))
	//						DataFile.get();

	//				} while (c = DataFile.peek(), !isalpha(c) && c != '#' && !DataFile.eof());

	//				string Sc = S; // use copy
	//				string::iterator pos; // first handle single quotes
	//				bool inField = false;

	//				for (pos = Sc.begin(); pos != Sc.end(); ++pos) {
	//					if (*pos == '\'')
	//						inField = !inField;
	//					if (inField && *pos == ' ')
	//						*pos = '_';
	//				}

	//				istringstream instr; // count columns
	//				instr.clear();
	//				instr.str(Sc);
	//				Cols = 0;
	//				for (;;) {
	//					instr >> s;
	//					if (instr.fail()) break;
	//					++Cols; // # of HRU's in Basin
	//				}

	//				if (module == "Shared") {
	//					// write shared parameters to module parameters
	//					// all parameter values are set to shared values.  If re-defined in a module will be changed.
	//					MapPar::iterator itPar;
	//					for (itPar = Global::MapPars.begin(); itPar != Global::MapPars.end(); ++itPar) {
	//						thisPar = (*itPar).second;
	//						if (thisPar->param == string(param)) {
	//							if (thisPar->dim == Cols / thisPar->lay) // find module parameter for template thisPar->varType == CRHM::Int || thisPar->varType == CRHM::Float ||
	//								break;
	//							else if (thisPar->varType == CRHM::Txt && thisPar->dimen < CRHM::NHRU) // text can have variable length
	//								break;
	//							else { // Added to handle 2D parameters
	//								if (thisPar->param == string(param) && (thisPar->dim == Cols / thisPar->dim))
	//									break;
	//								else
	//									thisPar = NULL;
	//							}
	//						}
	//					}
	//				}
	//				else
	//					thisPar = ClassParFind(module, param); // find module parameter for template

	//				if (thisPar) {
	//					ClassPar *newPar = new ClassPar(*thisPar);
	//					newPar->module = module; // set module name
	//					if (thisPar->varType == CRHM::Txt) {
	//						newPar->Strings->DelimitedText = S.c_str();
	//					}
	//					else {
	//						istringstream instr; // count columns
	//						instr.clear();
	//						instr.str(S);
	//						for (int jj = 0; jj<thisPar->lay; jj++) {
	//							for (int ii = 0; ii < newPar->dim; ii++) {

	//								if (newPar->varType == CRHM::Float)
	//									instr >> newPar->layvalues[jj][ii];
	//								else if (newPar->varType == CRHM::Int) {
	//									float x;
	//									instr >> x;
	//									newPar->ilayvalues[jj][ii] = x;
	//								}
	//							}

	//							if (newPar->dim > Cols) {
	//								if (!TooFewHRUs) {
	//									Application->MessageBox("Too few HRUs defined in the Project file",
	//										"parameters not complete", MB_OK);
	//									TooFewHRUs = true;
	//								}

	//								for (int ii = Cols; ii < newPar->dim; ii++)
	//									if (newPar->varType == CRHM::Float)
	//										newPar->layvalues[jj][ii] = newPar->layvalues[jj][ii - 1];
	//									else
	//										newPar->ilayvalues[jj][ii] = newPar->ilayvalues[jj][ii - 1];
	//							}
	//						}
	//					}

	//					if (module == "Shared") {
	//						SetSharedParams(newPar); // copy template parameter to basin module
	//						delete newPar;
	//					}
	//					else
	//						ClassParSet(newPar);  // can delete newPar!
	//				}
	//				else {
	//					CRHMException Except("Unknown Module Parameter: " + string(module) + " -> " + string(param) +
	//						" in " + string(OpenDialogPrj->FileName.c_str()), ERR);
	//					Application->MessageBox(Except.Message.c_str(), "Unknown Parameter in project file", MB_OK);
	//					LogError(Except);

	//					while (c = DataFile.peek(), !isalpha(c) && c != '#')
	//						DataFile.ignore(256, '\n');
	//				}
	//			} // while

	//			DataFile.close();

	//			SqueezeParams(Sender);  // converts identical parameters to shared parameters
	//		}
	//		else
	//			Application->MessageBox(String(FileS + " - file extension not 'prj', 'obs' or 'par'").c_str(), "Problem with File extension", MB_OK);
	//	}
	//	else
	//		Application->MessageBox(String(FileS + " - file does not exist").c_str(), "Problem with File", MB_OK);
	//}  // for param

	//if (PrjAutoRun->Checked) {
	//	if (!Global::OurModulesList->Count && ListBox4->Items->Count) {
	//		if (Last1->Checked) LastRprtObs(Sender);
	//		if (All1->Checked) AllRprtObs(Sender);
	//		if (DebugScreen1->Checked) DebugScreen1Rprt(Sender);
	//		if (SummaryScreen1->Checked) SummaryScreen1Rprt(Sender);
	//	}
	//	else
	//		RunClick(Sender);

	//	Main->Refresh();
	//}

	//CommandLine = false;

	//if (PrjAutoExit->Checked && !PlotControl->IntervalControl && (All1->Checked || Last1->Checked || DebugScreen1->Checked || SummaryScreen1->Checked)) {
	//	Close();
	//}

	//biweekly1->Checked = true; // keep in step with UpdateForm
} // end of FormActivate



//void CRHMmainDlg::OnRun32811()
//{
//	// TODO: Add your command handler code here
//	CRHMmain *test = CRHMmain::getInstance();
//	test->RunClick();
//	test->cdSeries[0];
//
//
//	int seriesIndex = 0;
//	CSeries series1 = tchart.Series(seriesIndex);
//
//	string values = "";
//
//
//	for (int i = 0; i < test->cdSeries[seriesIndex]->MaxCnt; i++)
//	{
//		//series1.AddXY(test->cdSeries[seriesIndex]->XValues[i], test->cdSeries[seriesIndex]->YValues[i], _T(""), 0);
//		series1.AddXY(test->cdSeries[seriesIndex]->XValues[i], test->cdSeries[seriesIndex]->YValues[i], _T(""), 0);
//		//values += " " + (float)(test->cdSeries[seriesIndex]->YValues[i]);
//	}
//	
//	seriesIndex = 1;
//	CSeries series2 = tchart.Series(seriesIndex);
//	for (int i = 0; i < test->cdSeries[seriesIndex]->MaxCnt; i++)
//	{
//		//series2.AddXY(test->cdSeries[seriesIndex]->XValues[i], test->cdSeries[seriesIndex]->YValues[i], _T(""), 0);
//		series2.AddXY(test->cdSeries[seriesIndex]->XValues[i], test->cdSeries[seriesIndex]->YValues[i], _T(""), 0);
//	}
//
//}


void CRHMmainDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	CString str, str2;
	int hru_value = 0;

	GetDlgItemText(IDC_EDIT1, str);
	hru_value = _ttoi(str);
	if (str.Trim().GetLength() > 0)
	{
		if (hru_value > 0)
		{
			hru_value = _ttoi(str) - 1;
			str2.Format(_T("%d"), hru_value);
			SetDlgItemText(IDC_EDIT1, str2);
		}
	}
}


void CRHMmainDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here

	CString str, str2;
	int hru_value = 1;

	GetDlgItemText(IDC_EDIT1, str);
	if (str.Trim().GetLength() > 0) { hru_value = _ttoi(str) + 1; }
	str2.Format(_T("%d"), hru_value);
	SetDlgItemText(IDC_EDIT1, str2);
}


void CRHMmainDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here


	CString str, str2;
	int hru_value = 0;

	GetDlgItemText(IDC_EDIT2, str);
	hru_value = _ttoi(str);
	if (str.Trim().GetLength() > 0)
	{
		if (hru_value > 0)
		{
			hru_value = _ttoi(str) - 1;
			str2.Format(_T("%d"), hru_value);
			SetDlgItemText(IDC_EDIT2, str2);
		}
	}
}


void CRHMmainDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here

	CString str, str2;
	int hru_value = 1;

	GetDlgItemText(IDC_EDIT2, str);
	if (str.Trim().GetLength() > 0) { hru_value = _ttoi(str) + 1; }
	str2.Format(_T("%d"), hru_value);
	SetDlgItemText(IDC_EDIT2, str2);
}


BOOL CRHMmainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here


	SetDlgItemText(IDC_EDIT1, _T("1"));
	SetDlgItemText(IDC_EDIT2, _T("3"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CRHMmainDlg::OnLbnSelchangeList5()
{
	// TODO: Add your control notification handler code here

	CString str;

	int index = listbox_varaiables_all.GetCurSel();

	listbox_varaiables_all.GetText(index, str);

	//CString s = listbox_varaiables_all.GetItemData(index);

	list_box_variables_selected.AddString(str);
}


void CRHMmainDlg::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here

	CString str;

	int index = listbox_observations.GetCurSel();
	listbox_observations.GetText(index, str);
	listbox_observations_selected.AddString(str);

}


void CRHMmainDlg::OnBuildConstruct()
{
	// TODO: Add your command handler code here

	CConstruct *build_form;
	TStringList *all_module_list = CRHMmain::getInstance()->getAllmodules();

	build_form = new CConstruct();
	//build_form->UpdateData();

	//	build_form.listbox_all_modules
	//	build_form->listbox_all_modules = new CListBox();

	//build_form->listbox_all_modules.AddString(_T("test"));


	//CListBox *test = &build_form->listbox_all_modules;
	//AddStringListToListBox(test, all_module_list);

	INT_PTR nRet = build_form->DoModal();

}


void CRHMmainDlg::OnRunRunmodel()
{
	// TODO: Add your command handler code here
	CRHMmain *test = CRHMmain::getInstance();
	test->RunClick();
	int seriesCount = test->SeriesCnt;
	
	
	CSeries series[100];
	for (int i = 0; i < seriesCount; i++)
	{
		series[i] = tchart.Series(i);
	}

	
	string values = "";
	int seriesIndex = 0;

	int PerIteration = 25;
	int TotalCount = test->cdSeries[0]->MaxCnt;
	int Iterations = TotalCount / PerIteration;

	int j = 0;
	for (int i = 1; i <= Iterations; i++)
	{
		if (j >= TotalCount) { break; }
		for (int k = 0; k < PerIteration; k++)
		{
			if (j >= TotalCount) { break; }
			for (int n = 0; n < seriesCount; n++)
			{
				series[n].AddXY(test->cdSeries[n]->XValues[j], test->cdSeries[n]->YValues[j], _T(""), 0);
			}
			j++;
			
		}					
		tchart.Repaint();
	}


	
	//int seriesIndex = 0;
	//CSeries series1 = tchart.Series(seriesIndex);
	//for (int i = 0; i < test->cdSeries[seriesIndex]->MaxCnt; i++)
	//{
	//	series1.AddXY(test->cdSeries[seriesIndex]->XValues[i], test->cdSeries[seriesIndex]->YValues[i], _T(""), 0);
	//}
	//	
	//seriesIndex = 1;
	//CSeries series2 = tchart.Series(seriesIndex);
	//for (int i = 0; i < test->cdSeries[seriesIndex]->MaxCnt; i++)
	//{
	//	series2.AddXY(test->cdSeries[seriesIndex]->XValues[i], test->cdSeries[seriesIndex]->YValues[i], _T(""), 0);
	//}


	
}


void CRHMmainDlg::OnFileSave()
{
	// TODO: Add your command handler code here
	TCHAR szFilters[] = _T("MyType Files (*.prj)|*.prj|All Files (*.*)|*.*||");

	//	CFileDialog fileDlg = CFileDialog(TRUE, _T(".txt"), NULL, 0, strFilter);


	CString fileName;
	wchar_t* p = fileName.GetBuffer(FILE_LIST_BUFFER_SIZE);
	//	CFileDialog fileDlg(TRUE);
	//	OPENFILENAME& ofn = fileDlg.GetOFN();


	CFileDialog fileDlg(FALSE, _T("prj"), _T("*.prj"),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);


	bool result = fileDlg.DoModal();

	if (result)
	{
	//	MessageBox(0, dlg->GetPathName(), L"Draw", 0);



	}
}
