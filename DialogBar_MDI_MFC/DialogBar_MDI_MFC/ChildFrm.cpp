
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "DialogBar_MDI_MFC.h"

#include "ChildFrm.h"
#include "Dialog_Bar.h"
#include "DialogBar_MDI_MFCView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
  ON_WM_PAINT()
END_MESSAGE_MAP()

// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient( LPCREATESTRUCT lpcs, CCreateContext* pContext) {
	if (!m_wndSplitter.CreateStatic(this, 1, 2, WS_CHILD | WS_VISIBLE)) {
		TRACE("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

  // First splitter pane
  if (!m_wndSplitter.CreateView(0, 0,
      RUNTIME_CLASS(Dialog_Bar), CSize(200,200), pContext)) {
		TRACE("Failed to create command view pane\n");
    return FALSE;
  }

  // Second splitter pane
  if (!m_wndSplitter.CreateView(0, 1,
    RUNTIME_CLASS(CDialogBar_MDI_MFCView), CSize(200,200), pContext)) {
    TRACE("Failed to create preview pane\n");
    return FALSE;
  }
	return TRUE;
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame message handlers
