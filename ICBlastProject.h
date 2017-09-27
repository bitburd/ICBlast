// ICBlastProject.h: ////////////////////////////////////////////////
#include <string>
#include <iostream>
#include <list>

using namespace std;
using std::string;

//typedef BOOL bool;

class ICBlastProject  
{
public:
	ICBlastProject();
	~ICBlastProject();
	bool CreateProj( string name );
	//void CreateFileList( );
	void AddFileToList( char *filename );
	//void DelFileFromList( char *filename );
	//void ResetFileList( );
private:
    string TheFile;
	string ThePath;
	string currFile;

};

