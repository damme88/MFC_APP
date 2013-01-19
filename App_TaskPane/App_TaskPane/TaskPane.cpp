// TaskPane.cpp : implementation file
//

#include "stdafx.h"
#include "App_TaskPane.h"
#include "TaskPane.h"


// CTaskPane

IMPLEMENT_DYNAMIC(CTaskPane, CMFCTasksPane)

CTaskPane::CTaskPane() {
  document_group_ = -1;
}

CTaskPane::~CTaskPane() {
}


BEGIN_MESSAGE_MAP(CTaskPane, CMFCTasksPane)
  ON_WM_CREATE()
END_MESSAGE_MAP()

int CTaskPane::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CMFCTasksPane::OnCreate(lpCreateStruct) == -1)
    return -1;
  SetIconsList(IDB_TASK_PANE, 16); // assign bitmap for ever items which is created
  SetCaption(__T("Task Pane"));    // create name task panel

  // page1
  SetPageCaption(0, __T("New Document"));  // name page
    // Group 1
    document_group_ = AddGroup(__T("Open a document"), FALSE, TRUE); // name group 1
    // add MUR list
    AddMRUFilesList(document_group_);
    AddTask(document_group_, __T("More Document..."), 0, ID_FILE_OPEN);

    // Group 2
    int nPage1Gr2 = AddGroup(__T("New"));                                  //name Group2
    AddTask(nPage1Gr2, __T("Blank document"), 1, ID_FILE_NEW);             // item 1
    AddTask(nPage1Gr2, __T("Blank Web Page"), 2, ID_DUMMY);                // item 2
    AddSeparator(nPage1Gr2);                                               // separator
    AddTask (nPage1Gr2, _T("Blank E-mail message"), 3, ID_DUMMY);          // item 3

  // Group3
  int nPage1Gr3 = AddGroup (_T("New from existing document"));              // name Group 3
	  AddTask (nPage1Gr3, _T("Choose document..."), 4, ID_DUMMY);             // item

  // Group4
	int nPage1Gr4 = AddGroup (_T("New from template"));                       // name Group 4
	  AddTask (nPage1Gr4, _T("General Templates..."), 5, ID_DUMMY);           // item 1
	  AddTask (nPage1Gr4, _T("Templates on my Web Sites..."), 6, ID_DUMMY);   // item 2
	  AddTask (nPage1Gr4, _T("Templates on Microsoft.com..."), 7, ID_DUMMY);  // item 3

  // Group 5
	int nPage1Gr5 = AddGroup (_T(""), TRUE /* Group at bottom */);            // name group 5
	  AddTask (nPage1Gr5, _T("Add Network Place..."), 8, ID_DUMMY);           // item 1
	  AddTask (nPage1Gr5, _T("Help..."), 9, ID_DUMMY);                        // item 2
	  AddLabel (nPage1Gr5, _T("Label"));                                      // item 3

  //page2
  int nPage2 = AddPage (_T("Basic Search"));                               // name Page 2
	  int nPage2Gr1 = AddGroup (nPage2, _T("Search for:"));                  // name Group 1
	    AddTask (nPage2Gr1, _T("Search Tips..."), 10, ID_DUMMY);             // item 

	  int nPage2Gr2 = AddGroup (nPage2, _T("See also:"));                    // name Group 2
	    AddTask (nPage2Gr2, _T("Advanced Search"), 11, ID_DUMMY);            // item 1
	    AddTask (nPage2Gr2, _T("Find in this document..."), 12, ID_DUMMY);   // item 2
      AddTask (nPage2Gr2, _T("Copy document concept"), 13, ID_DUMMY);      // item 3

    int nPage2Gr3 = AddGroup (nPage2, _T("Reference:"));                   // name Group 3
      AddTask(nPage2Gr3, _T("English Ebook..."), 14, ID_DUMMY);            // item 1
      AddTask (nPage2Gr3, _T("VietNamese Ebook..."), 15, ID_DUMMY);        // item 2

	// Page 3:
	int nPage3 = AddPage (_T("Custom page"));                               //name page
    // Group1 is folder tree windows
	  int nPage3Gr1 = AddGroup (nPage3, _T("Folders"));                     // name group
	  if (!CreateTreeWindows()) {
		  TRACE0("Failed to create the custom window\n");
		  return -1;      // fail to create
	  }
	  AddWindow (nPage3Gr1, wnd_tree_.GetSafeHwnd (), 65);
	  AddTask (nPage3Gr1, _T("My favorites..."), 0, ID_DUMMY);

   // Group2  is texbox
	  int nPage3Gr2 = AddGroup (nPage3, _T("Enter your text"));
	  CRect rectDummy;
	  rectDummy.SetRectEmpty ();
	  DWORD dwEditStyle = WS_CHILD | WS_VISIBLE | WS_BORDER | 
		ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN;
	  wnd_font_.CreateStockObject (DEFAULT_GUI_FONT);
	  if (!wnd_edit_.Create (dwEditStyle, rectDummy, this, (UINT)-1)) {
		  TRACE0("Failed to create the edit window\n");
		  return -1;      // fail to create
	  }
	  wnd_edit_.SetFont (&wnd_font_);
	  wnd_edit_.SetWindowText(
		_T("This is the standard multiline Edit Box.\r\nHere you can type your text."));
	
	  AddWindow (nPage3Gr2, wnd_edit_.GetSafeHwnd (), 65);
	  return 0;
}


void CTaskPane::UpdateMRUFileList() {
  AddMRUFilesList (document_group_);
  RedrawWindow();
}

// Function nay duoc su dung de tao 1 application dang windows tree
// Tuc la 1 cua so windows chua cac thu muc hoac item dang tree
BOOL CTaskPane::CreateTreeWindows() {
  CRect rectDummy (0, 0, 0, 0);
	const DWORD dwTreeStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;
	if (!wnd_tree_.Create (dwTreeStyle, rectDummy, this, (UINT)-1))
	{
		TRACE0("Failed to create the custom window\n");
		return FALSE;      // fail to create
	}

	TCHAR szWinDir [MAX_PATH + 1];
	if (GetWindowsDirectory (szWinDir, MAX_PATH) != 0)
	{
		SHFILEINFO sfi;
		HIMAGELIST himSystem = (HIMAGELIST)SHGetFileInfo (szWinDir, 0, &sfi, sizeof(SHFILEINFO),
                                                       SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
		int iIndex = sfi.iIcon;

		wnd_tree_.SetImageList (CImageList::FromHandle (himSystem), TVSIL_NORMAL);

		HTREEITEM hRoot = wnd_tree_.InsertItem (_T("Folders"), iIndex, iIndex);
		wnd_tree_.InsertItem (_T("Folder 1"), iIndex, iIndex, hRoot);
		wnd_tree_.InsertItem (_T("Folder 2"), iIndex, iIndex, hRoot);
		wnd_tree_.InsertItem (_T("Folder 3"), iIndex, iIndex, hRoot);
		wnd_tree_.InsertItem (_T("Folder 4"), iIndex, iIndex, hRoot);
		wnd_tree_.Expand (hRoot, TVE_EXPAND);

		wnd_tree_.RedrawWindow ();
	}
	return TRUE;
}

void CTaskPane::UpdateIcon() {
  SetIconsList (theApp.m_bHiColorIcons ? IDB_TASK_PANE : IDB_TASK_PANE, 16);
}

// CTaskPane message handlers


