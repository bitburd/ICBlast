// ICBlastDesignManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignManageDlg dialog


ICBlastDesignManageDlg::ICBlastDesignManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDesignManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ICBlastDesignManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignManageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignManageDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignManageDlg)
	ON_BN_CLICKED(IDAPPLY1, OnApply1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignManageDlg message handlers

void ICBlastDesignManageDlg::OnApply1() 
{
	// TODO: Add your control notification handler code here
	
}
