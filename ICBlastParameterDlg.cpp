// ICBlastParameterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastParameterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastParameterDlg dialog


ICBlastParameterDlg::ICBlastParameterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastParameterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastParameterDlg)
	m_current = 0;
	m_annotate = FALSE;
	m_paramname = _T("");
	m_plength = 0;
	m_power = 0;
	m_pwidth = 0;
	m_resistance = 0;
	m_vmax = 0;
	m_vmin = 0;
	//}}AFX_DATA_INIT
}


void ICBlastParameterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastParameterDlg)
	DDX_Control(pDX, IDC_COMPONENT, m_component);
	DDX_Text(pDX, IDC_CURRENT, m_current);
	DDX_Check(pDX, IDC_DISPLAY, m_annotate);
	DDX_Text(pDX, IDC_PARAMNAME, m_paramname);
	DDX_Text(pDX, IDC_PLENGTH, m_plength);
	DDX_Text(pDX, IDC_POWER, m_power);
	DDX_Text(pDX, IDC_PWIDTH, m_pwidth);
	DDX_Text(pDX, IDC_RESISTANCE, m_resistance);
	DDX_Text(pDX, IDC_VMAX, m_vmax);
	DDX_Text(pDX, IDC_VMIN, m_vmin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastParameterDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastParameterDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastParameterDlg message handlers
