#pragma once


// CTaskPane

class CTaskPane : public CMFCTasksPane {
	DECLARE_DYNAMIC(CTaskPane)

public:
	CTaskPane();
	virtual ~CTaskPane();

protected:
	DECLARE_MESSAGE_MAP()

protected:
  int document_group_;
  CFont wnd_font_;
  CTreeCtrl wnd_tree_;
  CEdit wnd_edit_;

public:
  void UpdateMRUFileList();
  void UpdateIcon();

protected:
  BOOL CreateTreeWindows();
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


