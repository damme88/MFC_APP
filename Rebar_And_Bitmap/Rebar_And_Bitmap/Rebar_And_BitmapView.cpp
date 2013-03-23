
// Rebar_And_BitmapView.cpp : implementation of the Rebar_And_BitmapView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Rebar_And_Bitmap.h"
#endif

#include "Rebar_And_BitmapDoc.h"
#include "Rebar_And_BitmapView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Rebar_And_BitmapView

IMPLEMENT_DYNCREATE(Rebar_And_BitmapView, CView)

BEGIN_MESSAGE_MAP(Rebar_And_BitmapView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Rebar_And_BitmapView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

  ON_COMMAND(ID_VIEW_LARGEICON, OnViewLargeicon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LARGEICON, OnUpdateViewLargeicon)
	ON_COMMAND(ID_VIEW_DETAILS, OnViewDetails)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DETAILS, OnUpdateViewDetails)
	ON_COMMAND(ID_VIEW_LIST, OnViewList)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LIST, OnUpdateViewList)
	ON_COMMAND(ID_VIEW_SMALLICON, OnViewSmallicon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SMALLICON, OnUpdateViewSmallicon)
END_MESSAGE_MAP()

// Rebar_And_BitmapView construction/destruction

Rebar_And_BitmapView::Rebar_And_BitmapView()
{
	// TODO: add construction code here

}

Rebar_And_BitmapView::~Rebar_And_BitmapView()
{
}

BOOL Rebar_And_BitmapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Rebar_And_BitmapView drawing

void Rebar_And_BitmapView::OnDraw(CDC* /*pDC*/)
{
	Rebar_And_BitmapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Rebar_And_BitmapView printing


void Rebar_And_BitmapView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Rebar_And_BitmapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Rebar_And_BitmapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Rebar_And_BitmapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Rebar_And_BitmapView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Rebar_And_BitmapView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Rebar_And_BitmapView diagnostics

#ifdef _DEBUG
void Rebar_And_BitmapView::AssertValid() const
{
	CView::AssertValid();
}

void Rebar_And_BitmapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Rebar_And_BitmapDoc* Rebar_And_BitmapView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Rebar_And_BitmapDoc)));
	return (Rebar_And_BitmapDoc*)m_pDocument;
}
#endif //_DEBUG


// Rebar_And_BitmapView message handlers

void Rebar_And_BitmapView::OnViewLargeicon() 
{
	//m_wndList.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}

void Rebar_And_BitmapView::OnUpdateViewLargeicon(CCmdUI* pCmdUI) 
{
	//pCmdUI->SetRadio ((m_wndList.GetStyle () & LVS_TYPEMASK) == LVS_ICON);
}

void Rebar_And_BitmapView::OnViewDetails() 
{
	//m_wndList.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}

void Rebar_And_BitmapView::OnUpdateViewDetails(CCmdUI* pCmdUI) 
{
	//pCmdUI->SetRadio ((m_wndList.GetStyle () & LVS_TYPEMASK) == LVS_REPORT);
}

void Rebar_And_BitmapView::OnViewList() 
{
	//m_wndList.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}

void Rebar_And_BitmapView::OnUpdateViewList(CCmdUI* pCmdUI) 
{
	//pCmdUI->SetRadio ((m_wndList.GetStyle () & LVS_TYPEMASK) == LVS_LIST);
}

void Rebar_And_BitmapView::OnViewSmallicon() 
{
	//m_wndList.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}

void Rebar_And_BitmapView::OnUpdateViewSmallicon(CCmdUI* pCmdUI) 
{
	//pCmdUI->SetRadio ((m_wndList.GetStyle () & LVS_TYPEMASK) == LVS_SMALLICON);
}