//////////////////////////////////////////////////////////////////////
// File: ICBlastFile.cpp: implementation of the ICBlastFile class.
// Purpose: contains member functions to input and output the design
//  files. Projects once loaded should appear in the main window
// Revision:
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastFile.h"
#include "ICBlastProjectIO.h"
#include "ICBlastProjectDlg.h"
#include "ICBlastAnalogue.h"
#include "ICBlastDesignSpecDlg.h"
#include "ICBlastDesignFileSpecDlg.h"
#include "ICBlastAddPortDlg.h"

#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>

#include "ICBlastDesignForm.h"
#include "ICBlastSaveVHDLDlg.h"

using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern ICBlastProjectIO ProjIO;
extern HWND hWnd;

extern ICBlastFile project;
extern ICBlastFile mask;
extern ICBlastProjectDlg ProjDlg;

extern ICBlastAnalogue signal;
extern ICBlastAnalogue wire;
extern ICBlastAnalogue pin;

extern ASIG tempsig;
extern ASIG signals[40];
extern ICBlastDesignSpecDlg DesignSpecDlg;
extern ICBlastDesignForm DesignFrm;
extern ICBlastDesignFileSpecDlg;
extern ICBlastSaveVHDLDlg SaveVHDLDlg;
extern ICBlastAddPortDlg AddPortDlg;
extern AATOM pins[40];

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ICBlastFile::ICBlastFile()
{
     format = 0;
	 strcpy(VHDLlibrary, "IEEE");
}

ICBlastFile::~ICBlastFile()
{

}

int isfile (char *filename)
{
  /* Returns a true value if filename exists as a file, or false if not. */

	FILE *stream;
		
	/* Open the file */
		
	if((stream=fopen(filename, "r")) != NULL){
	   /* Close the file, and return success */
       fclose(stream);
	   return (1);
	}
	else {
		/* Failed */
		return (0);
	}

}

void getdate(char *date)
{
  time_t rawtime;
  struct tm *timeinfo;
 

  time ( &rawtime );
  timeinfo = localtime( &rawtime );
  sprintf(date, "%s", asctime(timeinfo) );
}

//test if the new project is open-able
bool ICBlastFile::OpenNewProject(){
    bool result = IDYES;

	if(ProjIO.projname != "") {
		sprintf(ProjIO.projfile, "%s.icp",ProjIO.projname);
		
		if(ProjIO.maskname != "")
			sprintf(ProjIO.maskfile, "%s.mask", ProjIO.maskname);
		
		//find out if project exists. If so, ask to overwrite	
		if( result == IDYES ){
			/********* 
			TODO insert code to validate the file *****/
		}
	}
	return TRUE;
}

bool ICBlastFile::OpenNewMask() {
	
	char maskheader[80];
    
	sprintf(maskheader, "+maskname: %s", ProjIO.maskname);

	//write to a mask file if a new mask was created
	if(ProjIO.maskname != ""){
		sprintf(ProjIO.maskfile,"%s.mask",ProjIO.maskname);
		ofstream mfile (ProjIO.maskfile);
		
		//open mask design file
		mfile<<"ICblast Layout Mask Design-\n";
		mfile<<"\n";
		mfile<<"HEADER\n";
		sprintf(maskheader, "+maskname: %s\n", ProjIO.maskname);
		mfile<<maskheader;
		
		mfile.close;
		
		ofstream pfile (ProjIO.projfile);

		pfile<<"\n";
		pfile<<"="<<ProjIO.maskfile;
		
		mfile.close();
        pfile.close();
		return TRUE;
	}
	return FALSE;
}

