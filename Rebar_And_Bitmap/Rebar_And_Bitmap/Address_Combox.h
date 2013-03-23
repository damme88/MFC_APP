#pragma once
/******************************************************************************
* Name File   : Address_Combox
* Purpose     : Define Address_Combox Class to make Combox Address toolbar
* Maker       : Damme88
* Role        : Electronic_Communication_Engineer_And_Graphics_C++_Developer
* Address     : Phamtoanbonmat@gmail.com
* Language    : Visual C++ 2010. MFC library
* OS Run      : Windows 7 Ultimate x86.
*******************************************************************************/

// Address_Combox
class Address_Combox : public CComboBoxEx
{
	DECLARE_DYNAMIC(Address_Combox)

public:
	Address_Combox();
	virtual ~Address_Combox();

protected:
	DECLARE_MESSAGE_MAP()
public:
  virtual HRESULT get_accName(VARIANT , BSTR *pszName);
};


