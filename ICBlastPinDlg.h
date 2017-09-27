#if !defined(AFX_ICBLASTPINDLG_H__24B7B0F9_BFEA_4B29_A417_B6B3EA6D3B60__INCLUDED_)
#define AFX_ICBLASTPINDLG_H__24B7B0F9_BFEA_4B29_A417_B6B3EA6D3B60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastPinDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastPinDlg dialog

class ICBlastPinDlg : public CDialog
{
// Construction
public:
	ICBlastPinDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastPinDlg)
	enum { IDD = IDD_ADDPIN };
	CComboBox	m_pinwires;
	BOOL	m_genpinbus;
	CString	m_pinpurp;
	BOOL	m_shorttowire;
	CString	m_pinname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastPinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastPinDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPINDLG_H__24B7B0F9_BFEA_4B29_A417_B6B3EA6D3B60__INCLUDED_)
