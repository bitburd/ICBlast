#if !defined(AFX_ICBLASTBLANKVW_H__5220A8E0_EE69_4A30_9672_0ADEB9640242__INCLUDED_)
#define AFX_ICBLASTBLANKVW_H__5220A8E0_EE69_4A30_9672_0ADEB9640242__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastBlankVw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastBlankVw dialog

class ICBlastBlankVw : public CDialog
{
// Construction
public:
	ICBlastBlankVw(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastBlankVw)
	enum { IDD = IDD_BLANK };
	CStatic	m_background;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastBlankVw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	RECT r;

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastBlankVw)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTBLANKVW_H__5220A8E0_EE69_4A30_9672_0ADEB9640242__INCLUDED_)
