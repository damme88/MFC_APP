#ifndef FOLDER_DIALOG_H_
#define FOLDER_DIALOG_H_
#include "stdafx.h"
#include <afxdlgs.h>

class CFolderDialog:public CCommonDialog {
public:
  CFolderDialog(CWnd *pParent);
  virtual ~ CFolderDialog();
  static INT_PTR CALLBACK BrowseCallbackProc(IN HWND hwnd, IN UINT uMsg,
                                              IN LPARAM lParam, IN LPARAM lpData);
  virtual int DoModal();
  CString GetFolderPath();
  CString GetFolderName();
protected:
  BROWSEINFO browse_info_;
  CString folder_path_;
  CString folder_name_;

};

#endif // FOLDER_DIALOG_H_