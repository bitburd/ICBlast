// ICBlastMaskWindow.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastMaskWindow.h"
#include "OpenGLControl.h"
#include "ICBlastProjectIO.h"
#include "OpenGLDevice.h"
#include "ICBlastPathDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastMaskWindow MaskWin;
//extern COpenGLControl openGLControl;
extern ICBlastProjectIO ProjIO;
extern CFormView *pFormView;
extern COpenGLControl openGLControl;
extern COpenGLControl glControl;
extern COpenGLControl waveGLControl;
extern HINSTANCE hInstance;

extern void Redraw( int num );


/////////////////////////////////////////////////////////////////////////////
// ICBlastMaskWindow dialog


ICBlastMaskWindow::ICBlastMaskWindow(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastMaskWindow::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastMaskWindow)
	m_coordx = 0.0f;
	m_coordy = 0.0f;
	//}}AFX_DATA_INIT
	openGLControl.clicks = 0;

}


void ICBlastMaskWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastMaskWindow)
	DDX_Control(pDX, IDC_MASKBOX, m_maskpoly);
	DDX_Control(pDX, IDC_MASK2LAY, m_mask2layout);
	DDX_Control(pDX, IDC_MASKPIN, m_maskpin);
	DDX_Control(pDX, IDC_MASKPATH, m_maskpath);
	DDX_Text(pDX, IDC_COORDX, m_coordx);
	DDX_Text(pDX, IDC_COORDY, m_coordy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastMaskWindow, CDialog)
	//{{AFX_MSG_MAP(ICBlastMaskWindow)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_MASKPATH, OnMaskpath)
	ON_BN_CLICKED(IDC_MASKPIN, OnMaskpin)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastMaskWindow message handlers

BOOL ICBlastMaskWindow::OnInitDialog() 
{
	//openGLControl.m_grids = 1;
    //openGLControl.m_crosshair = 1;

    CDialog::OnInitDialog();

	ShowWindow(SW_SHOW);
	
	CRect rect;

	GetDlgItem(IDC_MASK_OPENGL_WINDOW)->GetWindowRect(rect);

	ScreenToClient(rect);

	openGLControl.m_type = 1;

	openGLControl.CreateFromStatic("MaskOGL",rect,this);

	

	char dutext[25];
	sprintf(dutext,"DU: %1.2f", ProjIO.du);

	if(hrc == NULL){
		//hrc = wglCreateContext(openGLControl.dc->m_hDC);
	    //wglMakeCurrent(openGLControl.dc->m_hDC, openGLControl.openGLDevice.renderContext);
	}

    // Create mask path button
    m_maskpath.SetBitmap( ::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_MASKPATHXP)) );
    //make button visible
	m_maskpath.ShowWindow(SW_SHOW);

	// Create bitmap for pin button
	m_maskpin.SetBitmap(::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_MASKPINXP)) );
    m_maskpin.ShowWindow(SW_SHOW);

	//create bitmap for the poly button
	m_maskpoly.SetBitmap(::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_MASKPOLYXP)) );
    m_maskpoly.ShowWindow(SW_SHOW);

	//create bitmap for mask to layout button
	m_mask2layout.SetBitmap(::LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_MASK2LAYXP)) );
    m_mask2layout.ShowWindow(SW_SHOW);

	wglMakeCurrent(openGLControl.dc->m_hDC,openGLControl.openGLDevice.renderContext);

	//setup initial mask window..
	openGLControl.m_grids = TRUE;

    if(openGLControl.m_hWnd != NULL){
	  openGLControl.m_grids = TRUE;
	  openGLControl.ClearGLWindow();
	  openGLControl.DrawLayoutGrids();
	  SwapBuffers(openGLControl.dc->m_hDC);
	}

	return TRUE;
}




void DrawPath() {
				
		        //create a path
                glBegin(GL_QUADS);
		       
                  
				if(ProjIO.ongrid == FALSE) {// Create a path start from the xy data if off grid
				  // Set the color to default light BLUE LAYER
		          glColor3f( 0.5f, 0.9f, 1.0f );
                //glVertex2f( (punit.vx[0]) -2, (punit.vy[0])-(punit.du) );    ///  first path point upper left corner
				  glVertex2f( 0.1, 0.1 );	          

			    //glVertex2f( (punit.vx[0]) +2, (punit.vy[0])-(punit.du) );    ///  first path point upper right corner
				  glVertex2f( -0.1, 0.1 );
				
			    //glVertex2f( (punit.vx[0]) +2, (punit.vy[0])+(punit.du) );    ///  first path point lower right
				  glVertex2f( -0.1, -0.1 );
				
				//glVertex2f( (punit.vx[0]) -2, (punit.vy[0])+(punit.du) );    ///  first path point lower left..
				  glVertex2f( 0.1, -0.1);	    
				}

				if(ProjIO.ongrid == TRUE){
				  // Set the color to default BLUE LAYER
		          glColor3f( 0.0f, 0.0f, 1.0f );
				  glVertex2f( (GLfloat)ProjIO.du, (GLfloat)ProjIO.du );	          ///  first path point on grid
				  glVertex2f( (GLfloat)-ProjIO.du, (GLfloat)ProjIO.du );
				  glVertex2f( (GLfloat)-ProjIO.du, (GLfloat)-ProjIO.du );
				  glVertex2f( (GLfloat)ProjIO.du, (GLfloat)-ProjIO.du);
				}


				glEnd();

}


//message handler members

BOOL ICBlastMaskWindow::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{

	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void ICBlastMaskWindow::OnMouseMove(UINT nFlags, CPoint point) 
{
	glControl.DrawGLWindow();
	glControl.DrawSchData(); //update the schematics
	//openGLControl.DrawGLWindow();
}


void ICBlastMaskWindow::OnMaskpath() 
{
	ProjIO.bNeedSave = TRUE;
	ProjIO.currTool = 51;

	// TODO: Add your control notification handler code here
	//openGLControl.DrawInitPath();
	
}



void ICBlastMaskWindow::OnMaskpin() 
{
	ProjIO.bNeedSave = TRUE;
	ProjIO.currTool = 21;
	// TODO: Add your control notification handler code here
	//openGLControl.DrawInitQuad();
	//openGLControl.UpdateData();
}

void ICBlastMaskWindow::OnSelect() 
{
	// TODO: Add your control notification handler code here
	ProjIO.currTool = -1;
}

void ICBlastMaskWindow::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//Redraw(1);
	CDialog::OnLButtonUp(nFlags, point);
}

void ICBlastMaskWindow::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ProjIO.currForm = 0;
    //Redraw(1);
	CDialog::OnLButtonDown(nFlags, point);
}
