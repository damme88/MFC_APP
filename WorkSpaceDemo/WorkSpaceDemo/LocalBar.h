#pragma once
#include "CustomListCtrl.h"
#include "TabBar.h"
#include "FormView.h"
#include "SystemForm.h"
#include <vector>


class LocalToolbar: public CMFCToolBar {
public:
  virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) {
    CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
  }

  virtual BOOL AllowShowOnList() const {
    return FALSE;
  }
};


// LocalBar

class LocalBar : public CDockablePane
{
	DECLARE_DYNAMIC(LocalBar)

public:
	LocalBar();
	virtual ~LocalBar();
  void AdjustLayout();
  void InitLocal();
  void InitCommon();
  void InitStack();
  void SetFont();
  DataListView GetDataLocal();
protected:
  TabBar                  m_wndTabs;
  CustomListCtrl          m_wndlocal;
  CustomListCtrl          m_wndcommon;
  SystemForm              m_wndSystem;
  FormView                m_wndStack;
  CFont                   font_;

protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg LRESULT OnAfxWmChangingActiveTab(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};


