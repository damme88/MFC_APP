
// ChildFrm.cpp : implementation of the ChildFrame class
//

#include "stdafx.h"
#include "Context_View_Demo.h"

#include "ChildFrm.h"
#include "Context_View.h"
#include "Context_View_DemoView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ChildFrame

IMPLEMENT_DYNCREATE(ChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(ChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// ChildFrame construction/destruction

ChildFrame::ChildFrame()
{
	context_view_ = NULL;
}

ChildFrame::~ChildFrame()
{
}


BOOL ChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// ChildFrame diagnostics

#ifdef _DEBUG
void ChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void ChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// ChildFrame message handlers

BOOL ChildFrame::OnCreateClient(LPCREATESTRUCT lpCreateStruct, CCreateContext *pContext) {
  if (!m_wndSplitter.CreateStatic(this, 2, 1, WS_CHILD | WS_VISIBLE)) {
    TRACE0("Failed to create static splitter");
    return FALSE;
  }

  if(!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(Context_View_DemoView), CSize(800, 450), pContext)) {
    TRACE("Failed to create preview pane\n");
    return FALSE;
  }

  if (!m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(Context_View), CSize(800, 100), pContext)) {
    TRACE0("Failed to create command view pane\n");
    return FALSE;
  }

  context_view_ = (Context_View*) m_wndSplitter.GetPane(1,0);
  return TRUE;
}