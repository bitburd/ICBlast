// ICBlastAddWireDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastAddWireDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastDesignForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;
extern ICBlastDesignForm DesignFrm;

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddWireDlg dialog


ICBlastAddWireDlg::ICBlastAddWireDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastAddWireDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastAddWireDlg)
	m_genbus = FALSE;
	m_wirebus = _T("");
	m_wirename = _T("");
	//}}AFX_DATA_INIT
}


void ICBlastAddWireDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastAddWireDlg)
	DDX_Check(pDX, IDC_GENBUS, m_genbus);
	DDX_Text(pDX, IDC_WIREBUSNAME, m_wirebus);
	DDX_Text(pDX, IDC_WIRENAME, m_wirename);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastAddWireDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastAddWireDlg)
	ON_BN_CLICKED(IDC_GENBUS, OnGenbus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddWireDlg message handlers

void ICBlastAddWireDlg::OnOK() 
{
	char wirename[] = "";
	char wirebus[] = "";

	if(m_wirename != ""){
		sprintf(wirename, m_wirename.GetBuffer(m_wirename.GetLength()) );
		strcpy(wirebus, wirename );
	  
	  //add wire to the listbox
	   DesignFrm.AddListItems(3,wirename,"wire","NA","NA");
	   ProjIO.nsig++;

    } else {
		MessageBox("You must first enter a wire name..","Wire Msg",MB_OK);  
	}
}

void ICBlastAddWireDlg::OnGenbus() 
{
	// TODO: Add your control notification handler code here
	CWnd *busname;
	busname = GetDlgItem(IDC_WIREBUSNAME);
    if(m_genbus == TRUE)
		busname->EnableWindow(FALSE);
	else 
		busname->EnableWindow(TRUE);

	UpdateData();
	busname->SetWindowText(m_wirename);
}
