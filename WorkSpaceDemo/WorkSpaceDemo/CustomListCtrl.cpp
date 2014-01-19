// CustomListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "CustomListCtrl.h"


// CustomListCtrl
#define WM_USER__BEGIN_EDIT_OFFSET_VALUE (WM_APP + 4200)
#define WM_USER__END_EDIT_OFFSET_VALUE (WM_APP + 4201)

IMPLEMENT_DYNAMIC(CustomListCtrl, CListCtrl)

CustomListCtrl::CustomListCtrl() :
  clicked_item_(-1),
  clicked_sub_item_(-1),
  editable_column_(-1)
{

}

CustomListCtrl::~CustomListCtrl()
{
}


BEGIN_MESSAGE_MAP(CustomListCtrl, CListCtrl)
  ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
  ON_NOTIFY_REFLECT(NM_DBLCLK, OnNMDoubleClick)
  ON_NOTIFY_REFLECT(NM_CLICK, OnNMClick)
  ON_WM_HSCROLL()
  ON_WM_VSCROLL()
  ON_MESSAGE(WM_TOOLSLOTEDIT_FINISHED, OnToolSlotEditFinished)
END_MESSAGE_MAP()


void CustomListCtrl::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{
  LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW)pNMHDR;

  switch(lplvcd->nmcd.dwDrawStage) {
    case CDDS_PREPAINT: {
      *pResult = CDRF_NOTIFYITEMDRAW;  // ask for item notifications.
      break;
    }
    case CDDS_ITEMPREPAINT: {
      *pResult = CDRF_DODEFAULT;
      int current_item = lplvcd->nmcd.dwItemSpec;
      break;
    }
    default:
      *pResult = CDRF_DODEFAULT;
  }
}

void CustomListCtrl::OnNMDoubleClick(NMHDR *pNMHDR, LRESULT *pResult) {
  NM_LISTVIEW *nm_list_view = (NM_LISTVIEW *)pNMHDR;
  if (!nm_list_view)
    return;

  int item = nm_list_view->iItem;
  int sub_item = nm_list_view->iSubItem;

  bool can_edit = (sub_item == editable_column_);

  if (can_edit) {
    clicked_item_ = item;
    clicked_sub_item_ = sub_item;

    StartEdit();
  }
  *pResult = 0;
}

void CustomListCtrl::OnNMClick(NMHDR *nmhdr, LRESULT *result) {
  EndEdit();

  *result = 0;
}

void CustomListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar) {
  EndEdit();

  CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CustomListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar) {
  EndEdit();

  CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CustomListCtrl::OnSize(UINT nType, int cx, int cy) {
  CListCtrl::OnSize(nType, cx, cy);
  EndEdit();
}

LRESULT CustomListCtrl::OnToolSlotEditFinished(WPARAM wParam, LPARAM /*lParam*/) {
  EndEdit((BOOL)wParam);

  return FALSE;
}

void CustomListCtrl::StartEdit() {
  if (clicked_item_ >= 0 &&+
      clicked_sub_item_ >= 0) {
    CRect item_rect;
    GetSubItemRect(clicked_item_, clicked_sub_item_, LVIR_BOUNDS, item_rect);

    item_rect.InflateRect(0, 2, 0, 2);

    edit_.Create(WS_VISIBLE | WS_CHILD | WS_BORDER,
                 item_rect,
                 this,
                 1);

    edit_.SetFont(GetFont());

    CString str = GetItemText(clicked_item_, clicked_sub_item_);

    edit_.SetWindowText(str);
    edit_.SetSel(0, -1, TRUE);
    edit_.SetFocus();

    // Tell OptimizePathDlg that offset value is editting and the dialog
    // will prevent return/escape key to close it.
    GetParent()->SendMessage(WM_USER__BEGIN_EDIT_OFFSET_VALUE, 0, 0);
  }
}

void CustomListCtrl::EndEdit(const BOOL does_commit /*= TRUE*/) {
  if (edit_.GetSafeHwnd() != NULL) {
    if (does_commit) {
      CString old_item;
      GetItemText(clicked_item_, clicked_sub_item_);

      CString str;
      edit_.GetWindowText(str);
      float val = _tstof(str);
      edit_.SetWindowText(str);

      CString new_item;
      edit_.GetWindowText(new_item);
      if (0 != new_item.Compare(old_item)) {
        SetItemText(clicked_item_, clicked_sub_item_, new_item);
      }
    }

    edit_.DestroyWindow();
    clicked_item_ = clicked_sub_item_ = -1;
    // End editing offset value, dialog can close by press return/escape key.
    GetParent()->SendMessage(WM_USER__END_EDIT_OFFSET_VALUE, 0, 0);
  }
}

void CustomListCtrl::SetDataListView(unsigned int IDTab,
                       std::vector<CString> id_list,
                       std::vector<CString> one_value_list,
                       std::vector<CString> two_value_list) {


  data_list_view_.tab_control = IDTab;
  data_list_view_.id_list = id_list;
  data_list_view_.one_value_list = one_value_list;
  data_list_view_.two_value_list = two_value_list;
}
// CustomListCtrl message handlers


