
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "ToolBarWithCombo.h"
class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

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
  CMFCToolBar       m_wndMoveBar;
	CMFCStatusBar     m_wndStatusBar;
  CToolBarWithCombo m_ToolbarCombo;
	CMFCToolBarImages m_UserImages;

public:
  void OnEnableCombo();
  void OnEnableCombo1();
  void OnEnableCombo2();
  void OnEnableCombo3();
  void OnEnableCombo4();
  void DesignCombo();
  int  GetCombo();

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowManager();
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

};


