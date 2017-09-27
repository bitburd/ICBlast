// ICBlastVC6Doc.cpp : implementation of the CICBlastVC6Doc class
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastVC6Doc.h"
#include "ICblastProjectIO.h"
#include "ICBlastFile.h"

#include <fstream>
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;
extern HWND hWnd;


/////////////////////////////////////////////////////////////////////////////
// CICBlastVC6Doc

IMPLEMENT_DYNCREATE(CICBlastVC6Doc, CDocument)

BEGIN_MESSAGE_MAP(CICBlastVC6Doc, CDocument)
	//{{AFX_MSG_MAP(CICBlastVC6Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICBlastVC6Doc construction/destruction

CICBlastVC6Doc::CICBlastVC6Doc()
{
	// TODO: add one-time construction code here
    sprintf(ProjIO.projfile, "%s.icp~", ProjIO.projname);
	sprintf(ProjIO.maskfile, "%s.mask~", ProjIO.maskname);
	//todo add more formats..
}

CICBlastVC6Doc::~CICBlastVC6Doc()
{

}

BOOL CICBlastVC6Doc::OnNewDocument()
{
	//if the document(project) is not opening, return false..
	if (!CDocument::OnNewDocument())
		return FALSE;

	//project.OpenNewProject();
	
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CICBlastVC6Doc serialization

void CICBlastVC6Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		//project.SaveProject(ProjIO.projfile);
	}
	else
	{
		// TODO: add loading code here
		//project.OpenProject(ProjIO.projfile);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CICBlastVC6Doc diagnostics

#ifdef _DEBUG
void CICBlastVC6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CICBlastVC6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CICBlastVC6Doc commands
