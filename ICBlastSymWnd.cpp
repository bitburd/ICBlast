// ICBlastSymWnd.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastSymWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastSymWnd

ICBlastSymWnd::ICBlastSymWnd()
{
	
}


ICBlastSymWnd::~ICBlastSymWnd()
{
}


BEGIN_MESSAGE_MAP(ICBlastSymWnd, CWnd)
	//{{AFX_MSG_MAP(ICBlastSymWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ICBlastSymWnd message handlers

BOOL ICBlastSymWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	

	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
