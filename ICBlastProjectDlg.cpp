// ICBlastProjectDlg.cpp The class that handles the input to the project's
// Design Specification fields and the file listbox on the main window
//  Jason Graham -

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastProjectIO.h"
#include "commctrl.h"
#include "ICBlastProjSpecDlg.h"
#include "string.h"
#include "ICBlastProjectEditTab.h"
#include "ICBlastDesignSpecDlg.h"
#include "ICBlastBlankVw.h"
#include "ICBlastDesignWin.h"


extern ICBlastBlankVw BlankFrm;
extern ICBlastProjectDlg ProjDlg;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;
extern CWnd *pParentWnd;
extern HINSTANCE hInstance;

ICBlastProjSpecDlg		ProjSpecDlg;
ICBlastProjectEditTab	ProjEditTab;
//ICBlastDesignSpecDlg	DesignSpec;
extern ICBlastDesignSpecDlg	DesignSpecDlg;
extern ICBlastDesignWin DesignWin;

CImageList *ImageList;  //TODO alocate on stack not heap


/////////////////////////////////////////////////////////////////////////////
// ICBlastProjectDlg dialog

//hide button width and height
const int hidew = 50;
const int hideh = 5;

ICBlastProjectDlg::ICBlastProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastProjectDlg::IDD, pParent)
{
	CImageList *ImageListAlloc = new CImageList();

	ImageListAlloc->Create( &ImageList );

	//{{AFX_DATA_INIT(ICBlastProjectDlg)
	m_processtext = _T("");
	m_specname = _T("");
	m_authorname = _T("");
	//}}AFX_DATA_INIT

	delete ImageListAlloc;

	m_fileItem = -1;

}

ICBlastProjectDlg::~ICBlastProjectDlg()
{
	
	ImageList.DeleteImageList();
	
}

void ICBlastProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastProjectDlg)
	DDX_Control(pDX, IDC_REVISION, m_revision);
	DDX_Control(pDX, IDC_PROJ_FILELIST, m_proj_filelist);
	DDX_Text(pDX, IDC_PROCESSTEXT, m_processtext);
	DDX_Text(pDX, IDC_DESSPCNAME, m_specname);
	DDX_Text(pDX, IDC_AUTHOR, m_authorname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastProjectDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastProjectDlg)
	ON_NOTIFY(NM_CLICK, IDC_PROJ_FILELIST, OnClickProjFilelist)
	ON_NOTIFY(LVN_INSERTITEM, IDC_PROJ_FILELIST, OnInsertitemProjFilelist)
	ON_BN_CLICKED(IDC_EDITPROCBTN, OnEditprocbtn)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_HIDE1, OnHide1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjectDlg message handlers



BOOL ICBlastProjectDlg::OnInitDialog() 
{
	char projname[100];
	CDialog::OnInitDialog();
	HBITMAP hbm;
    CBitmap cbm;
	CBitmap cbm2;
	CBitmap cbm3;
	CBitmap cbm4;

	//create imagelist. load a bitmap with the icons
    if(ProjDlg.m_hWnd != NULL && ImageList != NULL){
		ImageList.Create(16, 16, ILC_COLOR, 0, 3);
		
		cbm.LoadBitmap(IDB_BITMAP1);
		cbm2.LoadBitmap(IDB_BITMAP2);
		cbm3.LoadBitmap(IDB_BITMAP3);
		cbm4.LoadBitmap(IDB_BITMAP4);
		
		ImageList.Add(&cbm, RGB(255,0, 255));
		ImageList.Add(&cbm2, RGB(255,0, 255));
		ImageList.Add(&cbm3, RGB(255,0, 255));
		ImageList.Add(&cbm4, RGB(255,0, 255));
		
		//set the imagelist to the clistctrl item
		m_proj_filelist.EnableWindow(TRUE);
		
		m_proj_filelist.SetImageList(&ImageList, LVSIL_SMALL );
		
		//m_proj_filelist.SetImageList(&ImageList, LVSIL_SMALL );
		
		
		ProjIO.process = _T("");
		
		//m_proj_filelist.InsertItem(&lvi);
		//m_proj_filelist.SetItem(&lvi);
		
		ProjIO.files = 0;
		
		//if(ProjIO.data != NULL){
		//	ProjIO.files++;
		//	m_proj_filelist.InsertItem(ProjIO.files, ProjIO.projfile, 0);
		//}
		//if(ProjIO.icdesignfile != _T("") ){
		//	ProjIO.files++;
		//	m_proj_filelist.InsertItem(ProjIO.files, ProjIO.icdesignfile, 1);
		//}
	}
    
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void ICBlastProjectDlg::OnClickProjFilelist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_fileItem = -1;
    m_fileItem = GetSelectedItem();
    // item was selected
	if(nClicks != 1){
		    m_fileItem = GetSelectedItem();
		    //m_proj_filelist.SetItemState(m_fileItem, 
            //  LVIS_SELECTED, LVIS_SELECTED | LVIS_FOCUSED);
			nClicks++;
    }else{	
		char msg[20];
		sprintf(msg,"Item clicked was: %d",m_fileItem);
		MessageBox(msg,"Message",MB_OK);
		nClicks = 0;
	}
	
	*pResult = 0;
}

