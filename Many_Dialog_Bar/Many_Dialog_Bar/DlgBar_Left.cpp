// DlgBar_Left.cpp : implementation file
//

#include "stdafx.h"
#include "Many_Dialog_Bar.h"
#include "DlgBar_Left.h"


// DlgBar_Left

IMPLEMENT_DYNCREATE(DlgBar_Left, CFormView)

DlgBar_Left::DlgBar_Left()
	: CFormView(DlgBar_Left::IDD)
{

}

DlgBar_Left::~DlgBar_Left()
{
}

void DlgBar_Left::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DlgBar_Left, CFormView)
END_MESSAGE_MAP()


// DlgBar_Left diagnostics

#ifdef _DEBUG
void DlgBar_Left::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DlgBar_Left::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DlgBar_Left message handlers
