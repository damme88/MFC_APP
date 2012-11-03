#pragma once
#include <map>

// CMFCToolBarXml

struct toolbar_data {
  std::wstring name;
  std::vector<std::string> button;
};

class CMFCToolBarXml : public CMFCToolBar
{
	DECLARE_DYNAMIC(CMFCToolBarXml)

public:
	CMFCToolBarXml();
	virtual ~CMFCToolBarXml();
private:
   long count_toolbar_;
   CString *pstr_data_;
  typedef std::map<std::string, UINT> CmdMap;
  CmdMap inspect_xml_;
  std::vector<std::string> sub_str;
  std::vector<toolbar_data> data_xml;
  std::vector<unsigned int > number_item;
  SIZE size_of_image_;
protected:
	DECLARE_MESSAGE_MAP()

public:
  void LoadToolBarXml(std::string str_data_xml, SIZE button_size, int index_toolbar, int count);
  void PaserXml(int index);
  void SetButtonXml(int index, SIZE button_size);
  void SetImageXml(LPCTSTR image_name, SIZE image_size);
  void OnHandleMapID(int index);
  void GetSubString(std::string str);
  std::string ReverseString(std::string str);
  static CString GetPathModule();
  void GetStringItem();
};


