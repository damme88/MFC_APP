// Dialog_Bar.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Bar_Form.h"
#include "Dialog_Bar.h"
#include "MainFrm.h"

// Dialog_Bar

IMPLEMENT_DYNCREATE(Dialog_Bar, CFormView)

Dialog_Bar::Dialog_Bar()
	: CFormView(Dialog_Bar::IDD_DIALOG) {
  rotation_ = FALSE;
}

Dialog_Bar::~Dialog_Bar() {
}

void Dialog_Bar::DoDataExchange(CDataExchange* pDX) {
	CFormView::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_CHECKBOX_ROTATION, rotation_checkbox_);
}

BEGIN_MESSAGE_MAP(Dialog_Bar, CFormView)
  ON_WM_PAINT()
  ON_BN_CLICKED(IDC_CHECKBOX_ROTATION, OnHandleCheckRotation)
END_MESSAGE_MAP()


// Dialog_Bar diagnostics

#ifdef _DEBUG
void Dialog_Bar::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Dialog_Bar::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Dialog_Bar message handlers

void Dialog_Bar::OnPaint() {
	// Device context for painting
	CPaintDC dc(this); 
	// Options are stored in Application
  CDialog_Bar_FormApp *pApp = (CDialog_Bar_FormApp *)AfxGetApp();
	CRect rect;
}

void Dialog_Bar::OnInitialUpdate() {
	CFormView::OnInitialUpdate();
}


CView *Dialog_Bar::GetDialogBarFormView() {
	CDialog_Bar_FormApp *pApp = (CDialog_Bar_FormApp *)AfxGetApp();
	CMainFrame *pMainFrame = (CMainFrame *)pApp->m_pMainWnd;
  CView *pView = (CView *)pMainFrame->m_wndSplitter.GetPane(0, 1);
	return pView;
}

void Dialog_Bar::OnHandleCheckRotation() {
  int a =5;
}