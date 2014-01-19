#ifndef TOOLLIB_WINUI_EDIT_CTRL_H_
#define TOOLLIB_WINUI_EDIT_CTRL_H_

#include <toollib/toollib_export.h>

class InchEditCtrl : public CEdit {
 public:
  class Delegate {
  public:
    virtual void GotoDefaultControl(InchEditCtrl *edit_ctrl) {}
    virtual void GotoNextControl(InchEditCtrl *edit_ctrl) {}
    virtual void OnCalculateFormulaFinished(InchEditCtrl *edit_ctrl) {}
  };

  static double CalcValue(CEdit *edit_ctrl);

  InchEditCtrl() : CEdit(), delegate_(NULL), need_calc_(false) {}
  virtual ~InchEditCtrl() {}

  void set_delegate(Delegate *delegate) { delegate_ = delegate; }

 protected:
  afx_msg UINT OnGetDlgCode();
  afx_msg void OnKeyDown(UINT character, UINT count, UINT flags);
  afx_msg void OnChar(UINT character, UINT count, UINT flags);
  afx_msg void OnKillFocus(CWnd *wnd);

  DECLARE_MESSAGE_MAP()

private:
  Delegate *delegate_;
  bool need_calc_;
};

#endif  // TOOLLIB_WINUI_EDIT_CTRL_H_