// ---- opens a VHDL like design into icblast
bool ICBlastFile::OpenDesign(char *file)
{
	
    bool result;
	bool verify = FALSE;
	static char sig[30];
    int i = 0;
	char word[30];
	char comment[25];
	char prev[30] = "";
	char next[30] = "";
	ASIG value[30];
	char genname[40];
	
	//find out if file exists. If so, open it
	//result = isfile(file);
	
	//open the file here..
	ifstream ifile;
	
	//update the columns and rows 
	//purge existing form data from the listctrl
	DesignFrm.PurgeSigList();
	
    ifile.open(file, ios::in);
	
	//on an exception try catch so it is found..
    //ifile.exceptions ( ifstream::failbit | ifstream::badbit );
	//try {    ----this try catch code did not seem to work to well on winxp
	
	while ( ifile>>word ) {
		
		strcmp(prev, word);

		if(strcmp(word, "signal") == 0)
			strcpy(prev, "signal") ;

		//test for comment header
		if(strcmp(word, "--") == 0) {
			result = TRUE;
			//header line found test for settings. If file is not in project
			//return FALSE if header malformed and exit gracefully..
		}
		
		if(strcmp(prev, "Author:") == 0)
				if(strcmp(word, "") != 0 && strcmp(word, "--") != 0)
			      strcpy(ProjIO.authorname, word);
		else {
				//it is a comment..
				ifile>>word;
				strcpy(comment,word);
			
		} else if(strcmp(word, "entity") == 0) {   //entity section
			
			//continue 2 decipher the rest	
			char name[40];  
			sprintf(name, "%s", word); ifile>>word;
			strcpy(name, word);
			
		} else if(strcmp(word, "generic(") == 0) { 

				   ifile>>word;
			       strcpy(genname, word);
		}

		if(strcmp(word, "signal") == 0 ) { //test for sig
			
			ifile>>next;

			if(next == "signal"){
				
				/******** this code is obscolete *****/
				char *tempwrd;
				int n=0;
				char c, lastch;
				
				//read in entity. start with signal keywords
				
				strcpy(prev, "signal");
				tempwrd = NULL;
				
				strcpy(prev, word);
				
				c = word[n]; //read in a single char
				
				//test for end of signals      
				tempwrd = (char *)malloc( 10 );
				strcpy(tempwrd, "");
				
				while(c > ',' || c > ';'){	//c is greater than ascii value of , or ;
					if(sizeof(strlen(tempwrd)) != 10){
						c = word[n];
						char temp[2];
						sprintf(temp, "%c", c);
						strncat(tempwrd, (const char *)temp, 10); 
						n++;
					}
					
					c = word[n];
					
				}
            }
			//it prev was signal so just go fwd
            //if(strcmp(prev, "signal") == 0){
			//	strcpy(sig, tempwrd);
			//    DesignFrm.AddSignals(sig, i );
				i++;
			//    free(tempwrd);
			//}

			//strcpy(prev, "");

		}  //end else if signal
		
		strcpy(prev, word);	
	}
	
	ifile.close();
	
	//else {
	//	MessageBox(hWnd,"Design file open failed! Please try again","Error",MB_OK);
	//	return FALSE;
	//}
	
	
	//test to see if error
	if(result == FALSE) {
		MessageBox(hWnd,"This file is not in a format readable by icblast","File Error",MB_OK);
		ifile.close();
		return result;
	}
	
	//}
	//catch (ifstream::failure e) {
	//   char except[55];
	//   sprintf(except, "ERROR: %s. Exception reading file.", e);
	//   MessageBox(hWnd, except,"FileLoadException",MB_OK);
	//}
	
	DesignFrm.ShowWindow(SW_SHOW);
	
	if(ProjIO.data == FALSE){
		MessageBox(hWnd, "No project is loaded. ICBlast will open a new untitled one","Project",MB_OK);
		ProjDlg.ShowWindow(SW_SHOW);
		DesignFrm.UpdateData();
		ProjDlg.UpdateMe();
		ProjDlg.UpdateData();
		SetWindowText(hWnd,"ICBlast - Project:untitled.icp");
	} else {
		ProjDlg.UpdateMe();
	}
	
	return result;
}

//opens a file of your derived class
void ICBlastFile::Open( ) {

}


