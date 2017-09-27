#if !defined(AFX_ICBLASTDESIGNFRMDLG_H__6D26ACFA_B683_461C_8DAE_BC53D2007B34__INCLUDED_)
#define AFX_ICBLASTDESIGNFRMDLG_H__6D26ACFA_B683_461C_8DAE_BC53D2007B34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignFrmDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignFrmDlg dialog

class ICBlastDesignFrmDlg : public CDialog
{
// Construction
public:
	ICBlastDesignFrmDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastDesignFrmDlg)
	enum { IDD = IDD_DESIGNFORM };
	CListCtrl	m_sigListBox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignFrmDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignFrmDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSignaladd();
	virtual BOOL OnInitDialog();
	afx_msg void OnImportbutton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDESIGNFRMDLG_H__6D26ACFA_B683_461C_8DAE_BC53D2007B34__INCLUDED_)
