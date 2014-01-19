// InForBar.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "InForBar.h"


// InForBar

IMPLEMENT_DYNAMIC(InFoBar, CDockablePane)

InFoBar::InFoBar()
{

}

InFoBar::~InFoBar()
{
}


BEGIN_MESSAGE_MAP(InFoBar, CDockablePane)
  ON_WM_CREATE()
  ON_WM_SIZE()
END_MESSAGE_MAP()

int InFoBar::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CDockablePane::OnCreate(lpCreateStruct) == -1)
    return -1;

  font_.CreateStockObject(DEFAULT_GUI_FONT);
  CRect rect_dummy;
  rect_dummy.SetRectEmpty();

  // Create Local tab which is a PropertiesGirdList Control
  const DWORD dwStyle = WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL |
                        ES_AUTOHSCROLL | ES_MULTILINE | ES_READONLY|
                        WS_VSCROLL;
  if (!m_wndInfo.Create(dwStyle, rect_dummy, this, ID_INFO_BAR)) {
		TRACE0("Failed to create Properies Grid \n");
		return -1;      // fail to create
	}

  InitInfoBar();
	AdjustLayout();
}


static DWORD CALLBACK 
MyStreamInCallback(DWORD dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb)
{
   CFile* pFile = (CFile*) dwCookie;

   *pcb = pFile->Read(pbBuff, cb);

   return 0;
}


void InFoBar::InitInfoBar() {
  SetFont();

  CFile cFile(TEXT("My_RichEdit_InFile.rtf"), CFile::modeRead);
  EDITSTREAM es;

  es.dwCookie = (DWORD) &cFile;
  es.pfnCallback = MyStreamInCallback; 
  m_wndInfo.StreamIn(SF_RTF, es);
}
// InForBar message handlers


void InFoBar::SetFont()
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
  m_wndInfo.SetFont(&font_);
}


void InFoBar::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void InFoBar::AdjustLayout()
{
	if (GetSafeHwnd() == NULL) {
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

  m_wndInfo.SetWindowPos(NULL, rectClient.left, rectClient.top,
                            rectClient.Width(), rectClient.Height(),
                            SWP_NOACTIVATE | SWP_NOZORDER);
}