// SignalView.cpp : implementation of the CSignalView class
//

#include "stdafx.h"
#include "Signal.h"

#include "SignalDoc.h"
#include "SignalView.h"

#include "math.h"
#include "Input.h"
#include "Output.h"
#include "Sourdest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSignalView

IMPLEMENT_DYNCREATE(CSignalView, CView)

BEGIN_MESSAGE_MAP(CSignalView, CView)
	//{{AFX_MSG_MAP(CSignalView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CALCU_GAIN, OnCalcuGain)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignalView construction/destruction

CSignalView::CSignalView()
{
	// TODO: add construction code here

}

CSignalView::~CSignalView()
{
}

BOOL CSignalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	Njd=0;
	int x,y;
	for(x=0;x<256;x++)
	{
		for(y=0;y<256;y++)
		{
			CH[x][y]="0";
			A[x][y]="0";
			B[x][y]="0";
		}
	}

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView drawing

void CSignalView::OnDraw(CDC* pDC)
{
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	DrawLiuTu(pDC);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView printing

BOOL CSignalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSignalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSignalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView diagnostics

#ifdef _DEBUG
void CSignalView::AssertValid() const
{
	CView::AssertValid();
}

void CSignalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSignalDoc* CSignalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSignalDoc)));
	return (CSignalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSignalView message handlers

void CSignalView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	LDown=1;
	Ps.x=40*(point.x/40)+40*(point.x%40>20?1:0);
	Ps.y=40*(point.y/40)+40*(point.y%40>20?1:0);

	CView::OnLButtonDown(nFlags, point);
}

void CSignalView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(LDown==1)
	{
		Pe.x=40*(point.x/40)+40*(point.x%40>20?1:0);
		Pe.y=40*(point.y/40)+40*(point.y%40>20?1:0);
		int c=0,d=0,a,b;
        int i;
		for(i=0;i<Njd;i++)
		{
			if(Ps.x==Jd[i].x&&Ps.y==Jd[i].y)
			{
				c=1;
				a=i;
				break;
			}
		}
		for(i=0;i<Njd;i++)
		{
			if(Pe.x==Jd[i].x&&Pe.y==Jd[i].y)
			{
				d=1;
				b=i;
				break;
			}
		}
		if(c*d==1)
		{
			CInput data;
			data.GAIN=CH[b][a];
			if(data.DoModal()==IDOK)
			{
				CH[b][a]=data.GAIN;
				Invalidate(TRUE);
			}
		}
	}
	
	CView::OnLButtonUp(nFlags, point);
}

void CSignalView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int c=0;
	for(int i=0;i<Njd;i++)
	{
		if(40*(point.x/40)+40*(point.x%40>20?1:0)==Jd[i].x&&40*(point.y/40)+40*(point.y%40>20?1:0)==Jd[i].y)
		{
			c=1;
			break;
		}
	}
	if(c==0)
	{
		Jd[Njd].x=40*(point.x/40)+40*(point.x%40>20?1:0);
		Jd[Njd].y=40*(point.y/40)+40*(point.y%40>20?1:0);
		CH[Njd][Njd]="1";
		Njd++;
		Invalidate(TRUE);
	}
	
	CView::OnRButtonUp(nFlags, point);
}

void CSignalView::OnFileNew() 
{
	// TODO: Add your command handler code here
	Njd=0;
	int x,y;
	for(x=0;x<256;x++)
	{
		for(y=0;y<256;y++)
		{
			CH[x][y]="0";
			A[x][y]="0";
			B[x][y]="0";
		}
	}
	Invalidate(TRUE);
}

