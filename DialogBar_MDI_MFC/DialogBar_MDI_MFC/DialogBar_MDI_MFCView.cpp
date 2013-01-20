
// DialogBar_MDI_MFCView.cpp : implementation of the CDialogBar_MDI_MFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DialogBar_MDI_MFC.h"
#endif

#include "DialogBar_MDI_MFCDoc.h"
#include "DialogBar_MDI_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogBar_MDI_MFCView

IMPLEMENT_DYNCREATE(CDialogBar_MDI_MFCView, CView)

BEGIN_MESSAGE_MAP(CDialogBar_MDI_MFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDialogBar_MDI_MFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDialogBar_MDI_MFCView construction/destruction

CDialogBar_MDI_MFCView::CDialogBar_MDI_MFCView()
{
	// TODO: add construction code here

}

CDialogBar_MDI_MFCView::~CDialogBar_MDI_MFCView()
{
}

BOOL CDialogBar_MDI_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDialogBar_MDI_MFCView drawing

void CDialogBar_MDI_MFCView::OnDraw(CDC* /*pDC*/)
{
	CDialogBar_MDI_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDialogBar_MDI_MFCView printing


void CDialogBar_MDI_MFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDialogBar_MDI_MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDialogBar_MDI_MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDialogBar_MDI_MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDialogBar_MDI_MFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDialogBar_MDI_MFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDialogBar_MDI_MFCView diagnostics

#ifdef _DEBUG
void CDialogBar_MDI_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogBar_MDI_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogBar_MDI_MFCDoc* CDialogBar_MDI_MFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogBar_MDI_MFCDoc)));
	return (CDialogBar_MDI_MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogBar_MDI_MFCView message handlers