BOOL ICBlastProjectDlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::PreCreateWindow(cs);
}


BOOL ICBlastProjectDlg::Create(UINT nID, CWnd *pParentWnd) 
{
	BOOL retStat;

	if(m_hWnd == NULL)
		retStat = CDialog::Create(nID, pParentWnd);

	if(retStat < 0)
		ShowWindow(SW_SHOW);


	return retStat;
}

void ICBlastProjectDlg::OnInsertitemProjFilelist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void ICBlastProjectDlg::OnEditprocbtn() 
{
	// TODO: Add your control notification handler code here
	

	//ProjSpecDlg.DoModal();
	
	//DesignSpec.ShowWindow(SW_SHOW);
	if(DesignSpecDlg.m_hWnd == NULL){
		DesignSpecDlg.Create(IDD_DESIGNSPEC, this);
		DesignSpecDlg.ShowWindow(SW_SHOW);
	}
	else
		DesignSpecDlg.ShowWindow(SW_SHOW);
}

//updates the project dialog with values from the project..
void ICBlastProjectDlg::UpdateMe(void) 
{
	CWnd *dlgitem;
	CWnd *dlgitem1;
	CWnd *dlgitem2;
    CWnd *dlgitem3;

    //get the controls on the project dialog
	//dlgitem = GetDlgItem(IDC_PROCNAME);
	dlgitem = GetDlgItem(IDC_DESSPCNAME);
	dlgitem1 = GetDlgItem(IDC_PROCESSTEXT);
	dlgitem2 = GetDlgItem(IDC_AUTHOR);
	dlgitem3 = GetDlgItem(IDC_REVISION);
	
	//---- fix bug -----
	//set the project dialog values equal to the spec form values
	//if(DesignSpecDlg.m_hWnd != NULL){

	//set the dialog items to what is loaded in project..
      dlgitem->SetWindowText(ProjIO.specname);
	  dlgitem1->SetWindowText(ProjIO.procname);
	  dlgitem2->SetWindowText(ProjIO.authorname);

	  //sprintf(ProjIO.revisionstr,"%2f",ProjIO.revision);
	  dlgitem3->SetWindowText(ProjIO.revisionstr);

	  //char revnum[10];
	  //sprintf(revnum, "%1.2f", ProjIO.revision);
	  //dlgitem3->SetWindowText(revnum);
	//}

    //if(DesignSpecDlg.m_hWnd != NULL)
	//	DesignSpecDlg.UpdateData();
	
}

//updates the project dialog with values from a project file
void ICBlastProjectDlg::UpdatePrjFromFile(void) 
{
	CWnd *dlgitem;
	CWnd *dlgitem1;
	CWnd *dlgitem2;
    CWnd *dlgitem3;
	
	//if the design project has values, update them

	if(DesignSpecDlg.m_hWnd != NULL){

	  ShowWindow(SW_HIDE);

	} else {
		Create(IDD_DESIGNSPEC, this);
		ShowWindow(SW_HIDE);
    }


	//get the controls on the project dialog
	dlgitem = GetDlgItem(IDC_DESSPCNAME);
	dlgitem1 = GetDlgItem(IDC_PROCESSTEXT);
	dlgitem2 = GetDlgItem(IDC_AUTHOR);
	dlgitem3 = GetDlgItem(IDC_REVISION);

    dlgitem->SetWindowText(ProjIO.specname);
	dlgitem1->SetWindowText(ProjIO.process);
	dlgitem2->SetWindowText(ProjIO.authorname);

	sprintf(ProjIO.revisionstr,"%2f",ProjIO.revision);
	dlgitem3->SetWindowText(ProjIO.revisionstr);

	char revnum[10];
	sprintf(revnum, "%1.2f", ProjIO.revision);
	dlgitem3->SetWindowText(revnum);

	ShowWindow(SW_SHOW);
	
}


