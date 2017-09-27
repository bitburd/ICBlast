#if !defined(AFX_ICBLASTPARAMETERDLG_H__1B2C7881_0194_4C7D_91EC_BA11EED6EBC4__INCLUDED_)
#define AFX_ICBLASTPARAMETERDLG_H__1B2C7881_0194_4C7D_91EC_BA11EED6EBC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastParameterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastParameterDlg dialog

class ICBlastParameterDlg : public CDialog
{
// Construction
public:
	ICBlastParameterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastParameterDlg)
	enum { IDD = IDD_PARAMETERS };
	CComboBox	m_component;
	long	m_current;
	BOOL	m_annotate;
	CString	m_paramname;
	long	m_plength;
	long	m_power;
	long	m_pwidth;
	long	m_resistance;
	long	m_vmax;
	long	m_vmin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastParameterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastParameterDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPARAMETERDLG_H__1B2C7881_0194_4C7D_91EC_BA11EED6EBC4__INCLUDED_)
