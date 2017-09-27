// ICBlastProjFileListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ICBlastVC6.h"
#include "ICBlastProjFileListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjFileListCtrl

ICBlastProjFileListCtrl::ICBlastProjFileListCtrl()
{
}

ICBlastProjFileListCtrl::~ICBlastProjFileListCtrl()
{
}


BEGIN_MESSAGE_MAP(ICBlastProjFileListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(ICBlastProjFileListCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ICBlastProjFileListCtrl message handlers

void ICBlastProjFileListCtrl::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	nItem = GetSelectedItem();
	char msg[20];
	sprintf(msg,"Selected list item index: %d", nItem);
	MessageBox(msg,"Item DEBUG",MB_OK);
	*pResult = 0;
}

int ICBlastProjFileListCtrl::GetSelectedItem()
{
    nItem = -1;
    POSITION nPos = GetFirstSelectedItemPosition();
    if (nPos)
    {
        nItem = GetNextSelectedItem(nPos);
    }
    return nItem;
}