#pragma once


struct ITEMDATA {
 HICON icon;
 UINT iconID;
};

// CSmartComboBox Se la mot class ke thua class CComboBox
// Muc dich de overwrite lai 1 so ham co chuc nang rieng
// vi du nhu la seticon cho comboBox va Add item cho comboBox
class CSmartComboBox : public CComboBox
{
	DECLARE_DYNAMIC(CSmartComboBox)

public:
	CSmartComboBox();
	virtual ~CSmartComboBox();

public:
  void AddStringCombo(LPCTSTR str);
  void SetIconCombo(int item, int iconID);

protected:
  // DrawItem chinh la ham quan trong nhat de ve ra cac item va cac icon
  virtual void DrawItem (LPDRAWITEMSTRUCT lpDrawItemStruct);
  void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
  int CompareItem(LPCOMPAREITEMSTRUCT);

protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  CMap<int, int, ITEMDATA, ITEMDATA>myMap;
protected:
	DECLARE_MESSAGE_MAP()
};


