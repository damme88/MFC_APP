
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "Many_Dialog_Bar.h"

#include "ChildFrm.h"
#include "DlgBar_Left.h"
#include "Many_Dialog_BarView.h"
#include "DlgBar_Bottom.h"
#include "DlgBar_Sub.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#define DIALOG_BAR_STYLE_1
//#define DIALOG_BAR_STYLE_2
//#define DIALOG_BAR_STYLE_3
#define DIALOG_BAR_STYLE_4
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
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

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpCreateStruct, CCreateContext *pContext) {

#ifdef DIALOG_BAR_STYLE_1
  if (!splitter_.CreateStatic(this, 1, 2)) {
    TRACE0("Failed to create splitter windows");
    return FALSE;
  }

  CRect rect;
  GetClientRect(rect);
  // choose colum 1 for splitter to set infor about size
  splitter_.SetColumnInfo(0, rect.Width()*1/4, 0);

  if (!sub_splitter_.CreateStatic(&splitter_, 2, 1, WS_CHILD | WS_VISIBLE,
                                  splitter_.IdFromRowCol(0, 0))) {
    TRACE0("Failed to make  sub Splitter");
    return FALSE;
  }

  if (!sub_splitter_.CreateView(0, 0, RUNTIME_CLASS(DlgBar_Left),
                                CSize(rect.Width()*1/4, rect.Height()*3/4),
                                pContext)) {
    TRACE0("Failed to make sub row 1");
    return FALSE;
  }

  sub_splitter_.SetColumnInfo(0, rect.Width()*1/4, 0);
  sub_splitter_.SetRowInfo(0, rect.Height()*3/4, 0);
  sub_splitter_.SetRowInfo(1, rect.Height()*1/4, 0);

  if (!sub_splitter_.CreateView(1, 0, RUNTIME_CLASS(DlgBar_Bottom),
                                CSize(rect.Width()*1/4, rect.Height()*1/4),
                                pContext)) {
    TRACE0("Faile to make row 0");
    return FALSE;
  }

  if (!splitter_.CreateView(0, 1, RUNTIME_CLASS(CMany_Dialog_BarView),
                                CSize(rect.Width()*3/4, rect.Height()), pContext)) {
    TRACE0("Failed to make sub row 0");
    return FALSE;
  }

#endif

#ifdef DIALOG_BAR_STYLE_2
  CRect rect;
  GetClientRect(rect);
  // Divide View to 1 colum and 2 row
  if (!splitter_.CreateStatic(this, 1, 2)) {
    TRACE0("Failed to create splitter windows");
    return FALSE;
  }

  // choose colum 0 for splitter into set infor about size
  splitter_.SetColumnInfo(0, rect.Width()*3/4, 0);

  // continue divide sub view into 2 row and 1 colum
  if (!sub_splitter_.CreateStatic(&splitter_, 2, 1, WS_CHILD | WS_VISIBLE,
                                  splitter_.IdFromRowCol(0, 1))) {
    TRACE0("Failed to make  sub Splitter");
    return FALSE;
  }

  // sub row 0 is View
  if (!sub_splitter_.CreateView(0, 0, RUNTIME_CLASS(CMany_Dialog_BarView),
                                CSize(rect.Width()*3/4, rect.Height()*3/4),
                                pContext)) {
    TRACE0("Failed to make sub row 0");
    return FALSE;
  }
  sub_splitter_.SetColumnInfo(0, rect.Width()*3/4, 0); // colum 0 have width = 3/4
  sub_splitter_.SetRowInfo(0, rect.Height()*3/4, 0);   // sub row 0 (of colum 0)  have height = 3/4
  sub_splitter_.SetRowInfo(1, rect.Height()*1/4, 0);   // sub row 1 (of colum 1) have hgeith = 1/4

  // sub row 1 is DlgBar_Bottom
  if (!sub_splitter_.CreateView(1, 0, RUNTIME_CLASS(DlgBar_Bottom),
                                CSize(rect.Width()*3/4, rect.Height()*1/4),
                                pContext)) {
    TRACE0("Failed to make sub row 1");
    return FALSE;
  }

  // then divided row 0 (view) success
  // create colum 1 is DlgBar_leff
  if (!splitter_.CreateView(0, 0, RUNTIME_CLASS(DlgBar_Left),
                            CSize(rect.Width()*1/4, rect.Height()),
                            pContext)) {
    TRACE0("Faile to make row 0");
    return FALSE;
  }
#endif

#ifdef DIALOG_BAR_STYLE_3
  if (!splitter_.CreateStatic(this, 1, 2)) {
    TRACE0("Failed to create splitter windows");
    return FALSE;
  }

  CRect rect;
  GetClientRect(rect);
  // choose colum 1 for splitter to set infor about size
  splitter_.SetColumnInfo(0, rect.Width()*3/4, 0);

  if (!sub_splitter_.CreateStatic(&splitter_, 2, 1, WS_CHILD | WS_VISIBLE,
                                  splitter_.IdFromRowCol(0, 0))) {
    TRACE0("Failed to make  sub Splitter");
    return FALSE;
  }

  if (!sub_splitter_.CreateView(0, 0, RUNTIME_CLASS(CMany_Dialog_BarView),
                                CSize(rect.Width()*3/4, rect.Height()*3/4),
                                pContext)) {
    TRACE0("Failed to make sub row 0");
    return FALSE;
  }
  sub_splitter_.SetColumnInfo(0, rect.Width()*3/4, 0);
  sub_splitter_.SetRowInfo(0, rect.Height()*3/4, 0);
  sub_splitter_.SetRowInfo(1, rect.Height()*1/4, 0);

  if (!sub_splitter_.CreateView(1, 0, RUNTIME_CLASS(DlgBar_Bottom),
                                CSize(rect.Width()*3/4, rect.Height()*1/4),
                                pContext)) {
    TRACE0("Failed to make sub row 1");
    return FALSE;
  }

  if (!splitter_.CreateView(0, 1, RUNTIME_CLASS(DlgBar_Left),
                            CSize(rect.Width()*1/4, rect.Height()),
                            pContext)) {
    TRACE0("Faile to make row 0");
    return FALSE;
  }

#endif
#ifdef DIALOG_BAR_STYLE_4
  if (!splitter_.CreateStatic(this, 1, 2)) {
    TRACE0("Failed to create splitter windows");
    return FALSE;
  }
  CRect rect;
  GetClientRect(rect);
  // choose colum 1 for splitter to set infor about size
  splitter_.SetColumnInfo(0, rect.Width()*1/4, 0);

  /********************** divide Dialog bar into 2 row and 1 colum ***********/
  if (!sub_splitter_.CreateStatic(&splitter_, 2, 1, WS_CHILD | WS_VISIBLE,
                                  splitter_.IdFromRowCol(0, 0))) {
    TRACE0("Failed to make  sub Splitter");
    return FALSE;
  }

  if (!sub_splitter_.CreateView(0, 0, RUNTIME_CLASS(DlgBar_Left),
                                CSize(rect.Width()*1/4, rect.Height()*3/4),
                                pContext)) {
    TRACE0("Failed to make sub row 1");
    return FALSE;
  }

  sub_splitter_.SetColumnInfo(0, rect.Width()*1/4, 0);
  sub_splitter_.SetRowInfo(0, rect.Height()*3/4, 0);
  sub_splitter_.SetRowInfo(1, rect.Height()*1/4, 0);

  if (!sub_splitter_.CreateView(1, 0, RUNTIME_CLASS(DlgBar_Bottom),
                                CSize(rect.Width()*1/4, rect.Height()*1/4),
                                pContext)) {
    TRACE0("Faile to make row 0");
    return FALSE;
  }

  /***************************************** divide sub view ******************/
  splitter_.SetColumnInfo(1, rect.Width()*3/4, 0);
  if (!sub_splitter_2.CreateStatic(&splitter_, 2, 1, WS_CHILD | WS_VISIBLE,
                                   splitter_.IdFromRowCol(0, 1))) {
    TRACE0("Failed to make  sub Splitter");
    return FALSE;
  }

  if (!sub_splitter_2.CreateView(1, 0, RUNTIME_CLASS(DlgBar_Sub),
                                 CSize(rect.Width()*3/4, rect.Height()*1/4),
                                 pContext)) {
    TRACE0("Failed to make sub row 1");
    return FALSE;
  }

  sub_splitter_.SetColumnInfo(0, rect.Width()*3/4, 0);
  sub_splitter_.SetRowInfo(1, rect.Height()*1/4, 0);
  sub_splitter_.SetRowInfo(0, rect.Height()*3/4, 0);

  if (!sub_splitter_2.CreateView(0, 0, RUNTIME_CLASS(CMany_Dialog_BarView),
                                 CSize(rect.Width()*3/4, rect.Height()*3/4),
                                 pContext)) {
    TRACE0("Failed to make sub row 1");
    return FALSE;
  }
#endif
  return TRUE;
}