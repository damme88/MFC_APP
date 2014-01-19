#pragma once
#include "resource.h"

// CustomButton

class CustomButton : public CButton
{
	DECLARE_DYNAMIC(CustomButton)

public:
	CustomButton();
	virtual ~CustomButton();
protected:
  HCURSOR m_hCursor;
protected:
  afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	DECLARE_MESSAGE_MAP()
};


