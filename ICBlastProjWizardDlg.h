#if !defined(AFX_ICBLASTPROJWIZARDDLG_H__0A6EE29E_93FD_4AC3_9645_FA0BCBBB9635__INCLUDED_)
#define AFX_ICBLASTPROJWIZARDDLG_H__0A6EE29E_93FD_4AC3_9645_FA0BCBBB9635__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjWizardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjWizardDlg dialog

class ICBlastProjWizardDlg : public CDialog
{
// Construction
public:
	ICBlastProjWizardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastProjWizardDlg)
	enum { IDD = IDD_PROJWIZARD };
	BOOL	m_newhdldesign;
	BOOL	m_newschematic;
	BOOL	m_newspecdoc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjWizardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastProjWizardDlg)
	afx_msg void OnNext();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJWIZARDDLG_H__0A6EE29E_93FD_4AC3_9645_FA0BCBBB9635__INCLUDED_)
