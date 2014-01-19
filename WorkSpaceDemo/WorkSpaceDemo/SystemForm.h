#pragma once
#include "resource.h"
#include "CustomButton.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "CustomListCtrl.h"

// SystemForm form view

class SystemForm : public CFormView
{
	DECLARE_DYNCREATE(SystemForm)

public:
	SystemForm();           // protected constructor used by dynamic creation
	virtual ~SystemForm();

public:
	enum { IDD = IDD_SYSTEMFORM };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
  BOOL Create(CWnd* pParent);
  virtual void OnInitialUpdate();
protected:
  CustomButton button_1;
  CustomListCtrl system_list_;

protected:
  afx_msg void HandleButton1();
  virtual void PostNcDestroy();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) ;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

};


