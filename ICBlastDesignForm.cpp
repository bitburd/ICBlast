// ICBlastDesignForm.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignForm.h"
#include "openGLcontrol.h"
#include "openGLdevice.h"
#include "ICBlastProjectIO.h"
#include "ICBlastSigGateDlg.h"
#include "commctrl.h"
#include "ICBlastTestBenchDlg.h"
#include "ICBlastBlankVw.h"
#include "ICBlastPinDlg.h"
#include "ICBlastAddWireDlg.h"
#include "ICBlastParameterDlg.h"
#include "ICBlastAnalogue.h"
#include "ICBlastApplyTextDlg.h"
#include "ICBlastAddPortDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastDesignForm DesignFrm;
extern ICBlastProjectIO ProjIO;
extern ICBlastSigGateDlg SigGateDlg;
extern CFormView *pFormView;
extern ICBlastTestBenchDlg TestBenchDlg;
extern void forkedits();
extern ICBlastBlankVw BlankFrm;

extern ASIG signals[40];

extern ICBlastAddPortDlg AddPortDlg;

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignForm dialog

ICBlastApplyTextDlg funcDlg;

ICBlastDesignForm::ICBlastDesignForm(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignForm::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDesignForm)
	//}}AFX_DATA_INIT
}


void ICBlastDesignForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignForm)
	DDX_Control(pDX, IDC_SIGNALLIST, m_sigListBox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignForm, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignForm)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SIGNALADD, OnSignaladd)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_REMOVESIG, OnRemovesig)
	ON_BN_CLICKED(IDC_TESTBENCH, OnTestbench)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_ADDPIN, OnAddpin)
	ON_BN_CLICKED(IDC_ADDWIRE, OnAddwire)
	ON_BN_CLICKED(IDC_PARAMETERIZE, OnParameterize)
	ON_BN_CLICKED(IDC_ADDFUNCTION, OnAddfunction)
	ON_BN_CLICKED(IDC_PORTADD, OnPortadd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignForm message handlers

BOOL ICBlastDesignForm::OnInitDialog() 
{
	CDialog::OnInitDialog();
    //hide the blank form
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	char text[45] = "";
	sprintf(text,"Parameterize %s",DesignFrm.m_sigListBox.GetItemData(DesignFrm.m_sigListBox.GetSelectedCount()) );
	SetWindowText(text);

}

void ICBlastDesignForm::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	// Do not call CDialog::OnPaint() for painting messages
}


void ICBlastDesignForm::OnSignaladd() 
{
	ProjIO.bNeedSave = TRUE;

	//test to see if project data is still false
	if(ProjIO.data == FALSE)
		ProjIO.data = TRUE;

	// TODO: Add your control notification handler code here
	if(SigGateDlg.m_hWnd != NULL)
		SigGateDlg.ShowWindow(SW_SHOW);
    else {
		SigGateDlg.Create(IDD_SIGNALS,NULL);
		SigGateDlg.ShowWindow(SW_SHOW);
	}
}



BOOL ICBlastDesignForm::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	if(ProjIO.sigfocus == TRUE){
		for(int i=1; i<ProjIO.nsig; ++i){
			unsigned int select = m_sigListBox.GetItemState(i, LVIS_SELECTED);
			if( select == LVIS_SELECTED )
				ProjIO.sigselected = TRUE;
		}
		
	}
	
	//if(ProjIO.sigselected == TRUE)
	//	GetDlgItem(IDC_REMOVESIG)->EnableWindow(TRUE);
	//else
	//	GetDlgItem(IDC_REMOVESIG)->EnableWindow(FALSE);



	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void ICBlastDesignForm::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnMouseMove(nFlags, point);
}

