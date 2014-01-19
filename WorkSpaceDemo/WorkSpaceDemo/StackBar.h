#pragma once

class StackToolbar: public CMFCToolBar {
public:
  virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) {
    CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
  }

  virtual BOOL AllowShowOnList() const {
    return FALSE;
  }
};


// StackBar

class StackBar : public CDockablePane
{
	DECLARE_DYNAMIC(StackBar)

public:
	StackBar();
	virtual ~StackBar();
  void InitStackBar();
  void AdjustLayout();
  void SetFont();
protected:
  CListCtrl   m_wndStack;
  CFont font_;
protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
};


