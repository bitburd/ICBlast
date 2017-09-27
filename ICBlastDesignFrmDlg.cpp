// ICBlastDesignFrmDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignFrmDlg.h"
#include "ICBlastDesignWin.h"
#include "ICBlastSigGateDlg.h"
#include "OpenGLControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignFrmDlg dialog

extern ICBlastSigGateDlg SigGateDlg;


ICBlastDesignFrmDlg::ICBlastDesignFrmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignFrmDlg::IDD, pParent)
{

	//{{AFX_DATA_INIT(ICBlastDesignFrmDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void ICBlastDesignFrmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignFrmDlg)
	DDX_Control(pDX, IDC_SIGNALLIST, m_sigListBox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignFrmDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignFrmDlg)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SIGNALADD, OnSignaladd)
	ON_BN_CLICKED(IDC_DFBUTTON, OnImportbutton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignFrmDlg message handlers

int ICBlastDesignFrmDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}


/***void ICBlastDesignFrmDlg::OnParamadd() 
{
	//this function is gone!!

	// TODO: Add your control notification handler code here
	
}

void ICBlastDesignFrmDlg::OnCdbutton() 
{
	// TODO: Add your control notification handler code here
	
}***/

void ICBlastDesignFrmDlg::OnSignaladd() 
{
	// TODO: Add your control notification handler code here
	if(SigGateDlg.m_hWnd == NULL) {
		SigGateDlg.Create(IDD_SIGNALS,NULL);
		SigGateDlg.ShowWindow(SW_SHOW);
	}
	else 
		SigGateDlg.ShowWindow(SW_SHOW);
	
	
}

BOOL ICBlastDesignFrmDlg::OnInitDialog() 
{
	COpenGLControl openGLControl;

	CDialog::OnInitDialog();

	
	CRect rect;

	GetDlgItem(IDC_OPENGL_WINDOW)->GetWindowRect(rect);

	ScreenToClient(rect);

	openGLControl.CreateFromStatic("SymbolOGL",rect,this);
   
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ICBlastDesignFrmDlg::OnImportbutton() 
{
	// TODO: Add your control notification handler code here
	
}
