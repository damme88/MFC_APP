
#include "stdafx.h"
#include "Rebar_And_Bitmap.h"
#include "Address_Combox.h"


// Address_Combox

IMPLEMENT_DYNAMIC(Address_Combox, CComboBoxEx)

Address_Combox::Address_Combox()
{

}

Address_Combox::~Address_Combox()
{
}


BEGIN_MESSAGE_MAP(Address_Combox, CComboBoxEx)
END_MESSAGE_MAP()

HRESULT Address_Combox::get_accName (VARIANT, BSTR *pszzName) {
  CString str_text = __T("Address : ");
  // convert form CString to BSTR. (BSTR is WCHAR style)
  *pszzName = str_text.AllocSysString();
  return S_OK;  // = (HRESUL) 0L. value of long style
}



