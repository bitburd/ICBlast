#if !defined(AFX_ICBLASTAPPLYTEXTDLG_H__8B536E16_A7BF_40CB_BB47_61363FAC46F6__INCLUDED_)
#define AFX_ICBLASTAPPLYTEXTDLG_H__8B536E16_A7BF_40CB_BB47_61363FAC46F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastApplyTextDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastApplyTextDlg dialog

class ICBlastApplyTextDlg : public CDialog
{
// Construction
public:
	ICBlastApplyTextDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastApplyTextDlg)
	enum { IDD = IDD_APPLYTEXTDLG };
	CString	m_funcname;
	CString	m_textbox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastApplyTextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastApplyTextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnApply();
	afx_msg void OnFunc();
	afx_msg void OnAddbody();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTAPPLYTEXTDLG_H__8B536E16_A7BF_40CB_BB47_61363FAC46F6__INCLUDED_)
