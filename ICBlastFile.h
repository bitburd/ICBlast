// ICBlastFile.h: interface for the ICBlastFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICBLASTFILE_H__18C4E0DD_6EAE_4841_939C_765F6E031DEC__INCLUDED_)
#define AFX_ICBLASTFILE_H__18C4E0DD_6EAE_4841_939C_765F6E031DEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

class ICBlastFile  
{
public:
	ICBlastFile();
	virtual ~ICBlastFile();

	virtual void Open( );
	virtual void Save( char *file );

	bool OpenProject(char *file);
	bool OpenNewProject();
	bool OpenNewMask();
	bool SaveProject(char *file);
	bool SaveDesign(CString file);
	void Extract(CString &ret, char string[100], char c);
	char *ExtractKeyword(char *str, char *keywd );

	void RemoveTemps();
	bool OpenDesign(char *file);

	char VHDLlibrary[50];
	char VerilogInc[50];
	
	unsigned int format;

	char logicmap[20]; //std_logic, ustd_logic, std_logic_1164, std_logic_arith, std_logic_unsigned, std_logic_signed 


private:
	char *filename;
    //***** int  usermode, groupmode, worldmode, cvslock; //UNIX
	int read, write, owner, hidden, cvslock; //WINDOWS
};

#endif // !defined(AFX_ICBLASTFILE_H__18C4E0DD_6EAE_4841_939C_765F6E031DEC__INCLUDED_)
