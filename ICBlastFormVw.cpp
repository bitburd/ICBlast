// ICBlastFormVw.cpp 
// Used to display the initial forms on the ICBlast main view.
// The forms are all dialog templates. They should initially invisible.
// 2/27/08 add try catch and ASSERT codes to the dialog creations

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignFrmDlg.h"
#include "ICBlastBlankVw.h"
#include "ICBlastFormVw.h"
#include "ICBlastMaskFrmDlg.h"
#include "ICBlastMaskWindow.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastDesignForm.h"
#include "ICBlastDesignWin.h"

bool DEBUG=FALSE;

#ifdef _DEBUG
  #define new DEBUG_NEW
  #undef THIS_FILE
  static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastBlankVw BlankFrm;
extern ICBlastMaskFrmDlg MaskFrm;
extern ICBlastMaskWindow MaskWin;
extern ICBlastDesignForm DesignFrm;
extern ICBlastBlankVw DesignMain;
extern ICBlastDesignWin DesignWin;
extern ICBlastProjectDlg ProjDlg;
extern CWnd *pMainWnd;

/////////////////////////////////////////////////////////////////////////////
// ICBlastFormVw

IMPLEMENT_DYNCREATE(ICBlastFormVw, CFormView)

CFormView *pFormView;

ICBlastFormVw::ICBlastFormVw()
	: CFormView(ICBlastFormVw::IDD)
{
	//{{AFX_DATA_INIT(ICBlastFormVw)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: Add your control notification handler code here
}

ICBlastFormVw::~ICBlastFormVw()
{
	//fixes memory leaks..
	if(MaskFrm.m_hWnd != NULL)
		delete MaskFrm;
	if(DesignFrm.m_hWnd != NULL)
		delete DesignFrm;
	if(DesignWin.m_hWnd != NULL)
		delete DesignWin;

}

//Gets execute when the program first loads
//to create/initialize all dialogs and update their values.
void ICBlastFormVw::OnInitialUpdate()
{
    bool ret;

	
	if(DEBUG){
	  MaskWin.Create(IDD_MASKLAYOUT, this);
	  MaskWin.ShowWindow(SW_SHOW);
	  ProjDlg.Create(IDD_PROJDIALOG, this);
	  ProjDlg.ShowWindow(SW_SHOW);
	  DesignWin.Create(IDD_DESIGNWINDOW, this);
	  DesignWin.ShowWindow(SW_SHOW);
	  DesignFrm.Create(IDD_DESIGNFORM, BlankFrm.GetActiveWindow());
	  DesignFrm.ShowWindow(SW_SHOW);
	}
	else {
		int res = 0;
	
		//create a blank form to hold all other forms..
	    //if(BlankFrm.m_hWnd == NULL)
		//	BlankFrm.Create(IDD_BLANK, this);
		//BlankFrm.ShowWindow(SW_SHOW);

		//create the project form and hide it initially
		if(ProjDlg.m_hWnd == NULL)
		  ProjDlg.Create(IDD_PROJDIALOG, this );
		ProjDlg.ShowWindow(SW_HIDE);
		
	}

    //get pointer to windows form view
	pFormView = this;

}
	


void ICBlastFormVw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastFormVw)
	DDX_Control(pDX, IDC_BACKGROUND, m_background);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastFormVw, CFormView)
	//{{AFX_MSG_MAP(ICBlastFormVw)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastFormVw diagnostics

#ifdef _DEBUG
void ICBlastFormVw::AssertValid() const
{
	CFormView::AssertValid();
}

void ICBlastFormVw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ICBlastFormVw message handlers

void ICBlastFormVw::OnDraw(CDC* pDC) 
{
	PAINTSTRUCT *ps;

	// TODO: Add your specialized code here and/or call the base class
	//DesignFrm.Invalidate();
	DesignFrm.BeginPaint(ps);
	
}

BOOL ICBlastFormVw::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
		
	//GetClientRect(&r);
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void ICBlastFormVw::OnMouseMove(UINT nFlags, CPoint point) 
{
	pMainWnd->UpdateWindow();
	CFormView::OnMouseMove(nFlags, point);
}

void ICBlastFormVw::OnPaint() 
{
	
}
