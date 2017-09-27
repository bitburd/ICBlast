// ICBlastPinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastPinDlg.h"
#include "ICBlastAnalogue.h"
#include "ICBlastDesignForm.h"
#include "ICBlastProjectIO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AATOM pins[40];
extern ICBlastAnalogue pin;
extern ICBlastDesignForm DesignFrm;
extern ICBlastProjectIO ProjIO;

/////////////////////////////////////////////////////////////////////////////
// ICBlastPinDlg dialog


ICBlastPinDlg::ICBlastPinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastPinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastPinDlg)
	m_genpinbus = FALSE;
	m_pinpurp = _T("");
	m_shorttowire = FALSE;
	m_pinname = _T("");
	//}}AFX_DATA_INIT
}


void ICBlastPinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastPinDlg)
	DDX_Control(pDX, IDC_PINWIRES, m_pinwires);
	DDX_Check(pDX, IDC_GENPINBUS, m_genpinbus);
	DDX_Text(pDX, IDC_PINPURP, m_pinpurp);
	DDX_Check(pDX, IDC_SHORTTOWIRE, m_shorttowire);
	DDX_Text(pDX, IDC_PINNAME, m_pinname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastPinDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastPinDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastPinDlg message handlers

void ICBlastPinDlg::OnOK() 
{
	if(ProjIO.nlistsigs > 0){
		//enable the remove button
		if(DesignFrm.GetDlgItem(IDC_REMOVESIG))
			DesignFrm.GetDlgItem(IDC_REMOVESIG)->EnableWindow(TRUE);
		
		if(DesignFrm.GetDlgItem(IDC_EDIT))
			DesignFrm.GetDlgItem(IDC_EDIT)->EnableWindow(TRUE);
		
		
		char *sigtext;
		LVCOLUMN lvc;		  //microsoft listctrl column
		HINSTANCE hInst;        //microsloft hinst
		int iCol;			//???
		
		//microsoft - update the dialog data..
		UpdateData();
		
		//Microsoft - Initialize the LVCOLUMN structure.
		lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 
		
		//Microsoft - adds columns to the list
		char szText[256];
		const int C_COLUMNS = 4;
		
		
		CString strText = _T("Pindata");
		CString colText;
		CString waveText;
		
		int nColumnCount = C_COLUMNS;
		
		
		
		// Insert the item, select none
		DesignFrm.m_sigListBox.InsertItem(
			LVIF_TEXT|LVIF_STATE, ProjIO.nsig, m_pinname, 
			(ProjIO.nsig%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
			0, 0);
		
		
		///////////////// Initialize the text of the subitems.
		//type col
		DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 1, "Pin");
		
		//mode col
		DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 2, "NA");
		
		//waveform col
		DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 3, "NA");
		
		
		
		
		
		ProjIO.nlistpins++;
		ProjIO.nsig++;
		
		//signals[ProjIO.nsig].name = "";
		
		if(ProjIO.nsig != 0)
			sprintf(pins[pin.pinnum].name, "%s", m_pinname.GetBuffer(m_pinname.GetLength()) );
		
		UpdateData();
		sprintf(pins[pin.pinnum].name, m_pinname.GetBuffer(m_pinname.GetLength()) );
	}
	else
		MessageBox("You must first add a signal to load to the pin","Error",MB_OK);
	
	CDialog::OnOK();
}
