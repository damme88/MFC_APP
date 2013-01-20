
// Dialog_Bar_FormView.cpp : implementation of the CDialog_Bar_FormView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Dialog_Bar_Form.h"
#endif

#include "Dialog_Bar_FormDoc.h"
#include "Dialog_Bar_FormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialog_Bar_FormView

IMPLEMENT_DYNCREATE(CDialog_Bar_FormView, CView)

BEGIN_MESSAGE_MAP(CDialog_Bar_FormView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDialog_Bar_FormView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDialog_Bar_FormView construction/destruction

CDialog_Bar_FormView::CDialog_Bar_FormView()
{
	// TODO: add construction code here

}

CDialog_Bar_FormView::~CDialog_Bar_FormView()
{
}

BOOL CDialog_Bar_FormView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDialog_Bar_FormView drawing

void CDialog_Bar_FormView::OnDraw(CDC* /*pDC*/)
{
	CDialog_Bar_FormDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDialog_Bar_FormView printing


void CDialog_Bar_FormView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDialog_Bar_FormView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDialog_Bar_FormView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDialog_Bar_FormView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDialog_Bar_FormView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDialog_Bar_FormView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDialog_Bar_FormView diagnostics

#ifdef _DEBUG
void CDialog_Bar_FormView::AssertValid() const
{
	CView::AssertValid();
}

void CDialog_Bar_FormView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialog_Bar_FormDoc* CDialog_Bar_FormView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialog_Bar_FormDoc)));
	return (CDialog_Bar_FormDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialog_Bar_FormView message handlers
