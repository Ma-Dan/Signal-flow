// Sourdest.cpp : implementation file
//

#include "stdafx.h"
#include "Signal.h"
#include "Sourdest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSourdest dialog


CSourdest::CSourdest(CWnd* pParent /*=NULL*/)
	: CDialog(CSourdest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSourdest)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSourdest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSourdest)
	DDX_Text(pDX,IDC_SOUR,SOUR);
	DDX_Text(pDX,IDC_DEST,DEST);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSourdest, CDialog)
	//{{AFX_MSG_MAP(CSourdest)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSourdest message handlers
