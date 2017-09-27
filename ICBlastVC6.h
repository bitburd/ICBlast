// ICBlastVC6.h : main header file for the ICBLASTVC6 application
//

#if !defined(AFX_ICBLASTVC6_H__55739807_B1D3_483F_B660_7BC77D41FF0F__INCLUDED_)
#define AFX_ICBLASTVC6_H__55739807_B1D3_483F_B660_7BC77D41FF0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CICBlastVC6App:
// See ICBlastVC6.cpp for the implementation of this class
//

class CICBlastVC6App : public CWinApp
{
public:
	CICBlastVC6App();
    //create the opengl control for a mask window

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICBlastVC6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CICBlastVC6App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTVC6_H__55739807_B1D3_483F_B660_7BC77D41FF0F__INCLUDED_)
