
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Toolbar_Xml.h"

#include "MainFrm.h"
#include "MFCToolBarXml.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame
BOOL variable = TRUE;
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

#define ID_XML_START    ID_FILE_TOOLBAR_NEW
#define ID_XML_END   ID_FILE_TOOLBAR_HELP

#define ID_SHOW_START ID_SHOW1
#define ID_SHOW_END   ID_SHOW4
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
  ON_COMMAND_RANGE(ID_XML_START, ID_XML_END, OnHandle)
  ON_COMMAND_RANGE(ID_SHOW_START, ID_SHOW_END, OnHandle1)
  ON_UPDATE_COMMAND_UI_RANGE (ID_XML_START, ID_XML_END, OnUpdateButton)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
  count_ = 0;
  button_size.cx = 32;
  button_size.cy = 32;
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	// set the visual manager used to draw all user interface elements
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));

	//if (!m_wndMenuBar.Create(this))
	//{
	//	TRACE0("Failed to create menubar\n");
	//	return -1;      // fail to create
	//}
	//m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);
  //m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
  //EnableDocking(CBRS_ALIGN_ANY);
  //DockPane(&m_wndMenuBar);
	// prevent the menu bar from taking the focus on activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

  ReadFileXml(L"ToolBarConfig.xml");
  GetCountToolBar(str_xml_full_);
  if (count_ == 0)
    return 0;
  toolbar_ = new CMFCToolBarXml[count_];
  for (int i = 0; i <count_ ; i++) {
    if (!toolbar_[i].CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC)) {
      TRACE0("Failed to create toolbar\n");
		  return -1;      // fail to create
    }
    toolbar_[i].LoadToolBarXml(str_xml_full_, button_size, i, count_); 
  }


	// Allow user-defined toolbars operations:
	InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

  for (int i = 0; i <count_ ; i++) {
    toolbar_[i].EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockPane(&toolbar_[ i]);
  }

	// enable Visual Studio 2005 style docking window behavior
	CDockingManager::SetDockingMode(DT_SMART);
	// enable Visual Studio 2005 style docking window auto-hide behavior
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// enable quick (Alt+drag) toolbar customization
	CMFCToolBar::EnableQuickCustomization();

	// enable menu personalization (most-recently used commands)
	// TODO: define your own basic commands, ensuring that each pulldown menu has at least one basic command.
	CList<UINT, UINT> lstBasicCommands;

	lstBasicCommands.AddTail(ID_FILE_NEW);
	lstBasicCommands.AddTail(ID_FILE_OPEN);
	lstBasicCommands.AddTail(ID_FILE_SAVE);
	lstBasicCommands.AddTail(ID_FILE_PRINT);
	lstBasicCommands.AddTail(ID_APP_EXIT);
	lstBasicCommands.AddTail(ID_EDIT_CUT);
	lstBasicCommands.AddTail(ID_EDIT_PASTE);
	lstBasicCommands.AddTail(ID_EDIT_UNDO);
	lstBasicCommands.AddTail(ID_APP_ABOUT);
	lstBasicCommands.AddTail(ID_VIEW_STATUS_BAR);
	lstBasicCommands.AddTail(ID_VIEW_TOOLBAR);

	CMFCToolBar::SetBasicCommands(lstBasicCommands);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* scan menus */);
	pDlgCust->EnableUserDefinedToolbars();
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
{
	LRESULT lres = CFrameWndEx::OnToolbarCreateNew(wp,lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
{
	// base class does the real work

	if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// enable customization button for all user toolbars
	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	for (int i = 0; i < iMaxUserToolbars; i ++)
	{
		CMFCToolBar* pUserToolbar = GetUserToolBarByIndex(i);
		if (pUserToolbar != NULL)
		{
			pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
		}
	}
	return TRUE;
}

void CMainFrame::OnHandle(UINT nID) {
  if (nID == ID_FILE_TOOLBAR_NEW)
    MessageBox(L"You selected button toolbar 1");
  if (nID == ID_FILE_TOOLBAR_OPEN)
    MessageBox(L"You selected button toolbar 2");
  if (nID == ID_FILE_TOOLBAR_SAVE)
    MessageBox(L"You selected button toolbar 3");
  if (nID == ID_FILE_TOOLBAR_CUT)
    MessageBox(L"You selected button toolbar 4");
}

void CMainFrame::OnHandle1(UINT nID) {
  if (nID == ID_SHOW1)
    MessageBox(L"You selected show 1");
  if (nID == ID_SHOW2)
    MessageBox(L"You selected show 2");
  if (nID == ID_SHOW3)
    MessageBox(L"You selected show  3");
  if (nID == ID_SHOW4)
    MessageBox(L"You selected show 4");
}

void CMainFrame::OnUpdateButton(CCmdUI* pcmd) {
  if(pcmd->m_nID ==ID_FILE_TOOLBAR_CUT) {
    pcmd->Enable(FALSE);
  }
}

void CMainFrame::ReadFileXml(CString file_path) {
  std::fstream file;
  char ch;
  file.open(file_path, std::ios::in);
  if (!file) {
    CreateXmlFile(file_path);
    file.open(file_path, std::ios::in);
  }
  while (!file.eof()) {
    file.get(ch);
    str_xml_full_ += ch;
  }
}

void CMainFrame::CreateXmlFile(CString file_name) {
  fstream file_xml;
  file_xml.open(file_name, ios::out);
  const char *data_file[] = {"file_new", "file_open", "file_save",
                             "separator",
                             "file_cut", "file_copy", "file_paste",
                             "separator",
                             "file_printer", "file_help"};

  const char *data_show[] = {"show1", "separator", "show2", "separator", "show3", "separator", "show4"};

  const char *key_file[] = {"<toolbar name = \"file_toolbar\">", "</toolbar>"};
  const char *key_show[] = {"<toolbar name = \"show_toolbar\">", "</toolbar>"};

  const char *key_button [] = {"<button>", "</button>"};
  char str_down ='\n';
  char str_tab = '\t';
  const char *header[] = {"<sconf>", "</sconf>" };

  file_xml << header[0];
  file_xml <<str_down << str_tab;
  file_xml << key_file[0];
  for (int i = 0; i< 10; i++ ) {
    file_xml << str_down << str_tab << str_tab;
    file_xml << key_button[0] << data_file[i] << key_button[1];
  }
  file_xml <<str_down << str_tab;
  file_xml << key_file[1];

  file_xml <<str_down << str_tab;
  file_xml << key_show[0];
  for (int i = 0; i< 7; i++ ) {
    file_xml << str_down << str_tab << str_tab;
    file_xml << key_button[0] << data_show[i] << key_button[1];
  }
  file_xml <<str_down << str_tab;
  file_xml << key_show[1];
  file_xml <<str_down;
  file_xml << header[1];

  file_xml.close();
}

void CMainFrame::GetCountToolBar(std::string xml_data_str) {
    std::string sub_str = "";
  int j = 0;
  for (int i = 0; i <xml_data_str.length(); i++) {
    if (xml_data_str[i] == '<') {
      j = i;
      while (xml_data_str[j] != '>' ) {
        sub_str += xml_data_str[j];
        j++;
      }
      sub_str += '>';
      if (sub_str == "</toolbar>") {
        count_ = count_ + 1;
        sub_str = "";
        i = j;
      }
      else {
        sub_str = "";
        i = j;
      }
    }
  }
}