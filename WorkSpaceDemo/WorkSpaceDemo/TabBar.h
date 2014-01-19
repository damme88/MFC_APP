#pragma once


// TabBar

class TabBar : public CMFCTabCtrl
{
	DECLARE_DYNAMIC(TabBar)

public:
	TabBar();
	virtual ~TabBar();
  virtual BOOL SetActiveTab(int iTab);
protected:
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};


