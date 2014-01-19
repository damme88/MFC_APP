// SystemForm.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "SystemForm.h"


// SystemForm

IMPLEMENT_DYNCREATE(SystemForm, CFormView)

SystemForm::SystemForm()
	: CFormView(SystemForm::IDD)
{

}

SystemForm::~SystemForm()
{
}

void SystemForm::DoDataExchange(CDataExchange* pDX)
{
  CFormView::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_BUTTON1, button_1);
  DDX_Control(pDX, IDC_LIST1, system_list_);
}

BEGIN_MESSAGE_MAP(SystemForm, CFormView)
  ON_WM_MOUSEACTIVATE()
  ON_WM_SIZE()
  ON_BN_CLICKED(IDC_BUTTON1, &SystemForm::HandleButton1)
END_MESSAGE_MAP()


// SystemForm diagnostics

#ifdef _DEBUG
void SystemForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SystemForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SystemForm message handlers


void SystemForm::OnInitialUpdate() {
  CFormView::OnInitialUpdate();


  system_list_.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	system_list_.InsertColumn(0, _T("Colum1"), LVCFMT_LEFT, 80);
	system_list_.InsertColumn(1, _T("Colum2"), LVCFMT_LEFT, 80);
  system_list_.InsertColumn(2, _T("Colum3"), LVCFMT_LEFT, 80);

  for (int i = 50; i >0; i--) {
    CString str1;
    str1.Format(_T("%d"), 1000+i);
    CString str2;
    str2.Format(_T("%d"), 2000+i);
    system_list_.InsertItem(0, _T("ID"));
	  system_list_.SetItemText(0, 1, str1);
    system_list_.SetItemText(0, 2, str2);
  }
  return;
}


BOOL SystemForm::Create(CWnd* pParent){
  CRect rect;
  pParent->GetClientRect(rect);
  return CFormView::Create(NULL, NULL, WS_CHILDWINDOW | WS_VISIBLE, rect, pParent,ID_SYSTEM_BAR, NULL);
}


int SystemForm::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) {
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


void SystemForm::PostNcDestroy() {
  CWnd::PostNcDestroy();
}

void SystemForm::OnSize(UINT nType, int cx, int cy) {
  CRect rect_list;
  if (system_list_.m_hWnd != NULL) {

    int height = cy - 150;
    system_list_.GetWindowRect(rect_list);
    if (rect_list.Width() > cx) {
      system_list_.MoveWindow(0, 150, rect_list.Width(), height);
    } else {
      system_list_.MoveWindow(0, 150, cx, height);
    }
 }

  EnableScrollBarCtrl(SB_BOTH, FALSE);
  CFormView::OnSize(nType, cx, cy);
}

void SystemForm::HandleButton1() {
  int b(0);
}