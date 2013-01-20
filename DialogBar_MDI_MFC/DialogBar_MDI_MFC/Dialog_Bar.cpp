// Dialog_Bar.cpp : implementation file
//

#include "stdafx.h"
#include "DialogBar_MDI_MFC.h"
#include "Dialog_Bar.h"


// Dialog_Bar

IMPLEMENT_DYNCREATE(Dialog_Bar, CFormView)

Dialog_Bar::Dialog_Bar()
	: CFormView(Dialog_Bar::IDD)
{

}

Dialog_Bar::~Dialog_Bar()
{
}

void Dialog_Bar::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Dialog_Bar, CFormView)
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
