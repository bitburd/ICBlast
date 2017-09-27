// ICBlastDesignData.h: Class to handle user design data
// Jason Graham
//////////////////////////////////////////////////////////////////////

#include "OpenGLVertex.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PRIMAMMT 100
#define MAXCIRCUIT 50

typedef struct LINE {
	float px1, py1;  //vertex point geometry
	float px2, py2;
	float x1;
	float y1;
	float x2;
	float y2; //cartesian bounding box of geometry
}Line;

typedef struct BOX {
	float px1, py1;
	float px2, py2;
	float px3, py3;
	float px4, py4;
	float x1;
	float y1;
	float x2;
	float y2; //cartesian bounding box of geometry
}Box;

//defines a function prototype in a device.
//this should for now be a text item that 
//gets saved to the designs.
typedef struct FUNC {
	unsigned int id;
	char elementname[15];
	char function[255];
}Func;
	

// a class that implements the design data
// designs can have vertex, lines, boxes
// future designs can have symbols, functions, filenames..
class ICBlastDesignData  
{

public:
	ICBlastDesignData();
	virtual ~ICBlastDesignData();

	//geometry
	void AddVertex( float x1, float y1 );
    void AddLine( float x1, float y1, float x2, float y2 );
	void AddBox( float px1,
		    float py1,
			float px2,
			float py2,
			float px3,
			float py3,
			float px4,
			float py4 );
	int AddFunc(char *name, char *element);
	bool AddBitmap(int type, char *fname);  //types: 1=symbolic 2=mathematic 3=other..

	//public members
	void AddCircuit(int circuitid, char *name);
	void SaveCircuit(char *filen, int circuitid);
	bool LoadCircuit(char *filename, int circuitid);

	int Getnlines(void);
	void GetBox(int n, int nId);
	bool CalcBox(int n);
	bool fprintline(FILE *file, int n);

	float x1;
	float x2;
	float y1;
	float y2;


private:
	//private member data
    Vertex	v[PRIMAMMT];
	Line	l[PRIMAMMT];
	Box		b[PRIMAMMT];
	unsigned int vcount;
	unsigned int bcount;
	unsigned int lcount;
	long circuitid[MAXCIRCUIT];
	BITMAP	sbmp;   //symbol or data item's bitmap
	HBITMAP hsbmp;
};

