#pragma once
#include <vector>

#define WM_TOOLSLOTEDIT_FINISHED (WM_APP + 04101)

struct DataListView {
  unsigned int tab_control;
  std::vector<CString> id_list;
  std::vector<CString> one_value_list;
  std::vector<CString> two_value_list;
};



// CustomListCtrl
class CustomListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CustomListCtrl)

public:
	CustomListCtrl();
	virtual ~CustomListCtrl();
  void set_editable_column(const int column) {
    editable_column_ = column;
  }

  enum IDTab {
    LOCAL_TAB = 1,
    COMMON_TAB = 2,
    SYSTEM_TAB = 3,
    STACK_TAB = 4,
  };


  void SetDataListView(unsigned int IDTab,
                       std::vector<CString> id_list,
                       std::vector<CString> one_value_list,
                       std::vector<CString> two_value_list);

  DataListView GetDataListView() {return data_list_view_;}

protected:
  void StartEdit(void);
  void EndEdit(const BOOL does_commit = TRUE);

private:
  int editable_column_;
  int clicked_item_,
  clicked_sub_item_;
  CEdit edit_;

  DataListView data_list_view_;

protected:
  afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
  afx_msg void OnNMDoubleClick(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void OnNMClick(NMHDR *nmhdr, LRESULT *result);
  afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);
  afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);
  afx_msg void OnSize(UINT nType, int cx, int cy);
  // afx_msg void OnEnChangeEdit();
  afx_msg LRESULT OnToolSlotEditFinished(WPARAM wParam, LPARAM /*lParam*/);

	DECLARE_MESSAGE_MAP()
};


