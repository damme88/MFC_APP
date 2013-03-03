
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CMainFrame : public CFrameWndEx
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
  // variable for application
  CRichEditCtrl rich_edit_;
  CString		str_path_name_;


public:
  void ReadFile();
  void WriteFile();

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
  afx_msg void OnSetFocus(CWnd* wnd);

  afx_msg void OnEditCut();
  afx_msg void OnEditCopy();
  afx_msg void OnEditPaste();
  afx_msg void OnEditDelete();
  afx_msg void OnEditUndo();
  afx_msg void OnEditRedo();
  afx_msg void OnFileOpen();
  afx_msg void OnFileSave();
  afx_msg void OnFileNew();
  afx_msg void OnFileSaveAs();
  afx_msg void OnFilePrint();
	DECLARE_MESSAGE_MAP()

};


