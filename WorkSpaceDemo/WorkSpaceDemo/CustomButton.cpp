// CustomButton.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "CustomButton.h"


// CustomButton

IMPLEMENT_DYNAMIC(CustomButton, CButton)

CustomButton::CustomButton()
{
  m_hCursor = NULL;
}

CustomButton::~CustomButton()
{
  DestroyCursor(m_hCursor);
}


BEGIN_MESSAGE_MAP(CustomButton, CButton)
 ON_WM_SETCURSOR()
END_MESSAGE_MAP()



BOOL CustomButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) {
	m_hCursor = ::LoadCursor(NULL,IDC_ARROW);
	SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)m_hCursor);		
  return CButton::OnSetCursor(pWnd, nHitTest, message);
}
// CustomButton message handlers


