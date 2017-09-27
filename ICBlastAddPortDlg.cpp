// ICBlastAddPortDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastAddPortDlg.h"
#include "ICBlastProjectIO.h"
#include <stdlib.h>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ICBlastProjectIO ProjIO;

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddPortDlg dialog

int CharsToInt(char c[]);
int CharsToInt(char c[]) { int result=0; for ( int i=sizeof(c)-1; i>=0; i-- ){ result = result * 10 + ( c[i] - '0' ); } return result; }

struct pArray {
	char *name;
	int  value;
} ;

class ICBlastPort
{

public:
	ICBlastPort() { incin=incout=0; portin=FALSE; portout=FALSE; } ;
	~ICBlastPort() { } ;

	void AddIn(char *name)		 { portin=TRUE; portInArray[incin].name = name; };
	void AddOut(char *name)		 { portout=TRUE; portOutArray[incout].name = name;};
	int GetPortVal(char *name)   { return intval; };
	void SetPortVal(char *value) { intval = CharsToInt(value); };
	void Del(char *name) { };
	
	int		intval;
	float	floatval;

private:
	int incin;
	int incout;
	pArray portInArray[40];
	pArray portOutArray[10];
	bool portin;
	bool portout;
	bool inout;
};

ICBlastPort Ports;

ICBlastAddPortDlg::ICBlastAddPortDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastAddPortDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastAddPortDlg)
	m_prefixin = _T("");
	m_prefixout = _T("");
	//}}AFX_DATA_INIT
}


void ICBlastAddPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastAddPortDlg)
	DDX_Text(pDX, IDC_PREFIXIN, m_prefixin);
	DDX_Text(pDX, IDC_PREFIXOUT, m_prefixout);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastAddPortDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastAddPortDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastAddPortDlg message handlers

void ICBlastAddPortDlg::OnOK() 
{

	// this code helps create a port section in entity
	if( m_prefixin != _T("") ){
		Ports.AddIn( m_prefixin.GetBuffer(m_prefixin.GetLength()) );
	}
	if( m_prefixout != _T("") ){
		Ports.AddOut( m_prefixout.GetBuffer(m_prefixin.GetLength()) );
	}

	ProjIO.nlistports++;

	CDialog::OnOK();
}
