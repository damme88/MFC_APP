
// Toolbar_XmlView.cpp : implementation of the CToolbar_XmlView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Toolbar_Xml.h"
#endif

#include "Toolbar_XmlDoc.h"
#include "Toolbar_XmlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CToolbar_XmlView

IMPLEMENT_DYNCREATE(CToolbar_XmlView, CView)

BEGIN_MESSAGE_MAP(CToolbar_XmlView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CToolbar_XmlView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CToolbar_XmlView construction/destruction

CToolbar_XmlView::CToolbar_XmlView()
{
	// TODO: add construction code here

}

CToolbar_XmlView::~CToolbar_XmlView()
{
}

BOOL CToolbar_XmlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CToolbar_XmlView drawing

void CToolbar_XmlView::OnDraw(CDC* /*pDC*/)
{
	CToolbar_XmlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CToolbar_XmlView printing


void CToolbar_XmlView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CToolbar_XmlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CToolbar_XmlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CToolbar_XmlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CToolbar_XmlView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CToolbar_XmlView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CToolbar_XmlView diagnostics

#ifdef _DEBUG
void CToolbar_XmlView::AssertValid() const
{
	CView::AssertValid();
}

void CToolbar_XmlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolbar_XmlDoc* CToolbar_XmlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolbar_XmlDoc)));
	return (CToolbar_XmlDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolbar_XmlView message handlers
