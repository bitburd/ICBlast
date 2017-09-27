// ICBlastSigGateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastSigGateDlg.h"
#include "ICBlastAnalogue.h"
#include "ICBlastProjectIO.h"
#include "ICBlastDesignFrmDlg.h"
#include "commctrl.h"
#include "ICBlastDesignForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



extern ICBlastProjectIO ProjIO;
extern ICBlastDesignForm DesignFrm;
extern HWND hWnd;

extern ICBlastAnalogue signal; //temp

ASIG tempsig;   //temp
ASIG signals[40];

/////////////////////////////////////////////////////////////////////////////
// ICBlastSigGateDlg dialog


ICBlastSigGateDlg::ICBlastSigGateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastSigGateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastSigGateDlg)
	m_input = -1;
	m_signalname = _T("");
	m_type = _T("");
	m_waveform = _T("");
	m_currsig = 0.0f;
	//}}AFX_DATA_INIT
}


void ICBlastSigGateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastSigGateDlg)
	DDX_Radio(pDX, IDC_SIGNALPURP, m_input);
	DDX_Text(pDX, IDC_SIGNALNAME, m_signalname);
	DDX_CBString(pDX, IDC_TYPE, m_type);
	DDX_CBString(pDX, IDC_WAVEFORMTYPE, m_waveform);
	DDX_Text(pDX, IDC_CURRSIG, m_currsig);
	DDV_MinMaxFloat(pDX, m_currsig, 0.f, 99999.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastSigGateDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastSigGateDlg)
	ON_BN_CLICKED(IDC_CANCELSIG, OnCancelsig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastSigGateDlg message handlers

//user clicks add signal
void ICBlastSigGateDlg::OnOK() 
{
	//enable the remove sig button
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


	// adds signals to the design	
	sigtext = m_signalname.GetBuffer(m_signalname.GetLength());


	signal.CreateSignal(m_input,sigtext);

	//set up the type
	switch(m_input)
	{
	case 0:
		strcpy(tempsig.type, "Default-Mode");
		break;
	case 1:
		strcpy(tempsig.type, "Multi-Mode");
		break;
	case 2:
		strcpy(tempsig.type, "Filter");
		break;
	case 3:
		strcpy(tempsig.type, "Buffer");
		break;
	}

	//set up the mode
	strcpy(tempsig.mode, m_type.GetBuffer(m_type.GetLength()) );
         
    ProjIO.signalname = m_signalname;
    
	//Microsoft - Initialize the LVCOLUMN structure.
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 

	//Microsoft - adds columns to the list
	char szText[256];
	const int C_COLUMNS = 4;

    if(ProjIO.nlistsigs == 0){
		for (iCol = 0; iCol < C_COLUMNS; iCol++) 
		{ 
			lvc.iSubItem = iCol;
			lvc.pszText = szText;
			
			lvc.cx = 75;     // width of column in pixels
			
			if ( iCol < 2 )
			{
				lvc.fmt = LVCFMT_LEFT;  // left-aligned column
			}
			else
			{ 
				lvc.fmt = LVCFMT_LEFT; // 		                         
			}

			
			if(ProjIO.nlistsigs == 0){//create the design category columns for the list ctrl
			switch(iCol){
			case 0:
				lvc.pszText = "Name";  //col0
				break;
			case 1:
				lvc.pszText = "Data"; //col1
				break;
			case 2:
				lvc.pszText = "Mode";   //col2
				break;
			case 3:
				lvc.pszText = "datatype";    //col3
				break;
			}
			}

		
			
			LoadString(hInst, IDS_FIRSTCOLUMN + iCol, 
                szText, sizeof(szText)/sizeof(szText[0]));
			if (ListView_InsertColumn(DesignFrm.m_sigListBox.m_hWnd, iCol,
				&lvc) == -1) 
				MessageBox("Unable to update the list ctrl column!","Error",MB_OK);
            //return FALSE; 
		} 
	}

	

    CString strText;
	CString colText;
	CString waveText;

    int nColumnCount = C_COLUMNS;
	
	strText.Format(TEXT("%s"), m_signalname.GetBuffer(m_signalname.GetLength()));

		
	//get the data just in case user has changed something
	UpdateData();

	// Insert the item, select none
		DesignFrm.m_sigListBox.InsertItem(
			LVIF_TEXT|LVIF_STATE, ProjIO.nlistsigs, strText, 
			(ProjIO.nlistsigs%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
			0, 0);

	///////////////// Initialize the text of the subitems.
	 //sample type col
	colText.Format(TEXT("%s"), tempsig.mode);
	DesignFrm.m_sigListBox.SetItemText(ProjIO.nlistsigs, 3, colText);

	//sig mode col
	strText.Format(TEXT("%s"), tempsig.type);
	DesignFrm.m_sigListBox.SetItemText(ProjIO.nlistsigs, 2, strText);

	//data or waveform
	waveText.Format(TEXT("%s"), m_waveform);
	DesignFrm.m_sigListBox.SetItemText(ProjIO.nlistsigs, 1, waveText);



	ProjIO.nlistsigs++;
	ProjIO.nsig++;

	//signals[ProjIO.nsig].name = "";
	
	//if(ProjIO.nlistsigs != 0)
    sprintf(signals[ProjIO.nlistsigs].name, "%s", m_signalname.GetBuffer(m_signalname.GetLength()) );
	
	//if(m_currsig)
	ProjIO.currsig = m_currsig;
	
	signals[ProjIO.nlistsigs].data = m_currsig;

	CDialog::OnOK();
}


void ICBlastSigGateDlg::OnCancelsig() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
