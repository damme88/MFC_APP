
// WorkSpaceDemoView.cpp : implementation of the WorkSpaceDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WorkSpaceDemo.h"
#endif

#include "WorkSpaceDemoDoc.h"
#include "WorkSpaceDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// WorkSpaceDemoView

IMPLEMENT_DYNCREATE(WorkSpaceDemoView, CView)

BEGIN_MESSAGE_MAP(WorkSpaceDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &WorkSpaceDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// WorkSpaceDemoView construction/destruction

WorkSpaceDemoView::WorkSpaceDemoView()
{
	// TODO: add construction code here

}

WorkSpaceDemoView::~WorkSpaceDemoView()
{
}

BOOL WorkSpaceDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// WorkSpaceDemoView drawing

void WorkSpaceDemoView::OnDraw(CDC* /*pDC*/)
{
	WorkSpaceDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// WorkSpaceDemoView printing


void WorkSpaceDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL WorkSpaceDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void WorkSpaceDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void WorkSpaceDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void WorkSpaceDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void WorkSpaceDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// WorkSpaceDemoView diagnostics

#ifdef _DEBUG
void WorkSpaceDemoView::AssertValid() const
{
	CView::AssertValid();
}

void WorkSpaceDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

WorkSpaceDemoDoc* WorkSpaceDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(WorkSpaceDemoDoc)));
	return (WorkSpaceDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// WorkSpaceDemoView message handlers
