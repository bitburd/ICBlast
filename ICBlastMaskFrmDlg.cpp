// ICBlastMaskFrmDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastMaskFrmDlg.h"
#include "commctrl.h"
#include "ICBlastProjectIO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BOOL InitTreeViewImageLists(HWND hwndTV);
int GetNextHeadingAndLevelFromFile(HANDLE hf, char *szItemText, int nLevel);
void CreateTreeFromResource(UINT treeid);

extern ICBlastProjectIO ProjIO;

/////////////////////////////////////////////////////////////////////////////
// ICBlastMaskFrmDlg dialog


ICBlastMaskFrmDlg::ICBlastMaskFrmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ICBlastMaskFrmDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ICBlastMaskFrmDlg)
	m_ongrid = FALSE;
	m_maskwidth = 2.0;
	m_masklength = 2.0;
	//}}AFX_DATA_INIT
}


void ICBlastMaskFrmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ICBlastMaskFrmDlg)
	DDX_Check(pDX, IDC_ONGRID, m_ongrid);
	DDX_Text(pDX, IDC_MASKWIDTH, m_maskwidth);
	DDV_MinMaxLong(pDX, m_maskwidth, 1, 999999);
	DDX_Text(pDX, IDC_MASKLENGTH, m_masklength);
	DDV_MinMaxLong(pDX, m_masklength, 1, 999999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ICBlastMaskFrmDlg, CDialog)
	//{{AFX_MSG_MAP(ICBlastMaskFrmDlg)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_ONGRID, OnOngrid)
	ON_BN_CLICKED(IDC_APPLYMASK, OnApplymask)
	ON_BN_CLICKED(IDC_CLOSEMPROP, OnClosemprop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastMaskFrmDlg message handlers

BOOL ICBlastMaskFrmDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

    //get the tree control on the dialog	
	//CreateTreeFromResource(IDC_LAYOUTTREE);

	//if( InitTreeViewImageLists(m_hWnd) == FALSE) {
	//	MessageBox("The treectrl failed to load it's image bmp!","Error",MB_OK);
	//    return FALSE;
	//}
	//else {
//
	   return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
//	}
}

// The first time the dialog is created, fill a tree template:
void ICBlastMaskFrmDlg::CreateTreeFromResource(UINT treeid) {
	// Gain a pointer to our tree control
	
	CTreeCtrl* pCtrl = (CTreeCtrl*) GetDlgItem(treeid);
	ASSERT(pCtrl != NULL);
	
	// Insert a root item using the structure. We must
	// initialize a TVINSERTSTRUCT structure and pass its
	// address to the call. 
	
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.mask = TVIF_TEXT;
	tvInsert.item.pszText = _T("[TopLevel layout Atom]");
	
	HTREEITEM hCountry = pCtrl->InsertItem(&tvInsert);
	
	// Insert subitems of that root. Pennsylvania is
	// a state in the United States, so its item will be a child
	// of the United States item. We won't set any image or states,
	// so we supply only the TVIF_TEXT mask flag. This
	// override provides nearly complete control over the
	// insertion operation without the tedium of initializing
	// a structure. If you're going to add lots of items
	// to a tree, you might prefer the structure override
	// as it affords you a performance win by allowing you
	// to initialize some fields of the structure only once,
	// outside of your insertion loop.
	
	HTREEITEM hPA = pCtrl->InsertItem(TVIF_TEXT,
		_T("Grid_1"), 0, 0, 0, 0, 0, hCountry, NULL);
	
	// Insert the "Washington" item and assure that it is
	// inserted after the "Pennsylvania" item. This override is 
	// more appropriate for conveniently inserting items with 
	// images.
	
	HTREEITEM hWA = pCtrl->InsertItem(_T("DU_1"),
		0, 0, hCountry, hPA);
	
	// We'll add some cities under each of the states.
	// The override used here is most appropriate
	// for inserting text-only items.
	
	pCtrl->InsertItem(_T("X:_, Y:_"), hPA, TVI_SORT);
	
	pCtrl->InsertItem(_T("X0.05, Y0.05"), hWA, TVI_SORT);
	
}

/****BOOL InitTreeViewImageLists(HWND hwndTV) 
{ 
	int g_nOpen, g_nClosed, g_nDocument;
    HINSTANCE g_hinst;
    HIMAGELIST	himl;  // handle to image list 
    HBITMAP		hbmp;     // handle to bitmap 
    unsigned int CX_BITMAP = 14;
	unsigned int CY_BITMAP = 12;
	int NUM_BITMAPS = 3;
	
    // Create the image list. 
    if ((himl = ImageList_Create(CX_BITMAP, 
		CY_BITMAP,
		FALSE, 
		NUM_BITMAPS, 0)) == NULL) 
        return FALSE; 
	
    // Add the open file, closed file, and document bitmaps. 
    hbmp = LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_OPENNODE)); 
    g_nOpen = ImageList_Add(himl, hbmp, (HBITMAP)NULL); 
    DeleteObject(hbmp); 
	
    hbmp = LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_CLOSENODE)); 
    g_nClosed = ImageList_Add(himl, hbmp, (HBITMAP)NULL); 
    DeleteObject(hbmp); 
	
    hbmp = LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_NODE)); 
    g_nDocument = ImageList_Add(himl, hbmp, (HBITMAP)NULL); 
    DeleteObject(hbmp); 
	
    // Fail if not all of the images were added. 
    if (ImageList_GetImageCount(himl) < 3) 
        return FALSE; 
	
    // Associate the image list with the tree-view control. 
    TreeView_SetImageList(hwndTV, himl, TVSIL_NORMAL); 
	
    return TRUE; 
} 

int nitem = 0;

int GetNextHeadingAndLevelFromFile(HANDLE hf, char *szItemText, int *nLevel){
	int level = 1;
	
	nLevel = &level;
	
	char *itemlist[3] = {"TreeControl Item 1  ",
		"TreeControl Item 2  ",
		"TreeControl Item 3  "};
	
	szItemText = itemlist[nitem];
	nitem++;
	
	if(nitem == 2)
		return FALSE;
	else
		return TRUE;
}

****/



int ICBlastMaskFrmDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetDlgItemText(IDC_MASKWIDTH, ProjIO.maskwidth);
	SetDlgItemText(IDC_MASKHEIGHT, ProjIO.maskheight);

	return 0;
}

void ICBlastMaskFrmDlg::OnOngrid() 
{
    ProjIO.bNeedSave = TRUE;

	//check for check marked..
	if(m_ongrid == TRUE) {
		m_ongrid == FALSE;
		ProjIO.ongrid = FALSE;
	}
	if(m_ongrid == FALSE) {
		m_ongrid == TRUE;
		ProjIO.ongrid = TRUE;
	}

	Invalidate();

}

void ICBlastMaskFrmDlg::OnApplymask() 
{
	ProjIO.bNeedSave = TRUE;
	// TODO: Add your control notification handler code here
	UpdateData();
}

void ICBlastMaskFrmDlg::OnClosemprop() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}
