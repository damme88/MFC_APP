
// App_TaskPaneView.cpp : implementation of the CApp_TaskPaneView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "App_TaskPane.h"
#endif

#include "App_TaskPaneDoc.h"
#include "App_TaskPaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CApp_TaskPaneView

IMPLEMENT_DYNCREATE(CApp_TaskPaneView, CView)

BEGIN_MESSAGE_MAP(CApp_TaskPaneView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CApp_TaskPaneView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CApp_TaskPaneView construction/destruction

CApp_TaskPaneView::CApp_TaskPaneView()
{
	// TODO: add construction code here

}

CApp_TaskPaneView::~CApp_TaskPaneView()
{
}

BOOL CApp_TaskPaneView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CApp_TaskPaneView drawing

void CApp_TaskPaneView::OnDraw(CDC* /*pDC*/)
{
	CApp_TaskPaneDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CApp_TaskPaneView printing


void CApp_TaskPaneView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CApp_TaskPaneView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CApp_TaskPaneView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CApp_TaskPaneView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CApp_TaskPaneView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CApp_TaskPaneView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CApp_TaskPaneView diagnostics

#ifdef _DEBUG
void CApp_TaskPaneView::AssertValid() const
{
	CView::AssertValid();
}

void CApp_TaskPaneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CApp_TaskPaneDoc* CApp_TaskPaneView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CApp_TaskPaneDoc)));
	return (CApp_TaskPaneDoc*)m_pDocument;
}
#endif //_DEBUG


// CApp_TaskPaneView message handlers