//saves design files to disk
bool ICBlastFile::SaveDesign(CString file)
{
	HWND hWnd;
	char design[50];
	char date[50];

	getdate(date);
	
	//format = 0;

    //if there is data in the project name, check it
	if(ProjIO.data == TRUE && ProjIO.nsig != 0)
	{
		//if data is ok write it to file..
		if(file != ""){
			if(ofstream icfile (file)){
				
				//decipher file type
				switch(format){
					//write a .ic file..
					case 0:
						icfile<<"-- New ICBlast ic design"<<"\n";
						ProjDlg.UpdateData();
						icfile<<"-- Author: "<<ProjDlg.m_authorname.GetBuffer(ProjDlg.m_authorname.GetLength())<<"\n";
						icfile<<"-- Date: "<<date;
						icfile<<"-- Revision: "<<ProjIO.revision<<"\n\n";
						
						//begining of design
						icfile<<"BEGIN"<<"\n\n";
						//write the elements
						strcpy(design,ProjIO.icdesignfile);
						icfile<<"element "<<design<<" is \n";
						
						//If design element signals exist, write them to file..
						if(ProjIO.nlistsigs > 0) {
							
							//start with signals
							char oldmode[15]; 
							
							
							for(int i=1; i<=ProjIO.nlistsigs; i++){
								strcpy(oldmode, signals[i].mode);
								icfile<<signals[i].name;  //( signal =  s1 )..
								
								icfile<<"  signal ";
								icfile<<"="<<signals[i].data<<";\n";
								
								strcpy(oldmode, signals[i].name); //in out etc..
							}

							icfile<<");\nend element "<<design<<";\n\n";
						}

						//if design pins exist, write them to file
						if(ProjIO.nlistpins > 0) {
							
							//start with signals
							char oldmode[15]; 
							
							
							for(int p=0; p<=ProjIO.nlistpins; p++){
								//strcpy(oldmode, pins[p].mode);
								icfile<<" "<<pins[p].name;  //( signal =  s1 )..
								icfile<<" = default pin\n";
							}

							icfile<<");\nend pin\n\n";
						}

						//if design wires, write them
						if(ProjIO.nlistwires > 0){
					
							icfile<<" end"<<"\n";

							//icfile<<");\nend element "<<design<<";\n\n";
						}

						icfile<<"END \n";

					    break;

					//write a VHDL file..
					case 1:
						icfile<<"-- ICBlast VHDL design"<<"\n";
						ProjDlg.UpdateData();
						icfile<<"-- Author: "<<ProjDlg.m_authorname.GetBuffer(ProjDlg.m_authorname.GetLength())<<"\n";
						icfile<<"-- Date: "<<date;
						icfile<<"-- Revision: "<<ProjIO.revision<<"\n\n";
						
						//use ieee libs?
						if(SaveVHDLDlg.m_ieee_libs == 1){
							icfile<<"library "<<VHDLlibrary<<"\n";
							icfile<<"use IEEE.std_logic_1164.all;\n";
						}

						//write entity
						icfile<<"entity GENERIC is \n";
						//write the input ports to VHDL
						icfile<<"  port ( ";
						for(int i=1; i<ProjIO.nlistports; i++){
							icfile<<i<<", ";
						}
						icfile<<" ); "<<"\n";

						if(SaveVHDLDlg.m_functions == 1){
							for(int i=0; i<ProjIO.nlistsigs; i++){
								if(strcmp(signals[i].name,"") != 0){
									icfile<<"\narchitecture "<<signals[i].name<<" of "<<ProjIO.projname<<" is\n";
									//TODO add architecture here..
									icfile<<"begin\n";
									icfile<<"  "<<signals[i].data<<" : process is\n";
									icfile<<"        variable V : integer;\n"; //the voltage
									icfile<<"      begin\n";
									icfile<<"       -- Add architectural code here\n\n";
									icfile<<"      end process "<<signals[i].data<<";\n";
									icfile<<"end architecture "<<signals[i].name<<";\n";
								}
							}

						}

						icfile.close();
						break;
				}
			}
			else
				return -1;
		}
	} else
		MessageBox(hWnd,"No design opened. Please load or add a new design first","ERROR",MB_OK);
	
	return 0;
}

//saves any changed project data
bool ICBlastFile::SaveProject(char *filename)
{
	char *desspecname;
	char *process;
	char *author;

	//combine the project name to make a project file if one is
	//not selected from the file save as..
    if(filename != "")
	{
		sprintf(ProjIO.projfile, filename);
	}
	
	if(ProjIO.bNeedSave){
		if(ofstream pfile (filename))
		{
			//get projects process and author into char strings
			author = ProjIO.author.GetBuffer(50);
			
			
			//open ICblast project file
			pfile<<"ICBlastVC6 Project\n";
			pfile<<"projname="<<ProjIO.projname<<"\n";
			pfile<<"specname="<<ProjIO.specname<<"\n";
            pfile<<"process="<<"NONE\n";
			pfile<<"author="<<ProjIO.authorname<<"\n";
			pfile<<"revision="<<ProjIO.revision<<"\n\n";
			
			pfile<<"designunits="<<ProjIO.du<<"\n";
			pfile<<"databaseunits="<<ProjIO.dbu<<"\n";
			
			
			//Save any mask data here..
			
			
			//Save any project and design data here
			if(ProjIO.data) {
				pfile<<"\n";
				//search for a valid design file
				if(ProjIO.icdesignfile != ""){
				  pfile<<"icdesignfile="<<ProjIO.icdesignfile.GetBuffer(ProjIO.icdesignfile.GetLength());
				  SaveDesign(ProjIO.icdesignfile);
				}
			}
			
			//pfile.close;
			
			return 0;
		} else {
			return 1;
		}
	}
	return 0;
}

//saves the data in the derived file class
void ICBlastFile::Save( char *filename ) {

	
}

void SaveGeneric( char *filename ) {

	//find out if the file exists. If not, continue
	if(isfile(filename) != 1){
		
		if(ofstream ofile (filename))
		{
			//loop until end of file..
			//first, process the header at front of file

			ofile << filename << " - file data\n";  //write a header
			ofile << "\n";  //return

			
			ofile.close;

		}
		else {
			MessageBox(hWnd,"file save failed! Please try saving again or contact bitburd@yahoo.com","Error",MB_OK);
			
		}
	} 
}