void ICBlastDesignForm::OnRemovesig() 
{
	ProjIO.bNeedSave = TRUE;

	//start with no items selected
	int item = -1;
	
	int items[50];
    bool selected = FALSE;

	//find the list items states. what is selected?
	if(m_sigListBox.m_hWnd != NULL){
		m_sigListBox.SetFocus();
		for(int i=0; i<ProjIO.nlistsigs; ++i){
		  unsigned int state = m_sigListBox.GetItemState(i, LVIS_SELECTED);
			
		  if( state == LVIS_SELECTED ){
				item = state;
				items[i] = TRUE;  //tag this item to delete
				
		  }
		}	

		if(item == -1)
			//nothing was selected so dont remove it
		    MessageBox("you must first select a signal name to remove it","Signal removal",MB_OK);
		else {
			
			//loop through tagged items and delete them,,
			for(i=0; i<sizeof(items)-1; i++)
			{
			   if(items[i] == TRUE)
				  DesignFrm.m_sigListBox.DeleteItem(i);
			}
			
			ProjIO.nlistsigs--;
			ProjIO.nsig--;
			
		}

		//check to see if nlistsigs empty. If so, erase all sigs in
		//signals array
		if(ProjIO.nlistsigs == 0){
			for(i=0; i<ProjIO.nsig; ++i){
				strcpy(signals[i].name, "");
				signals[i].data = NULL;
			}
			ProjIO.nsig = 0;
			ProjIO.nlistsigs = 0;
		}


	}

 

}

void ICBlastDesignForm::OnTestbench() 
{
	// find what signal is selected for testing
	TestBenchDlg.DoModal();
}

BOOL ICBlastDesignForm::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(lParam == IDC_SIGNALLIST){
		switch(wParam) {
		case WM_LBUTTONDOWN:
			ProjIO.sigfocus = TRUE;
			break;
		case WM_LBUTTONUP:
			ProjIO.sigfocus = FALSE;
			break;	
		}
	}

	return CDialog::OnCommand(wParam, lParam);
}

void ICBlastDesignForm::Populate( void )
{

	UpdateData();

	//TODO populate form fields with file data

}

void ICBlastDesignForm::PurgeSigList( void )
{
	ProjIO.bNeedSave = TRUE;

	//loop through design signals and erase all
    for( int i=0; i<ProjIO.nsig; i++ )
	{	
		//loop through listctrl items and delete them
		DesignFrm.m_sigListBox.DeleteItem(i);
	}
}

//when user clicks add design items to the list
void ICBlastDesignForm::AddListItems(int element, char *name, char *type, char *mode, char* datatype) 
{
	char		*text;
    LVCOLUMN	lvc;		  //microsoft listctrl column
	HINSTANCE	hInst;        //microsloft hinst
    int			iCol;			//???
   	char		szText[256];
	const int	C_COLUMNS = 4;

	//enable the remove sig button
	if(GetDlgItem(IDC_REMOVESIG))
		GetDlgItem(IDC_REMOVESIG)->EnableWindow(TRUE);
	
	if(GetDlgItem(IDC_EDIT))
		GetDlgItem(IDC_EDIT)->EnableWindow(TRUE);

		//Microsoft - Initialize the LVCOLUMN structure.
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 

	//adds columns to the list if not already added
    if(ProjIO.nsig == 0){
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
			
			if(ProjIO.nsig == 0){//create the design category columns for the list ctrl
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
			if (ListView_InsertColumn(m_sigListBox.m_hWnd, iCol,
				&lvc) == -1) 
				MessageBox("Unable to update the list ctrl column!","Error",MB_OK);
            //return FALSE; 
		} 
	}

	int nColumnCount = C_COLUMNS;

	//enumerate design elements
	switch(element){

	case 1: //pin
	// adds pin to the design list	
	// Insert the item, select none
		DesignFrm.m_sigListBox.InsertItem(
			LVIF_TEXT|LVIF_STATE, ProjIO.nsig, name, 
			(ProjIO.nsig%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
			0, 0);

	    ///////////////// Initialize the text of the subitems.
	    
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 3, "NA");

	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 2, "NA");

	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 1, "PIN");

	
		ProjIO.nsig++;
		break;

	case 2:
	// adds signal to the design list	
	// Insert the item, select none
		DesignFrm.m_sigListBox.InsertItem(
			LVIF_TEXT|LVIF_STATE, ProjIO.nsig, name, 
			(ProjIO.nsig%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
			0, 0);
	    ///////////////// Initialize the text of the subitems.
	    //data
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 3, datatype);
	    //mode
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 2, mode);
	    //type col
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 1, type);
	

		ProjIO.nsig++;
		break;

	case 3:
	// adds wire to the design list	
	    // Insert the item, select none
		DesignFrm.m_sigListBox.InsertItem(
			LVIF_TEXT|LVIF_STATE, ProjIO.nsig, name, 
			(ProjIO.nsig%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
			0, 0);
	    ///////////////// Initialize the text of the subitems.
	    // col
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 3, "BusName");
	    //mode col
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 2, "NA");
	    //type col
	    DesignFrm.m_sigListBox.SetItemText(ProjIO.nsig, 1, "Wire");
	
		

		ProjIO.nsig++;
		break;
	}

	//if(ProjIO.nsig != 0)
    //     sprintf(signals[ProjIO.nsig].name, "%s", m_signalname.GetBuffer(m_signalname.GetLength()) );
	
}

