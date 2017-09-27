#if !defined(AFX_ICBLASTPROJWIZDLG3_H__80F80A3E_0B19_4899_AAE6_444CE32027A1__INCLUDED_)
#define AFX_ICBLASTPROJWIZDLG3_H__80F80A3E_0B19_4899_AAE6_444CE32027A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjWizDlg3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizDlg3 dialog

class ICBlastProjWizDlg3 : public CDialog
{
// Construction
public:
	ICBlastProjWizDlg3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastProjWizDlg3)
	enum { IDD = IDD_PROJWIZARD3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjWizDlg3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastProjWizDlg3)
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJWIZDLG3_H__80F80A3E_0B19_4899_AAE6_444CE32027A1__INCLUDED_)
