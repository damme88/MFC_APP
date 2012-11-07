// ToolBarWithCombo.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBox_Toolbar.h"
#include "ToolBarWithCombo.h"


// CToolBarWithCombo

IMPLEMENT_DYNAMIC(CToolBarWithCombo, CMFCToolBar)

CToolBarWithCombo::CToolBarWithCombo()
{

}

CToolBarWithCombo::~CToolBarWithCombo()
{
}


BEGIN_MESSAGE_MAP(CToolBarWithCombo, CMFCToolBar)
END_MESSAGE_MAP()

// ham create nay se cho phep tao ra mot combobox Va combobox nay se duoc mot doi tuong quan ly
// doi tuong nay chinh la doi tuong cua lop CToolBarWithCombo duoc ke thua tu CMFCToolBar
// Phuong phap nay ko su dung ham replacebutton cua lop CMFCToolBar
BOOL CToolBarWithCombo::CreateComboBox(CSmartComboBox& comboBox, UINT index, UINT nID, int nWidth, int nDropHeight) {
  SetButtonInfo(index, nID, TBBS_SEPARATOR, nWidth);
  CRect rect;
  GetItemRect(index, rect);
  rect.top = 1;
  rect.bottom = rect.top + nDropHeight;
  if (!comboBox.Create(CBS_DROPDOWNLIST|CBS_OWNERDRAWVARIABLE|WS_VISIBLE, rect, this, nID))
  {
    TRACE("Failed to create comboBox");
    return TRUE;
  }
}

// CToolBarWithCombo message handlers


