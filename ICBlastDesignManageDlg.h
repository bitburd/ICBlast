#if !defined(AFX_ICBLASTDESIGNMANAGEDLG_H__C141A696_A8EE_42B8_86C3_91DD5640818C__INCLUDED_)
#define AFX_ICBLASTDESIGNMANAGEDLG_H__C141A696_A8EE_42B8_86C3_91DD5640818C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignManageDlg dialog

class ICBlastDesignManageDlg : public CDialog
{
// Construction
public:
	ICBlastDesignManageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastDesignManageDlg)
	enum { IDD = IDD_DM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignManageDlg)
	afx_msg void OnApply1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDESIGNMANAGEDLG_H__C141A696_A8EE_42B8_86C3_91DD5640818C__INCLUDED_)
