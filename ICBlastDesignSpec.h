
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignSpec.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignSpec dialog

class ICBlastDesignSpec : public CDialog
{
// Construction
public:
	ICBlastDesignSpec(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastDesignSpec)
	enum { IDD = IDD_EDITPROJTAB };
	CTabCtrl	m_projtab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignSpec)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignSpec)
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

