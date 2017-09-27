// ICBlastDesignSpec.cpp : implementation file
// Implement the design spec dialog on the tab windows

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjectEditTab.h"
#include "ICBlastProjSpecDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastDesignSpec.h"
#include "ICBlastDesignSpecDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern ICBlastProjSpecDlg ProjSpecDlg;
extern ICBlastProjectIO ProjIO;
extern ICBlastProjectDlg ProjDlg;
extern ICBlastProjectEditTab * EditProjTab;
extern ICBlastDesignSpecDlg  DesignSpecDlg;

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignSpec dialog


ICBlastDesignSpec::ICBlastDesignSpec(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignSpec::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDesignSpec)
	//}}AFX_DATA_INIT
}


void ICBlastDesignSpec::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignSpec)
	DDX_Control(pDX, IDC_TABS, m_projtab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignSpec, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignSpec)
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_BN_CLICKED(IDC_REVERT, OnRevert)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignSpec message handlers

BOOL ICBlastDesignSpec::OnInitDialog() 
{
	CDialog::OnInitDialog();
    CenterWindow(); 
	
	//create a tab in the edit spec tabs
	//The tab is initially hidden in the beta version
	m_projtab.InsertItem(TCIF_TEXT, "Project");
	m_projtab.InsertItem(TCIF_TEXT, "Architecture");
	m_projtab.InsertItem(TCIF_TEXT, "Design Files");
	m_projtab.InsertItem(TCIF_TEXT, "Models");
	m_projtab.InsertItem(TCIF_TEXT, "Revisions & DM");

	//TODO - fix the tab coeds they dont work..
	//CWnd *page;
	//page = m_projtab.GetActiveWindow();

	//ICBlastProjSpecDlg SpecDlg;
	//CRect prect;
	//page->GetClientRect(prect);
	//SpecDlg.Create(IDD_PROJEDITSPEC,page);
    //SpecDlg.ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ICBlastDesignSpec::OnApply() 
{
	ProjIO.bNeedSave = TRUE;
	// TODO: Add your control notification handler code here
	UpdateData();
	
	sprintf( ProjIO.description, "%s", DesignSpecDlg.m_description.GetBuffer(DesignSpecDlg.m_description.GetLength()) );
	ProjIO.revision = ProjIO.revision;

	// refresh the project dlg..
    //GetDlgItemText(IDC_DESSPCNAME, m_specname); 
	//GetDlgItemText(IDC_AUTHORNAMETAB,m_author);
	//GetDlgItemText(IDC_PROCESSTEXT,m_processname);

	//ProjIO.author = m_author;
	//ProjIO.process = m_process;

	ProjIO.du = 0.05;
	//ProjIO.revision = m_revision;
	//ProjIO.author = m_author;
	ProjIO.layers = 4;
	//ProjIO.process = m_processname;
	//ProjIO.du = m_du;
	//ProjIO.layers = m_numlayers;

	ProjDlg.UpdateMe();
	ProjDlg.Invalidate(FALSE);

	//EndDialog(0);
}

void ICBlastDesignSpec::OnRevert() 
{
	// TODO: Add your control notification handler code here
	
}

void ICBlastDesignSpec::OnOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	EndDialog(0);
}




int ICBlastDesignSpec::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
