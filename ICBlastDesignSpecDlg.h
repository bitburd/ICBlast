#if !defined(AFX_ICBLASTDESIGNSPECDLG_H__D7726736_3471_4027_A1A7_E05DC9987767__INCLUDED_)
#define AFX_ICBLASTDESIGNSPECDLG_H__D7726736_3471_4027_A1A7_E05DC9987767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignSpecDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignSpecDlg dialog

class ICBlastDesignSpecDlg : public CDialog
{
// Construction
public:
	ICBlastDesignSpecDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastDesignSpecDlg)
	enum { IDD = IDD_DESIGNSPEC };
	CButton	m_layeredit;
	CString	m_authorname;
	CString	m_specname;
	UINT	m_layers;
	float	m_du;
	float	m_revision;
	CString	m_process;
	float	m_corevolt;
	BOOL	m_genpinsfromtxt;
	CString	m_specfile;
	BOOL	m_subsection;
	CString	m_description;
	float	m_width;
	float	m_height;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignSpecDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignSpecDlg)
	afx_msg void OnApply();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDESIGNSPECDLG_H__D7726736_3471_4027_A1A7_E05DC9987767__INCLUDED_)
