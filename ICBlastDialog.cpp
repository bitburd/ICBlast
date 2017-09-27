// ICBlastDialog.cpp : implementation file
//  This code implements the File->new menu..
// ----- Warning! this code is obscolete.. -----------------------

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDialog.h"
#include "ICBlastProjectIO.h"

#include "string.h"
#include "stdio.h"
#include "OpenGLWnd.h"
#include "GL/gl.h"
#include "glut.h"
#include "ICBlastBlankVw.h"
#include "ICBlastFormVw.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastVC6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastDialog dialog

extern ICBlastProjectIO ProjIO;
extern ICBlastBlankVw BlankFrm;
extern ICBlastProjectDlg ProjDlg;
extern CFormView *pFormView;
extern CWnd *pMainWnd;
extern ICBlastBlankVw BlankFrm;


ICBlastDialog::ICBlastDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDialog)
	m_projname = _T("untitled");
	sprintf(ProjIO.projfile, "%s.icp", m_projname);
	//}}AFX_DATA_INIT
}


void ICBlastDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDialog)
	DDX_Text(pDX, ID_PROJNAME, m_projname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDialog, CDialog)
	//{{AFX_MSG_MAP(ICBlastDialog)
	ON_BN_CLICKED(IDPROJCANCEL, OnProjcancel)
	ON_BN_CLICKED(IDPROJOK, OnProjok)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDialog message handlers

void ICBlastDialog::OnOK()
{
	ProjIO.data = TRUE;
	UpdateData();

	
}

bool ICBlastDialog::CheckOK() 
{
	int nwhitesp = 0;

	// TODO: Add extra validation here
	GetDlgItemText(ID_PROJNAME,ProjIO.projname,256);

	//todo- add support for unix- this is for DOS and NT filesystems..
	//if the string contains spaces, stop here and ask them to add _..
	for(int i=0; i<256; i++){
		if(ProjIO.projname[i] == ' ' || ProjIO.projname[i] == '\t')
           nwhitesp++;
		
	}

	if( nwhitesp > 0 ){
		MessageBox("Project Name must not contain spaces or any whitespace.\n Please change them to underscores..","Name Error",MB_OK);
	    return 1;
	}
    else {
		sprintf(ProjIO.title, "ICblast - Project:%s ", ProjIO.projname);
		SetWindowText(ProjIO.title);
		sprintf(ProjIO.projfile, "%s.icp", ProjIO.projname);

		ProjIO.data = TRUE;
		ProjIO.opendata = 1;

		//hide the blank form..
         BlankFrm.ShowWindow(SW_HIDE);
		return 0;
	}
}

void ICBlastDialog::OnProjcancel() 
{
	// TODO: Add your control notification handler code here
	//BlankFrm.ShowWindow(SW_SHOW);
	if(m_hWnd != NULL){
		ShowWindow(SW_HIDE);
    }
	
	//CDialog::OnOK();

}

void ICBlastDialog::OnProjok() 
{
	// TODO: Add your control notification handler code here

	if(CheckOK() == 0){	
	  //BlankFrm.ShowWindow(SW_HIDE);

	  ProjDlg.ShowWindow(SW_SHOW);

      CDialog::OnOK();
	}

}
