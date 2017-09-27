// ICBlastNewICDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastNewICDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastDesignForm.h"
#include "ICBlastFormVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern ICBlastProjectDlg	ProjDlg;
extern ICBlastDesignForm	DesignFrm;
extern ICBlastProjectIO		ProjIO;
extern ICBlastFormVw		BlankFrm;

/////////////////////////////////////////////////////////////////////////////
// ICBlastNewICDlg dialog


ICBlastNewICDlg::ICBlastNewICDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastNewICDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastNewICDlg)
	m_icdesignfile = _T("");
	//}}AFX_DATA_INIT
}


void ICBlastNewICDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastNewICDlg)
	DDX_Text(pDX, IDC_ICDESIGNFILE, m_icdesignfile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastNewICDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastNewICDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastNewICDlg message handlers

void ICBlastNewICDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();

	if(ProjDlg.m_hWnd != NULL)
		ProjDlg.ShowWindow(SW_SHOW);
	else{
		MessageBox("No project is open. You must open a project or define a new one first","NO PROJECT",MB_OK);
		ProjDlg.Create(IDD_PROJDIALOG, BlankFrm.GetActiveWindow() );
		ProjDlg.ShowWindow(SW_SHOW);
	}

	if(DesignFrm.m_hWnd == NULL)
		DesignFrm.Create(IDD_DESIGNFORM,BlankFrm.GetActiveWindow() );
    DesignFrm.ShowWindow(SW_SHOW);

	if(m_icdesignfile && ProjDlg.m_hWnd != NULL){
	   ProjDlg.m_proj_filelist.InsertItem(0, m_icdesignfile, 0);
	   ProjIO.icdesignfile = m_icdesignfile;
	}

	ProjIO.data = TRUE;

	CDialog::OnOK();
}
