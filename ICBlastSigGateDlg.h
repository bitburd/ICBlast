#if !defined(AFX_ICBLASTSIGGATEDLG_H__5137BF9B_C62F_48B9_8A69_EB69BCC878DD__INCLUDED_)
#define AFX_ICBLASTSIGGATEDLG_H__5137BF9B_C62F_48B9_8A69_EB69BCC878DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastSigGateDlg.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// ICBlastSigGateDlg dialog

class ICBlastSigGateDlg : public CDialog
{
// Construction
public:
	ICBlastSigGateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastSigGateDlg)
	enum { IDD = IDD_SIGNALS };
	int		m_input;
	CString	m_signalname;
	CString	m_type;
	CString	m_waveform;
	float	m_currsig;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastSigGateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL


// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastSigGateDlg)
	virtual void OnOK();
	afx_msg void OnCancelsig();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTSIGGATEDLG_H__5137BF9B_C62F_48B9_8A69_EB69BCC878DD__INCLUDED_)
