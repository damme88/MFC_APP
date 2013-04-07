// DlgBar_Sub.cpp : implementation file
//

#include "stdafx.h"
#include "Many_Dialog_Bar.h"
#include "DlgBar_Sub.h"


// DlgBar_Sub

IMPLEMENT_DYNCREATE(DlgBar_Sub, CFormView)

DlgBar_Sub::DlgBar_Sub()
	: CFormView(DlgBar_Sub::IDD)
{

}

DlgBar_Sub::~DlgBar_Sub()
{
}

void DlgBar_Sub::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DlgBar_Sub, CFormView)
END_MESSAGE_MAP()


// DlgBar_Sub diagnostics

#ifdef _DEBUG
void DlgBar_Sub::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DlgBar_Sub::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DlgBar_Sub message handlers
