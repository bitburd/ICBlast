// ICBlastDesignSpecDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignSpecDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastProjectDlg.h"

extern ICBlastProjectIO ProjIO;
extern ICBlastProjectDlg ProjDlg;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastDesignSpecDlg DesignSpecDlg;

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignSpecDlg dialog


ICBlastDesignSpecDlg::ICBlastDesignSpecDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignSpecDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDesignSpecDlg)
	m_authorname = _T("");
	m_specname = _T("untitled");
	m_layers = 0;
	m_du = 0.05f;
	m_revision = 1.0f;
	m_process = _T("");
	m_corevolt = 0.0f;
	m_genpinsfromtxt = FALSE;
	m_specfile = _T("");
	m_subsection = FALSE;
	m_description = _T("");
	m_width = 0.0f;
	m_height = 0.0f;
	//}}AFX_DATA_INIT
}


void ICBlastDesignSpecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignSpecDlg)
	DDX_Control(pDX, IDC_LAYEREDIT, m_layeredit);
	DDX_Text(pDX, IDC_AUTHORNAME, m_authorname);
	DDX_Text(pDX, IDC_SPECNAME, m_specname);
	DDX_Text(pDX, IDC_METALLAYERS, m_layers);
	DDX_Text(pDX, IDC_DU, m_du);
	DDX_Text(pDX, IDC_REVISION, m_revision);
	DDX_Text(pDX, IDC_PROCESS, m_process);
	DDX_Text(pDX, IDC_COREVOLT, m_corevolt);
	DDX_Check(pDX, IDC_GENPINS, m_genpinsfromtxt);
	DDX_Text(pDX, IDC_SPECFILE, m_specfile);
	DDX_Check(pDX, IDC_SUBSECTIONS, m_subsection);
	DDX_Text(pDX, IDC_DESCRIPTION, m_description);
	DDX_Text(pDX, IDC_MASKWIDTH, m_width);
	DDX_Text(pDX, IDC_MASKHEIGHT, m_height);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignSpecDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignSpecDlg)
	ON_BN_CLICKED(IDAPPLY, OnApply)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignSpecDlg message handlers

void ICBlastDesignSpecDlg::OnApply() 
{
	// bugFix:bitburd - updates the main window
	if(m_hWnd != NULL)
		UpdateData();

	//update proj dialog name
	sprintf(ProjIO.specname, "%s", m_specname.GetBuffer(m_specname.GetLength()) );

	//update proj dialog process
	ProjIO.process = m_process;
	
	//update proj dialog Author
	strcpy(ProjIO.authorname, m_authorname.GetBuffer(m_authorname.GetLength()) );

	//update the project description if there is one..
    sprintf(ProjIO.description, "<p><pre>%s\n</pre></p>\n",m_description.GetBuffer(m_description.GetLength()) );

	//update design specification fields on proj dialog form
	ProjIO.revision = m_revision;

	ProjIO.du = m_du;
	ProjIO.revision = m_revision;
	ProjIO.layers = m_layers;

	if(ProjDlg.m_hWnd != NULL)
		ProjDlg.UpdateMe();
	
}