//Adds all the signals defined
void ICBlastDesignForm::AddSignals( char *signals, int currow )
{
	LVCOLUMN lvc;		  //microsoft listctrl column
	HINSTANCE hInst;		//microsloft hinst
	int iCol;			//???
	UINT type;
	

	if(DesignFrm.m_hWnd != NULL)
	{
			
		char *sigtext;
			
			
		//microsoft - update the dialog data..
		UpdateData();
			
			
		// adds signal to the design 
		sigtext = signals;
			
		
		
		ProjIO.signalname = signals[0];
		
		//Microsoft - Initialize the LVCOLUMN structure.
		lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 
		
		//Microsoft - adds columns to the list
		char szText[256];
		const int C_COLUMNS = 4;
		
		//initialize the first 4 columns in row 0
		if(ProjIO.nsig == 0){
			for (iCol = 0; iCol < C_COLUMNS; iCol++) 
			{ 
				lvc.iSubItem = iCol;
				lvc.pszText = szText;
				
				lvc.cx = 75;	 // width of column in pixels
				
				if ( iCol < 2 )
				{
					lvc.fmt = LVCFMT_LEFT;	// left-aligned column
				}
				else
				{ 
					lvc.fmt = LVCFMT_LEFT; //								 
				}
				
				//create the design category columns for the list ctrl
				switch(iCol){
				case 0:
					lvc.pszText = "Name";  //col0
					break;
				case 1:
					lvc.pszText = "Data"; //col1
					break;
				case 2:
					lvc.pszText = "Mode";	//col2
					break;
				case 3:
					lvc.pszText = "Datatype";	 //col3
				}
				
				LoadString(hInst, IDS_FIRSTCOLUMN + iCol, 
					szText, sizeof(szText)/sizeof(szText[0]));
				if (ListView_InsertColumn(DesignFrm.m_sigListBox.m_hWnd, iCol,
					&lvc) == -1) 
					MessageBox("Unable to update the list ctrl column!","Error",MB_OK);
				//return FALSE; 
			} 
		}
		
		char strText[20];
		CString colText;
		CString waveText;
		
		int nColumnCount = C_COLUMNS;
		
		sprintf(strText, "%s", signals);
		
		// Insert the item, select none
		DesignFrm.m_sigListBox.InsertItem(
			LVIF_TEXT|LVIF_STATE, currow, strText, 
			(currow%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
			0, 0);
		
		//get the data just in case user has changed something
		UpdateData();
		
		
	}
}

void ICBlastDesignForm::OnEdit() 
{
	// TODO: Add your control notification handler code here
	forkedits();
}

void ICBlastDesignForm::OnAddpin() 
{
	// TODO: Add your control notification handler code here
	ICBlastPinDlg PinDlg;
	PinDlg.DoModal();
}

void ICBlastDesignForm::OnAddwire() 
{
	// TODO: Add your control notification handler code here
	ICBlastAddWireDlg AddWireDlg;
	AddWireDlg.DoModal();

}

void ICBlastDesignForm::OnParameterize() 
{
	// TODO: Add your control notification handler code here
	ICBlastParameterDlg ParamDlg;
	ParamDlg.DoModal();
}

void ICBlastDesignForm::OnAddfunction() 
{
	// TODO: Add your control notification handler code here
	//open a function control to add the function to a element

	if(funcDlg.m_hWnd == NULL)
		funcDlg.Create(IDD_APPLYTEXTDLG, NULL);
	funcDlg.ShowWindow(SW_SHOW);

}

void ICBlastDesignForm::OnPortadd() 
{
	// TODO: Add your control notification handler code here

	if(AddPortDlg.m_hWnd == NULL)
		 AddPortDlg.Create(IDD_DIALOG3, NULL);

	AddPortDlg.ShowWindow(SW_SHOW);
}
