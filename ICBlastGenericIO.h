//base class for implementing project data
#include "ICBlastUnit.h"

class ICBlastGenericIO {

public:
	//construct destruct
	ICBlastGenericIO();
	~ICBlastGenericIO();

	int				datatype;	//one of MASK, VERILOG, VHDL, CHECK
	bool			data;		//the IO class contains data if = 1
	char			atomname[256];  //the object atom name
	unsigned int	atom;		//the atom id of the IO object
	
	double			xpos;		//the x position
	double			ypos;		//the y position

  //IO private members
private:
	ICBlastUnit anchor;
	ICBlastUnit endpt;
	ICBlastUnit startpt;
    
	//the bounding box..
	double top;
	double bottom;
	double right;
	double left;
};
