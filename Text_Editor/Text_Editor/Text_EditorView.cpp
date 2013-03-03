
// Text_EditorView.cpp : implementation of the CText_EditorView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Text_Editor.h"
#endif

#include "Text_EditorDoc.h"
#include "Text_EditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CText_EditorView

IMPLEMENT_DYNCREATE(CText_EditorView, CView)

BEGIN_MESSAGE_MAP(CText_EditorView, CView)
	// Standard printing commands
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CText_EditorView construction/destruction

CText_EditorView::CText_EditorView()
{
	// TODO: add construction code here

}

CText_EditorView::~CText_EditorView()
{
}

BOOL CText_EditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CText_EditorView drawing

void CText_EditorView::OnDraw(CDC* /*pDC*/)
{
	CText_EditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CText_EditorView printing


void CText_EditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CText_EditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CText_EditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CText_EditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CText_EditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CText_EditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CText_EditorView diagnostics

#ifdef _DEBUG
void CText_EditorView::AssertValid() const
{
	CView::AssertValid();
}

void CText_EditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CText_EditorDoc* CText_EditorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CText_EditorDoc)));
	return (CText_EditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CText_EditorView message handlers
