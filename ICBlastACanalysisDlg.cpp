// ICBlastACanalysisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastACanalysisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastACanalysisDlg dialog


ICBlastACanalysisDlg::ICBlastACanalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastACanalysisDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastACanalysisDlg)
	m_frequency = 0.0f;
	m_periodmax = 0.0f;
	m_periodmin = 0.0f;
	m_controlpoints = 0.0f;
	m_cycles = 0.0f;
	//}}AFX_DATA_INIT
}


void ICBlastACanalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastACanalysisDlg)
	DDX_Control(pDX, IDC_STEPS, m_steps);
	DDX_Text(pDX, IDC_FREQUENCY, m_frequency);
	DDX_Text(pDX, IDC_PERIOD_MAX, m_periodmax);
	DDX_Text(pDX, IDC_PERIOD_MIN, m_periodmin);
	DDX_Text(pDX, IDC_CONTROLPOINTS, m_controlpoints);
	DDX_Text(pDX, IDC_CYCLES, m_cycles);
	DDV_MinMaxFloat(pDX, m_cycles, 0.0f, 687000.0f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastACanalysisDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastACanalysisDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastACanalysisDlg message handlers
