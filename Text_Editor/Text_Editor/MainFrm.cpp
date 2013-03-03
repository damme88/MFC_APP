
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Text_Editor.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
  ON_COMMAND(ID_EDIT_CUT, &CMainFrame::OnEditCut)
  ON_COMMAND(ID_EDIT_COPY, &CMainFrame::OnEditCopy)
  ON_COMMAND(ID_EDIT_PASTE, &CMainFrame::OnEditPaste)
  ON_COMMAND(ID_EDIT_DELETE, &CMainFrame::OnEditDelete)
  ON_COMMAND(ID_EDIT_UNDO, &CMainFrame::OnEditUndo)
  ON_COMMAND(ID_EDIT_REDO, &CMainFrame::OnEditRedo)
  ON_COMMAND(ID_FILE_NEW, &CMainFrame::OnFileNew)
  ON_COMMAND(ID_FILE_OPEN, &CMainFrame::OnFileOpen)
  ON_COMMAND(ID_FILE_SAVE, &CMainFrame::OnFileSave)
  ON_COMMAND(ID_FILE_SAVE_AS, &CMainFrame::OnFileSaveAs)
  ON_COMMAND(ID_FILE_PRINT, &CMainFrame::OnFilePrint)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
  ON_WM_SETFOCUS()
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
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

  // Create rich edit editor as notepead or word...
  if (!rich_edit_.Create(WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_AUTOHSCROLL |
                    ES_MULTILINE | WS_HSCROLL | WS_VSCROLL, CRect(0, 0, 0, 0),
                    this, AFX_IDW_PANE_FIRST)) 
  {
    TRACE0("Failed to create rich text editor ");
    return -1;
  }
  SetWindowLong(rich_edit_.GetSafeHwnd(), GWL_EXSTYLE, WS_EX_CLIENTEDGE);

  // Set the default font for text
  CHARFORMAT cf_default;
  cf_default.cbSize = sizeof (cf_default);
  cf_default.dwEffects = CFE_PROTECTED;
  cf_default.dwMask = CFM_BOLD | CFM_FACE | CFM_SIZE | CFM_CHARSET | CFM_PROTECTED;
  cf_default.yHeight = 200;
  cf_default.bCharSet = 0x00;
  strcpy((char*)cf_default.szFaceName, "Time New Roman");
  
  rich_edit_.SetDefaultCharFormat(cf_default);
  rich_edit_.SetEventMask(ENM_CHANGE | ENM_SELCHANGE | ENM_PROTECTED);
  DragAcceptFiles();

	BOOL bNameValid;

	// set the visual manager used to draw all user interface elements
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));

	//if (!m_wndMenuBar.Create(this))
	//{
	//	TRACE0("Failed to create menubar\n");
	//	return -1;      // fail to create
	//}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// prevent the menu bar from taking the focus on activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// Allow user-defined toolbars operations:
	InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these five lines if you don't want the toolbar and menubar to be dockable
	//m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	//DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolBar);


	// enable Visual Studio 2005 style docking window behavior
	CDockingManager::SetDockingMode(DT_SMART);
	// enable Visual Studio 2005 style docking window auto-hide behavior
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// Enable toolbar and docking window menu replacement
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// enable quick (Alt+drag) toolbar customization
	CMFCToolBar::EnableQuickCustomization();

	if (CMFCToolBar::GetUserImages() == NULL)
	{
		// load user-defined toolbar images
		if (m_UserImages.Load(_T(".\\UserImages.bmp")))
		{
			CMFCToolBar::SetUserImages(&m_UserImages);
		}
	}

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

void CMainFrame::OnSetFocus(CWnd* wnd) {
  rich_edit_.SetFocus();
}


void CMainFrame::OnEditCut() {
  rich_edit_.Cut();
}

void CMainFrame::OnEditCopy() {
  rich_edit_.Copy();
}

void CMainFrame::OnEditDelete() {
}

void CMainFrame::OnEditPaste() {
  rich_edit_.Paste();
}

void CMainFrame::OnEditUndo() {
  rich_edit_.Undo();
}

void CMainFrame::OnEditRedo() {
  rich_edit_.Redo();
}

void CMainFrame::OnFileNew() {
  rich_edit_.SetWindowText(L"");
}
void CMainFrame::OnFileOpen(){
	CString szFilters = L"Text Files (*.txt)|*.txt|All Files (*.*)|*.*|";  // Text Files (*.txt*)
                                                                          // All Files (*.*)
  CFileDialog file_dlg (TRUE, L"txt", L"*.txt", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, szFilters, this);
  if (file_dlg.DoModal() == IDOK) {
    str_path_name_ = file_dlg.GetPathName();
  }
  // Call Read File then got path name of file
  ReadFile();
}

void CMainFrame::OnFileSave() {
  if (str_path_name_ == "")
    OnFileSaveAs();
  else 
    WriteFile();
}

void CMainFrame::OnFilePrint() {

}

DWORD CALLBACK MyStreamCallBack(CFile *dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb) {
  CFile *pFile = (CFile*) dwCookie;
  *pcb = pFile->Read(pbBuff, cb);
  return 0;
}


void CMainFrame::ReadFile() {
  CString file_name = str_path_name_;
  file_name.Replace(__T("\\"), _T("\\\\"));
  
  CFile cFile(file_name, CFile::modeRead);
  EDITSTREAM es;
  es.dwCookie = (DWORD) &cFile;
  es.pfnCallback = (EDITSTREAMCALLBACK) MyStreamCallBack;
  rich_edit_.StreamIn(SF_TEXT, es);
}

void CMainFrame::OnFileSaveAs() {
  CString szFile = L"Text Files (*.txt)|*.txt|All Files(*.*)|*.*||";
  CFileDialog file_dlg(FALSE, L".txt", L"*.txt", OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, szFile, this);
  if (file_dlg.DoModal() == IDOK) {
    str_path_name_ = file_dlg.GetPathName();
    WriteFile();
  }
}


DWORD CALLBACK MyStreamOutCallBack(CFile *dwCookie, LPBYTE pBuff, LONG cb, LONG *pcb) {
  CFile *pFile = (CFile*) dwCookie;
  pFile->Write(pBuff, cb);
  *pcb = cb;
  return 0;
}

void CMainFrame::WriteFile() {
  CString file_name = str_path_name_;
  file_name.Replace(_T("\\"), _T("\\\\"));
  CFile cFile(file_name, CFile::modeCreate|CFile::modeWrite);
  EDITSTREAM es;
  es.dwCookie = (DWORD)&cFile;
  es.pfnCallback = (EDITSTREAMCALLBACK) MyStreamOutCallBack;
  rich_edit_.StreamOut(SF_TEXT, es);
}