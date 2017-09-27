#if !defined(AFX_ICBLASTSAVEVHDLDLG_H__E49BDD54_2D11_4A1C_90DC_93B1ACB23FC6__INCLUDED_)
#define AFX_ICBLASTSAVEVHDLDLG_H__E49BDD54_2D11_4A1C_90DC_93B1ACB23FC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastSaveVHDLDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastSaveVHDLDlg dialog

class ICBlastSaveVHDLDlg : public CDialog
{
// Construction
public:
	ICBlastSaveVHDLDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastSaveVHDLDlg)
	enum { IDD = IDD_SAVEVHDL };
	BOOL	m_functions;
	BOOL	m_ieee_libs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastSaveVHDLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastSaveVHDLDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTSAVEVHDLDLG_H__E49BDD54_2D11_4A1C_90DC_93B1ACB23FC6__INCLUDED_)
