
// ComboBox_ToolbarView.cpp : implementation of the CComboBox_ToolbarView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ComboBox_Toolbar.h"
#endif

#include "ComboBox_ToolbarDoc.h"
#include "ComboBox_ToolbarView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComboBox_ToolbarView

IMPLEMENT_DYNCREATE(CComboBox_ToolbarView, CView)

BEGIN_MESSAGE_MAP(CComboBox_ToolbarView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CComboBox_ToolbarView::OnFilePrintPreview)
  ON_CBN_SELENDOK(ID_MOVE_DOWN, OnHandleComboView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CComboBox_ToolbarView construction/destruction

CComboBox_ToolbarView::CComboBox_ToolbarView()
{
	// TODO: add construction code here

}

CComboBox_ToolbarView::~CComboBox_ToolbarView()
{
}

BOOL CComboBox_ToolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CComboBox_ToolbarView drawing

void CComboBox_ToolbarView::OnDraw(CDC* /*pDC*/)
{
	CComboBox_ToolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CComboBox_ToolbarView printing


void CComboBox_ToolbarView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CComboBox_ToolbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CComboBox_ToolbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CComboBox_ToolbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CComboBox_ToolbarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CComboBox_ToolbarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CComboBox_ToolbarView diagnostics

#ifdef _DEBUG
void CComboBox_ToolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CComboBox_ToolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComboBox_ToolbarDoc* CComboBox_ToolbarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComboBox_ToolbarDoc)));
	return (CComboBox_ToolbarDoc*)m_pDocument;
}
#endif //_DEBUG


// CComboBox_ToolbarView message handlers

void CComboBox_ToolbarView::OnHandleComboView() {
  CMainFrame *main_frame = reinterpret_cast<CMainFrame *>(AfxGetMainWnd());
  int item_view;
  item_view = main_frame->GetCombo();
   if (item_view == 0) {
     MessageBox(L"select view top");
  }
  if (item_view == 1) {
    MessageBox(L"select view bottom");
  }
  if (item_view == 2) {
    MessageBox(L"select view left");
  }
  if (item_view == 3) {
   MessageBox(L"select view right");
  }
}