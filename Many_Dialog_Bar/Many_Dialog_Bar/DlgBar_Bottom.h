#pragma once
#include "afxcmn.h"



// DlgBar_Bottom form view

class DlgBar_Bottom : public CFormView
{
	DECLARE_DYNCREATE(DlgBar_Bottom)

protected:
	DlgBar_Bottom();           // protected constructor used by dynamic creation
	virtual ~DlgBar_Bottom();

public:
	enum { IDD = IDD_DLGBAR_BOTTOM };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual void OnInitialUpdate();
	DECLARE_MESSAGE_MAP()
  CListCtrl List_Control_;
};


