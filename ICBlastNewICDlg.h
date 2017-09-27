#if !defined(AFX_ICBLASTNEWICDLG_H__0D817183_DBB5_4DA9_B1A1_1CEAB86DE3B6__INCLUDED_)
#define AFX_ICBLASTNEWICDLG_H__0D817183_DBB5_4DA9_B1A1_1CEAB86DE3B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastNewICDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastNewICDlg dialog

class ICBlastNewICDlg : public CDialog
{
// Construction
public:
	ICBlastNewICDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastNewICDlg)
	enum { IDD = IDD_NEWICDLG };
	CString	m_icdesignfile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastNewICDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastNewICDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTNEWICDLG_H__0D817183_DBB5_4DA9_B1A1_1CEAB86DE3B6__INCLUDED_)
