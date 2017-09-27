///////////////////////////////////////////////////////////////
// ICBlastAnalogue.h
//   This class is a superclass for analog tool data
//   It holds the signal data, the parametric data for signal
//   and circuit topology, circuit parasitics and design
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICBLASTANALOGUE_H__40CF13EF_58AC_4F24_A55C_2770E1DA3480__INCLUDED_)
#define AFX_ICBLASTANALOGUE_H__40CF13EF_58AC_4F24_A55C_2770E1DA3480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// analog atom data structure
//
// atoms are at the top of the data map
// They can help add, delete and store information
// about the design data lattice. The data associated with an
// atom can hold wiring, node, or signal data or names
struct AATOM {
  int atomid;
  char name[30];
  bool chain;  //a chain is part of a lattice that makes up a design hierarchy
} ;

struct AVERT {
	int id;
	char name[18];
	float x, y;
};

struct ASIG {
	int sigid;
	char name[15];
	char type[15];
	char mode[15];
	unsigned float data;
	bool chain;
} ;

struct AWIRE {
	int wireid;
	char name[18];
	int bus;
	float x1, y1, x2, y2; //it's box
	AVERT v1,v2;
	bool chain;
};





//class for analogue
class ICBlastAnalogue
{
	
    
public:
	ICBlastAnalogue(char *name);
	virtual ~ICBlastAnalogue();

	virtual bool CreateSignal(int sigtype, char *signame);
	virtual bool CreateWire( int AtomId, float p1x, float p1y, float p2x, float p2y);
	virtual bool DeleteSignal(unsigned int sigid);
	virtual bool AttachSignal(unsigned int sigid);
	
	void AddAtom(int atom);  //add analog atoms
	void DeleteAtom(int atom); //delete analog atoms
	bool AddDesignPin(char *name, int id);
	char modulename[40];
	int pinnum;

};

#endif // !defined(AFX_ICBLASTANALOGUE_H__40CF13EF_58AC_4F24_A55C_2770E1DA3480__INCLUDED_)
