// ICBlastDesignWin.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignWin.h"
#include "OpenGLVertex.h"
#include "OpenGLControl.h"
#include "ICBlastProjectIO.h"
#include "ICBlastAnalogSigWin.h"
#include "ICBlastWndStates.h"
#include "ICBlastWireToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignWin dialog
extern COpenGLControl glControl;
extern COpenGLControl waveGLControl;
extern ICBlastProjectIO ProjIO;
extern HINSTANCE hInstance;
extern HWND hWnd;
extern ICBlastWireToolDlg wiretool;
extern void Redraw(int n);

ICBlastWndState DWndState;


ICBlastDesignWin::ICBlastDesignWin(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignWin::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDesignWin)
	m_cadprompt = _T("");
	m_x = _T("");
	m_y = _T("");
	//}}AFX_DATA_INIT
	ProjIO.currTool = 0;

}


void ICBlastDesignWin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignWin)
	DDX_Control(pDX, IDC_COPYSCH, m_copysch);
	DDX_Control(pDX, IDC_DELETESCH, m_deletesch);
	DDX_Control(pDX, IDC_MOVESCH, m_movesch);
	DDX_Control(pDX, IDC_OPENGL_ANALOG, m_opengl_analog);
	DDX_Control(pDX, IDC_SELECTVTX, m_selectvtx);
	DDX_Control(pDX, IDC_SELECT, m_select);
	DDX_Control(pDX, IDC_TEXT, m_text);
	DDX_Control(pDX, IDC_PIN, m_pin);
	DDX_Control(pDX, IDC_LINE, m_line);
	DDX_Control(pDX, IDC_DOT, m_dot);
	DDX_Control(pDX, IDC_CIRCLE, m_circle);
	DDX_Control(pDX, IDC_BOX, m_box);
	DDX_Control(pDX, IDC_INV, m_inv);
	DDX_Control(pDX, IDC_GATE, m_gate);
	DDX_Control(pDX, IDC_PWRSRC, m_pwrsrc);
	DDX_Control(pDX, IDC_RESISTOR, m_resistor);
	DDX_Control(pDX, IDC_OPEN, m_open);
	DDX_Control(pDX, IDC_LOAD, m_load);
	DDX_Control(pDX, IDC_CAPB, m_capb);
	DDX_Control(pDX, IDC_CAPA, m_capa);
	DDX_Control(pDX, ID_WIRE, m_wire);
	DDX_Control(pDX, ID_POWER, m_power);
	DDX_Control(pDX, ID_GND, m_gnd);
	DDX_Control(pDX, IDC_OPAMP, m_opamp);
	DDX_Control(pDX, IDC_NORGATEBTN, m_norgate);
	DDX_Control(pDX, IDC_ORBOXGATEBTN, m_orboxgate);
	DDX_Control(pDX, IDC_ORGATEBTN, m_orgate);
	DDX_Control(pDX, IDC_ANDBOXGATE, m_andboxgate);
	DDX_Control(pDX, IDC_NANDGATEBTN, m_nandgate);
	DDX_Control(pDX, IDC_ANDGATEBTN, m_andgate);
	DDX_Text(pDX, IDC_CADPROMPT, m_cadprompt);
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_Y, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignWin, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignWin)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_ANDGATEBTN, OnAndgatebtn)
	ON_BN_CLICKED(IDC_TEXT, OnText)
	ON_BN_CLICKED(IDC_CIRCLE, OnCircle)
	ON_BN_CLICKED(IDC_BOX, OnBox)
	ON_BN_CLICKED(IDC_PIN, OnPin)
	ON_BN_CLICKED(IDC_LINE, OnLine)
	ON_WM_RBUTTONDOWN()
	ON_WM_MOVE()
	ON_BN_CLICKED(IDC_DOT, OnDot)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_BN_CLICKED(IDC_SELECTVTX, OnSelectvtx)
	ON_WM_SHOWWINDOW()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CString *DetectOS(void)
{

	CString m_sStr;
	
	OSVERSIONINFO OSversion;
	
	OSversion.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
	::GetVersionEx(&OSversion);
	
	switch(OSversion.dwPlatformId)
	{
	case VER_PLATFORM_WIN32s: 
		m_sStr.Format("Windows %d.%d",OSversion.dwMajorVersion,OSversion.dwMinorVersion);
		break;
		
	case VER_PLATFORM_WIN32_WINDOWS:
		if(OSversion.dwMinorVersion==0)
			m_sStr="Windows 95";  
		else
			if(OSversion.dwMinorVersion==10)  
				m_sStr="Windows 98";
			else
				if(OSversion.dwMinorVersion==90)  
					m_sStr="Windows Me";
				break;
				
	case VER_PLATFORM_WIN32_NT:
		if(OSversion.dwMajorVersion==5 && OSversion.dwMinorVersion==0) {
			MessageBox(hWnd,"Your operating system is 2000. To get a better look in ICBlast, try running this software on XP's default theme.","Color warning",MB_OK);
			m_sStr.Format("Windows 2000 With %s", OSversion.szCSDVersion);
		}
		else	
			if(OSversion.dwMajorVersion==5 &&   OSversion.dwMinorVersion==1)
				m_sStr.Format("Windows XP %s",OSversion.szCSDVersion);
			else	
				if(OSversion.dwMajorVersion<=4)
					m_sStr.Format("Windows NT %d.%d with %s",
					OSversion.dwMajorVersion,
					OSversion.dwMinorVersion,
					OSversion.szCSDVersion);			
				else	
					//for unknown windows/newest windows version
					::MessageBox(hWnd,"Even though you are running the latest windows, it is not \
								yet worked into this software. The software will run but the colors \
								and fonts will look best on older version of windows, like XP.","Message",MB_OK);
					m_sStr.Format("Windows %d.%d ",
					OSversion.dwMajorVersion,
					OSversion.dwMinorVersion);
				break;
	}
	return &m_sStr;
}

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignWin message handlers

