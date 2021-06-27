#if !defined(AFX_OUTPUT_H__9983F121_1781_11D7_B8EF_20784BC10000__INCLUDED_)
#define AFX_OUTPUT_H__9983F121_1781_11D7_B8EF_20784BC10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Output.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutput dialog

class COutput : public CDialog
{
// Construction
public:
	COutput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutput)
	enum { IDD = IDD_OUTPUT };
	int SOUR;
	int DEST;
	CString GAIN;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutput)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUT_H__9983F121_1781_11D7_B8EF_20784BC10000__INCLUDED_)
