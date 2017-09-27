#if !defined(AFX_ICBLASTANALOGSIGWIN_H__4DC91F47_31C5_4584_A66C_D1E8C20CD7D2__INCLUDED_)
#define AFX_ICBLASTANALOGSIGWIN_H__4DC91F47_31C5_4584_A66C_D1E8C20CD7D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastAnalogSigWin.h : header file
//
#include "ICBlastWndStates.h"

/////////////////////////////////////////////////////////////////////////////
// ICBlastAnalogSigWin dialog

class ICBlastAnalogSigWin : public CDialog
{
// Construction
	friend class ICBlastWndState;
public:
	ICBlastAnalogSigWin(CWnd* pParent = NULL);   // standard constructor
    float zoom;

// Dialog Data
	//{{AFX_DATA(ICBlastAnalogSigWin)
	enum { IDD = IDD_ANALOGWINDOW };
	CComboBox	m_waveform;
	int		m_frequencyslide;
	int		m_signalslide;
	//}}AFX_DATA

	HGLRC   hrc;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastAnalogSigWin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastAnalogSigWin)
	afx_msg void OnApplywave();
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnZoomin();
	afx_msg void OnZoomout();
	afx_msg void OnEditanalysis();
	afx_msg void OnReleasedcaptureSignalslide(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTANALOGSIGWIN_H__4DC91F47_31C5_4584_A66C_D1E8C20CD7D2__INCLUDED_)
