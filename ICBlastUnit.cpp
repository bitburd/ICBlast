// ICBlastUnit.cpp: implementation of the ICBlastUnit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastUnit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ICBlastUnit::ICBlastUnit()
{
   du = 1.0; //1micron design units
   //du = 0.001; //1nanometer design units
   //dbu = 1.0; //1micron database design units
   
}

ICBlastUnit::~ICBlastUnit()
{

}
