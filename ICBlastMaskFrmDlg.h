#if !defined(AFX_ICBLASTMASKFRMDLG_H__6A686755_6A64_4541_9B41_1A14B0DCE30F__INCLUDED_)
#define AFX_ICBLASTMASKFRMDLG_H__6A686755_6A64_4541_9B41_1A14B0DCE30F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastMaskFrmDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastMaskFrmDlg dialog

class ICBlastMaskFrmDlg : public CDialog
{
// Construction
public:
	ICBlastMaskFrmDlg(CWnd* pParent = NULL);   // standard constructor
    void CreateTreeFromResource(UINT treeid);
// Dialog Data
	//{{AFX_DATA(ICBlastMaskFrmDlg)
	enum { IDD = IDD_MASKFORM };
	BOOL	m_ongrid;
	long	m_maskwidth;
	long	m_masklength;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastMaskFrmDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastMaskFrmDlg)
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnOngrid();
	afx_msg void OnApplymask();
	afx_msg void OnClosemprop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTMASKFRMDLG_H__6A686755_6A64_4541_9B41_1A14B0DCE30F__INCLUDED_)
