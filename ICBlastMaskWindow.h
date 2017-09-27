#if !defined(AFX_ICBLASTMASKWINDOW_H__5D42B82C_569E_4B43_BBA7_F4376C3BA412__INCLUDED_)
#define AFX_ICBLASTMASKWINDOW_H__5D42B82C_569E_4B43_BBA7_F4376C3BA412__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastMaskWindow.h : header file
//

#include "OpenGLControl.h"



/////////////////////////////////////////////////////////////////////////////
// ICBlastMaskWindow dialog

class ICBlastMaskWindow : public CDialog
{
// Construction
public:
	ICBlastMaskWindow(CWnd* pParent = NULL);   // standard constructor
	CWnd *pParentWnd;  //parent to the main window
    unsigned long m_px;
	unsigned long m_py;

	//COpenGLControl openGLControl;

// Dialog Data
	//{{AFX_DATA(ICBlastMaskWindow)
	enum { IDD = IDD_MASKLAYOUT };
	CButton	m_maskpoly;
	CButton	m_mask2layout;
	CButton	m_maskpin;
	CButton	m_maskpath;
	float	m_coordx;
	float	m_coordy;
	//}}AFX_DATA

    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastMaskWindow)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	HGLRC   hrc;

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(ICBlastMaskWindow)
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMaskpath();
	afx_msg void OnMaskpin();
	afx_msg void OnSelect();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTMASKWINDOW_H__5D42B82C_569E_4B43_BBA7_F4376C3BA412__INCLUDED_)
