// ICBlastPath.cpp: mask path creation object
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastPath.h"
#include "ICBlastUnit.h"
#include "ICBlastProjectIO.h"
#include "ICBlastVC6Doc.h"
#ifndef _CVIEW_
  #include "ICBlastVC6View.h"
#endif

#include "ICLayoutToolDlg.h"

#include "GL\gl.h"
#include "GL\glaux.h"
#include "GL\glu.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


  ICBlastUnit punit;  //path start
  ICBlastUnit punit2; //path end


//extern CRect rect;
extern ICBlastProjectIO ProjIO;
extern HWND hWnd;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ICBlastPath::ICBlastPath()
{
   
   ProjIO.data = 1;
   ProjIO.bNeedSave = 1;
   int i = 0;  //num path points in the dragable mouse path
}

ICBlastPath::~ICBlastPath()
{

}

void ICBlastPath::Create() 
{
	
    int i = 0;
	i = i +1;

	RECT rect;

	GetWindowRect(hWnd, &rect);

	//start path in middle of screen..
    InitPath( (GLfloat)0.5,(GLfloat)0.0,(GLfloat)-0.5,(GLfloat)-0.5, 0);

	//InitPath( (GLfloat) (rect.Width() / 2)-10, 
	//	      (GLfloat) (rect.Height() / 2),
	//		  (GLfloat) (rect.Width() / 2)+10,
	//		  (GLfloat) (rect.Height() / 2), 0);
    
	
}

void ICBlastPath::InitPath( double px, double py, double px2, double py2, bool grid)
{

	//if a design is open, create a draggable path
	if( ProjIO.opendata == 1 && ProjIO.datatype == 0 ){
	  punit.vx[0] = px;
	  punit.vy[0] = py;
	  punit2.vx[1] = px2;
	  punit2.vy[1] = py2;
	}

}

void ICBlastPath::RenderPathData() {
				
		        //create a path
                glBegin(GL_POLYGON);
		          // Set the color to default RED LAYER
		          glColor3f( 1.0f, 0.0f, 0.0f );
                  
				  // Create a path start from the xy data
                  glVertex2f( (punit.vx[0]) -2, (punit.vy[0])-(punit.du) );    ///  first path point upper left corner
					          
			      glVertex2f( (punit.vx[0]) +2, (punit.vy[0])-(punit.du) );    ///  first path point upper right corner
				             
			      glVertex2f( (punit.vx[0]) +2, (punit.vy[0])+(punit.du) );    ///  first path point lower right
				              
				  glVertex2f( (punit.vx[0]) -2, (punit.vy[0])+(punit.du) );    ///  first path point lower left..
					          


				glEnd();

}