
// Preview_PaneView.cpp : implementation of the CPreview_PaneView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Preview_Pane.h"
#endif

#include "Preview_PaneDoc.h"
#include "Preview_PaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPreview_PaneView

IMPLEMENT_DYNCREATE(CPreview_PaneView, CView)

BEGIN_MESSAGE_MAP(CPreview_PaneView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPreview_PaneView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPreview_PaneView construction/destruction

CPreview_PaneView::CPreview_PaneView()
{
	// TODO: add construction code here

}

CPreview_PaneView::~CPreview_PaneView()
{
}

BOOL CPreview_PaneView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPreview_PaneView drawing

void CPreview_PaneView::OnDraw(CDC* /*pDC*/)
{
	CPreview_PaneDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPreview_PaneView printing


void CPreview_PaneView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPreview_PaneView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPreview_PaneView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPreview_PaneView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPreview_PaneView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPreview_PaneView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPreview_PaneView diagnostics

#ifdef _DEBUG
void CPreview_PaneView::AssertValid() const
{
	CView::AssertValid();
}

void CPreview_PaneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPreview_PaneDoc* CPreview_PaneView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPreview_PaneDoc)));
	return (CPreview_PaneDoc*)m_pDocument;
}
#endif //_DEBUG


// CPreview_PaneView message handlers
