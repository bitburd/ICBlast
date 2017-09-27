#if !defined(AFX_ICBLASTPATHDLG_H__21745C7A_C1D7_47A7_A15B_99E63CF7D5C4__INCLUDED_)
#define AFX_ICBLASTPATHDLG_H__21745C7A_C1D7_47A7_A15B_99E63CF7D5C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastPathDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastPathDlg dialog

class ICBlastPathDlg : public CDialog
{
// Construction
public:
	ICBlastPathDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastPathDlg)
	enum { IDD = IDD_PATH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastPathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastPathDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPATHDLG_H__21745C7A_C1D7_47A7_A15B_99E63CF7D5C4__INCLUDED_)
