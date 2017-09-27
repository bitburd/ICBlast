//base class for implementing project data
#include "ICBlastAnalogue.h"
#include "ICBlastDesignData.h"

#include <vector>


class ICBlastProjectIO {

public:
	//construct destruct
	ICBlastProjectIO();
	~ICBlastProjectIO();

	int     currTool;
	int		currForm;
	int		datatype;  //one of MASK, VERILOG, VHDL, CHECK
	bool    data;		//design contains data if = 1
	double  revision;  //the revision of each design file
	char	revisionstr[10];

	double  du; //project design units
	double  dbu; //projects database design units
	double  xpos;
	double  ypos;

	char projname[256];
	char authorname[200];
	char procname[100];
	char specname[200];
    char maskname[256];
	char projfile[256];
	char maskfile[256];
    char repository[256];

	char XYstr[15];

  //IO public members
    int OpenData(char *file);

  //determines wizard status
	BOOL bWizard;

  //something is open
	BOOL opendata;
  
  //design project title
	char title[100];
  //design or proj is locked and or readonly
    BOOL bLocked;
  //design is in need of a save
	BOOL bNeedSave;
  //design needs cvs commit
	BOOL bNeedCommit;
  //design needs revision update
    BOOL bNeedUpdate;
  //design was/was-not checked recently
	BOOL bNeedCheck;
  //design has layers or hierarchy
	BOOL bHier;

  //number layers
	int layers;

  //author first/last name
	CString author;
  //process name for project
    CString process;

	//mask width/height
	CString maskwidth;
	CString maskheight;

	//filenames given to new design files
	CString icdesignfile;
	CString maskdesignfile;
	CString wirename;
	CString wirebus;

	
	bool isInMask;
	bool ongrid;

	int nsig;

	CString signalname;
	bool sigselected;
	bool sigfocus;

	char description[200];

	bool snap;
	int dessnap;  //snap to degrees..

	int		files;
	float	currsig;
						//temp save design to memory
	int		savetype;   //1=RAM 2=DISK 3=DISK&CHECKIN
	ICBlastDesignData dd;

	char waveclr[7];

	int nlistsigs;
	int nlistwires;
	int nlistpins;
	int nlistports;

	bool schdata;

	unsigned int nprojfile;


};
