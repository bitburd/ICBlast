// ICBlastTestBenchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastTestBenchDlg.h"
#include "ICBlastProjectIO.h"
#include "stdio.h"
#include "ICBlastAnalogue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;
extern ASIG signals[40];
extern ICBlastTestBenchDlg TestBenchDlg;

/////////////////////////////////////////////////////////////////////////////
// ICBlastTestBenchDlg dialog


ICBlastTestBenchDlg::ICBlastTestBenchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastTestBenchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastTestBenchDlg)
	m_volt = FALSE;
	m_testvolt = _T("");
	m_testrange = _T("");
	m_testbias = _T("");
	m_range = FALSE;
	m_noise = FALSE;
	m_distortion = FALSE;
	m_bias = FALSE;
	//}}AFX_DATA_INIT
}


void ICBlastTestBenchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastTestBenchDlg)
	DDX_Control(pDX, IDC_TESTNAME, m_testname);
	DDX_Control(pDX, IDC_TESTITEM, m_testitem);
	DDX_Check(pDX, IDC_VOLTAGE, m_volt);
	DDX_Text(pDX, IDC_TESTVOLT, m_testvolt);
	DDX_Text(pDX, IDC_TESTRANGE, m_testrange);
	DDX_Text(pDX, IDC_TESTBIAS, m_testbias);
	DDX_Check(pDX, IDC_NOISE, m_noise);
	DDX_Check(pDX, IDC_DISTORTION, m_distortion);
	DDX_Check(pDX, IDC_BIAS, m_bias);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastTestBenchDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastTestBenchDlg)
	ON_BN_CLICKED(IDC_TBFILE, OnTbfile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastTestBenchDlg message handlers

void ICBlastTestBenchDlg::OnOK() 
{
	// TODO: Add extra validation here
	char testname[256] = "";

	
	if(TestBenchDlg.m_testname.m_hWnd != NULL){
		TestBenchDlg.m_testname.GetWindowText(testname, sizeof(testname));
		
		if(testname == "")
			MessageBox("Enter a testname and then press ok","Error",MB_OK);
		else {
			FILE *testfile;
			testfile = fopen(testname,"wt");
			
			fprintf(testfile, "-- ICBlast %s testbench file\n", testname);
			fprintf(testfile, "signal ");
			
			fprintf(testfile, "process (");
			
			for(int i=0; i<ProjIO.nsig; ++i)
				fprintf(testfile, "%s ", signals[i].name);
			
			fprintf(testfile, ") : std_logic\n\n");
			
			fprintf(testfile, "begin\nend\n");
			
			fclose(testfile);
		}
	}else
		MessageBox("Path or file name error!","Error saving test",MB_OK);
	

	if(testname != "")
		CDialog::OnOK();

}

void ICBlastTestBenchDlg::OnTbfile() 
{
	// TODO: Add your control notification handler code here
	char filename[256];

	//save project data to file
	// TODO: Add your command handler code here
	char szFileDialogExt[] = "v";
    static char BASED_CODE szFilter[] = "Testbench Files (*.v)|All Files (*.*)|*.*||";


    OPENFILENAME ofn;
    ofn.lpstrTitle = "Save Testbench To";
    GetSaveFileName(&ofn);

    //CFileDialog fileDialog(TRUE, szFileDialogExt, NULL,
    //     OFN_HIDEREADONLY | OFN_ENABLETEMPLATE, szFileDialogFilter);
	CFileDialog fileDialog(FALSE, szFileDialogExt, NULL,
          OFN_HIDEREADONLY, szFilter);

	fileDialog.m_ofn.lpTemplateName = "OPENFILENAME";
	sprintf(filename, "%s.icp", ProjIO.projname);
	fileDialog.m_ofn.lpstrFile = filename;

    if (fileDialog.DoModal() == IDOK) {
		CString filen;
		char filenstr[256];
		filen = fileDialog.GetFileName();
		if(filen.IsEmpty() == FALSE){
		   //_tcscpy(filenstr, filen);
			if(filen != ""){
			   char pathname[100];
		       sprintf(pathname, "%s", fileDialog.GetPathName() );
		       TestBenchDlg.m_testname.SetWindowText(pathname);
			}
		}
		else {
		   int ret = MessageBox("You must type a file name first!","Filename?",MB_ICONEXCLAMATION|MB_OKCANCEL);
		   if(ret = IDOK)
			   fileDialog.ShowWindow(SW_SHOW);
		   else
			   fileDialog.CloseWindow();
		}
	}

}
