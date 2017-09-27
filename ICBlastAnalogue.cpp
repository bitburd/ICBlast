// ICBlastAnalogue.cpp: 
//  This class is a container for analog design
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastAnalogue.h"

#include <iostream.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


extern HWND hWnd;


ICBlastAnalogue signal("");
ICBlastAnalogue wire("");
ICBlastAnalogue pin("");

AWIRE wires[40];
AATOM pins[40];

//////////////////////////////////////////////////////////////////////


//analogue constructor.
//char *name: The character string of the analog
//device or design item. Could be the name of a device,
//symbol, or top level design atom.
ICBlastAnalogue::ICBlastAnalogue(char *name)
{
   pinnum = 0;
}

ICBlastAnalogue::~ICBlastAnalogue()
{

}

/// members

bool ICBlastAnalogue::CreateSignal(int sigtype, char *name)
{

	switch( sigtype ) {
	case 0:
           
		   break;
	case 1:
           
		   break;
	case 2:
           
		   break;
	case 3:
           
		   break;

    default:
		break;
	}

  return 0;
}

//creates a wire inside a newly created design
bool ICBlastAnalogue::CreateWire(int id, float p1x, float p1y, float p2x, float p2y)
{
	
  wires[id].wireid = id;
  wires[id].x1 = p1x;
  wires[id].x2 = p2x;
  wires[id].y1 = p1y;
  wires[id].y2 = p2y;

  return 0;
}

//adds new pins to a new design
bool ICBlastAnalogue::AddDesignPin(char *name, int id)
{
   pin.pinnum++;
   pins[pinnum].atomid = rand();
   sprintf(pins[pinnum].name, name);
   return TRUE;
}

//deletes signals from a new design
bool ICBlastAnalogue::DeleteSignal(unsigned int sigid)
{
   return 0;
}

//attaches signals to other designs or design circuits
bool ICBlastAnalogue::AttachSignal(unsigned int sigid)
{
   return 0;
}



void ICBlastAnalogue::AddAtom(int elem1)
{
	
}

void ICBlastAnalogue::DeleteAtom(int elem)
{

}


