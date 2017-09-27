// ICBlastSymbol.h: interface for the ICBlastSymbol class.
//  the class loads simple bitmap images as schematic symbols
//  The images can then be placed in the schematics
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICBLASTSYMBOL_H__7EF51C38_9070_49C2_9AA1_6C8BFEC8F749__INCLUDED_)
#define AFX_ICBLASTSYMBOL_H__7EF51C38_9070_49C2_9AA1_6C8BFEC8F749__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ICBlastSymbol  
{

public:
	ICBlastSymbol();
	virtual ~ICBlastSymbol();
	HBITMAP LoadSymbol( char *name);
	void DisplaySymbol( char *name );
	HBITMAP ReturnSymbol( );
	int LoadDefSymbols();

	HBITMAP hBmp;
	BITMAP BM;

	char m_symboldir[100];

};

#endif // !defined(AFX_ICBLASTSYMBOL_H__7EF51C38_9070_49C2_9AA1_6C8BFEC8F749__INCLUDED_)
