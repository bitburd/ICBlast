//ICBlastProjectIO.cpp 
//Class to handle the program's Input and Output
//All members that are related to File access are
//in ICBlastFile.cpp.

#include "stdafx.h"
#include "ICBlastProjectIO.h"
#include "ICBlastAnalogue.h"

#include <string>
#include <stdio.h>

ICBlastProjectIO::ICBlastProjectIO()
{
	opendata = 0;
	sprintf(maskname, "");
	sprintf(projname, "");
	sprintf(projfile, "");
	sprintf(procname, "");
	sprintf(maskfile, "");
	currTool = 0;
	currForm = 0; //blank form
	sprintf(title, "ICblast");
	du = 0.05;
	dbu = 1.0;
	process = _T("");
	maskwidth = _T("10.0");
	maskheight = _T("8.0");
	icdesignfile = _T("untitled.ic");
	maskdesignfile = _T("");
	ongrid = FALSE;
	signalname = _T("");
	nsig = 0;
	revision = 1.0;
	sigselected = FALSE;
	sigfocus = FALSE;
	wirename = _T("");
	wirebus = _T("");
	currsig = 2.0;
	savetype = 1;

	nlistsigs = 0;
	nlistwires = 0;
	nlistpins = 0;
	nlistports = 0;

	schdata=FALSE;

	nprojfile=0;
}

ICBlastProjectIO::~ICBlastProjectIO()
{
   
}

int ICBlastProjectIO::OpenData(char *file){
	data = FALSE;
	opendata = 1;
	strcpy(projfile, file);
	return 0;
}

