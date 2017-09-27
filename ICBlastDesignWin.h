#if !defined(AFX_ICBLASTDESIGNWIN_H__64D43461_4289_4A82_A468_E338554EEC92__INCLUDED_)
#define AFX_ICBLASTDESIGNWIN_H__64D43461_4289_4A82_A468_E338554EEC92__INCLUDED_
#include "Resource.h"
#include "OpenGLControl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastDesignWin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignWin dialog

class ICBlastDesignWin : public CDialog
{
// Construction
public:
	ICBlastDesignWin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastDesignWin)
	enum { IDD = IDD_DESIGNWINDOW };
	CButton	m_copysch;
	CButton	m_deletesch;
	CButton	m_movesch;
	CStatic	m_opengl_analog;
	CButton	m_selectvtx;
	CButton	m_select;
	CButton	m_text;
	CButton	m_pin;
	CButton	m_line;
	CButton	m_dot;
	CButton	m_circle;
	CButton	m_box;
	CButton	m_inv;
	CButton	m_gate;
	CButton	m_pwrsrc;
	CButton	m_resistor;
	CButton	m_open;
	CButton	m_load;
	CButton	m_drain;
	CButton	m_capb;
	CButton	m_capa;
	CButton	m_wire;
	CButton	m_power;
	CButton	m_gnd;
	CButton	m_opamp;
	CButton	m_norgate;
	CButton	m_orboxgate;
	CButton	m_orgate;
	CButton	m_andboxgate;
	CButton	m_nandgate;
	CButton	m_andgate;
	CString	m_cadprompt;
	CString	m_x;
	CString	m_y;
	//}}AFX_DATA

    char m_schfilename[50];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastDesignWin)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL


	HGLRC   hrc;
	

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastDesignWin)
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAndgatebtn();
	afx_msg void OnText();
	afx_msg void OnCircle();
	afx_msg void OnBox();
	afx_msg void OnPin();
	afx_msg void OnLine(WPARAM wParam);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnDot();
	afx_msg void OnSelect();
	afx_msg void OnSelectvtx();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTDESIGNWIN_H__64D43461_4289_4A82_A468_E338554EEC92__INCLUDED_)