BOOL ICBlastProjectDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	//update the project dlg..
	//UpdateMe();

	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



void ICBlastProjectDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	//UpdateMe();

	// Do not call CDialog::OnPaint() for painting messages
}

/// Hides the IC design project attributes group from the
// Project form's dialog window to save space..
void ICBlastProjectDlg::OnHide1() 
{
	CWnd *hwin1; //window group to hide
	CWnd *hwinplbl; //process label hide
	CWnd *hwndalbl; //author label to hide
	CWnd *hwndrlbl; //revision label to hide
	CWnd *hwndprocn; //hwnd to procname input field
	CWnd *hwndauthor; //hwnd to author input fld
	CWnd *hwndrev;    //hwnd to the revision fld
    CWnd *edit;       //hwnd to the edit button
	CWnd *bhide1;
	
	if(m_bhide1 == FALSE) {
		//get the hwnds and hide the dialog elements
		hwin1 = GetDlgItem(IDC_DESIGNPROJ);
		hwin1->ShowWindow(SW_HIDE);
		
		hwinplbl = GetDlgItem(IDC_PLBL);
		hwinplbl->ShowWindow(SW_HIDE);
		
		hwndalbl = GetDlgItem(IDC_ALBL);
		hwndalbl->ShowWindow(SW_HIDE);
		
		hwndrlbl = GetDlgItem(IDC_RLBL);
		hwndrlbl->ShowWindow(SW_HIDE);
		
		hwndprocn = GetDlgItem(IDC_PROCNAME);
		hwndprocn->ShowWindow(SW_HIDE);
		
		hwndauthor = GetDlgItem(IDC_AUTHOR);
		hwndauthor->ShowWindow(SW_HIDE);
		
		hwndrev = GetDlgItem(IDC_REVISION);
		hwndrev->ShowWindow(SW_HIDE);
		
		edit = GetDlgItem(IDC_EDITPROCBTN);
		edit->ShowWindow(SW_HIDE);
		
		bhide1 = GetDlgItem(IDC_HIDE1);
		bhide1->SetWindowText("Show");

		m_bhide1 = TRUE;

		//move the files group and listbox up
		CWnd *fprjgrp;

		fprjgrp = GetDlgItem(IDC_FPRJGRP);
		fprjgrp->SetWindowPos(NULL,10,10,180,139,SWP_NOZORDER);

		//move the hide button normal place
		CWnd *hidebtn;
		hidebtn = GetDlgItem(IDC_HIDE1);
		hidebtn->SetWindowPos(NULL,5,10,5+hidew,10+hideh,SWP_NOZORDER);

	}
	else {
		hwin1 = GetDlgItem(IDC_DESIGNPROJ);
		hwin1->ShowWindow(SW_SHOW);
		
		hwinplbl = GetDlgItem(IDC_PLBL);
		hwinplbl->ShowWindow(SW_SHOW);
		
		hwndalbl = GetDlgItem(IDC_ALBL);
		hwndalbl->ShowWindow(SW_SHOW);
		
		hwndrlbl = GetDlgItem(IDC_RLBL);
		hwndrlbl->ShowWindow(SW_SHOW);
		
		hwndprocn = GetDlgItem(IDC_PROCNAME);
		hwndprocn->ShowWindow(SW_SHOW);
		
		hwndauthor = GetDlgItem(IDC_AUTHOR);
		hwndauthor->ShowWindow(SW_SHOW);
		
		hwndrev = GetDlgItem(IDC_REVISION);
		hwndrev->ShowWindow(SW_SHOW);
		
		edit = GetDlgItem(IDC_EDITPROCBTN);
		edit->ShowWindow(SW_SHOW);
		
		bhide1 = GetDlgItem(IDC_HIDE1);
		bhide1->SetWindowText("Hide");

		m_bhide1 = FALSE;

		//move the files group and listbox up
		CWnd *fprjgrp;

		fprjgrp = GetDlgItem(IDC_FPRJGRP);
		fprjgrp->SetWindowPos(NULL,5,81,185,220,SWP_NOZORDER);

		CWnd *hidebtn;
		hidebtn = GetDlgItem(IDC_HIDE1);
		hidebtn->SetWindowPos(NULL,5,72,50,72,SWP_NOZORDER);
	}

}

int ICBlastProjectDlg::GetSelectedItem()
{
	int nItem = -1;
    POSITION nPos = m_proj_filelist.GetFirstSelectedItemPosition();
    if (nPos)
    {
        nItem = m_proj_filelist.GetNextSelectedItem(nPos);
    }
    return nItem;
}


