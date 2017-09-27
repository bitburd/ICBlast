#if !defined(AFX_ICBLASTFORMVW_H__0C67EB87_D3FA_4844_910F_E2D205CEFA8E__INCLUDED_)
#define AFX_ICBLASTFORMVW_H__0C67EB87_D3FA_4844_910F_E2D205CEFA8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastFormVw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastFormVw form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class ICBlastFormVw : public CFormView
{
protected:
	ICBlastFormVw();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(ICBlastFormVw)


// Form Data
public:
	//{{AFX_DATA(ICBlastFormVw)
	enum { IDD = IDD_BLANK };
	CStatic	m_background;
	//}}AFX_DATA

	RECT r;

// Attributes
public:
    virtual void OnInitialUpdate();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastFormVw)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~ICBlastFormVw();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(ICBlastFormVw)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTFORMVW_H__0C67EB87_D3FA_4844_910F_E2D205CEFA8E__INCLUDED_)
