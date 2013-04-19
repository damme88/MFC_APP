#pragma once
#include "afxcmn.h"
#include "SliderBar.h"
#include "afxwin.h"

// Context_View form view

class Context_View : public CFormView
{
	DECLARE_DYNCREATE(Context_View)

protected:
	Context_View();           // protected constructor used by dynamic creation
	virtual ~Context_View();

public:
	enum { IDD = IDD_CONTEXT_VIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

protected:
  CString str_edit_1;
  CSliderBar progress_bar;
public:
  void InitContextView();
  virtual void OnInitialUpdate();
protected:
  afx_msg void OnBnClickedRadio1();
  afx_msg BOOL OnEraseBkgnd(CDC* pDC);
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnBnClickedCheck1();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
  afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
  HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
  CButton checbox_1;
  CButton radio_btn_3;
};


