#if !defined(AFX_SOURDEST_H__9983F122_1781_11D7_B8EF_20784BC10000__INCLUDED_)
#define AFX_SOURDEST_H__9983F122_1781_11D7_B8EF_20784BC10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sourdest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSourdest dialog

class CSourdest : public CDialog
{
// Construction
public:
	CSourdest(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSourdest)
	enum { IDD = IDD_SOURDEST };
	int SOUR;
	int DEST;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSourdest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSourdest)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOURDEST_H__9983F122_1781_11D7_B8EF_20784BC10000__INCLUDED_)
