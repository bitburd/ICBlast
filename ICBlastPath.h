// ICBlastPath.h: interface for the ICBlastPath class.
//
//////////////////////////////////////////////////////////////////////
//#include "ICBlastVC6View.h"

#if !defined(AFX_ICBLASTPATH_H__789EBA02_5923_4343_B2A2_5E1CF22384B5__INCLUDED_)
#define AFX_ICBLASTPATH_H__789EBA02_5923_4343_B2A2_5E1CF22384B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ICBlastPath
{
public:
	ICBlastPath();
	void Create();
	void InitPath( double px, double py, double px2, double py2, bool grid);
	virtual ~ICBlastPath();
	void RenderPathData();
    
};

#endif // !defined(AFX_ICBLASTPATH_H__789EBA02_5923_4343_B2A2_5E1CF22384B5__INCLUDED_)
