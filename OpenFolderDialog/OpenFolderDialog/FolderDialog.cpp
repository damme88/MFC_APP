
#include "stdafx.h"
#include "FolderDialog.h"

CFolderDialog::CFolderDialog(CWnd* pParent):CCommonDialog(pParent) {
  LPCTSTR lpsztitle = _T("Select the root folder for the browse dialog");
  UINT uFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
  browse_info_.hwndOwner = pParent->GetSafeHwnd();
  browse_info_.pidlRoot = NULL;
  browse_info_.lpszTitle = lpsztitle;
  browse_info_.lpfn = (BFFCALLBACK)&BrowseCallbackProc;
  browse_info_.lParam = (LPARAM)this;
  browse_info_.pszDisplayName = new TCHAR [MAX_PATH];
  ASSERT(browse_info_.pszDisplayName != NULL);
}

CFolderDialog::~CFolderDialog() {
  if (browse_info_.pszDisplayName != NULL) {
    delete [] browse_info_.pszDisplayName;
    browse_info_.pszDisplayName = NULL;
  }
}

int CFolderDialog::DoModal() {
  INT_PTR nRet = -1;
  browse_info_.hwndOwner = PreModal();
  LPITEMIDLIST pItemIDList = ::SHBrowseForFolder(&browse_info_);
  if (pItemIDList) {
    TCHAR szFolPath[ MAX_PATH ];
    if(::SHGetPathFromIDList( pItemIDList, szFolPath)) {
      nRet = IDOK;
    }
    folder_path_ = CString(szFolPath);
  } else {
    nRet = IDCANCEL;
  }

  PostModal();
  return ( nRet );
}


CString CFolderDialog::GetFolderPath() {
  return folder_path_;
}

CString CFolderDialog::GetFolderName() {
  folder_name_ = browse_info_.pszDisplayName;
  return folder_name_;
}

INT_PTR CALLBACK CFolderDialog::BrowseCallbackProc(IN HWND hWnd, IN UINT uMsg, 
                                                   IN LPARAM lParam, IN LPARAM lpData) {

 INT_PTR nRet = 1;
  return nRet;  
}