void CSignalView::OnCalcuGain() 
{
	// TODO: Add your command handler code here
	CSourdest data;
	COutput Out;
	int x,y,h,i,j;
	CString D;
Input:
	data.SOUR=data.DEST=1;
	if(data.DoModal()==IDOK)
	{
		Out.SOUR=data.SOUR;
		Out.DEST=data.DEST;
		data.SOUR-=1;
		data.DEST-=1;
		x=0;
		if(data.SOUR>Njd-1||data.DEST>Njd-1)
		{
			AfxMessageBox("输入有误!\n请重新输入!");
			goto Input;
		}
		for(i=0;i<Njd;i++)
		{
			if(i==data.DEST) 
			{
				h=x;
			}
			if(i==data.SOUR) continue;			
			else
			{
				y=0;
				for(j=0;j<Njd;j++)
				{
					if(j==data.SOUR) continue;
					else
					{
						if(i!=j)
						{
							if(CH[i][j][0]!='-')
							{
								A[x][y]="-"+CH[i][j];
							}
							else
							{
								D=CH[i][j];
								D.Delete(0,1);
								A[x][y]=D;
							}								
						}
						else
						{
							if(CH[i][j]!="1")
							{
								if(CH[i][j][0]=='-')
								{
									D=CH[i][j];
									D.Delete(0,1);
									A[x][y]="(1+"+D+")";
								}
								else
								{
									A[x][y]="(1-"+CH[i][j]+")";
								}
							}
							else
							{
								A[x][y]=CH[i][j];
							}
						}
						y++;
					}
				}
				x++;
			}
		}

		Fenmu="";		
		FM(p,Njd-1,Njd-1);

		for(i=0;i<Njd-1;i++)
		{
			for(j=0;j<Njd-1;j++)
			{
				B[i][j]=A[i][j];
			}
		}
		int j=0;
		for(i=0;i<Njd;i++)
		{
			if(i==data.SOUR) continue;
			else
			{
				B[j][h]=CH[i][data.SOUR];
				j++;
			}
		}	
		
		Fenzi="";
		FZ(p,Njd-1,Njd-1);

		Out.GAIN="("+Fenzi+")/("+Fenmu+")";
		Out.DoModal();
	}
	
}

void CSignalView::DrawLiuTu(CDC* pDC)
{
    int i;
	pDC->SetTextColor(RGB(0,0,255));
	for(i=0;i<Njd;i++)
	{
		CString A;
		A.Format("%d",i+1);
		pDC->Ellipse(Jd[i].x-5,Jd[i].y-5,Jd[i].x+5,Jd[i].y+5);
		pDC->TextOut(Jd[i].x,Jd[i].y,A);
	}
	for(i=0;i<Njd;i++)
	{
		for(int j=0;j<Njd;j++)
		{
			if(CH[i][j]!="0")
			{
				if(i==j)
				{
					if(CH[i][j]!="1")
					{
						pDC->Ellipse(Jd[i].x-30,Jd[i].y-60,Jd[i].x+30,Jd[i].y);
						pDC->TextOut(Jd[i].x,Jd[i].y-55,CH[i][j]);
					}
				}
				else
				{
					if((Jd[i].x>Jd[j].x&&Jd[i].y<=Jd[j].y)||(Jd[i].x>=Jd[j].x&&Jd[i].y<Jd[j].y))
					{
						if(Jd[i].x-Jd[j].x==40||Jd[j].y-Jd[i].y==40)
						{
							pDC->MoveTo(Jd[j]);
							pDC->LineTo(Jd[i]);
							pDC->TextOut((Jd[i].x+Jd[j].x)/2,(Jd[i].y+Jd[j].y)/2+5,CH[i][j]);						
						}
						else
						{
							double Xc,Yc,a,b,c,d,th,al;
							Xc=((double)(Jd[i].x+Jd[j].x))/2;Yc=((double)(Jd[i].y+Jd[j].y))/2;
							a=sqrt((double)((Jd[i].x-Jd[j].x)*(Jd[i].x-Jd[j].x)+(Jd[i].y-Jd[j].y)*(Jd[i].y-Jd[j].y)))/2;
							b=a/3;
							if(Jd[j].x==Jd[i].x) th=1.57;
							else 
							{
								th=atan((double)(Jd[i].y-Jd[j].y)/(double)(Jd[j].x-Jd[i].x));
							}
							c=cos(th);
							d=sin(th);
							for(al=0;al<=3.14;al+=0.01)
							{
								pDC->SetPixel((int)(Xc+a*cos(al)*c-b*sin(al)*d),(int)(Yc-b*sin(al)*c-a*cos(al)*d),RGB(0,0,0));
								
							}
							pDC->TextOut((int)(Xc-b*d),(int)(Yc-b*c),CH[i][j]);
						}
					}
					else
					{
						double Xc,Yc,a,b,c,d,th,al;
							Xc=((double)(Jd[i].x+Jd[j].x))/2;Yc=((double)(Jd[i].y+Jd[j].y))/2;
							a=sqrt((double)((Jd[i].x-Jd[j].x)*(Jd[i].x-Jd[j].x)+(Jd[i].y-Jd[j].y)*(Jd[i].y-Jd[j].y)))/2;
							b=a/3;
							if(Jd[j].x==Jd[i].x) th=1.57;
							else 
							{
								th=atan((double)(Jd[i].y-Jd[j].y)/(double)(Jd[j].x-Jd[i].x));
							}
							if(Jd[i].x<=Jd[j].x) th+=3.14;
							c=cos(th);
							d=sin(th);
							for(al=0;al<=3.14;al+=0.01)
							{
								pDC->SetPixel((int)(Xc+a*cos(al)*c-b*sin(al)*d),(int)(Yc-b*sin(al)*c-a*cos(al)*d),RGB(0,0,0));
							}
							pDC->TextOut((int)(Xc-b*d),(int)(Yc-b*c),CH[i][j]);
					}
					

				}
			}
		}
	}
	for(i=1;i<=30;i++)
	{
		for(int j=1;j<=30;j++)
		{
			pDC->SetPixel(i*40,j*40,RGB(0,0,255));
		}
	}
}

