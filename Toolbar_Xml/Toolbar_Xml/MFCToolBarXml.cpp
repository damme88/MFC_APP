// MFCToolBarXml.cpp : implementation file
//

#include "stdafx.h"
#include "Toolbar_Xml.h"
#include "MFCToolBarXml.h"


// CMFCToolBarXml

IMPLEMENT_DYNAMIC(CMFCToolBarXml, CMFCToolBar)

CMFCToolBarXml::CMFCToolBarXml()
{
  count_toolbar_ = 0;
  size_of_image_.cx = 32;
  size_of_image_.cy = 32;
}

CMFCToolBarXml::~CMFCToolBarXml()
{

}


BEGIN_MESSAGE_MAP(CMFCToolBarXml, CMFCToolBar)
END_MESSAGE_MAP()


void CMFCToolBarXml::LoadToolBarXml(std::string str_data_xml, SIZE button_size, int index_toolbar, int count) {
  count_toolbar_ = count;
  data_xml.resize(count);
  GetSubString(str_data_xml);
  GetStringItem();
  OnHandleMapID(index_toolbar);

  SetButtonXml(index_toolbar,  button_size);
  CString str;
  PaserXml(index_toolbar);
  for (int j = 0; j<data_xml[index_toolbar].button.size(); j++) {
    str = data_xml[index_toolbar].button[j].c_str();
    SetImageXml(str, size_of_image_);
  }
}


void CMFCToolBarXml::GetSubString(std::string str) {
  int k = 0;
  if (count_toolbar_ ==0) {
    return;
  } else {
    sub_str.resize(count_toolbar_);
    int pos = 0;
    int begin_pos = 0;
    int end_pos  = 0;
    while (begin_pos != -1 || end_pos != -1) {
      begin_pos = str.find("<toolbar", pos);
      end_pos = str.find("</toolbar>", pos);
      for (int i = begin_pos; i<end_pos; i++) {
        sub_str[k] += str[i];
      }
      k++;
      pos = end_pos+1;
    }
  }
}

std::string CMFCToolBarXml::ReverseString(std::string str) {
  std::string str_standar;
  for (int i = str.length()-1; i >=0; i-- ) {
    str_standar += str[i];
  }
  return str_standar;
}

void CMFCToolBarXml::GetStringItem() {
  int key_str_pos = 0;
  int item_str_pos = 0;
  int pos = 0;
  int k = 0;
  number_item.resize(count_toolbar_);
  for (int i = 0; i<count_toolbar_; i++) {
    for (int j = 0; j <sub_str[i].length(); j++) {
      if (sub_str[i][j] == '/') {
        number_item[i] ++;
      }
    }
      data_xml[i].button.resize(number_item[i]);
  }

  for (int i =0; i<count_toolbar_; i++) {
      key_str_pos = sub_str[i].find('"', 0);
      if (key_str_pos == -1) {
        data_xml[i].name = L"";
      } else {
        while (sub_str[i][key_str_pos+1] != '"' ) {
          data_xml[i].name += sub_str[i][key_str_pos+1];
          key_str_pos++;
        }
      }
    }

  for(int i = 0; i<count_toolbar_; i++) {
    for (int j = 0; j<number_item[i]; j++) {
      item_str_pos = sub_str[i].find("</button>", pos);
      k = item_str_pos;
      if (item_str_pos == -1)
        data_xml[i].button[j] = "";
      else {
         while (sub_str[i][k-1] != '>') {
           data_xml[i].button[j] += sub_str[i][k-1];
           k--;
         }
      }
      pos = item_str_pos +1;
      data_xml[i].button[j] = ReverseString(data_xml[i].button[j]);
    }
    pos = 0;
  }
}



void CMFCToolBarXml::OnHandleMapID(int index) {
  for (int j = 0 ; j<data_xml[index].button.size(); j++ ) {
  if (data_xml[index].button[j] == "file_new")
    inspect_xml_["file_new"] = ID_FILE_TOOLBAR_NEW;
  if (data_xml[index].button[j] == "file_open")
    inspect_xml_["file_open"] = ID_FILE_TOOLBAR_OPEN;
  if (data_xml[index].button[j] == "file_save")
    inspect_xml_["file_save"] = ID_FILE_TOOLBAR_SAVE;
  if (data_xml[index].button[j]== "file_cut")
    inspect_xml_["file_cut"] = ID_FILE_TOOLBAR_CUT;
  if (data_xml[index].button[j] == "file_copy")
    inspect_xml_["file_copy"] = ID_FILE_TOOLBAR_COPY;
  if (data_xml[index].button[j] == "file_paste")
    inspect_xml_["file_paste"] = ID_FILE_TOOLBAR_PASTE;
  if (data_xml[index].button[j] == "file_printer")
    inspect_xml_["file_printer"] = ID_FILE_TOOLBAR_PRINTER;
  if (data_xml[index].button[j] == "file_help")
    inspect_xml_["file_help"] = ID_FILE_TOOLBAR_HELP;
  if (data_xml[index].button[j] == "show1")
    inspect_xml_["show1"] = ID_SHOW1;
  if (data_xml[index].button[j] == "show2")
    inspect_xml_["show2"] = ID_SHOW2;
    if (data_xml[index].button[j] == "show3")
    inspect_xml_["show3"] = ID_SHOW3;
  if (data_xml[index].button[j] == "show4")
    inspect_xml_["show4"] = ID_SHOW4;
   }
}


void CMFCToolBarXml::PaserXml(int index) {
  for (int j = 0; j<data_xml[index].button.size(); j++) {
    data_xml[index].button[j] = data_xml[index].button[j] + ".bmp";
  }
}


void CMFCToolBarXml::SetButtonXml(int index_toolbar, SIZE button_size) {
  std::fstream check_file;
  std::string bitmap_name = "";
  std::string moudle_folder_path = CStringA(GetPathModule());
  static long index_image = 0;
  SetSizes(button_size, size_of_image_);
  for (int j = 0 ; j< data_xml[index_toolbar].button.size(); j ++) {
    bitmap_name = moudle_folder_path + "\\res\\" + data_xml[index_toolbar].button[j] + ".bmp";
    check_file.open(bitmap_name, std::ios::in);
    if (check_file.fail() != TRUE) {
      if (data_xml[index_toolbar].button[j] == "separator") { 
        InsertSeparator(j);
      } else {
        CMFCToolBarButton button(inspect_xml_[data_xml[index_toolbar].button[j]], index_image, NULL, TRUE, FALSE);
        InsertButton(button);
      }
      index_image++;
      check_file.close();
    }
  }
}

void CMFCToolBarXml::SetImageXml(LPCTSTR bitmap_name, SIZE image_size) {
 CString path_file = GetPathModule() + L"\\res\\" + bitmap_name;
 static CMFCToolBarImages *pUserImage_ = CMFCToolBar::GetImages();
  SIZE size;
  size = image_size;
    HBITMAP bitmap = (HBITMAP)LoadImage(AfxGetResourceHandle(), path_file,
      IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if (bitmap == NULL) {
      return;
    }
    pUserImage_->SetImageSize(size);
    pUserImage_->AddImage(bitmap, TRUE);
}


CString CMFCToolBarXml::GetPathModule() {
  CString full_path = L"";
  ::GetModuleFileName(NULL, full_path.GetBufferSetLength(MAX_PATH+1), MAX_PATH);
  full_path = full_path.Left(full_path.ReverseFind('\\'));
  return full_path;
}