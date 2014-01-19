// LocalBar.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "LocalBar.h"
#include <memory>

// LocalBar

IMPLEMENT_DYNAMIC(LocalBar, CDockablePane)

LocalBar::LocalBar()
{
  std::vector<CString> local_one_value_list;
  local_one_value_list.push_back(L"100");
  local_one_value_list.push_back(L"101");
  local_one_value_list.push_back(L"102");

  std::vector<CString> local_id_list;
  local_id_list.push_back(L"id_0");
  local_id_list.push_back(L"id_1");
  local_id_list.push_back(L"id_2");

  std::vector<CString> local_two_value_list;

  m_wndlocal.SetDataListView(CustomListCtrl::IDTab::LOCAL_TAB,
                             local_id_list,
                             local_one_value_list,
                             local_two_value_list);


  std::vector<CString> common_one_value_list;
  common_one_value_list.push_back(L"9900");
  common_one_value_list.push_back(L"9901");
  common_one_value_list.push_back(L"9902");

  
  std::vector<CString> common_two_value_list;
  common_two_value_list.push_back(L"9900");
  common_two_value_list.push_back(L"9901");
  common_two_value_list.push_back(L"9902");

  std::vector<CString> common_id_list;
  common_id_list.push_back(L"id_0");
  common_id_list.push_back(L"id_1");
  common_id_list.push_back(L"id_2");


  m_wndcommon.SetDataListView(CustomListCtrl::IDTab::COMMON_TAB,
                             common_id_list,
                             common_one_value_list,
                             common_two_value_list);
}

LocalBar::~LocalBar()
{
}


BEGIN_MESSAGE_MAP(LocalBar, CDockablePane)
ON_WM_CREATE()
ON_WM_SIZE()
ON_REGISTERED_MESSAGE(AFX_WM_CHANGING_ACTIVE_TAB,&LocalBar::OnAfxWmChangingActiveTab)
END_MESSAGE_MAP()

int LocalBar::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CDockablePane::OnCreate(lpCreateStruct) == -1)
    return -1;

  font_.CreateStockObject(DEFAULT_GUI_FONT);
  CRect rect_dummy;
  rect_dummy.SetRectEmpty();

  const DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_VSCROLL | LVS_REPORT;

  // Create Local tab which is a PropertiesGirdList Control
  if (!m_wndlocal.Create(dwStyle, rect_dummy, this, ID_LOCAL_BAR)) {
		TRACE0("Failed to create Properies Grid \n");
		return -1;      // fail to create
	}
  InitLocal();

  if (!m_wndcommon.Create(dwStyle, rect_dummy, this, ID_COMMON_BAR)) 
  {
    TRACE0("Failed to create Common Bar\n");
    return -1;
  }
  InitCommon();


  if (!m_wndSystem.Create(this)) {
    TRACE0("Failed to create System Bar\n");
    return -1;
  }

  if (!m_wndStack.Create(this)) {
    TRACE0("Failed to create Stack Bar\n"); 
    return -1;
  }

  	// Create tabs window:
  if (!m_wndTabs.Create (CMFCTabCtrl::STYLE_3D_ONENOTE, rect_dummy, this, ID_TAB_BAR)) {
		TRACE0("Failed to create workspace tab window\n");
		return -1;      // fail to create
	}

  // Create Tab and add tab
  m_wndTabs.AddTab (&m_wndlocal, _T("Local"));
  m_wndTabs.AddTab (&m_wndcommon, _T("Commom"));
  m_wndTabs.AddTab (&m_wndSystem, _T("System"));
  m_wndTabs.AddTab (&m_wndStack, _T("Stack"));
  
  m_wndTabs.SetActiveTab(0);
  m_wndTabs.SetActiveTabBoldFont(true);

	AdjustLayout();
}


void LocalBar::InitLocal() {

  m_wndlocal.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_wndlocal.InsertColumn(0, _T("Colum1"), LVCFMT_LEFT, 80);
	m_wndlocal.InsertColumn(1, _T("Colum2"), LVCFMT_LEFT, 80);
  m_wndlocal.set_editable_column(1);

  for (int i = 0; i < m_wndlocal.GetDataListView().id_list.size(); i++) {
    m_wndlocal.InsertItem(0, m_wndlocal.GetDataListView().id_list[i]);
    m_wndlocal.SetItemText(0, 1, m_wndlocal.GetDataListView().one_value_list[i]);
  }
}

void LocalBar::InitCommon() {
  m_wndcommon.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_wndcommon.InsertColumn(0, _T("Colum1"), LVCFMT_LEFT, 80);
	m_wndcommon.InsertColumn(1, _T("Colum2"), LVCFMT_LEFT, 80);
  m_wndcommon.set_editable_column(1);

  for (int i = 0; i < m_wndcommon.GetDataListView().id_list.size(); i++) {
    m_wndcommon.InsertItem(0, m_wndcommon.GetDataListView().id_list[i]);
    m_wndcommon.SetItemText(0, 1, m_wndcommon.GetDataListView().one_value_list[i]);
  }
}


void LocalBar::SetFont()
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
}


// LocalBar message handlers
void LocalBar::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void LocalBar::AdjustLayout()
{
	if (GetSafeHwnd() == NULL) {
		return;
	}
	CRect rectClient;
	GetClientRect(rectClient);
  m_wndTabs.SetWindowPos (NULL, 0, 0, rectClient.Width(), rectClient.Height(),
							            SWP_NOACTIVATE | SWP_NOZORDER);
}


DataListView LocalBar::GetDataLocal() {
  DataListView data_list_view;

  std::vector<CString> id_list;
  std::vector<CString> one_list;

  int count = m_wndlocal.GetItemCount();
  for (int i = 0; i < count; i++) {
    CString str1 = m_wndlocal.GetItemText(i, 0);
    id_list.push_back(str1);
    CString str2 = m_wndlocal.GetItemText(i, 1);
    one_list.push_back(str2);
  }

  data_list_view.one_value_list = one_list;
  data_list_view.id_list = id_list;
  data_list_view.tab_control = 1;
  return data_list_view;
}

LRESULT LocalBar::OnAfxWmChangingActiveTab(WPARAM wParam, LPARAM lParam) {
  return 0L;
}