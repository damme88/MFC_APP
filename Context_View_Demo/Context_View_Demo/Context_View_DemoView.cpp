
// Context_View_DemoView.cpp : implementation of the Context_View_DemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Context_View_Demo.h"
#endif

#include "Context_View_DemoDoc.h"
#include "Context_View_DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Context_View_DemoView

IMPLEMENT_DYNCREATE(Context_View_DemoView, CView)

BEGIN_MESSAGE_MAP(Context_View_DemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Context_View_DemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Context_View_DemoView construction/destruction

Context_View_DemoView::Context_View_DemoView()
{
	// TODO: add construction code here

}

Context_View_DemoView::~Context_View_DemoView()
{
}

BOOL Context_View_DemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Context_View_DemoView drawing

void Context_View_DemoView::OnDraw(CDC* /*pDC*/)
{
	Context_View_DemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Context_View_DemoView printing


void Context_View_DemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Context_View_DemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Context_View_DemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Context_View_DemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Context_View_DemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Context_View_DemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Context_View_DemoView diagnostics

#ifdef _DEBUG
void Context_View_DemoView::AssertValid() const
{
	CView::AssertValid();
}

void Context_View_DemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Context_View_DemoDoc* Context_View_DemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Context_View_DemoDoc)));
	return (Context_View_DemoDoc*)m_pDocument;
}
#endif //_DEBUG


// Context_View_DemoView message handlers
