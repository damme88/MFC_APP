
// OpenFolderDialogView.cpp : implementation of the OpenFolderDialogView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OpenFolderDialog.h"
#endif

#include "OpenFolderDialogDoc.h"
#include "OpenFolderDialogView.h"
#include "FolderDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// OpenFolderDialogView

IMPLEMENT_DYNCREATE(OpenFolderDialogView, CView)

BEGIN_MESSAGE_MAP(OpenFolderDialogView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &OpenFolderDialogView::OnFilePrintPreview)
  ON_COMMAND(ID_OPEN_FOLDER_DLG, &OpenFolderDialogView::OnHandleOpenFolderDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// OpenFolderDialogView construction/destruction

OpenFolderDialogView::OpenFolderDialogView()
{
	// TODO: add construction code here

}

OpenFolderDialogView::~OpenFolderDialogView()
{
}

BOOL OpenFolderDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// OpenFolderDialogView drawing

void OpenFolderDialogView::OnDraw(CDC* /*pDC*/)
{
	OpenFolderDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// OpenFolderDialogView printing


void OpenFolderDialogView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL OpenFolderDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void OpenFolderDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void OpenFolderDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void OpenFolderDialogView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void OpenFolderDialogView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// OpenFolderDialogView diagnostics

#ifdef _DEBUG
void OpenFolderDialogView::AssertValid() const
{
	CView::AssertValid();
}

void OpenFolderDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

OpenFolderDialogDoc* OpenFolderDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(OpenFolderDialogDoc)));
	return (OpenFolderDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// OpenFolderDialogView message handlers


void OpenFolderDialogView::OnHandleOpenFolderDlg() {
  CFolderDialog folder_dialog(AfxGetMainWnd());
  folder_dialog.DoModal();
}