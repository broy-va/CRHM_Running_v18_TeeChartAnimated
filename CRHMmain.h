#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "CString"
#include "Common.cpp"
#include "TStringList.h"
#include "boost/shared_ptr.hpp"
#include "ClassCRHM.h"
#include <map>
#include <iostream>



class TSeries {
public:
	double *XValues;
	float *YValues;
	int Tag;
	int MaxCnt;
	int Used;
	string Title;
	TSeries(int Cnt) { MaxCnt = Cnt; XValues = new double[MaxCnt]; YValues = new float[MaxCnt]; Used = 0; };
	~TSeries() { delete[] XValues; delete[] YValues; };
	void AddXY(double X, float Y) { XValues[Used] = X; YValues[Used++] = Y; };
	int Count(void) { return Used; };
	double XValue(int nn) { return XValues[nn]; };
	float YValue(int nn) { return YValues[nn]; };
};



class Classinfo {
public:
	Classinfo() : thisPar(NULL), rootinfo(NULL), matched(false), cnt(0) {};
	Classinfo(ClassPar *thisPar) : thisPar(thisPar), rootinfo(NULL), matched(false), cnt(0) {};
	ClassPar *thisPar;
	Classinfo *rootinfo;
	long cnt;
	bool matched;
};

class CRHMmain
{


static CRHMmain* instance;

public:
	static CRHMmain *  getInstance();
	CRHMmain();

	//virtual void DoPrjOpen(string OpenNamePrj, string ProjectDirectory);

	string OpenNamePrj;
	string OpenNameState;
	//string OpenNamePar;
	string OpenNameObs;
	string OpenNameReport;

	//	string ProjectDirectory;
	string ApplicationDir;

	TStringList *ListBox1;
	TStringList *ListBox2;
	TStringList *ListBox3;
	TStringList *ListBox4;

	

	TStringList *ObsFilesList;
	TStringList *ProjectList;

	bool OpenStateFlag;

	//double ProjectFileDate;
	double Dt0; // used to ca


	string ProjectDir;// = ApplicationDir;
	string ProjectDirectory;

	string SaveDialogPrj;
	
	
	
	TStringList *OpenDLLs;
	TStringList *PrjObsHelp;
	TStringList *ListHruNames;
	TStringList *LoopList;  // used by ControlReadState
	MapstrSS    *MapGrpNames;

	bool SaveStateFlag;
	bool ProjectOpen;
	bool ShiftDown; // Linked to ListBox1 and ListBox2

	typedef __declspec(dllimport) void LoadModuleType(string DllName);

//	TDateTime ProjectFileDate;

	TSeries **cdSeries;
	long SeriesCnt;

	~CRHMmain();

	void __fastcall DoPrjOpen(string OpenNamePrj, string ProjectDirectory);

	void FormCreate(void);

	void InitModules(void);

	void Label4Click(void);

	CRHM::TFun FindObservationType(string Kind);

	void SqueezeParams(void);

	void SetBasinParams(ClassPar * basinPar);

	void MacroLoad(void);

	string DeclObsName(ClassVar * thisVar);

	bool OpenObsFile(string FileName);

	void ObsCloseClick(void);

	void ObsFileClose(void);

	void FormDestroy(void);

	void FreeChart1(void);

	bool FileExistsSp(string FileName);

	bool FindFileName(string & FileName);

	

	//Global global;

	

	CRHM::TFun Funct = CRHM::FOBS;

	int InitModCnt = 0;
	int InitMacroCnt = 0;

	ClassPar *StatePar = NULL; // used to handle basin StateVars_to_Handle


	TStringList * getObservations();

	TStringList * getAllmodules();

	TStringList* getVariables();

	void RunClick();
	void AllRprt();
	void  ControlReadState(bool MainLoop, ClassPar * VarPar);
	void  LastRprt(void);
	void  ControlSaveState(bool MainLoop, ClassPar * VarPar, BitSet &Bit);
	void DoObsStatus(bool &First);
	void RprtHeader(TStringList *LogList, int LocalCnt);
	void ResetLoopList(void);
	void ReadStateFile(bool & GoodRun);
	string DttoStr(double D);
	string inttoStr(int I);
	void LogMessageX(const char *S);

	void SaveProject(string description);

	void SaveProject();

	double GetStartDate();
	void setStartDate(double sdate);
	double GetEndDate();
	void setEndDate(double edate);
	TStringList* getSelectedVariables();
	void setSelectedVariables(TStringList * t);
	TStringList* getSelectedObservatoions();
	void setSelectedObservatoions(TStringList * t);
};



//class Classinfo; // used to process shared parameters




