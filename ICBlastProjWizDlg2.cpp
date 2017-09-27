// ICBlastProjWizDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjWizDlg2.h"
#include "ICBlastProjWizDlg3.h"
#include "ICBlastProjWizardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjWizDlg2 ProjWizDlg2;
extern ICBlastProjWizardDlg ProjWizDlg;
extern ICBlastProjWizDlg3 ProjWizDlg3;

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizDlg2 dialog


ICBlastProjWizDlg2::ICBlastProjWizDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastProjWizDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastProjWizDlg2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ICBlastProjWizDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastProjWizDlg2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastProjWizDlg2, CDialog)
	//{{AFX_MSG_MAP(ICBlastProjWizDlg2)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizDlg2 message handlers

void ICBlastProjWizDlg2::OnNext() 
{
	// TODO: Add your control notification handler code here
	ProjWizDlg.ShowWindow(SW_HIDE);
	ProjWizDlg2.ShowWindow(SW_HIDE);

	if(ProjWizDlg3.m_hWnd == NULL){
		ProjWizDlg3.Create(IDD_PROJWIZARD3,NULL);
	    ProjWizDlg3.ShowWindow(SW_SHOW);
	}
}
