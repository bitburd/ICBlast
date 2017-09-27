#if !defined(AFX_ICBLASTADDPORTDLG_H__E8C6523C_D49E_4772_BC11_90714C730224__INCLUDED_)
#define AFX_ICBLASTADDPORTDLG_H__E8C6523C_D49E_4772_BC11_90714C730224__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastAddPortDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddPortDlg dialog

class ICBlastAddPortDlg : public CDialog
{
// Construction
public:
	ICBlastAddPortDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastAddPortDlg)
	enum { IDD = IDD_DIALOG3 };
	CString	m_prefixin;
	CString	m_prefixout;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastAddPortDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastAddPortDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTADDPORTDLG_H__E8C6523C_D49E_4772_BC11_90714C730224__INCLUDED_)
