#pragma once
#include "resource.h"
#include "ControlSplitter.h"

// FormView form view

class FormView : public CFormView
{
	DECLARE_DYNCREATE(FormView)

public:
	FormView();           // protected constructor used by dynamic creation
	virtual ~FormView();

public:
	enum { IDD = IDD_FORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
  virtual BOOL Create(CWnd* pParent);

protected:
  CControlSplitter  m_wndSplitter;
  CListCtrl         m_wndStackList;
  CEdit             m_wndStackEdit;

  virtual void OnInitialUpdate();
  void Resize();
  void MoveDlgItem(int nID, const CRect& rcPos, BOOL bRepaint);

protected:
  virtual void PostNcDestroy();
  afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	DECLARE_MESSAGE_MAP()
};


