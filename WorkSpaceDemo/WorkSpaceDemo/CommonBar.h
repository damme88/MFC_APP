#pragma once


// CommonBar

class CommonToolbar: public CMFCToolBar {
public:
  virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) {
    CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
  }

  virtual BOOL AllowShowOnList() const {
    return FALSE;
  }
};


class CommonBar : public CDockablePane
{
	DECLARE_DYNAMIC(CommonBar)

public:
	CommonBar();
	virtual ~CommonBar();
  void InitCommon();
  void AdjustLayout();
  void SetFont();

private:
  CMFCPropertyGridCtrl    m_wndprolist_common;
  CFont                   font_;
protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};


