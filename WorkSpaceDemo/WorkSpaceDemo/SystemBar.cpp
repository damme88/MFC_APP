// SystemBar.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "SystemBar.h"


// SystemBar

IMPLEMENT_DYNAMIC(SystemBar, CDockablePane)

SystemBar::SystemBar()
{

}

SystemBar::~SystemBar()
{
}


BEGIN_MESSAGE_MAP(SystemBar, CDockablePane)
  ON_WM_CREATE()
  ON_WM_SIZE()
  ON_WM_PAINT()
  ON_WM_SETFOCUS()
END_MESSAGE_MAP()

int SystemBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	font_.CreateStockObject(DEFAULT_GUI_FONT);

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create output pane:
	const DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_VSCROLL | LVS_REPORT;

  m_wndSystem.Create(dwStyle, rectDummy, this, ID_SYSTEM_BAR);

	m_wndSystem.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_wndSystem.InsertColumn(0, _T("Colum1"), LVCFMT_LEFT, 50);
	m_wndSystem.InsertColumn(1, _T("Colum2"), LVCFMT_LEFT, 50);
  m_wndSystem.InsertColumn(2, _T("Colum3"), LVCFMT_LEFT, 50);

  for (int i = 20; i >0; i--) {
    CString str1;
    str1.Format(_T("%d"), 1000+i);
    CString str2;
    str2.Format(_T("%d"), 2000+i);
    m_wndSystem.InsertItem(0, _T("ID"));
	  m_wndSystem.SetItemText(0, 1, str1);

    m_wndSystem.SetItemText(0, 2, str2);
  }


	return 0;
}

void  SystemBar::SetFont()
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
	m_wndSystem.SetFont(&font_);
}





void SystemBar::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	if (CanAdjustLayout())
	{
		CRect rc;
		GetClientRect(rc);

		m_wndSystem.SetWindowPos(NULL, rc.left + 1, rc.top + 1, rc.Width() - 2, rc.Height() - 2, SWP_NOACTIVATE | SWP_NOZORDER);
	}
}

void SystemBar::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectTree;
	m_wndSystem.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void SystemBar::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
	m_wndSystem.SetFocus();
}



// SystemBar message handlers


