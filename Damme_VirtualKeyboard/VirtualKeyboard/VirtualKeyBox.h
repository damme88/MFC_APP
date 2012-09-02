#pragma once
#include "afxwin.h"


// CVirtualKeyBox dialog
// Them mot hop thoai nua la CVrtualKeyBox duoc khoi tao
class CVirtualKeyBox : public CDialog
{
	DECLARE_DYNAMIC(CVirtualKeyBox)

public:
	CVirtualKeyBox(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVirtualKeyBox();

// Dialog Dataoihklop
	enum { IDD = IDD_DIALOG_BOARD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonS();
	CButton m_ButtonA;
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonQ();
	afx_msg void shiftPress();
	CButton m_ButtonZ;
	CButton m_b;
	afx_msg void OnBnClickedButton82();
	afx_msg void OnBnClickedButtonArleft();
	afx_msg void OnBnClickedButtonAltLeft();
	afx_msg void OnBnClickedButton97();
};

/*CVirtualKeyBox myVirtualKeyBox;*/