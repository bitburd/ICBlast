// ICBlastProjWizDlg3.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjWizDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizDlg3 dialog


ICBlastProjWizDlg3::ICBlastProjWizDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastProjWizDlg3::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastProjWizDlg3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ICBlastProjWizDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastProjWizDlg3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastProjWizDlg3, CDialog)
	//{{AFX_MSG_MAP(ICBlastProjWizDlg3)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizDlg3 message handlers

void ICBlastProjWizDlg3::OnNext() 
{
	// TODO: Add your control notification handler code here
	//finish a project wizard..
	//FinishWiz();
}
