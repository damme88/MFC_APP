
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "MFCToolBarXml.h"

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
  void OnHandle(UINT pcmd);
  void OnHandle1(UINT pcmd);
  void OnUpdateButton(CCmdUI *pcmd);
// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBarXml    m_wndToolBar;
  CMFCToolBarXml    m_wndShowBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

  SIZE button_size;
  unsigned int count_;
  std::string str_xml_full_;
  CMFCToolBarXml* toolbar_;

public:
  void ReadFileXml(CString file_path);
  void CreateXmlFile(CString file_name);
  void GetCountToolBar(std::string xml_data_str);
  CString CMainFrame::GetPathModule();
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
};


