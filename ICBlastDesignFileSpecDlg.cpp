// ICBlastDesignFileSpecDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastDesignFileSpecDlg.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>

#include "ICBlastProjectIO.h"
#include "ICBlastAnalogue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

extern ICBlastProjectIO ProjIO;

extern void getdate(char *date);
extern ASIG signals[40];


/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignFileSpecDlg dialog


ICBlastDesignFileSpecDlg::ICBlastDesignFileSpecDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastDesignFileSpecDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastDesignFileSpecDlg)
	m_defauthorname = _T("");
	m_createhierarchy = TRUE;
	m_hierarchyroot = _T("");
	m_defprocessname = _T("");
	m_gendesignspec = FALSE;
	m_ghdl = FALSE;
	m_vhdl = -1;
	m_icblasthdl = 1;
	//}}AFX_DATA_INIT
}


void ICBlastDesignFileSpecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastDesignFileSpecDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastDesignFileSpecDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastDesignFileSpecDlg)
	ON_BN_CLICKED(IDAPPLY, OnApply)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastDesignFileSpecDlg message handlers

void ICBlastDesignFileSpecDlg::OnApply() 
{
	// TODO: Add your control notification handler code here
	if(m_hWnd != NULL)
		UpdateData();

	if(m_gendesignspec == TRUE ){
		//This is where the try catch would come in handy
	    FILE *spec;
		spec = fopen("C:\\designspec.html","w+");

		//write a HTML design spec with it's header info:
		if(spec){
			MessageBox("Generating design spec in C:\designspec.html","ICBlast automation",MB_OK);
			
			fprintf(spec, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n ");
			fprintf(spec, "<HTML>\n<!-- TODO javascripts and css here -->\n");
			fprintf(spec, "  <HEAD>\n");

			//css for borders
			fprintf(spec, "<STYLE type=text/css> TABLE { color: black; background: LightBlue; padding: 12px 0px 12px 12px; }\n");
            fprintf(spec, " TABLE.withborder { border-style: solid; border-width: thin; border-color: black; }\n");
			fprintf(spec, "</STYLE>\n");
      
		
	        //write a title and an initial document titlepage
			fprintf(spec, "<title>%s Design Specifications</title>\n", ProjIO.specname);
			fprintf(spec, "<center><H2>%s Design Specifications</H2>", ProjIO.specname);
			fprintf(spec, "<p><table border=0><TR><TD>");

			fprintf(spec, "Author</TD><TD>%s</TD></TR>\n", ProjIO.authorname);
			fprintf(spec, "<TR><TD>Revision</TD><TD>%2.1f</TD></TR>",ProjIO.revision);
			char thedate[50];
			getdate(thedate);
			fprintf(spec, "<TR><TD>Date</TD><TD>%s</TD></TR></TABLE></p>", thedate);

			
			fprintf(spec, "%s", ProjIO.description);
			

			//First, output the analog signals..
			fprintf(spec, "<p><b>Analog Signals</b><p><TABLE width=60%% class=SpecIdx.withborder>\n");

			for(int i=1; i<ProjIO.nsig+1; i++)
				if(signals[i].data != 0.0)
				   fprintf(spec, "<TR><TD>%s</TD><TD><TYPE></TD><TD><DESCRIBE></TD><TD>%1.1f</TD></TR>\n", signals[i].name, signals[i].data);

			fprintf(spec, "</TABLE>\n");

			fprintf(spec, "<font color=#98AFC7>\n");
			fprintf(spec, "<p><p><!-- insert footer HERE --->\n");
			fprintf(spec, "CONFIDENTIAL project design documentation (c) %s\n", ProjIO.authorname );

			fclose(spec);
		}
	}

     //add more feature here...

}
