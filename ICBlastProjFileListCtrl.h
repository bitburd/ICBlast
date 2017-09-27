#if !defined(AFX_ICBLASTPROJFILELISTCTRL_H__D346F51A_393C_445E_A2F1_5CDAFCCAABD2__INCLUDED_)
#define AFX_ICBLASTPROJFILELISTCTRL_H__D346F51A_393C_445E_A2F1_5CDAFCCAABD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjFileListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjFileListCtrl window

class ICBlastProjFileListCtrl : public CListCtrl
{
// Construction
public:
	ICBlastProjFileListCtrl();
	int GetSelectedItem();
    unsigned int nItem;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjFileListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ICBlastProjFileListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(ICBlastProjFileListCtrl)
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJFILELISTCTRL_H__D346F51A_393C_445E_A2F1_5CDAFCCAABD2__INCLUDED_)
