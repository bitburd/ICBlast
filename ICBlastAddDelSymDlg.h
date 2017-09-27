#if !defined(AFX_ICBLASTADDDELSYMDLG_H__9A049713_9ED6_4AA4_A5D5_E4E92B6F73C3__INCLUDED_)
#define AFX_ICBLASTADDDELSYMDLG_H__9A049713_9ED6_4AA4_A5D5_E4E92B6F73C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICBlastAddDelSymDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddDelSymDlg dialog

class ICBlastAddDelSymDlg : public CDialog
{
// Construction
public:
	ICBlastAddDelSymDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ICBlastAddDelSymDlg)
	enum { IDD = IDD_ADDDELSYMBOL };
	CComboBox	m_delsymlist;
	CString	m_addsym;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ICBlastAddDelSymDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ICBlastAddDelSymDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICBLASTADDDELSYMDLG_H__9A049713_9ED6_4AA4_A5D5_E4E92B6F73C3__INCLUDED_)
