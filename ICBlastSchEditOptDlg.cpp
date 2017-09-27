// ICBlastSchEditOptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastSchEditOptDlg.h"
#include "ICBlastSymbol.h"
#include "resource.h"
#include "ICBlastProjectIO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastSchEditOptDlg dialog
extern ICBlastSymbol Symbol;
extern ICBlastSchEditOptDlg EditOptDlg;
extern ICBlastProjectIO ProjIO;


ICBlastSchEditOptDlg::ICBlastSchEditOptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastSchEditOptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastSchEditOptDlg)
	m_grids = FALSE;
	m_color_wires = FALSE;
	m_crosshairs = FALSE;
	m_viewgrid = TRUE;
	m_filedirectory = _T("E:\\ICBlast_2\\win32\\bitmaps");
	m_boundboxes = FALSE;
	//}}AFX_DATA_INIT

	//OnLoadDefSymbols();
}


void ICBlastSchEditOptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastSchEditOptDlg)
	DDX_Check(pDX, IDC_GRIDS, m_grids);
	DDX_Check(pDX, IDC_COLOR_WIRES, m_color_wires);
	DDX_Check(pDX, IDC_CROSSHAIRS, m_crosshairs);
	DDX_Check(pDX, IDC_VIEWGRID, m_viewgrid);
	DDX_Text(pDX, IDC_SYMBOLDIREDIT, m_filedirectory);
	DDX_Check(pDX, IDC_BOUNDBOXES, m_boundboxes);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastSchEditOptDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastSchEditOptDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastSchEditOptDlg message handlers

/****void ICBlastSchEditOptDlg::OnLoadsymbols() 
{
	char dirpath[100] = "";
	char defdirpath[100] = "E:\\ICBlastVC6_2\\win32\\Bitmaps";
	// TODO: Add your control notification handler code here
	//UpdateData();

	strcpy(dirpath, m_symdiredit.GetBuffer(m_symdiredit.GetLength()) );

	//TODO add more validations
	if(dirpath != ""){
		strcpy(Symbol.m_symboldir, dirpath);
	}

	//load default symbol bitmaps
	strcpy(Symbol.m_symboldir, defdirpath);
	
	//just load defaults for now..
	OnLoadDefSymbols();

	//TODO load symbol bmps..
	
	
}*****/

//loads a set of initial bitmapped symbols
/***void ICBlastSchEditOptDlg::OnLoadDefSymbols()
{
	int retval;

	//load default bitmaps from disk	
	retval = Symbol.LoadDefSymbols();

		

}
*****/

///save editing options
void ICBlastSchEditOptDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();

	sprintf(Symbol.m_symboldir, "%s", m_filedirectory.GetBuffer(m_filedirectory.GetLength()));
	CDialog::OnOK();
}


