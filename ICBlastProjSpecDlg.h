#if !defined(AFX_ICBLASTPROJSPECDLG_H__B8979907_05EE_4707_9FA3_98227CB74A24__INCLUDED_)
#define AFX_ICBLASTPROJSPECDLG_H__B8979907_05EE_4707_9FA3_98227CB74A24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjSpecDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjSpecDlg dialog

class ICBlastProjSpecDlg : public CDialog
{
// Construction
public:
	ICBlastProjSpecDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastProjSpecDlg)
	enum { IDD = IDD_EDITPROJTAB };
	//CString	m_authorname;
	//CString	m_procname;
	//double	m_du;
	//double	m_revision;
	//int		m_metallayer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjSpecDlg)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastProjSpecDlg)
	afx_msg void OnOkprojedit();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJSPECDLG_H__B8979907_05EE_4707_9FA3_98227CB74A24__INCLUDED_)
