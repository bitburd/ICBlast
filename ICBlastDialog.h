#if !defined(AFX_ICBLASTDIALOG_H__AA4BF375_321C_4582_95ED_118DF2C1E195__INCLUDED_)
#define AFX_ICBLASTDIALOG_H__AA4BF375_321C_4582_95ED_118DF2C1E195__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDialog dialog

class ICBlastDialog : public CDialog
{
// Construction
public:
	ICBlastDialog(CWnd* pParent = NULL);   // standard constructor
    virtual bool CheckOK();
// Dialog Data
	//{{AFX_DATA(ICBlastDialog)
	enum { IDD = IDD_DIALOG1 };
	CString	m_projname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDialog)
	virtual void OnOK();
	afx_msg void OnProjcancel();
	afx_msg void OnProjok();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDIALOG_H__AA4BF375_321C_4582_95ED_118DF2C1E195__INCLUDED_)
