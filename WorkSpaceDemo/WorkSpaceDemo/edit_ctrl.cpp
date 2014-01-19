#include "edit_ctrl.h"

#include <string>

#include "base/string_utls.h"

#include "toollib/winui/winui_utls.h"

typedef bool (*CalcParser)(std::string, double *, std::string *);

BEGIN_MESSAGE_MAP(InchEditCtrl, CEdit)
  ON_WM_GETDLGCODE()
  ON_WM_KEYDOWN()
  ON_WM_CHAR()
  ON_WM_KILLFOCUS()
END_MESSAGE_MAP()

double InchEditCtrl::CalcValue(CEdit *edit_ctrl) {
  CString str;
  edit_ctrl->GetWindowText(str);
  double val = 0.0;
  std::string msg;
  HINSTANCE hmodule = NULL;
#ifdef WIN64
#if (TOOLLIB_VERSION > 1300)
  hmodule = ::LoadLibrary(_T("CalcParser_x64.dll"));
#else
  // Version 1.3 - Load in Dll folder of GTANG
  hmodule = ::LoadLibrary(_T("Dll\\CalcParser_x64.dll"));
#endif
#else
  // WIN32
#if (TOOLLIB_VERSION > 1300)
  hmodule = ::LoadLibrary(_T("CalcParser.dll"));
#else
  // Version 1.3 - Load in Dll folder of GTANG
  hmodule = ::LoadLibrary(_T("Dll\\CalcParser.dll"));
#endif
#endif  // WIN64

  bool ok = false;
  if (hmodule) {
    CalcParser proc = (CalcParser)::GetProcAddress(hmodule, "CalcParse");
    if (proc) {
      std::string input_str = base::StringUtls::wstos(str.GetString());
      ok = proc(input_str, &val, &msg);
    }

    ::FreeLibrary(hmodule);
  }
  if (!ok) {
    val = WinuiUtls::GetDoubleFromEdit(*edit_ctrl);
  }

  return val;
}


UINT InchEditCtrl::OnGetDlgCode() {
  UINT ret = CEdit::OnGetDlgCode() | DLGC_WANTALLKEYS;

  return ret;
}

void InchEditCtrl::OnChar(UINT character, UINT count, UINT flags) {
  need_calc_ = true;

  CEdit::OnChar(character, count, flags);
}

void InchEditCtrl::OnKeyDown(UINT character, UINT count, UINT flags) {
  if (character == VK_RETURN ||
      character == VK_TAB) {
    if (need_calc_) {
      double val = CalcValue(this);
      WinuiUtls::DisplayDoubleOnEdit(*this, val);
      if (delegate_)
        delegate_->OnCalculateFormulaFinished(this);
    }

    if (delegate_ && (character == VK_RETURN))
      delegate_->GotoDefaultControl(this);
    if (delegate_ && (character == VK_TAB))
      delegate_->GotoNextControl(this);
  }

  CEdit::OnKeyDown(character, count, flags);
}

 void InchEditCtrl::OnKillFocus(CWnd *wnd) {
   if (need_calc_) {
     double val = CalcValue(this);
     WinuiUtls::DisplayDoubleOnEdit(*this, val);
     if (delegate_)
        delegate_->OnCalculateFormulaFinished(this);
   }

   CEdit::OnKillFocus(wnd);
 }