BOOL ICBlastDesignWin::OnInitDialog() 
{
	DWndState.AddWin("DesignWindow");
	DWndState.bActive = TRUE;

	CDialog::OnInitDialog();
	
	if(m_hWnd != NULL)
	   ShowWindow(SW_SHOW);
	else
		MessageBox("Window graphics could not refresh!","ERROR",MB_OK);

    CRect rect;

	GetDlgItem(IDC_OPENGL_ANALOG)->GetWindowRect(rect);

	ScreenToClient(rect);

	glControl.CreateFromStatic("AnalogOGL",rect,this);
	

	hrc = wglCreateContext(glControl.dc->m_hDC);

	SwapBuffers(glControl.dc->m_hDC);

	//create the bitmaped buttons
    //get the os version. The default XP theme is a bit orange. Change
	//the buttons according to which os or theme is running

    // Create a and bitmap button.
    //if(m_andgate.m_hWnd == NULL)
	//	m_andgate.Create(_T("and"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 1234);

    //else {
		// Set the bitmap of the button to be the system XP bitmap.
     //   m_andgate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_ANDGATEXP)) );
        //make button visible
	//    m_andgate.ShowWindow(SW_SHOW);
	//}

	//create a nand bitmap button
	//if(m_nandgate.m_hWnd == NULL)
	//	m_nandgate.Create(_T("nand"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 12345);

    //else {
		
    //    m_nandgate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_NANDGATEXP)) );
        //make button visible
	//    m_nandgate.ShowWindow(SW_SHOW);
	//}

	//create a and box button
    //if(m_andboxgate.m_hWnd == NULL)
	//	m_andboxgate.Create(_T("andbox"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 123456);

    //else {
		
    //    m_andboxgate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_ANDBOXGATEXP)) );
        //make button visible
	//    m_andboxgate.ShowWindow(SW_SHOW);
	//}

	//create a or gate button
    //if(m_orgate.m_hWnd == NULL)
	//	m_orgate.Create(_T("or"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 123457);

    //else {
		
    //    m_orgate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_ORGATEXP)) );
        //make button visible
	//    m_orgate.ShowWindow(SW_SHOW);
	//}

	//create a nor gate button
	//if(m_norgate.m_hWnd == NULL)
	//	m_norgate.Create(_T("nor"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 1234578);

    //else {
		
    //    m_norgate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_NORGATEXP)) );
        //make button visible
	//    m_norgate.ShowWindow(SW_SHOW);
	//}

	//create a or box gate button
	//if(m_orboxgate.m_hWnd == NULL)
	//	m_orboxgate.Create(_T("orbox"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 1234579);

    //else {
		
    //    m_orboxgate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_ORBOXGATEXP)) );
        //make button visible
	//    m_orboxgate.ShowWindow(SW_SHOW);
	//}


	//create pwrsrc button
    //m_pwrsrc.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_PWRSRCXP)) );
    //make button visible
	//m_pwrsrc.ShowWindow(SW_SHOW);
	
	
	//create a load button
    //m_load.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_LOADXP)) );
     //make button visible
	//m_load.ShowWindow(SW_SHOW);

	//create a resistor button
	m_resistor.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_RESISTORXP)) );
	m_resistor.ShowWindow(SW_SHOW);

	//create a capacitor button
	m_capa.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_CAPAXP)) );
	m_capa.ShowWindow(SW_SHOW);

	//create a variable type b capacitor button
	//m_capb.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_CAPBXP)) );
	//m_capb.ShowWindow(SW_SHOW);

	//create a wire button
	//m_wire.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_WIREXP)) );
	//m_wire.ShowWindow(SW_SHOW);


	//create a opamp button
	//if(m_opamp.m_hWnd == NULL)
	//	m_opamp.Create(_T("opamp"), WS_CHILD|WS_VISIBLE, 
    //                CRect(10,10,36,36), this, 123457);

    //else {
		
    //    m_opamp.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_OPAMPXP)) );
        //make button visible
	//    m_opamp.ShowWindow(SW_SHOW);
	//}

	
	//create a open switch button
	//m_open.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_OPENXP)) );
	//m_open.ShowWindow(SW_SHOW);

	//create a power button
	//m_power.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_POWERXP)) );
	//m_power.ShowWindow(SW_SHOW);

    //create gnd button
	//m_gnd.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_GNDXP)) );
	//m_gnd.ShowWindow(SW_SHOW);


	//line
	m_line.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_LINEXP)) );
	m_line.ShowWindow(SW_SHOW);

	//dot
	m_dot.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_DOTXP)) );
	m_dot.ShowWindow(SW_SHOW);

	//Text
	m_text.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_TEXT)) );
	m_text.ShowWindow(SW_SHOW);

	//circle
	m_circle.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_CIRCLEXP)) );
	m_circle.ShowWindow(SW_SHOW);

	//box
	m_box.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BOX)) );
	m_box.ShowWindow(SW_SHOW);

	//IOpin
	m_pin.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_PINXP)) );
	m_pin.ShowWindow(SW_SHOW);

	
	
	//gate
	//m_gate.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_GATEXP)) );
	//m_gate.ShowWindow(SW_SHOW);

	//inverter
	//m_inv.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_INVXP)) );
	//m_inv.ShowWindow(SW_SHOW);

	//--------- the circuit editor edit buttons -------------
	//select
	m_select.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_SELECT)) );
	m_select.ShowWindow(SW_SHOW);

	//selectvtx
	m_selectvtx.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_SELECTVTX)) );
	m_selectvtx.ShowWindow(SW_SHOW);

	//move
	m_movesch.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_MOVESCH)) );
	m_movesch.ShowWindow(SW_SHOW);

	//copy
	m_copysch.SetBitmap(::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_COPYSCH)) );

	//delete
	m_deletesch.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_DELETESCH)) );



	SetWindowText("Visual Circuit Designer [new schematic]");


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL ICBlastDesignWin::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
		//create an opengl window for the visual designer
   
	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void ICBlastDesignWin::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Redraw(2);
	CDialog::OnMouseMove(nFlags, point);
}

