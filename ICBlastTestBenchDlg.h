#if !defined(AFX_ICBLASTTESTBENCHDLG_H__F8C45305_4A30_4442_8941_1EAEB2008213__INCLUDED_)
#define AFX_ICBLASTTESTBENCHDLG_H__F8C45305_4A30_4442_8941_1EAEB2008213__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastTestBenchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastTestBenchDlg dialog

class ICBlastTestBenchDlg : public CDialog
{
// Construction
public:
	ICBlastTestBenchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastTestBenchDlg)
	enum { IDD = IDD_TESTBENCHDLG };
	CEdit	m_testname;
	CListBox	m_testitem;
	BOOL	m_volt;
	CString	m_testvolt;
	CString	m_testrange;
	CString	m_testbias;
	BOOL	m_range;
	BOOL	m_noise;
	BOOL	m_distortion;
	BOOL	m_bias;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastTestBenchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastTestBenchDlg)
	virtual void OnOK();
	afx_msg void OnTbfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTTESTBENCHDLG_H__F8C45305_4A30_4442_8941_1EAEB2008213__INCLUDED_)
