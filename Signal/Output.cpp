// Output.cpp : implementation file
//

#include "stdafx.h"
#include "Signal.h"
#include "Output.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutput dialog


COutput::COutput(CWnd* pParent /*=NULL*/)
	: CDialog(COutput::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COutput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutput)
	DDX_Text(pDX,IDC_SOUR,SOUR);
	DDX_Text(pDX,IDC_DEST,DEST);
	DDX_Text(pDX,IDC_GAIN,GAIN);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutput, CDialog)
	//{{AFX_MSG_MAP(COutput)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutput message handlers
