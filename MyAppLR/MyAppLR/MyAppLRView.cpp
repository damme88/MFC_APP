
// MyAppLRView.cpp : implementation of the MyAppLRView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MyAppLR.h"
#endif

#include "MyAppLRDoc.h"
#include "MyAppLRView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MyAppLRView

IMPLEMENT_DYNCREATE(MyAppLRView, CView)

BEGIN_MESSAGE_MAP(MyAppLRView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &MyAppLRView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// MyAppLRView construction/destruction

MyAppLRView::MyAppLRView()
{
	// TODO: add construction code here

}

MyAppLRView::~MyAppLRView()
{
}

BOOL MyAppLRView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// MyAppLRView drawing

void MyAppLRView::OnDraw(CDC* /*pDC*/)
{
	MyAppLRDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// MyAppLRView printing


void MyAppLRView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL MyAppLRView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void MyAppLRView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void MyAppLRView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void MyAppLRView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void MyAppLRView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// MyAppLRView diagnostics

#ifdef _DEBUG
void MyAppLRView::AssertValid() const
{
	CView::AssertValid();
}

void MyAppLRView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

MyAppLRDoc* MyAppLRView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MyAppLRDoc)));
	return (MyAppLRDoc*)m_pDocument;
}
#endif //_DEBUG


// MyAppLRView message handlers
