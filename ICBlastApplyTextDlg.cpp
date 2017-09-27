// ICBlastApplyTextDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastApplyTextDlg.h"
#include "ICBlastProjectIO.h"
#include "ICBlastAnalogue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

char thefunc[50];

extern ICBlastProjectIO ProjIO;
extern ASIG signals[40];

/////////////////////////////////////////////////////////////////////////////
// ICBlastApplyTextDlg dialog


ICBlastApplyTextDlg::ICBlastApplyTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastApplyTextDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastApplyTextDlg)
	m_funcname = _T("untitled");
	m_textbox = _T("[type function here]");
	//}}AFX_DATA_INIT
}


void ICBlastApplyTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastApplyTextDlg)
	DDX_Text(pDX, IDC_FUNCTIONNAME, m_funcname);
	DDX_Text(pDX, IDC_TEXTBOX, m_textbox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastApplyTextDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastApplyTextDlg)
	ON_BN_CLICKED(IDAPPLY, OnApply)
	ON_BN_CLICKED(IDC_FUNC, OnFunc)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastApplyTextDlg message handlers

BOOL ICBlastApplyTextDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_textbox.Format("type function here");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ICBlastApplyTextDlg::OnApply() 
{
	// TODO: Add your control notification handler code here

}

void ICBlastApplyTextDlg::OnFunc() 
{
	// TODO: Add your control notification handler code here
	sprintf(thefunc, "function %s return boolean;\r\nbegin\r\nend function %s;", m_funcname.GetBuffer(m_funcname.GetLength()), m_funcname.GetBuffer(m_funcname.GetLength()) );
	m_textbox = _T(thefunc);	
	//m_textbox.UpdateData();
	//m_textbox.ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}

void ICBlastApplyTextDlg::OnAddbody() 
{
	char string5[20] = "function";
	char string6[] = "variable";

    //Add some function definitions from signal names
	//then add some logic from the design specifications
	
	sprintf(string5, "function %s \r\nbegin\r\n", m_funcname.GetBuffer(m_funcname.GetLength()));

	strcat(string5, string6);
    
	//MessageBox(string5,"STRING CAT DEBUG",MB_OK);

	//for(int s=1; s<ProjIO.nlistsigs; s++){
	//	sprintf(siglogic, "variable %s : float;\r\n", signals[s].name);
	//   	strcat(siglogic, "a var goes here");
	//}
    //sprintf(ending, "%s end function %s;\r\n", pointr, m_funcname.GetBuffer(m_funcname.GetLength())  );
	//strcat(pointr, ending);
	//m_textbox.Format();
	UpdateData(FALSE);
}
