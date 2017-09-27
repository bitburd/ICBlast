#if !defined(AFX_ICBLASTDESIGNFORM_H__C5F83C2E_BF0B_44B6_ACBE_806F2D5C85ED__INCLUDED_)
#define AFX_ICBLASTDESIGNFORM_H__C5F83C2E_BF0B_44B6_ACBE_806F2D5C85ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignForm.h : header file
//

#include "OpenGLControl.h"
#include <vector>

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignForm dialog

class ICBlastDesignForm : public CDialog
{
// Construction
public:
	void Populate(void);
	void PurgeSigList( void );
	void AddSignals( char *signals, int currow );
	ICBlastDesignForm(CWnd* pParent = NULL);   // standard constructor
	CWnd *pParentWnd;  //parent to the main window

	COpenGLControl openGL;
    void AddListItems(int elem, char *c1, char *c2, char *c3, char *c4);  


// Dialog Data
	//{{AFX_DATA(ICBlastDesignForm)
	enum { IDD = IDD_DESIGNFORM };
	CListCtrl	m_sigListBox;
	//}}AFX_DATA



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignForm)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignForm)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSignaladd();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRemovesig();
	afx_msg void OnTestbench();
	afx_msg void OnEdit();
	afx_msg void OnAddpin();
	afx_msg void OnAddwire();
	afx_msg void OnParameterize();
	afx_msg void OnAddfunction();
	afx_msg void OnPortadd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDESIGNFORM_H__C5F83C2E_BF0B_44B6_ACBE_806F2D5C85ED__INCLUDED_)
