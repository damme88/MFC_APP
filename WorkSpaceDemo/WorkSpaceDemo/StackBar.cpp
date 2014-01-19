// StackBar.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "StackBar.h"


// StackBar

IMPLEMENT_DYNAMIC(StackBar, CDockablePane)

StackBar::StackBar()
{

}

StackBar::~StackBar()
{
}


BEGIN_MESSAGE_MAP(StackBar, CDockablePane)
  ON_WM_CREATE()
  ON_WM_SIZE()
END_MESSAGE_MAP()

int StackBar::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CDockablePane::OnCreate(lpCreateStruct) == -1)
    return -1;

  font_.CreateStockObject(DEFAULT_GUI_FONT);
  CRect rect_dummy;
  rect_dummy.SetRectEmpty();
  const DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_VSCROLL | LVS_REPORT;
  if (!m_wndStack.Create(dwStyle, rect_dummy, this, ID_STACK_BAR)) {
    TRACE0("Failed to create Properies Grid \n");
		return -1;      // fail to create
  }
  InitStackBar();

	AdjustLayout();
}

void StackBar::InitStackBar() {

  SetFont();

  m_wndStack.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_wndStack.InsertColumn(0, _T("Colum1"), LVCFMT_LEFT, 60);
	m_wndStack.InsertColumn(1, _T("Colum2"), LVCFMT_LEFT, 60);
  m_wndStack.InsertColumn(2, _T("Colum3"), LVCFMT_LEFT, 60);

  for (int i = 5; i >0; i--) {
    CString str1;
    str1.Format(_T("%d"), 1000+i);
    CString str2;
    str2.Format(_T("%d"), 2000+i);
    m_wndStack.InsertItem(0, _T("ID_#"));

	  m_wndStack.SetItemText(0, 1, str1);
    m_wndStack.SetItemText(0, 2, str2);
  }
}


void StackBar::SetFont()
{
  ::DeleteObject (font_.Detach ());

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont (&lf);

	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);

	afxGlobalData.GetNonClientMetrics (info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;

	font_.CreateFontIndirect (&lf);
  m_wndStack.SetFont(&font_);
}


// LocalBar message handlers
void StackBar::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void StackBar::AdjustLayout()
{
	if (GetSafeHwnd() == NULL) {
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

  m_wndStack.SetWindowPos(NULL, rectClient.left, rectClient.top,
                            rectClient.Width(), rectClient.Height(),
                            SWP_NOACTIVATE | SWP_NOZORDER);
}


// StackBar message handlers


