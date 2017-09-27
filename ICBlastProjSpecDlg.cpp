// ICBlastProjSpecDlg.cpp : implementation file
// This code has been phased out in V2

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjSpecDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastProjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;
extern ICBlastProjSpecDlg ProjSpecDlg;
extern ICBlastProjectDlg ProjDlg;

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjSpecDlg dialog


ICBlastProjSpecDlg::ICBlastProjSpecDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastProjSpecDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastProjSpecDlg)
	//m_authorname = _T("");
	//m_procname = _T("");
	//m_du = 0.05;
	//m_revision = 1;
	//m_metallayer = 4;
	//}}AFX_DATA_INIT
}


void ICBlastProjSpecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	/*//{{AFX_DATA_MAP(ICBlastProjSpecDlg)
	DDX_Text(pDX, IDC_AUTHORNAME, m_authorname);
	DDX_Text(pDX, IDC_PROCESSNAME, m_procname);
	DDX_Text(pDX, IDC_DU, m_du);
	DDX_Text(pDX, IDC_REVISIONNUM, m_revision);
	DDX_Text(pDX, IDC_METALLAYER, m_metallayer);
	//}}AFX_DATA_MAP
	*/
}


BEGIN_MESSAGE_MAP(ICBlastProjSpecDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastProjSpecDlg)
	ON_BN_CLICKED(IDOKPROJEDIT, OnOkprojedit)
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjSpecDlg message handlers

void ICBlastProjSpecDlg::OnOkprojedit() 
{
	CDialog::OnOK(); // This will close the dialog and DoModal will return.

	/***
	//form validation..
	//this code is sort of broken..
	//if ( m_du == 0 || 
	//	m_procname == "" ||
	//	m_revision == -1 || 
	//	m_authorname == "" || 
	//	m_metallayer == 0 ) // Is a particular field still empty?
	//{
	//	AfxMessageBox("Please enter a value for all fields");
	//	return; // Inform the user that he can't close the dialog without
		// entering the necessary values and don't close the 
		// dialog.
	//} else {
		
		// setup project IO members from form Cstring values
	    CString dutext,revtext,layertext;
		double dunum,revnum,layernum;

		//get the form strings to convert to decimals..
		GetDlgItemText(IDC_DU,dutext);
		GetDlgItemText(IDC_REVISIONNUM,revtext);
		GetDlgItemText(IDC_AUTHORNAME,m_authorname);
		GetDlgItemText(IDC_METALLAYER,layertext);
		GetDlgItemText(IDC_PROCESSNAME,m_procname);
		
		//convert string to a decimal value first
		dunum = atof(dutext);
		revnum = atof(revtext);
		layernum = atoi(layertext);

		ProjIO.du = dunum;
		ProjIO.revision = revnum;
		ProjIO.author = m_authorname;
		ProjIO.layers = layernum;
	    ProjIO.process = m_procname;
    ***/

		ProjDlg.UpdateData();
        ProjDlg.Invalidate(FALSE);
	
}





BOOL ICBlastProjSpecDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	//set the project up according to the dialog values
    //ProjIO.author = m_authorname;
	//ProjIO.revision = m_revision;
	//ProjIO.process = m_procname;
	//ProjIO.layers = m_metallayer;
	//ProjIO.du = m_du;
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void ICBlastProjSpecDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	
}



void ICBlastProjSpecDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}
