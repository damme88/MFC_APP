
// RestartAppAutomaticView.cpp : implementation of the RestartAppAutomaticView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RestartAppAutomatic.h"
#endif

#include "RestartAppAutomaticDoc.h"
#include "RestartAppAutomaticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// RestartAppAutomaticView

IMPLEMENT_DYNCREATE(RestartAppAutomaticView, CView)

BEGIN_MESSAGE_MAP(RestartAppAutomaticView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &RestartAppAutomaticView::OnFilePrintPreview)
  ON_COMMAND(ID_RESTART_THE_APP, &RestartAppAutomaticView::RestartTheApplication)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// RestartAppAutomaticView construction/destruction

RestartAppAutomaticView::RestartAppAutomaticView()
{
	// TODO: add construction code here

}

RestartAppAutomaticView::~RestartAppAutomaticView()
{
}

BOOL RestartAppAutomaticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// RestartAppAutomaticView drawing

void RestartAppAutomaticView::OnDraw(CDC* /*pDC*/)
{
	RestartAppAutomaticDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// RestartAppAutomaticView printing


void RestartAppAutomaticView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL RestartAppAutomaticView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void RestartAppAutomaticView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void RestartAppAutomaticView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void RestartAppAutomaticView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void RestartAppAutomaticView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// RestartAppAutomaticView diagnostics

#ifdef _DEBUG
void RestartAppAutomaticView::AssertValid() const
{
	CView::AssertValid();
}

void RestartAppAutomaticView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

RestartAppAutomaticDoc* RestartAppAutomaticView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(RestartAppAutomaticDoc)));
	return (RestartAppAutomaticDoc*)m_pDocument;
}
#endif //_DEBUG


// RestartAppAutomaticView message handlers

void RestartAppAutomaticView::RestartTheApplication() {

#if 0
  STARTUPINFO m_StartupInfo;
  PROCESS_INFORMATION m_ProcessInformation;
  ZeroMemory(&m_StartupInfo, sizeof(STARTUPINFO));
  ZeroMemory(&m_ProcessInformation, sizeof(PROCESS_INFORMATION));

  char* szPrgPathName = "\"restart_self.exe\"";
  char module_file_name [MAX_PATH];
  GetModuleFileName(NULL, (LPWSTR)module_file_name, 255);
  CreateProcess ((LPWSTR)module_file_name
    , (LPWSTR)szPrgPathName   // the command line options
    , (LPSECURITY_ATTRIBUTES)NULL
    , (LPSECURITY_ATTRIBUTES)NULL
    , FALSE
    , CREATE_NEW_CONSOLE
    , NULL
    , NULL
    , &m_StartupInfo
    , &m_ProcessInformation) ;
  DWORD dwLastError = GetLastError();   // for test only

  // should work in view based application, not tested
   theApp.CloseAllDocuments(TRUE);
#else 
  TCHAR file_name[MAX_PATH];
  file_name[0] = 0;
  GetModuleFileName(0, file_name, MAX_PATH);
  theApp.CloseAllDocuments(TRUE);
  HINSTANCE histance = ShellExecute(0,
                                    _T("open"),
                                    file_name,
                                    _T(""),
                                    0,
                                    SW_SHOW);
#endif
}
