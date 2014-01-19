
// ComStudy_OpenIEDlg.h : header file
//

#pragma once


// ComStudy_OpenIEDlg dialog
class ComStudy_OpenIEDlg : public CDialogEx
{
// Construction
public:
	ComStudy_OpenIEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_COMSTUDY_OPENIE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
  afx_msg void OnHandleOpenIE();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
  CString link_web_;
};