void ICBlastDesignWin::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ProjIO.currForm = 1;
	CDialog::OnLButtonDown(nFlags, point);
}

void ICBlastDesignWin::OnAndgatebtn() 
{
	// TODO: Add your control notification handler code here
	
}

void ICBlastDesignWin::OnText() 
{
	ProjIO.currTool = 3;
	// TODO: Add your control notification handler code here
	glControl.DrawGLWindow();
	glControl.DrawStringbox(0.0, 0.0, "TypeMe");
	SwapBuffers(glControl.dc->m_hDC);
}

void ICBlastDesignWin::OnCircle() 
{
	// TODO: Add your control notification handler code here
	
}

void ICBlastDesignWin::OnBox() 
{
	// TODO: Add your control notification handler code here
	
}

void ICBlastDesignWin::OnPin() 
{
	// TODO: Add your control notification handler code here
	
}

void ICBlastDesignWin::OnLine(WPARAM wParam) 
{
	// TODO: Add your control notification handler code here
	ProjIO.currTool = 1;
	
    DWndState.bRecInput = TRUE;
}

void ICBlastDesignWin::OnRButtonDown(UINT nFlags, CPoint point) 
{

	// TODO: Add your message handler code here and/or call default
	//if(ProjIO.currTool == 1){
	//	if(wiretool.m_hWnd == NULL){
	//      wiretool.Create(IDD_WIRE,this);
	//	  wiretool.ShowWindow(SW_SHOW);
	//	}
	//	else
	//      wiretool.ShowWindow(SW_SHOW);
	//}
		// TODO: Add your message handler code here and/or call default
	switch(ProjIO.currTool){
	case 0: //in selection tool(any graphics window)
		//start with waveform tool
		//if(waveGLControl){
			//if(WaveColorDlg.m_hWnd == NULL)
			//   WaveColorDlg.Create(IDD_WAVEFORM_COLOR, NULL);
			//WaveColorDlg.ShowWindow(SW_SHOW);
		//}
		///todo - add dialogs for other graph window here..
		break;
	case 1:
		if(wiretool.m_hWnd != NULL)
		  wiretool.ShowWindow(SW_SHOW);
	    else{
		  wiretool.Create(IDD_WIRE, this);
	      wiretool.ShowWindow(SW_SHOW);
		}
		break;

	}

	CDialog::OnRButtonDown(nFlags, point);
}

void ICBlastDesignWin::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	if(glControl)
		Redraw(2);
}


void ICBlastDesignWin::OnDot() 
{
	// TODO: Add your control notification handler code here
	ProjIO.currTool = 2;
}

void ICBlastDesignWin::OnSelect() 
{
	// TODO: Add your control notification handler code here
	ProjIO.currTool = 0;
}

void ICBlastDesignWin::OnSelectvtx() 
{
	// TODO: Add your control notification handler code here
	ProjIO.currTool = -1;
}

void ICBlastDesignWin::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	glControl.m_grids=TRUE;
	glControl.DrawGLWindow();
	// TODO: Add your message handler code here
	
}

int ICBlastDesignWin::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void ICBlastDesignWin::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	
}

void ICBlastDesignWin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	glControl.DrawGLWindow();
	glControl.DrawSchData();
    SwapBuffers(glControl.dc->m_hDC);
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
