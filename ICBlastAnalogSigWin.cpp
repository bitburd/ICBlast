// ICBlastAnalogSigWin.cpp : A basic circuit analisys waveform
//  in the form of a dialog and basic graphs. The AC input signals can
//  be simulated and displayed in the waveform dialog box. Different
//  views can be selected from menus, controls and dialogs. The wave
//  can be imported from simulators like 3f5..

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastAnalogSigWin.h"
#include "OpenGLControl.h"
#include "ICBlastWndStates.h"
#include "ICBlastACanalysisDlg.h"
#include "ICBlastProjectIO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

ICBlastWndState SigWinState;

extern ICBlastProjectIO ProjIO;

/////////////////////////////////////////////////////////////////////////////
//  dialog

//global control for sig wave
extern COpenGLControl waveGLControl;
extern ICBlastAnalogSigWin AnalogSigWin;

ICBlastAnalogSigWin::ICBlastAnalogSigWin(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastAnalogSigWin::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastAnalogSigWin)
	m_frequencyslide = 0;
	m_signalslide = 0;
	//}}AFX_DATA_INIT

	zoom = 0.0;
}


void ICBlastAnalogSigWin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastAnalogSigWin)
	DDX_Control(pDX, IDC_WAVEFORM, m_waveform);
	DDX_Slider(pDX, IDC_FREQUENCYSLIDE, m_frequencyslide);
	DDX_Slider(pDX, IDC_SIGNALSLIDE, m_signalslide);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastAnalogSigWin, CDialog)
	//{{AFX_MSG_MAP(ICBlastAnalogSigWin)
	ON_BN_CLICKED(ID_APPLYWAVE, OnApplywave)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_ZOOMIN, OnZoomin)
	ON_BN_CLICKED(IDC_ZOOMOUT, OnZoomout)
	ON_BN_CLICKED(IDC_EDITANALYSIS, OnEditanalysis)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SIGNALSLIDE, OnReleasedcaptureSignalslide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastAnalogSigWin message handlers

void ICBlastAnalogSigWin::OnApplywave() 
{
	// TODO: Add your control notification handler code here
	waveGLControl.DrawWaveGLWindow();
    SwapBuffers(waveGLControl.dc->m_hDC);
}

BOOL ICBlastAnalogSigWin::OnInitDialog() 
{
	SigWinState.AddWin("Wave");
	SigWinState.bActive = FALSE;

	CDialog::OnInitDialog();
	
	CRect rect;

	GetDlgItem(IDC_GL_WAVEFORM)->GetWindowRect(rect);

	ScreenToClient(rect);

	waveGLControl.m_type = 2;  //wave
	waveGLControl.CreateFromStatic("WaveOGL",rect,this);


	hrc = wglCreateContext(waveGLControl.dc->m_hDC);
    
	waveGLControl.DrawWaveGLWindow();

    SwapBuffers(waveGLControl.dc->m_hDC);

	return TRUE;  
}

void ICBlastAnalogSigWin::OnMouseMove(UINT nFlags, CPoint point) 
{
    SigWinState.bActive = TRUE;

    waveGLControl.DrawWaveGLWindow();

    SwapBuffers(waveGLControl.dc->m_hDC);

	CDialog::OnMouseMove(nFlags, point);
}

void ICBlastAnalogSigWin::OnZoomin() 
{
	// TODO: Add your control notification handler code here
	zoom=zoom+0.2;
	waveGLControl.Zoom(zoom);
}

void ICBlastAnalogSigWin::OnZoomout() 
{
	// TODO: Add your control notification handler code here
	zoom=zoom-0.2;
	waveGLControl.Zoom(zoom);
}


ICBlastACanalysisDlg ACanalysisDlg;

void ICBlastAnalogSigWin::OnEditanalysis() 
{
	// TODO: Add your control notification handler code here
	if(ACanalysisDlg.m_hWnd == NULL)
		ACanalysisDlg.DoModal();
	//ACanalysisDlg.ShowWindow(SW_SHOW);
}

void ICBlastAnalogSigWin::OnReleasedcaptureSignalslide(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	char sigstrength[50];
	sprintf(sigstrength, "signal displayed = %f + %f", ProjIO.currsig, (m_signalslide * 0.1));
	waveGLControl.DrawWaveGLWindow();
	SwapBuffers(waveGLControl.dc->m_hDC);
    //MessageBox(sigstrength,"DEBUG",MB_OK);
	*pResult = 0;
}