void CSignalView::FM(int *p,int m,int n)
{
	int i,j,c;
	int a,b,d,r,s,t;
	CString D,E;
	for(i=0;i<m;i++)
	{
		c=0;
		for(j=0;j<m-n;j++)
		{
			if(i==p[j])
			{
				c=1;
				break;
			}
		}
		if(c==0)
		{
			p[m-n]=i;
			if(n!=1&&A[m-n][p[m-n]]!="0"&&A[m-n][p[m-n]]!="-0") 
			{
				FM(p,m,n-1);
			}
			
			if(n==1&&A[m-1][p[m-1]]!="0"&&A[m-1][p[m-1]]!="-0")
			{
				s=1;
				d=0;
				E="";
				for(t=0;t<Njd-1;t++)
				{
					b=0;
					a=p[t];
					for(r=t;r<Njd-1;r++)
					{
						if(a>p[r])
						{
							b++;
						}
					}
					d+=b;
				}
				if(d%2==0)
				{
					d=1;
				}
				else
				{
					d=-1;
				}
				for(t=0;t<m;t++)
				{						
					if(A[t][p[t]][0]=='-')
					{
						s*=-1;
						D=A[t][p[t]];
						D.Delete(0,1);
						if(D!="1")
							E+=D;
					}
					else
					{
						if(A[t][p[t]]!="1")
							E+=A[t][p[t]];
					}						
				}
				if(d*s==1)
				{
					if(E!="")
					{
						Fenmu+="+"+E;
					}
					else
					{
						Fenmu+="+1";
					}
				}
				else
				{
					if(E!="")
					{
						Fenmu+="-"+E;
					}
					else
					{
						Fenmu+="-1";
					}
				}
				if(Fenmu[0]=='+')
				{
					Fenmu.Delete(0,1);
				}
			}
		}
	}
}

void CSignalView::FZ(int *p,int m,int n)
{
	int i,j,c;
	int a,b,d,r,s,t;
	CString D,E;
	for(i=0;i<m;i++)
	{
		c=0;
		for(j=0;j<m-n;j++)
		{
			if(i==p[j])
			{
				c=1;
				break;
			}
		}
		if(c==0)
		{
			p[m-n]=i;
			if(n!=1&&B[m-n][p[m-n]]!="0"&&B[m-n][p[m-n]]!="-0") 
			{
				FZ(p,m,n-1);
			}
			
			if(n==1&&B[m-1][p[m-1]]!="0"&&B[m-1][p[m-1]]!="-0")
			{
				s=1;
				d=0;
				E="";
				for(t=0;t<Njd-1;t++)
				{
					b=0;
					a=p[t];
					for(r=t;r<Njd-1;r++)
					{
						if(a>p[r])
						{
							b++;
						}
					}
					d+=b;
				}
				if(d%2==0)
				{
					d=1;
				}
				else
				{
					d=-1;
				}
				for(t=0;t<m;t++)
				{						
					if(B[t][p[t]][0]=='-')
					{
						s*=-1;
						D=B[t][p[t]];
						D.Delete(0,1);
						if(D!="1")
							E+=D;
					}
					else
					{
						if(B[t][p[t]]!="1")
							E+=B[t][p[t]];
					}						
				}
				if(d*s==1)
				{
					if(E!="")
					{
						Fenzi+="+"+E;
					}
					else
					{
						Fenzi+="+1";
					}
				}
				else
				{
					if(E!="")
					{
						Fenzi+="-"+E;
					}
					else
					{
						Fenzi+="-1";
					}
				}
				if(Fenzi[0]=='+')
				{
					Fenzi.Delete(0,1);
				}
			}
		}
	}
}





