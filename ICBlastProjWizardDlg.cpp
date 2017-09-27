// ICBlastProjWizardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjWizardDlg.h"
#include "ICBlastProjWizDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjWizardDlg ProjWizDlg;
extern ICBlastProjWizDlg2 ProjWizDlg2;

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizardDlg dialog


ICBlastProjWizardDlg::ICBlastProjWizardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastProjWizardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastProjWizardDlg)
	m_newhdldesign = FALSE;
	m_newschematic = FALSE;
	m_newspecdoc = FALSE;
	//}}AFX_DATA_INIT
}


void ICBlastProjWizardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastProjWizardDlg)
	DDX_Check(pDX, IDC_NEWHDLDESIGN, m_newhdldesign);
	DDX_Check(pDX, IDC_NEWSCHEMATIC, m_newschematic);
	DDX_Check(pDX, IDC_NEWSPECDOC, m_newspecdoc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastProjWizardDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastProjWizardDlg)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizardDlg message handlers

void ICBlastProjWizardDlg::OnNext() 
{
	
	ProjWizDlg.ShowWindow(SW_HIDE);
	if(ProjWizDlg2.m_hWnd == NULL){
		ProjWizDlg2.Create(IDD_PROJWIZARD2,NULL);
	    ProjWizDlg2.ShowWindow(SW_SHOW);
	}
}

void ICBlastProjWizardDlg::OnOK() 
{
	// Tests the checkboxes. If some are checked, go immediately and
	//create entries in project and add files to project list..
	if(m_newhdldesign)

	CDialog::OnOK();
}
