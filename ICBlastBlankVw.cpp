// ICBlastBlankVw.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastBlankVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastBlankVw dialog


ICBlastBlankVw::ICBlastBlankVw(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastBlankVw::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastBlankVw)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ICBlastBlankVw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastBlankVw)
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastBlankVw, CDialog)
	//{{AFX_MSG_MAP(ICBlastBlankVw)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastBlankVw message handlers

void ICBlastBlankVw::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
}
