#if !defined(AFX_ICBLASTPROJWIZDLG2_H__056F8E9A_2361_40C4_9B5C_77DD2E9E9115__INCLUDED_)
#define AFX_ICBLASTPROJWIZDLG2_H__056F8E9A_2361_40C4_9B5C_77DD2E9E9115__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjWizDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizDlg2 dialog

class ICBlastProjWizDlg2 : public CDialog
{
// Construction
public:
	ICBlastProjWizDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastProjWizDlg2)
	enum { IDD = IDD_PROJWIZARD2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjWizDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastProjWizDlg2)
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJWIZDLG2_H__056F8E9A_2361_40C4_9B5C_77DD2E9E9115__INCLUDED_)
