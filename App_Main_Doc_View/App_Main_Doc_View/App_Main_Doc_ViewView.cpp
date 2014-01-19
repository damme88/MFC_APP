
// App_Main_Doc_ViewView.cpp : implementation of the CApp_Main_Doc_ViewView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "App_Main_Doc_View.h"
#endif

#include "App_Main_Doc_ViewDoc.h"
#include "App_Main_Doc_ViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CApp_Main_Doc_ViewView

IMPLEMENT_DYNCREATE(CApp_Main_Doc_ViewView, CView)

BEGIN_MESSAGE_MAP(CApp_Main_Doc_ViewView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CApp_Main_Doc_ViewView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CApp_Main_Doc_ViewView construction/destruction

CApp_Main_Doc_ViewView::CApp_Main_Doc_ViewView()
{
	// TODO: add construction code here

}

CApp_Main_Doc_ViewView::~CApp_Main_Doc_ViewView()
{
}

BOOL CApp_Main_Doc_ViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CApp_Main_Doc_ViewView drawing

void CApp_Main_Doc_ViewView::OnDraw(CDC* /*pDC*/)
{
	CApp_Main_Doc_ViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CApp_Main_Doc_ViewView printing


void CApp_Main_Doc_ViewView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CApp_Main_Doc_ViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CApp_Main_Doc_ViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CApp_Main_Doc_ViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CApp_Main_Doc_ViewView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CApp_Main_Doc_ViewView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CApp_Main_Doc_ViewView diagnostics

#ifdef _DEBUG
void CApp_Main_Doc_ViewView::AssertValid() const
{
	CView::AssertValid();
}

void CApp_Main_Doc_ViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CApp_Main_Doc_ViewDoc* CApp_Main_Doc_ViewView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CApp_Main_Doc_ViewDoc)));
	return (CApp_Main_Doc_ViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CApp_Main_Doc_ViewView message handlers

// Function is used to get View 
CApp_Main_Doc_ViewView* CApp_Main_Doc_ViewView::GetView() {
  //CFrameWnd *pChild = (CFrameWnd*)(AfxGetApp()->m_pMainWnd); // use for SDI MFC

  CMDIChildWnd * pChild = ((CMDIFrameWnd*)(AfxGetApp()->m_pMainWnd))->MDIGetActive(); // use MFD MFC
  if (pChild == NULL)
    return NULL;
  CView* pview = pChild->GetActiveView();
  if (!pview)
    return NULL;
  if (!pview->IsKindOf(RUNTIME_CLASS(CApp_Main_Doc_ViewView)))
    return NULL;
  return (CApp_Main_Doc_ViewView*)pview;
}