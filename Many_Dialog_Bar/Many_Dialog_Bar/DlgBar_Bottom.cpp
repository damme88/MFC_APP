// DlgBar_Bottom.cpp : implementation file
//

#include "stdafx.h"
#include "Many_Dialog_Bar.h"
#include "DlgBar_Bottom.h"


// DlgBar_Bottom

IMPLEMENT_DYNCREATE(DlgBar_Bottom, CFormView)

DlgBar_Bottom::DlgBar_Bottom()
	: CFormView(DlgBar_Bottom::IDD)
{

}

DlgBar_Bottom::~DlgBar_Bottom()
{
}

void DlgBar_Bottom::DoDataExchange(CDataExchange* pDX)
{
  CFormView::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_LIST1, List_Control_);
}

BEGIN_MESSAGE_MAP(DlgBar_Bottom, CFormView)
END_MESSAGE_MAP()


// DlgBar_Bottom diagnostics

#ifdef _DEBUG
void DlgBar_Bottom::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DlgBar_Bottom::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DlgBar_Bottom message handlers

void DlgBar_Bottom::OnInitialUpdate() {
  CFormView::OnInitialUpdate();
  DWORD dwstyle = List_Control_.GetExtendedStyle();
  List_Control_.SetExtendedStyle(dwstyle | LVS_EX_FULLROWSELECT |
                                 LVS_EX_GRIDLINES| LVS_EX_CHECKBOXES);
  List_Control_.InsertColumn(0, L"", LVCFMT_LEFT, 50); 
  List_Control_.InsertColumn(1, L"col_1", LVCFMT_LEFT, 80); 
  List_Control_.InsertColumn(2, L"col_2", LVCFMT_LEFT, 80);
  List_Control_.InsertColumn(2, L"col_2", LVCFMT_LEFT, 80); 

  for (unsigned int i = 0; i < 10; i++) {
    CString str_col_0 = L"";
    // make rows for one colum;
    List_Control_.InsertItem(i, str_col_0);

    char str_num[3];
    itoa(i, str_num, 10);

    // make rows for two colum;
    CString str_col_1 = L"Item ";
    str_col_1 += (CString)str_num;
    List_Control_.SetItemText(i, 1, str_col_1);
    
    // make rows for two colum;
    CString str_col_2 = L"Concept_";
    str_col_2 += (CString) str_num;
    List_Control_.SetItemText(i, 2, str_col_2);
  }
}