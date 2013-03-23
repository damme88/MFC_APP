
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Rebar_And_Bitmap.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

// set styles for status bar
static UINT indicators[] =  { ID_SEPARATOR,       /* status line */
                              ID_INDICATOR_CAPS,  /* Cap lock*/
                              ID_INDICATOR_NUM,   /* num lock */
                              ID_INDICATOR_SCRL   /* scrl lock*/};


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)

  ON_COMMAND(ID_TOOLBAR_COME_BACK, &CMainFrame::OnHandleComeback)
  ON_COMMAND(ID_TOOLBAR_FORWARD, &CMainFrame::OnHandleForward)
  ON_COMMAND(ID_TOOLBAR_FOLDER_UP, &CMainFrame::OnHandleFolderUp)
  ON_COMMAND(ID_TOOLBAR_VIEW_FOLDER, &CMainFrame::OnHandleViewFolder)
  ON_COMMAND(ID_TOOLBAR_MOVE_TO, &CMainFrame::OnHandleMoveTo)
  ON_COMMAND(ID_TOOLBAR_COPY_TO, &CMainFrame::OnHandleCopyTo)
  ON_COMMAND(ID_TOOLBAR_VIEW_STYLES, &CMainFrame::OnHandleViewStyles)

  ON_COMMAND(IDS_HISTORY, &CMainFrame::OnHandleViewHistory)
	ON_REGISTERED_MESSAGE(AFX_WM_RESETTOOLBAR, OnToolbarReset)

END_MESSAGE_MAP()

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
   /***************** Create windows XP look for interface of application ****/
  CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
  CMFCToolBar::EnableQuickCustomization();

  /********************** Set size for toolbar and menubar  *******************/
  CMFCToolBar::SetSizes(CSize(32, 32), CSize(24, 24));
  CMFCToolBar::SetMenuSizes(CSize(22, 22), CSize(16, 16));

  /********************** create menu bar ***********************************/
	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}
	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// prevent the menu bar from taking the focus on activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

  /***************************Create toolbar ********************************/
  CClientDC dc(this);
  BOOL is_hight_color = dc.GetDeviceCaps(BITSPIXEL) > 16;
  UINT toolbar_hot_id = is_hight_color ? IDB_TOOLBAR_256 : 0;
  UINT toolbar_cold_id = is_hight_color ? IDB_TOOLBARCOLD256 : 0;
  UINT menu_id = is_hight_color ? IDB_MENU256 : IDB_MENU16;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | 
                                   CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
                                   CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
                                   !m_wndToolBar.LoadToolBar(IDR_MAINFRAME,
                                                             toolbar_cold_id,
                                                             menu_id, FALSE,
                                                             0, 0,
                                                             toolbar_hot_id))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

  // remove toolbar girpper and border
  m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER |
                                                            CBRS_BORDER_TOP |
                                                            CBRS_BORDER_BOTTOM |
                                                            CBRS_BORDER_LEFT |
                                                            CBRS_BORDER_RIGHT));

    // Create Customize for toolbar
  BOOL bNameValid;
	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

  /***************************** Create combobox and address bar  ************/
  if (!address_combox_bar_.Create(CBS_DROPDOWN|
                                  WS_CHILD, CRect(0, 0, 200, 120),
                                  this, AFX_IDW_TOOLBAR + 1)) {
    TRACE0("Failed to make address combox bar");
    return -1;
  }

  address_combox_bar_.EnableActiveAccessibility();

  /********************************** Create Rebar to dock toolbars **********/
  // get DwStyle
  DWORD dwStyle = RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP | RBBS_BREAK;
  if (! wnd_rebar_.Create(this) ||
      ! wnd_rebar_.AddBar(&m_wndToolBar, NULL, NULL, dwStyle) ||
      ! wnd_rebar_.AddBar(&m_wndMenuBar) ||
      ! wnd_rebar_.AddBar(&address_combox_bar_, __T("Address: "), NULL, dwStyle)) 
  {
    TRACE0("Faile to create Rebar");
    return -1;
  }
  // allow menubar and toolbar can adjust layout (can move position)

  /************************** Create Status Bar ******************************/
  if (!m_wndStatusBar.Create(this) ||
      !m_wndStatusBar.SetIndicators(indicators,
                                    sizeof(indicators)/ sizeof(UINT)))
  {
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

  // Allow user-defined toolbars operations:
	InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

  EnableDocking(CBRS_ALIGN_ANY);
  wnd_rebar_.EnableDocking(CBRS_TOP);
  DockPane(&wnd_rebar_);

  m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() |
		                        CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() |
		                        CBRS_TOOLTIPS | CBRS_FLYBY);

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

LRESULT CMainFrame::OnToolbarReset(WPARAM wp, LPARAM lp) {
  // check wp with IDR_MAINFRAME
  UINT id = (UINT)wp;
  if (id != IDR_MAINFRAME)
    return 0;
  // replace "Back" and "Forward" button by menu button
  // create history item
  CMenu history_menu;
  history_menu.LoadMenu(IDR_MENU_HISTORY);

  CMFCToolBarMenuButton button_back(ID_TOOLBAR_COME_BACK,
                                    history_menu,
                                    GetCmdMgr()->GetCmdImage(ID_TOOLBAR_COME_BACK),
                                    _T("Back"));
  button_back.m_bText = TRUE;
  m_wndToolBar.ReplaceButton(ID_TOOLBAR_COME_BACK, button_back);

  	m_wndToolBar.ReplaceButton (ID_TOOLBAR_FORWARD,
      CMFCToolBarMenuButton (ID_TOOLBAR_FORWARD, history_menu, 
					GetCmdMgr ()->GetCmdImage (ID_TOOLBAR_FORWARD), _T("Forward")));

  // replace button view styles by menu button
  CMenu menu_view_style;
  menu_view_style.LoadMenu(IDR_MENU_VIEW_STYLES);
  CMFCToolBarMenuButton button_menu_view_styles(ID_TOOLBAR_VIEW_STYLES,
                                                menu_view_style,
                                                GetCmdMgr()->GetCmdImage(ID_TOOLBAR_VIEW_STYLES),
                                                _T("View Styles"));
  m_wndToolBar.ReplaceButton(ID_TOOLBAR_VIEW_STYLES, button_menu_view_styles);
  return 0L;
}


void CMainFrame::OnHandleComeback() {

}

void CMainFrame::OnHandleForward() {
  
}

void CMainFrame::OnHandleFolderUp() {
  
}

void CMainFrame::OnHandleViewFolder() {
  
}

void CMainFrame::OnHandleMoveTo() {
  
}

void CMainFrame::OnHandleCopyTo() {
  
}

void CMainFrame::OnHandleViewStyles() {
  
}

void CMainFrame::OnHandleViewHistory() {
  
}
