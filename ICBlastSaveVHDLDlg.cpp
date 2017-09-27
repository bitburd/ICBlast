// ICBlastSaveVHDLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastSaveVHDLDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastSaveVHDLDlg dialog


ICBlastSaveVHDLDlg::ICBlastSaveVHDLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastSaveVHDLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastSaveVHDLDlg)
	m_functions = TRUE;
	m_ieee_libs = TRUE;
	//}}AFX_DATA_INIT
}


void ICBlastSaveVHDLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastSaveVHDLDlg)
	DDX_Check(pDX, IDC_FUNCTIONS, m_functions);
	DDX_Check(pDX, IDC_IEEE_LIBS, m_ieee_libs);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastSaveVHDLDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastSaveVHDLDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastSaveVHDLDlg message handlers
