#pragma once

class SystemToolbar: public CMFCToolBar {
public:
  virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) {
    CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
  }

  virtual BOOL AllowShowOnList() const {
    return FALSE;
  }
};

// SystemBar

class SystemBar : public CDockablePane
{
	DECLARE_DYNAMIC(SystemBar)

public:
	SystemBar();
	virtual ~SystemBar();
protected:
	CFont font_;
  CListCtrl     m_wndSystem;
  void InitSystem();
  void SetFont();
protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	DECLARE_MESSAGE_MAP()
};


