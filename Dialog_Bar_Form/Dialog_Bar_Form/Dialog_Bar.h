#pragma once
#include "resource.h"


// Dialog_Bar form view
class CDialog_Bar_FormDoc;

class Dialog_Bar : public CFormView
{
	DECLARE_DYNCREATE(Dialog_Bar)

protected:
	Dialog_Bar();           // protected constructor used by dynamic creation
	virtual ~Dialog_Bar();

public:
	enum { IDD = IDD_DIALOG_BAR };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
 virtual void OnInitialUpdate();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
  enum {IDD_DIALOG = IDD_DIALOG_BAR};
  CDialog_Bar_FormDoc *GetDocument();
  CView *GetDialogBarFormView();
  BOOL UpdateSCaling();
  afx_msg void OnHandleCheckRotation();
  afx_msg void OnPaint();

private:
  BOOL rotation_;
  CButton rotation_checkbox_;


};


