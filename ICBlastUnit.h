// ICBlastUnit.h: interface for the ICBlastUnit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICBLASTUNIT_H__B7E4E067_13E3_4BAB_ABFE_2D4CE4ADEB6B__INCLUDED_)
#define AFX_ICBLASTUNIT_H__B7E4E067_13E3_4BAB_ABFE_2D4CE4ADEB6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class ICBlastUnit  
{
public:
	ICBlastUnit();
	virtual ~ICBlastUnit();
    double du;
	double dbu;
	double vx[50];  //screen vector x
    double vy[50];  //screen vector y
};

#endif // !defined(AFX_ICBLASTUNIT_H__B7E4E067_13E3_4BAB_ABFE_2D4CE4ADEB6B__INCLUDED_)
