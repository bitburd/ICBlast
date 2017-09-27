// ICBlastProject.cpp
// The class that constructs an initial project.
// By Jason Graham
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProject.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastProjectIO.h"

#include <list>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using std::list;
using std::string;

list <std::string> filelist;

extern ICBlastProjectDlg ProjDlg;
extern ICBlastProjectIO ProjIO;

//constructor. Call from main or CMainFrame..
ICBlastProject::ICBlastProject()
{

}

ICBlastProject::~ICBlastProject()
{

}

//creates a projet object to manipulate memory
bool ICBlastProject::CreateProj( string name )
{
	HWND hWnd;
	char afile[50];
	int a;

	try {
		a = name.empty();
		if(a != 1){
			strcpy(afile, name.c_str());
			AddFileToList( afile );
			return 0;
		}
	}
	catch( int a ) {
			MessageBox(hWnd,"Project Obj Name not set or NULL","PROJECT ERROR",MB_OK);
			return 1;
	}

}

//adds a file name to the list of the projects files
void ICBlastProject::AddFileToList( char *filename )
{
	string filestr(filename);

	//push it to the list
	filelist.push_back(filestr);


	ProjDlg.m_proj_filelist.InsertItem(
      LVIF_TEXT|LVIF_STATE, ProjIO.nprojfile, filename, 
      (ProjIO.nprojfile%2)==0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
      0, 0);

}