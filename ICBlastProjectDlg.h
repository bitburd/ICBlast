#if !defined(AFX_ICBLASTPROJECTDLG_H__31467BDF_B33A_4A45_92C1_EE3653CC3755__INCLUDED_)
#define AFX_ICBLASTPROJECTDLG_H__31467BDF_B33A_4A45_92C1_EE3653CC3755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjectDlg dialog

class ICBlastProjectDlg : public CDialog
{
// Construction
public:
	ICBlastProjectDlg(CWnd* pParent = NULL);   // standard constructor
    ~ICBlastProjectDlg();
	void UpdatePrjFromFile(void);

// Dialog Data
	//{{AFX_DATA(ICBlastProjectDlg)
	enum { IDD = IDD_PROJDIALOG };
	CStatic	m_revision;
	CListCtrl	m_proj_filelist;
	CString	m_processtext;
	CString	m_specname;
	CString	m_authorname;
	//}}AFX_DATA

	bool m_bhide1;
	bool m_bhide2;

	void UpdateMe(void);

	CImageList ImageList;

	int GetSelectedItem();
	int m_fileItem;
    unsigned int nClicks;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjectDlg)
	public:
	virtual BOOL Create(UINT nID, CWnd* pParentWnd);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastProjectDlg)
	afx_msg void OnClickProjFilelist(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnInsertitemProjFilelist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditprocbtn();
	afx_msg void OnPaint();
	afx_msg void OnHide1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJECTDLG_H__31467BDF_B33A_4A45_92C1_EE3653CC3755__INCLUDED_)