// extracts data from project and design files
//returns the data to the right of char 'c'
//return NULL if errors..
void ICBlastFile::Extract( CString &ret, char *s, char c ) {
	unsigned int size;
	char temp;
	int t=0;			//t is the count of the chars in tempchars
	int pos=0;			//array position of the char 'c'
	CString tempchars;	//temp array to return
     
	size = strlen(s);

    for(int i=0; i<size; i++)
    {
        //get a char and see if it match the one passed..
	    temp = s[i];

        if(temp == '=')
            pos = i+1;  //save the position of char c in the array

		//get the rest of the chars after c into tempchars
		if(pos != 0)
			if(temp != '=')
				tempchars.Insert(i+1, temp);        
			
    }
    
	//return string to string passed in ret;
    ret = tempchars;
	
}

//extract a Lvalue of a design keyword
//returns the lvalue on match, NULL on no match..
char *ICBlastFile::ExtractKeyword(char str[30], char keywd[30])
{
	//switch on keywords. Allow only HDL type keywords
	if(str != "" && keywd != "")
	{
		if(strcmp(keywd, "sig") == 0){
			MessageBox(hWnd,"Signal found!","DEBUG",MB_OK);
			return str;
		}
		if(strcmp(keywd, "wire") == 0){
			MessageBox(hWnd,"wire found!","DEBUG",MB_OK);
			return str;
		}
			
	}
	else
	{
		return NULL;
	}
}

//opens a previously saved project
bool ICBlastFile::OpenProject(char *file){

    bool result;
	unsigned int rev;
	char header1[20], header2[20];
	char temp[256];
	
	
	//find out if project exists. If so, continue
	if(isfile(file) == 1){
		 
		//declare the project data as open
		ProjIO.OpenData(file);

		if(ifstream pifile (file))
		{
			//loop until end of file..
			//process the header at front of file
			
			pifile >> header1;  //"ICBlastVC6"
			pifile >> header2;  //" Project\n"
			
			pifile >> ProjIO.projname;
			pifile >> ProjIO.specname;
			pifile >> ProjIO.procname;

			//bugfix for loading proj..
			char firstname[50];
			char lastname[55];
			char next[55];
			pifile >> firstname;
			pifile >> next;
			//test for revision
			if(next[3] == 'v')
				//the next is a revision
				strcpy(ProjIO.revisionstr, next);
			else if(next[3] != 'v')
				strcpy(lastname, next);
			
			strcpy(ProjIO.revisionstr, next);

			//authorname bug fix
			sprintf(ProjIO.authorname, "%s %s", firstname, lastname);

			pifile.close;
			
			
			CString projext;
			CString specext;
			CString procnameext;
			CString authorext;
			CString revext;
			CString processext;
			
			//extract the Cstring after the equal cpy into char *
            Extract( projext, ProjIO.projname, '=' );
			strcpy(ProjIO.projname, projext.GetBuffer(projext.GetLength()));
			
			Extract( specext, ProjIO.specname, '=');
			strcpy(ProjIO.specname, specext.GetBuffer(specext.GetLength()));
			
			//BugFix - no extract for procname in ProjIO
			Extract( procnameext, ProjIO.procname, '=');
			strcpy(ProjIO.procname, procnameext.GetBuffer(procnameext.GetLength()) );

			Extract( authorext, ProjIO.authorname, '=');
			strcpy(ProjIO.authorname, authorext.GetBuffer(authorext.GetLength()));
			
			Extract( revext, ProjIO.revisionstr, '=' );
			strcpy(ProjIO.revisionstr, revext.GetBuffer(revext.GetLength()));
			
			ProjIO.data = TRUE;
			ProjIO.opendata = 1;

			ProjDlg.UpdateMe();
		
		}
		else {
			MessageBox(hWnd,"Project file open failed! Please try open again or contact bitburd@yahoo.com","Error",MB_OK);
			return FALSE;
		}
		
	}
	
    if(ProjIO.icdesignfile == _T(""))
		sprintf(ProjIO.title, "ICBlast - Project: %s", ProjIO.projname);
	else
		sprintf(ProjIO.title, "ICBlast - Project: %s", ProjIO.icdesignfile.GetBuffer(ProjIO.icdesignfile.GetLength()) );

	//debug only
	//char thedata[200];
	
	//sprintf(thedata, "%s %s %s %s", ProjIO.projname, ProjIO.specname, ProjIO.authorname, ProjIO.revisionstr);
	//MessageBox(hWnd, thedata, "LOADED PROJECT DATA", MB_OK);
	//ProjDlg.m_specname = ProjIO.specname;
	
	//char rev[10];

	//sprintf(rev, "%3g", &ProjIO.revision);
	//ProjDlg.m_revision.SetWindowText("1.0");
	//ProjDlg.m_authorname.SetWindowText("");


	ProjDlg.UpdatePrjFromFile();
	ProjDlg.UpdateData();

	return TRUE;
}
