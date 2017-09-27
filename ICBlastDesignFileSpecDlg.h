#if !defined(AFX_ICBLASTDESIGNFILESPECDLG_H__91946E11_BAA2_4CC2_9C8F_2DFFF89C26E6__INCLUDED_)
#define AFX_ICBLASTDESIGNFILESPECDLG_H__91946E11_BAA2_4CC2_9C8F_2DFFF89C26E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignFileSpecDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignFileSpecDlg dialog

class ICBlastDesignFileSpecDlg : public CDialog
{
// Construction
public:
	ICBlastDesignFileSpecDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastDesignFileSpecDlg)
	enum { IDD = IDD_DESIGNFILESPEC };
	CButton	m_findtempbtn;
	CButton	m_findhierroot;
	CString	m_defauthorname;
	BOOL	m_createhierarchy;
	CString	m_hierarchyroot;
	CString	m_defprocessname;
	BOOL	m_gendesignspec;
	BOOL	m_ghdl;
	int		m_vhdl;
	int		m_icblasthdl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignFileSpecDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignFileSpecDlg)
	afx_msg void OnApply();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDESIGNFILESPECDLG_H__91946E11_BAA2_4CC2_9C8F_2DFFF89C26E6__INCLUDED_)
