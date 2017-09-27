// ICBlastAddDelSymDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastAddDelSymDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddDelSymDlg dialog


ICBlastAddDelSymDlg::ICBlastAddDelSymDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastAddDelSymDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastAddDelSymDlg)
	m_addsym = _T("");
	//}}AFX_DATA_INIT
}


void ICBlastAddDelSymDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastAddDelSymDlg)
	DDX_Control(pDX, IDC_DELSYMLIST, m_delsymlist);
	DDX_Text(pDX, IDC_ADDSYM, m_addsym);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastAddDelSymDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastAddDelSymDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddDelSymDlg message handlers
