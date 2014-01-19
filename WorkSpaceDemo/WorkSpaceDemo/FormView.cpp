// FormView.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "FormView.h"
#include "resource.h"


// FormView

IMPLEMENT_DYNCREATE(FormView, CFormView)

FormView::FormView()
	: CFormView(FormView::IDD)
{

}

FormView::~FormView()
{
}

void FormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_SPLITTER, m_wndSplitter);
  DDX_Control(pDX, IDC_LIST1, m_wndStackList);
  DDX_Control(pDX, IDC_EDIT1, m_wndStackEdit);
}

BEGIN_MESSAGE_MAP(FormView, CFormView)
  ON_WM_MOUSEACTIVATE()
  ON_WM_SIZE()

END_MESSAGE_MAP()


// FormView diagnostics

#ifdef _DEBUG
void FormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


BOOL FormView::Create(CWnd* pParent){
  CRect rect;
  pParent->GetClientRect(rect);
  return CFormView::Create(NULL, NULL, WS_CHILDWINDOW | WS_VISIBLE, rect, pParent,ID_STACK_BAR, NULL);
}


int FormView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) {
  int nResult = CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
	if (nResult == MA_NOACTIVATE || nResult == MA_NOACTIVATEANDEAT)
		return nResult;   // frame does not want to activate

	CFrameWnd* pParentFrame = GetParentFrame();
	if (pParentFrame != NULL)
	{
		// eat it if this will cause activation
		//ASSERT(/*pParentFrame == pDesktopWnd || */pDesktopWnd->IsChild(pParentFrame)); // ToanPT Comment

		// either re-activate the current view, or set this view to be active
		CView* pView = pParentFrame->GetActiveView();
		HWND hWndFocus = ::GetFocus();
		if (pView == this &&
			m_hWnd != hWndFocus && !::IsChild(m_hWnd, hWndFocus))
		{
			// re-activate this view
			OnActivateView(TRUE, this, this);
		}
		else
		{
			// activate this view
			;//pParentFrame->SetActiveView(this);  // ToanPT Comment
		}
	}
	return nResult;
}
// FormView message handlers
void FormView::OnInitialUpdate() {
  CFormView::OnInitialUpdate();

  m_wndSplitter.SetType(CControlSplitter::CS_HORZ);
	m_wndSplitter.AddToTopOrLeftCtrls(IDC_EDIT1);
	m_wndSplitter.AddToBottomOrRightCtrls(IDC_LIST1);

  m_wndStackList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_wndStackList.InsertColumn(0, _T("Colum1"), LVCFMT_LEFT, 80);
	m_wndStackList.InsertColumn(1, _T("Colum2"), LVCFMT_LEFT, 80);
  m_wndStackList.InsertColumn(2, _T("Colum3"), LVCFMT_LEFT, 80);

  for (int i = 2; i >0; i--) {
    CString str1;
    str1.Format(_T("%d"), 1000+i);
    CString str2;
    str2.Format(_T("%d"), 2000+i);
    m_wndStackList.InsertItem(0, _T("ID"));
	  m_wndStackList.SetItemText(0, 1, str1);
    m_wndStackList.SetItemText(0, 2, str2);
  }
  return;
}

void FormView::OnSize(UINT nType, int cx, int cy) {

      CRect rect_edit;
  if (m_wndStackEdit.m_hWnd != NULL) {

    m_wndStackEdit.GetWindowRect(rect_edit);
    int height1 = rect_edit.Height();
    if (rect_edit.Width() > cx) {
      m_wndStackEdit.MoveWindow(0, 4, rect_edit.Width(), height1);
    } else {
      m_wndStackEdit.MoveWindow(0, 4, cx, height1);
    }
  }

  CRect rect_list;
  if (m_wndStackList.m_hWnd != NULL) {

    int height2 = rect_edit.Height() + 20;
    m_wndStackList.GetWindowRect(rect_list);
    if (rect_list.Width() > cx) {
      m_wndStackList.MoveWindow(0, height2, rect_list.Width(), rect_list.Height());
    } else {
      m_wndStackList.MoveWindow(0, height2, cx, rect_list.Height());
    }
  }

  CRect rect_splitter;
  if (m_wndSplitter.m_hWnd != NULL) {
    m_wndSplitter.GetWindowRect(rect_splitter);
    int height3 = rect_edit.Height() + 5;
    if (rect_splitter.Width() > cx) {
      m_wndSplitter.MoveWindow(0, height3, rect_splitter.Width(), rect_splitter.Height());
    } else {
      m_wndSplitter.MoveWindow(0, height3, cx, rect_splitter.Height());
    }
  }

  RedrawWindow();
  CFormView::OnSize(nType, cx, cy);
}

void FormView::PostNcDestroy() {
  CWnd::PostNcDestroy();
}