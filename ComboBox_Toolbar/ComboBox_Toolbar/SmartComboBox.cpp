// SmartComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBox_Toolbar.h"
#include "SmartComboBox.h"


// CSmartComboBox

IMPLEMENT_DYNAMIC(CSmartComboBox, CComboBox)

CSmartComboBox::CSmartComboBox()
{

}

CSmartComboBox::~CSmartComboBox()
{
}

BEGIN_MESSAGE_MAP(CSmartComboBox, CComboBox)
  ON_WM_CREATE()
END_MESSAGE_MAP()


int CSmartComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CComboBox::OnCreate(lpCreateStruct) == -1) {
    return -1;
  }
  return 0;
}

void CSmartComboBox::AddStringCombo(LPCTSTR str) {
  CComboBox::AddString(str);
}

void CSmartComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) {
  return;
}

int CSmartComboBox::CompareItem(LPCOMPAREITEMSTRUCT) {
 return 1;
}

void CSmartComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) {
  CString str;
	long int num = GetCount();
  if (!num || lpDrawItemStruct->itemID >= num ||lpDrawItemStruct->itemID < 0) {
    str = '\0';
    return;
  } else {
	  str = (LPCTSTR)lpDrawItemStruct->itemData; //str se lay cac string item duoc create trong combobox
	}

  CDC dc;
  ITEMDATA* pItemData = NULL;
  dc.Attach(lpDrawItemStruct->hDC); 

  COLORREF crOldTextColor = dc.GetTextColor(); // lay mau cua text
  COLORREF crOldBkColor = dc.GetBkColor();     // get color background

  if ((lpDrawItemStruct->itemAction | ODA_SELECT) &&
    (lpDrawItemStruct->itemState  & ODS_SELECTED))       
  {                                                       
    dc.SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));  // set color for text
    dc.SetBkColor(::GetSysColor(COLOR_HIGHLIGHT)); 
    dc.FillSolidRect(&lpDrawItemStruct->rcItem, ::GetSysColor(COLOR_HIGHLIGHT)); 
  }
  else
    dc.FillSolidRect(&lpDrawItemStruct->rcItem, crOldBkColor);

  CRect rect(lpDrawItemStruct->rcItem);
  rect.DeflateRect(1,0);

  HICON hIcon = NULL;
  ITEMDATA iData;
  if (myMap.Lookup(lpDrawItemStruct->itemID,iData))
  {
	  hIcon = iData.icon;
  }
  // draw icon
  DrawIconEx(dc.GetSafeHdc(),rect.left,rect.top, hIcon, 0, 0, 0, NULL, DI_NORMAL);
  rect.left += 30;  // space between text and icon

  // Draw the text.
  dc.DrawText(
    str,
	    -1,
    &rect,
    DT_LEFT|DT_SINGLELINE|DT_VCENTER);

  // Reset the background color and the text color back to their
  // original values.
  dc.SetTextColor(crOldTextColor);
  dc.SetBkColor(crOldBkColor);
  dc.Detach();
}

// Ham nay se cho phep set icon trong combobox chi so item va id cua icon 
void CSmartComboBox::SetIconCombo(int iItem, int iconId)
{
	HICON hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(iconId),IMAGE_ICON,23,23,0);   // lay hicon tu id resource voi size la 23, 23

	ITEMDATA iData; 
	myMap.Lookup(iItem,iData);
  iData.icon = hIcon;
	myMap.SetAt(iItem, iData);
	Invalidate();
}
// CSmartComboBox message handlers


