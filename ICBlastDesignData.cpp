// ICBlastDesignData.cpp: implementation of the ICBlastDesignData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignData.h"
#include "ICBlastProjectIO.h"
#include "OpenGLVertex.h"
#include "ICBlastDesignForm.h"
#include "ICBlastWireToolDlg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern ICBlastProjectIO ProjIO;
extern ICBlastDesignForm DesignFrm;
extern ICBlastWireToolDlg wiretool;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ICBlastDesignData::ICBlastDesignData()
{
   bcount = 0; //box count.
   vcount = 0; //vertices count.
   lcount = 0; //line count. line segments are what make up wires
}

ICBlastDesignData::~ICBlastDesignData()
{

}

void ICBlastDesignData::AddVertex(float x1, float y1){
	v[vcount].Add(x1,y1);
	vcount++;
}

void ICBlastDesignData::AddBox(float px1, float py1, float px2, float py2, float px3, float py3, float px4, float py4)
{
	bcount++;
	b[bcount].px1 = px1;
	b[bcount].py1 = py1;
	b[bcount].px2 = px2;
	b[bcount].py2 = py2;
	b[bcount].px3 = px3;
	b[bcount].py3 = py3;
	b[bcount].px4 = px4;
	b[bcount].py4 = py4;

}

void ICBlastDesignData::AddLine(float x1, float y1, float x2, float y2)
{
	lcount++;
    l[lcount].px1 = x1;
	l[lcount].py1 = y1;
	l[lcount].px2 = x2;
	l[lcount].py2 = y2;
}

//add the design elements to a finish circuit schematic
void ICBlastDesignData::AddCircuit(int circuitid, char *name)
{

}

//add a design function or algorithm to a design element
int ICBlastDesignData::AddFunc(char *name, char *element)
{
	bool reterror;
	bool exists;
	extern ASIG signals[40];

    //test to see if design element exists
    //First, test the signal lists
	for(int i=0; i<ProjIO.nlistsigs; i++){
		char signame[10] = "";
		strcpy(signame, signals[i].name);
		if(strcmp(signame, "") == 0)
			exists = 1;
		else
			exists = 0;
	}

	if(exists == 1)
		return 1;
		
	if(exists == 0)
		return 0;
        
}

//save a circuit to disk or RAM..
void ICBlastDesignData::SaveCircuit(char *filen, int circuitid)
{
	int i, j, k;

    //get the save data type from the project
	switch(ProjIO.savetype){
	case 1: //only save it to RAM
		long size1,size2,size3;
		//count how big the array we have..
        size1 = sizeof(v);
		size2 = sizeof(l);
		size3 = sizeof(b);
		for(i=0; i<size1; i++){
		//	ProjIO.dd.v[i] = v[i];
		//    ProjIO.dd.vcount = i;
		}
		for(j=0; j<size2; j++){
		//	ProjIO.dd.l[j] = l[j];
		//	ProjIO.dd.lcount = j;
		}
		for(k=0; k<size3; k++){
		//	ProjIO.dd.b[k] = b[k];
		//	ProjIO.dd.bcount = k;
		}
		break;
	case 2:
		CFile file;
		CFileException ex;
		//file.Open(filen,CFile::modeWrite|CFile::typeBinary,&ex);
		
		if(filen)
		  file.Open(filen,CFile::modeWrite|CFile::typeBinary,&ex);
		

		break;
	}
}

bool ICBlastDesignData::LoadCircuit(char *filename, int circuitid)
{

	return TRUE;
}

int ICBlastDesignData::Getnlines(void)
{
	return lcount;
}

bool ICBlastDesignData::fprintline(FILE *file, int n)
{
	//n = the line in designdata struct to print to file
	if(file->_ptr != NULL){
		fprintf(file, "(%1.5f,Y%1.5f) (%1.5f,%1.5f)\n", l[n].px1, l[n].py1, l[n].px2, l[n].py2 ); 
		return 1;
	}
	else
		return 0;
}

//gets the bounding box of the nth item or dataitem with id and sets them in dd coords
void ICBlastDesignData::GetBox( int n, int nId ){
	HWND hWnd;
   if(nId)
	   MessageBox(hWnd,"getting the dataitem's box by id not supported yet","ERROR",MB_OK);
   else{
     x1 = ProjIO.dd.l[n].px1;
     x2 = ProjIO.dd.l[n].px2;
     y1 = ProjIO.dd.l[n].py1;
     y2 = ProjIO.dd.l[n].py2;
   }
}

bool ICBlastDesignData::CalcBox( int n ){
	//first, see if the line segment is single axis
    if(l[n].y1 == l[n].y2){
		//line is on y axis
		y1 = l[n].y1;
		y2 = y1;
	}

	if(l[n].x1 == l[n].x2){
		//line is on x axis
		x1 = l[n].x1;
		x2 = x1;
	}
	//if the line segments are bounding, set them in public design data
	if(wiretool.m_snap == TRUE){
      x1 = l[n].x1;
	  y1 = l[n].y1;
	  x2 = l[n].x2;
	  y2 = l[n].y2;
	}
	//TODO throw error if line is a point or other illegal bounds
	return TRUE;
}
   
bool ICBlastDesignData::AddBitmap(int type, char *fname)
{
	HINSTANCE hInst;

	//load a 256 color bitmap from a .bmp file
	hsbmp = LoadBitmap(hInst,fname);

	if(hsbmp == NULL)
		return 1;
	else
		return 0;
}