#if !defined(AFX_ICBLASTADDWIREDLG_H__B261942A_E6DF_4280_AAF1_24FDF7BBAD2D__INCLUDED_)
#define AFX_ICBLASTADDWIREDLG_H__B261942A_E6DF_4280_AAF1_24FDF7BBAD2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastAddWireDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddWireDlg dialog

class ICBlastAddWireDlg : public CDialog
{
// Construction
public:
	ICBlastAddWireDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastAddWireDlg)
	enum { IDD = IDD_ADDWIRE };
	BOOL	m_genbus;
	CString	m_wirebus;
	CString	m_wirename;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastAddWireDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastAddWireDlg)
	virtual void OnOK();
	afx_msg void OnGenbus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTADDWIREDLG_H__B261942A_E6DF_4280_AAF1_24FDF7BBAD2D__INCLUDED_)
