// ICBlastVC6Doc.h : interface of the CICBlastVC6MaskDoc class
//
/////////////////////////////////////////////////////////////////////////////

//#if !defined(AFX_ICBLASTVC6DOC_H__A5E0CC3A_B6E4_4962_96C3_86E7CAEBC4A3__INCLUDED_)
//#define AFX_ICBLASTVC6DOC_H__A5E0CC3A_B6E4_4962_96C3_86E7CAEBC4A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CICBlastVC6MaskDoc : public CDocument
{
protected: // create from serialization only
	CICBlastVC6MaskDoc();
	DECLARE_DYNCREATE(CICBlastVC6MaskDoc)

// Attributes
public:


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICBlastVC6MaskDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CICBlastVC6MaskDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CICBlastVC6MaskDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

//#endif // !defined(AFX_ICBLASTVC6DOC_H__A5E0CC3A_B6E4_4962_96C3_86E7CAEBC4A3__INCLUDED_)
