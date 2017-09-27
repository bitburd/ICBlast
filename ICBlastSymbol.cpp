// ICBlastSymbol.cpp: implementation of the ICBlastSymbol class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastSymbol.h"
#include "ICBlastViewSymbolDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

ICBlastSymbol AndSymbol;
ICBlastSymbol OrSymbol;
ICBlastSymbol NAndSymbol;
ICBlastSymbol NOrSymbol;

extern ICBlastViewSymbolDlg ViewSymDlg;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ICBlastSymbol Symbol;

ICBlastSymbol::ICBlastSymbol()
{

}

ICBlastSymbol::~ICBlastSymbol()
{

}

HBITMAP ICBlastSymbol::LoadSymbol(char *name)
{
   hBmp = (HBITMAP) ::LoadImage (AfxGetResourceHandle(),
                       name, IMAGE_BITMAP, 0, 0,
                        LR_CREATEDIBSECTION | LR_LOADFROMFILE);
   return hBmp;
}

void ICBlastSymbol::DisplaySymbol(char *name)
{
    //
}

HBITMAP ICBlastSymbol::ReturnSymbol( void )
{
	return hBmp;
}

//loads a series of file based bitmaps to the icblast
// view symbols tool dialog
int ICBlastSymbol::LoadDefSymbols( )
{
	int ret = 0;

	HBITMAP and;
	HBITMAP or;
	HBITMAP nand;
	HBITMAP nor;
	
	char defdirpath[100] = "E:\\ICBlastVC6_2\\win32\\Bitmaps";
	char dirpath[100] = "";	

	ViewSymDlg.UpdateData();

	strcpy(dirpath, ViewSymDlg.m_symbolfile.GetBuffer(ViewSymDlg.m_symbolfile.GetLength()) );

	//if bitmaps exists in the directory given, use them
	//else add from default dir
	//TODO add dir validation and file valid..
	if(strcmp(dirpath, "") == 0){

		//load default symbol bitmaps
		sprintf(dirpath, "%s\\AndSymbol.bmp", defdirpath);
		and = AndSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_andsym.SetBitmap(and);
			
		strcpy(dirpath, "");
		sprintf(dirpath, "%s\\OrSymbol.bmp", defdirpath);
		or = OrSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_orsym.SetBitmap(or);
		
		sprintf(dirpath, "%s\\NandSymbol.bmp", defdirpath);
		nand = NAndSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_nandsym.SetBitmap(nand);
		
		sprintf(dirpath, "%s\\NorSymbol.bmp", defdirpath);
		nor = NOrSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_norsym.SetBitmap(nor);

		if(and == NULL || or == NULL || nand == NULL || nor == NULL)
		  ret = 1;		
		else 
		  ret = 0;

	} else {

		//load default symbol bitmaps from directory
		sprintf(dirpath, "%s\\AndSymbol.bmp", dirpath);
		and = AndSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_andsym.SetBitmap(and);
			
		strcpy(dirpath, "");
		sprintf(dirpath, "%s\\OrSymbol.bmp", dirpath);
		or = OrSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_orsym.SetBitmap(or);
		
		sprintf(dirpath, "%s\\NandSymbol.bmp", dirpath);
		nand = NAndSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_nandsym.SetBitmap(nand);
		
		sprintf(dirpath, "%s\\NorSymbol.bmp", dirpath);
		nor = NOrSymbol.LoadSymbol( dirpath );
		ViewSymDlg.m_norsym.SetBitmap(nor);

		if(and == NULL || or == NULL || nand == NULL || nor == NULL)
		  ret = 1;		
		else 
		  ret = 0;
	}

	return ret;

}

