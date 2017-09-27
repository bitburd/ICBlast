#if !defined(AFX_ICBLASTSYMWND_H__D62649B7_09CA_4394_BD6E_F011586D4741__INCLUDED_)
#define AFX_ICBLASTSYMWND_H__D62649B7_09CA_4394_BD6E_F011586D4741__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastSymWnd.h : header file
//

#include "OpenGLControl.h"

/////////////////////////////////////////////////////////////////////////////
// ICBlastSymWnd window

class ICBlastSymWnd : public CWnd
{
// Construction
public:
	ICBlastSymWnd();

// Attributes
public:
   COpenGLControl openGL;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastSymWnd)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ICBlastSymWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(ICBlastSymWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTSYMWND_H__D62649B7_09CA_4394_BD6E_F011586D4741__INCLUDED_)
