#if !defined(AFX_INPUT_H__9983F120_1781_11D7_B8EF_20784BC10000__INCLUDED_)
#define AFX_INPUT_H__9983F120_1781_11D7_B8EF_20784BC10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Input.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInput dialog

class CInput : public CDialog
{
// Construction
public:
	CInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInput)
	enum { IDD = IDD_INPUT };
	CString GAIN;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInput)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUT_H__9983F120_1781_11D7_B8EF_20784BC10000__INCLUDED_)
