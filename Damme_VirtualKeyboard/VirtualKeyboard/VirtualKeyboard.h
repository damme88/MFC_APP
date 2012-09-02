#include "afxwin.h"
#include "resource.h"
#include "VirtualKeyBox.h"
#define MAX_CHARACTER 27
typedef struct _BUT_KEY{
	CButton cButton;
	TCHAR	szChar;
} BUT_KEY;

/******************************************************************************
* Class Name  : VirtualKeyboard
* Purpose     : Lop nay thuc hien dai dien cho dialog ban phim ao
*             : Duoc ke thua tu lop dialog
*
******************************************************************************/
class VirtualKeyboard:public CDialog
{
public:
  // ham contructors 
	VirtualKeyboard(CWnd *pParent= NULL);
  // Bien liet ke IDD_Dialog = value ID cuar dialog
	enum{IDD_DIALOG = IDD_DIALOG_BOARD};	

protected:
  // Ham thuc hien chuyen doi du lieu 
	virtual void DoDataExchange(CDataExchange *pDX);
	BOOL shfState;   // biến này kiểm tra trạng thái của phím shirt
	BOOL altState;   // Bien nay check status cua key alt
	BOOL CtrlState;  // Tuong tu bien nay cung se check status cua key Ctr

public:
	HICON hIcon;       // 1 bien thuc hien se lay icon duoc tao ra trong resource
	CButton m_ButtonQ; // Cac bien thanh vien cho cac button chu cua kepad
	CButton m_ButtonW;
	CButton m_ButtonE;
	CButton m_ButtonR;
	CButton m_ButtonT;
	CButton m_ButtonY;
	CButton m_ButtonU;
	CButton m_ButtonI;
	CButton m_ButtonO;
	CButton m_ButtonP;
	CButton m_ButtonA;
	CButton m_ButtonS;
	CButton m_ButtonD;
	CButton m_ButtonF;
	CButton m_ButtonG;
	CButton m_ButtonH;
	CButton m_ButtonJ;
	CButton m_ButtonK;
	CButton m_ButtonL;
	CButton m_ButtonZ;
	CButton m_ButtonX;
	CButton m_ButtonC;
	CButton m_ButtonV;
	CButton m_ButtonB;
	CButton m_ButtonN;
	CButton m_ButtonM;
public:
	DECLARE_MESSAGE_MAP() // mot macro de thuc hien anh xa thong diep
                        // neu ko khai bao no thi khong su dung duoc viec
                        // viec anh xa thong diep
  // Ham khoi tao trang thai ban dau cho ban phim 
	virtual BOOL OnInitDialog();
  // ham xu ly su kien khi click vao cac phim 
	afx_msg void OnBnClickedButtonQ();
	afx_msg void OnBnClickedButtonW();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonR();
	afx_msg void OnBnClickedButtonT();
	afx_msg void OnBnClickedButtonY();
	afx_msg void OnBnClickedButtonU();
	afx_msg void OnBnClickedButtonI();
	afx_msg void OnBnClickedButtonO();
	afx_msg void OnBnClickedButtonP();
	afx_msg void OnBnClickedButtonA();
  // ham xu ly khi keo re chuot
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnBnClickedButtonS();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonF();
	afx_msg void OnBnClickedButtonG();
	afx_msg void OnBnClickedButtonH();
	afx_msg void OnBnClickedButtonJ();
	afx_msg void OnBnClickedButtonK();
	afx_msg void OnBnClickedButtonL();
	afx_msg void OnBnClickedButtonZ();
	afx_msg void OnBnClickedButtonX();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonV();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonN();
	afx_msg void OnBnClickedButtonM();	
  // phim enter
	afx_msg void OnBnClickedButtonEnter();	
  // phim space
	afx_msg void OnBnClickedButtonSpace();
	afx_msg void OnBnClickedButtonLwin();
	afx_msg void OnBnClickedButtonLshift();
	afx_msg void ShiftPress();
	afx_msg void ShiftRelease();
	afx_msg void OnBnClickedButtonBsp();
	afx_msg void OnBnClickedButtonArleft();
	afx_msg void OnBnClickedButtonArup();
	afx_msg void OnBnClickedButtonArright();
	afx_msg void OnBnClickedButtonArdown();
	afx_msg void OnBnClickedButtonTab();
	afx_msg void OnBnClickedButtonAltLeft();
	afx_msg void OnBnClickedButtonCtrlLeft();
	afx_msg void OnBnClickedButtonCap();
};