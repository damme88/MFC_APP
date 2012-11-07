#pragma once
#include "SmartComboBox.h"

// CToolBarWithCombo


// class nay se ke thua class CMFCToolBar.
class CToolBarWithCombo : public CMFCToolBar
{
	DECLARE_DYNAMIC(CToolBarWithCombo)
public:
	CToolBarWithCombo();
	virtual ~CToolBarWithCombo();

protected:
	DECLARE_MESSAGE_MAP()

public:
  CSmartComboBox m_combo;

public:
  BOOL CreateComboBox(CSmartComboBox& comboBox, UINT index, UINT nID, int Width, int DropHeight);
};


