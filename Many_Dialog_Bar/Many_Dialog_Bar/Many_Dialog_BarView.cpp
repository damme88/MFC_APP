
// Many_Dialog_BarView.cpp : implementation of the CMany_Dialog_BarView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Many_Dialog_Bar.h"
#endif

#include "Many_Dialog_BarDoc.h"
#include "Many_Dialog_BarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMany_Dialog_BarView

IMPLEMENT_DYNCREATE(CMany_Dialog_BarView, CView)

BEGIN_MESSAGE_MAP(CMany_Dialog_BarView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMany_Dialog_BarView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMany_Dialog_BarView construction/destruction

CMany_Dialog_BarView::CMany_Dialog_BarView()
{
	// TODO: add construction code here

}

CMany_Dialog_BarView::~CMany_Dialog_BarView()
{
}

BOOL CMany_Dialog_BarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMany_Dialog_BarView drawing

void CMany_Dialog_BarView::OnDraw(CDC* /*pDC*/)
{
	CMany_Dialog_BarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMany_Dialog_BarView printing


void CMany_Dialog_BarView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMany_Dialog_BarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMany_Dialog_BarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMany_Dialog_BarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMany_Dialog_BarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMany_Dialog_BarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMany_Dialog_BarView diagnostics

#ifdef _DEBUG
void CMany_Dialog_BarView::AssertValid() const
{
	CView::AssertValid();
}

void CMany_Dialog_BarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMany_Dialog_BarDoc* CMany_Dialog_BarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMany_Dialog_BarDoc)));
	return (CMany_Dialog_BarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMany_Dialog_BarView message handlers
