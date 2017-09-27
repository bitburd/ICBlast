#if !defined(AFX_ICBLASTSCHEDITOPTDLG_H__547F8171_7D49_477F_802B_AD347811305D__INCLUDED_)
#define AFX_ICBLASTSCHEDITOPTDLG_H__547F8171_7D49_477F_802B_AD347811305D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastSchEditOptDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastSchEditOptDlg dialog

class ICBlastSchEditOptDlg : public CDialog
{
// Construction
public:
	ICBlastSchEditOptDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastSchEditOptDlg)
	enum { IDD = IDD_OPTIONS };
	BOOL	m_grids;
	BOOL	m_color_wires;
	BOOL	m_crosshairs;
	BOOL	m_viewgrid;
	CString	m_filedirectory;
	BOOL	m_boundboxes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastSchEditOptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	//void OnLoadDefSymbols( void );

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastSchEditOptDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTSCHEDITOPTDLG_H__547F8171_7D49_477F_802B_AD347811305D__INCLUDED_)
