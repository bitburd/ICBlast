#if !defined(AFX_ICBLASTPROJECTEDITTAB_H__CC7BB3DA_6BAC_497A_AF20_3E7AFABD7EE6__INCLUDED_)
#define AFX_ICBLASTPROJECTEDITTAB_H__CC7BB3DA_6BAC_497A_AF20_3E7AFABD7EE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastProjectEditTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjectEditTab dialog

class ICBlastProjectEditTab : public CDialog
{
// Construction
public:
	ICBlastProjectEditTab(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastProjectEditTab)
	enum { IDD = IDD_EDITPROJTAB };
	CTabCtrl	m_projtab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastProjectEditTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastProjectEditTab)
	virtual BOOL OnInitDialog();
	afx_msg void OnApply();
	afx_msg void OnRevert();
	afx_msg void OnOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTPROJECTEDITTAB_H__CC7BB3DA_6BAC_497A_AF20_3E7AFABD7EE6__INCLUDED_)
