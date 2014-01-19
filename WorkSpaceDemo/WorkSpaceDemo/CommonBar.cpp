// CommonBar.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "CommonBar.h"
#include <memory>

// CommonBar

IMPLEMENT_DYNAMIC(CommonBar, CDockablePane)

CommonBar::CommonBar()
{

}

CommonBar::~CommonBar()
{
}


BEGIN_MESSAGE_MAP(CommonBar, CDockablePane)
ON_WM_CREATE()
ON_WM_SIZE()
END_MESSAGE_MAP()



// CommonBar message handlers

int CommonBar::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CDockablePane::OnCreate(lpCreateStruct) == -1)
    return -1;

  font_.CreateStockObject(DEFAULT_GUI_FONT);

  CRect rect_dummy;
  rect_dummy.SetRectEmpty();


  if (!m_wndprolist_common.Create(WS_VISIBLE | WS_CHILD, rect_dummy, this, ID_COMMON_BAR)) {
    TRACE0("Failed to create Properies Grid \n");
    return -1;
  }
  InitCommon();

	AdjustLayout();
}


void CommonBar::InitCommon() {
  SetFont();

  m_wndprolist_common.EnableHeaderCtrl(FALSE);
	//wnd_prolist_2.EnableDescriptionArea();
	//wnd_prolist_2.SetVSDotNetLook();
	//wnd_prolist_2.MarkModifiedProperties();

	std::auto_ptr<CMFCPropertyGridProperty> apGroup1(new CMFCPropertyGridProperty(_T("Common")));
  for (int i = 0; i < 30; i++) {
    CString str_label;
    str_label.Format(_T("%d"), i);
    str_label = _T("#") + str_label;
    CString str_value;
    str_value.Format(_T("%d"), 1000+i);

    apGroup1->AddSubItem(new CMFCPropertyGridProperty(str_label, (_variant_t)str_value, _T("")));
  }

  m_wndprolist_common.AddProperty(apGroup1.release());
}

void CommonBar::SetFont()
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
  m_wndprolist_common.SetFont(&font_);
}


// LocalBar message handlers
void CommonBar::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CommonBar::AdjustLayout()
{
	if (GetSafeHwnd() == NULL) {
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);


  m_wndprolist_common.SetWindowPos(NULL, rectClient.left, rectClient.top,
                            rectClient.Width(), rectClient.Height(),
                            SWP_NOACTIVATE | SWP_NOZORDER);
}
