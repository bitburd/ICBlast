#include "stdafx.h"
#include "ICBlastVC6.h"
//#include "ICBlast.h"
#include "OpenGLWnd.h"
#include "GL/gl.h"
#include "glut.h"
#include "ICBlastProjectIO.h"
#include "ICBlastFormVw.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;

/////////////////////////////////////////////////////////////////////////////
// COpenGLWnd

IMPLEMENT_DYNCREATE(COpenGLWnd, CView)

COpenGLWnd::COpenGLWnd()
{
	//m_RenderScene = ClearCellVw;	// Set the default draw function.
}

COpenGLWnd::~COpenGLWnd()
{
}

// Standard OpenGL Init Stuff

BOOL COpenGLWnd::SetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd = 
	{
		sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd
		1,                                // version number
		PFD_DRAW_TO_WINDOW |              // support window
		PFD_SUPPORT_OPENGL |              // support OpenGL
		PFD_DOUBLEBUFFER,                 // double buffered
		PFD_TYPE_RGBA,                    // RGBA type
		24,                               // 24-bit color depth
		0, 0, 0, 0, 0, 0,                 // color bits ignored
		0,                                // no alpha buffer
		0,                                // shift bit ignored
		0,                                // no accumulation buffer
		0, 0, 0, 0,                       // accumulation bits ignored
		16,                               // 16-bit z-buffer
		0,                                // no stencil buffer
		0,                                // no auxiliary buffer
		PFD_MAIN_PLANE,                   // main layer
		0,                                // reserved
		0, 0, 0                           // layer masks ignored
	};

   int m_nPixelFormat = ::ChoosePixelFormat( m_pDC->GetSafeHdc(), &pfd );

    if ( m_nPixelFormat == 0 )
        return FALSE;

    return ::SetPixelFormat( m_pDC->GetSafeHdc(), m_nPixelFormat, &pfd );
}

BOOL COpenGLWnd::InitOpenGL()
{
	/****
	//Get a DC for the Client Area
	m_pDC = new CClientDC(this);

	//Failure to Get DC
	if( m_pDC == NULL )
		return FALSE;

	if( !SetupPixelFormat() )
		return FALSE;

    //Create Rendering Context
	m_hRC = ::wglCreateContext( m_pDC->GetSafeHdc() );

    //Failure to Create Rendering Context
    if( m_hRC == 0 )
        return FALSE;

	//Make the RC Current
	if( ::wglMakeCurrent( m_pDC->GetSafeHdc(), m_hRC ) == FALSE )
		return FALSE;

	// Usual OpenGL stuff
    //glColor3f(1.0, 1.0, 1.0);
	//glClearColor(1.0f,1.0f,1.0f,1.0f);  //start with gray screen mean no file open
	//glClearDepth(1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_TEXTURE_2D );
	glLineWidth( 1.0f );
	glPointSize( 3.0f );
	glShadeModel(GL_FLAT);
    
    
***/
	return TRUE;
}

void COpenGLWnd::RenderScene()
{
//DEBUG - try to draw something!!
	glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
	  glVertex2f(0.0, 0.0);
	  glVertex2f(0.0, 3.0);
	  glVertex2f(4.0, 3.0);
	  glVertex2f(6.0, 1.5);
	  glVertex2f(4.0, 0.0);
	glEnd();

	glFlush();
	
}

BEGIN_MESSAGE_MAP(COpenGLWnd, CView)
	//{{AFX_MSG_MAP(COpenGLWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// COpenGLWnd diagnostics

#ifdef _DEBUG
void COpenGLWnd::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLWnd::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLWnd message handlers

// Initialize OpenGL when window is created.
int COpenGLWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	/***if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if ( !InitOpenGL() )
	{
		MessageBox( "Error setting up OpenGL!", "Init Error!",
			MB_OK | MB_ICONERROR );
		return -1;
	}
   */
	return 0;
}

// Shutdown this view when window is destroyed.
void COpenGLWnd::OnDestroy()
{
	CView::OnDestroy();

	//wglMakeCurrent(0,0);
	//wglDeleteContext(m_hRC);
	//if( m_pDC )
	//{
	//	delete m_pDC;
	//}
	//m_pDC = NULL;
}

// Override the errase background function to
// do nothing to prevent flashing.
BOOL COpenGLWnd::OnEraseBkgnd(CDC* pDC) 
{	
	return TRUE;
}

// Set a few flags to make sure OpenGL only renders
// in its viewport.
BOOL COpenGLWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
	//cs.lpszClass = ::AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC,
	//	::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
	//cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	
	return CView::PreCreateWindow(cs);
}

void COpenGLWnd::OnDraw(CDC *pDC)
{
	//SetContext();
	//switch(ProjIO.opendata){
	//case 0:
	//    glClearColor(0.6, 0.6, 0.6, 0.6);
	//    glClear(GL_COLOR_BUFFER_BIT);
	//	break;
	//case 1:
	//	glClearColor(1.0, 1.0, 1.0, 0.0);
	//    glClear(GL_COLOR_BUFFER_BIT);
        
	//	break;
	//}

	//RenderScene();
	//SwapGLBuffers();
}


