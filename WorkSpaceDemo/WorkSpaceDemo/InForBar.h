#pragma once

class InfoToolbar: public CMFCToolBar {
public:
  virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) {
    CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
  }

  virtual BOOL AllowShowOnList() const {
    return FALSE;
  }
};

// InForBar

class InFoBar : public CDockablePane
{
	DECLARE_DYNAMIC(InFoBar)

public:
	InFoBar();
	virtual ~InFoBar();
  void AdjustLayout();
  void InitInfoBar();
  void SetFont();
protected:
  CFont font_;
  CRichEditCtrl   m_wndInfo;
protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
};


