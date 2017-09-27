#if !defined(AFX_ICBLASTACANALYSISDLG_H__E46B7E78_BF74_46B9_8620_F53E8E6F5A8E__INCLUDED_)
#define AFX_ICBLASTACANALYSISDLG_H__E46B7E78_BF74_46B9_8620_F53E8E6F5A8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastACanalysisDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastACanalysisDlg dialog

class ICBlastACanalysisDlg : public CDialog
{
// Construction
public:
	ICBlastACanalysisDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastACanalysisDlg)
	enum { IDD = IDD_ACRUNPARAMS };
	CComboBox	m_steps;
	float	m_frequency;
	float	m_periodmax;
	float	m_periodmin;
	float	m_controlpoints;
	float	m_cycles;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastACanalysisDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastACanalysisDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTACANALYSISDLG_H__E46B7E78_BF74_46B9_8620_F53E8E6F5A8E__INCLUDED_)
