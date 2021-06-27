// SignalView.h : interface of the CSignalView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGNALVIEW_H__484C09CC_1734_11D7_B8EF_00744BC10310__INCLUDED_)
#define AFX_SIGNALVIEW_H__484C09CC_1734_11D7_B8EF_00744BC10310__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSignalView : public CView
{
protected: // create from serialization only
	CSignalView();
	DECLARE_DYNCREATE(CSignalView)

// Attributes
public:
	CSignalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSignalView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
	int Njd;
	int p[256];
	int LDown;
	CString CH[256][256],A[256][256],B[256][256],Fenmu,Fenzi;
	CPoint Jd[256],Ps,Pe;
	void DrawLiuTu(CDC* pDC);
	void FM(int *p,int m,int n);
	void FZ(int *p,int m,int n);

// Implementation
public:
	virtual ~CSignalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSignalView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCalcuGain();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SignalView.cpp
inline CSignalDoc* CSignalView::GetDocument()
   { return (CSignalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGNALVIEW_H__484C09CC_1734_11D7_B8EF_00744BC10310__INCLUDED_)
