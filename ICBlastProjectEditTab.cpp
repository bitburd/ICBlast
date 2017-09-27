// ICBlastProjectEditTab.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjectEditTab.h"
#include "ICBlastProjSpecDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastDesignSpecDlg.h"
#include "ICBlastDesignFileSpecDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern ICBlastProjSpecDlg ProjSpecDlg;
extern ICBlastProjectIO ProjIO;
extern ICBlastProjectDlg ProjDlg;
extern ICBlastDesignSpecDlg DesignSpec;

ICBlastDesignFileSpecDlg dialog;

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjectEditTab dialog


ICBlastProjectEditTab::ICBlastProjectEditTab(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastProjectEditTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastProjectEditTab)
	//}}AFX_DATA_INIT
}


void ICBlastProjectEditTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastProjectEditTab)
	DDX_Control(pDX, IDC_TABS, m_projtab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastProjectEditTab, CDialog)
	//{{AFX_MSG_MAP(ICBlastProjectEditTab)
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_BN_CLICKED(IDC_REVERT, OnRevert)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjectEditTab message handlers

BOOL ICBlastProjectEditTab::OnInitDialog() 
{
	CDialog::OnInitDialog();
    CenterWindow(); 

	//create a tab in the edit spec tabs
	//The tab is initially hidden in the beta version
    
	m_projtab.InsertItem(TCIF_TEXT, "Design files");

	//TODO - fix the tab code they dont work..
	CWnd *tab;
	tab = m_projtab.GetActiveWindow();
	CRect prect;
	tab->GetClientRect(prect);
	

	dialog.Create( IDD_DESIGNFILESPEC, this );
	
	if(dialog.m_hWnd != NULL)
		dialog.ShowWindow(SW_SHOW);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ICBlastProjectEditTab::OnApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	
	ProjIO.revision = ProjIO.revision;

	// refresh the project dlg..

	ProjDlg.UpdateMe();
	ProjDlg.Invalidate(FALSE);

	//EndDialog(0);
}

void ICBlastProjectEditTab::OnRevert() 
{
	// TODO: Add your control notification handler code here
	
}

void ICBlastProjectEditTab::OnOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	EndDialog(0);
}




int ICBlastProjectEditTab::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
