#include "VirtualKeyboard.h"
#include "atlbase.h"

// ham khoi tao contrucstor
VirtualKeyboard::VirtualKeyboard(CWnd *pParent/* = NULL */)
:CDialog(VirtualKeyboard::IDD_DIALOG, pParent){
	/*ShowWindow(SW_SHOWNOACTIVATE);*/
	shfState = FALSE;
	altState = FALSE;
	CtrlState = FALSE;
	
}

// ham khoi tao status ban dau OnInit
BOOL VirtualKeyboard::OnInitDialog()
{
  // thuc hien viec load icon trong resour de tao len icon cho ban phim
	hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	SetIcon(hIcon, TRUE);
	SetIcon(hIcon, FALSE);
	return TRUE;
}

// ham tu dong chuyen doi du lieu 
void VirtualKeyboard::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
  // value cua IDC_BUTTON_Q va trang thai cua bien m_ButtonQ update
	DDX_Control(pDX, IDC_BUTTON_Q,m_ButtonQ );
	DDX_Control(pDX, IDC_BUTTON_W,m_ButtonW );	
	DDX_Control(pDX, IDC_BUTTON_E,m_ButtonE );	
	DDX_Control(pDX, IDC_BUTTON_R,m_ButtonR );	
	DDX_Control(pDX, IDC_BUTTON_T,m_ButtonT );	
	DDX_Control(pDX, IDC_BUTTON_Y,m_ButtonY );	
	DDX_Control(pDX, IDC_BUTTON_U,m_ButtonU );	
	DDX_Control(pDX, IDC_BUTTON_I,m_ButtonI );	
	DDX_Control(pDX, IDC_BUTTON_O,m_ButtonO );	
	DDX_Control(pDX, IDC_BUTTON_P,m_ButtonP );	
	DDX_Control(pDX, IDC_BUTTON_A,m_ButtonA );	
	DDX_Control(pDX, IDC_BUTTON_S,m_ButtonS );	
	DDX_Control(pDX, IDC_BUTTON_D,m_ButtonD );	
	DDX_Control(pDX, IDC_BUTTON_F,m_ButtonF );	
	DDX_Control(pDX, IDC_BUTTON_G,m_ButtonG );	
	DDX_Control(pDX, IDC_BUTTON_H,m_ButtonH );	
	DDX_Control(pDX, IDC_BUTTON_J,m_ButtonJ );	
	DDX_Control(pDX, IDC_BUTTON_K,m_ButtonK );	
	DDX_Control(pDX, IDC_BUTTON_L,m_ButtonL );	
	DDX_Control(pDX, IDC_BUTTON_Z,m_ButtonZ );	
	DDX_Control(pDX, IDC_BUTTON_X,m_ButtonX );	
	DDX_Control(pDX, IDC_BUTTON_C,m_ButtonC );	
	DDX_Control(pDX, IDC_BUTTON_V,m_ButtonV );	
	DDX_Control(pDX, IDC_BUTTON_B,m_ButtonB );	
	DDX_Control(pDX, IDC_BUTTON_N,m_ButtonN );
	DDX_Control(pDX, IDC_BUTTON_M,m_ButtonM );	
}

// bat dau anh xa thong diep 
BEGIN_MESSAGE_MAP(VirtualKeyboard, CDialog)
  // neu 1 key duoc kich do la phim Q thi goi ham Xu ly phim Q. Dong thoi
  // luc nay value cua m_ButtonQ  duoc cap nhat gia tri
ON_BN_CLICKED(IDC_BUTTON_Q, &VirtualKeyboard::OnBnClickedButtonQ)
ON_BN_CLICKED(IDC_BUTTON_W, &VirtualKeyboard::OnBnClickedButtonW)
ON_BN_CLICKED(IDC_BUTTON_E, &VirtualKeyboard::OnBnClickedButtonE)
ON_BN_CLICKED(IDC_BUTTON_R, &VirtualKeyboard::OnBnClickedButtonR)
ON_BN_CLICKED(IDC_BUTTON_T, &VirtualKeyboard::OnBnClickedButtonT)
ON_BN_CLICKED(IDC_BUTTON_Y, &VirtualKeyboard::OnBnClickedButtonY)
ON_BN_CLICKED(IDC_BUTTON_U, &VirtualKeyboard::OnBnClickedButtonU)
ON_BN_CLICKED(IDC_BUTTON_I, &VirtualKeyboard::OnBnClickedButtonI)
ON_BN_CLICKED(IDC_BUTTON_O, &VirtualKeyboard::OnBnClickedButtonO)
ON_BN_CLICKED(IDC_BUTTON_P, &VirtualKeyboard::OnBnClickedButtonP)
ON_BN_CLICKED(IDC_BUTTON_A, &VirtualKeyboard::OnBnClickedButtonA)
ON_WM_MOUSEMOVE()
ON_BN_CLICKED(IDC_BUTTON_S, &VirtualKeyboard::OnBnClickedButtonS)
ON_BN_CLICKED(IDC_BUTTON_D, &VirtualKeyboard::OnBnClickedButtonD)
ON_BN_CLICKED(IDC_BUTTON_F, &VirtualKeyboard::OnBnClickedButtonF)
ON_BN_CLICKED(IDC_BUTTON_G, &VirtualKeyboard::OnBnClickedButtonG)
ON_BN_CLICKED(IDC_BUTTON_H, &VirtualKeyboard::OnBnClickedButtonH)
ON_BN_CLICKED(IDC_BUTTON_J, &VirtualKeyboard::OnBnClickedButtonJ)
ON_BN_CLICKED(IDC_BUTTON_K, &VirtualKeyboard::OnBnClickedButtonK)
ON_BN_CLICKED(IDC_BUTTON_L, &VirtualKeyboard::OnBnClickedButtonL)
ON_BN_CLICKED(IDC_BUTTON_Z, &VirtualKeyboard::OnBnClickedButtonZ)
ON_BN_CLICKED(IDC_BUTTON_X, &VirtualKeyboard::OnBnClickedButtonX)
ON_BN_CLICKED(IDC_BUTTON_C, &VirtualKeyboard::OnBnClickedButtonC)
ON_BN_CLICKED(IDC_BUTTON_V, &VirtualKeyboard::OnBnClickedButtonV)
ON_BN_CLICKED(IDC_BUTTON_B, &VirtualKeyboard::OnBnClickedButtonB)
ON_BN_CLICKED(IDC_BUTTON_N, &VirtualKeyboard::OnBnClickedButtonN)
ON_BN_CLICKED(IDC_BUTTON_M, &VirtualKeyboard::OnBnClickedButtonM)
ON_BN_CLICKED(IDC_BUTTON_ENTER, &VirtualKeyboard::OnBnClickedButtonEnter)
ON_BN_CLICKED(IDC_BUTTON_SPACE, &VirtualKeyboard::OnBnClickedButtonSpace)
ON_BN_CLICKED(IDC_BUTTON_LWIN, &VirtualKeyboard::OnBnClickedButtonLwin)
ON_BN_CLICKED(IDC_BUTTON_LSHIFT, &VirtualKeyboard::OnBnClickedButtonLshift)
ON_BN_CLICKED(IDC_BUTTON_BSP, &VirtualKeyboard::OnBnClickedButtonBsp)
ON_BN_CLICKED(IDC_BUTTON_ARLEFT, &VirtualKeyboard::OnBnClickedButtonArleft)
ON_BN_CLICKED(IDC_BUTTON_ARUP, &VirtualKeyboard::OnBnClickedButtonArup)
ON_BN_CLICKED(IDC_BUTTON_ARRIGHT, &VirtualKeyboard::OnBnClickedButtonArright)
ON_BN_CLICKED(IDC_BUTTON_ARDOWN, &VirtualKeyboard::OnBnClickedButtonArdown)
ON_BN_CLICKED(IDC_BUTTON_TAB, &VirtualKeyboard::OnBnClickedButtonTab)
ON_BN_CLICKED(IDC_BUTTON_ALT_LEFT, &VirtualKeyboard::OnBnClickedButtonAltLeft)
ON_BN_CLICKED(IDC_BUTTON_CTRL_LEFT, &VirtualKeyboard::OnBnClickedButtonCtrlLeft)

ON_BN_CLICKED(IDC_BUTTON_CAP, &VirtualKeyboard::OnBnClickedButtonCap)
END_MESSAGE_MAP()


void VirtualKeyboard::OnBnClickedButtonQ()
{
	// TODO: Add your control notification handler code here
	keybd_event('Q', 0x8f, 0, 0); // thuc hien gui ky tu Q ra mot thiet bi
	/*m_ButtonQ.SetColor(RED,GREEN);*/
}
void VirtualKeyboard::OnBnClickedButtonW()
{
	// TODO: Add your control notification handler code here
	keybd_event('W',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonE()
{
	// TODO: Add your control notification handler code here
	keybd_event('E',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonR()
{
	// TODO: Add your control notification handler code here
	keybd_event('R',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonT()
{
	// TODO: Add your control notification handler code here
	keybd_event('T',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonY()
{
	// TODO: Add your control notification handler code here
	keybd_event('Y',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonU()
{
	// TODO: Add your control notification handler code here
	keybd_event('U',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonI()
{
	// TODO: Add your control notification handler code here
	keybd_event('I',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonO()
{
	// TODO: Add your control notification handler code here
	keybd_event('O',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonP()
{
	// TODO: Add your control notification handler code here
	keybd_event('P',0x8f, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonA()
{
	keybd_event('A',0x8f,0,0);
	
	
}	

void VirtualKeyboard::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
// 	CWnd *pWndActive = CWnd::GetForegroundWindow();
// 	//pWndActive->ShowWindow(SW_SHOWMINIMIZED);
// 	CWnd *pWndCurrent = pWndActive;
// 	while(pWndCurrent = pWndCurrent->GetNextWindow(GW_HWNDNEXT))
// 	{
// 		if(pWndCurrent->IsWindowVisible())
// 		{
// 			pWndCurrent->SetForegroundWindow();
// 			break;
// 		}
// 	}
	CDialog::OnMouseMove(nFlags, point);
}

void VirtualKeyboard::OnBnClickedButtonS()
{
	// TODO: Add your control notification handler code here
	keybd_event('S',0x8f, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonD()
{
	// TODO: Add your control notification handler code here
	keybd_event('D',0x8f, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonF()
{
	// TODO: Add your control notification handler code here
	keybd_event('F',0x8f, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonG()
{
	// TODO: Add your control notification handler code here
	keybd_event('G',0x8f, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonH()
{
	// TODO: Add your control notification handler code here
	keybd_event('H',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonJ()
{
	// TODO: Add your control notification handler code here
	keybd_event('J',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonK()
{
	// TODO: Add your control notification handler code here
	keybd_event('K',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonL()
{
	// TODO: Add your control notification handler code here
	keybd_event('L',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonZ()
{
	// TODO: Add your control notification handler code here
	keybd_event('Z',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonX()
{
	// TODO: Add your control notification handler code here
	keybd_event('X',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonC()
{
	// TODO: Add your control notification handler code here
	keybd_event('C',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonV()
{
	// TODO: Add your control notification handler code here
	keybd_event('V',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonB()
{
	// TODO: Add your control notification handler code here
	keybd_event('B',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonN()
{
	// TODO: Add your control notification handler code here
	keybd_event('N',0x8f, 0, 0);
}
void VirtualKeyboard::OnBnClickedButtonM()
{
	// TODO: Add your control notification handler code here
	keybd_event('M',0x8f, 0, 0);
}


void VirtualKeyboard::OnBnClickedButtonEnter()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_RETURN, 0x8f, 0, 0);
}


void VirtualKeyboard::OnBnClickedButtonSpace()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_SPACE, 0x8f, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonLwin()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_LWIN, 0, KEYEVENTF_EXTENDEDKEY, 0);
	keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
}
void VirtualKeyboard::OnBnClickedButtonLshift()
{
	// TODO: Add your control notification handler code here
	if(shfState == TRUE)
	{
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		ShiftRelease();
		shfState = FALSE;
	}
	else
	{
		keybd_event(VK_SHIFT, 0, 0, 0);//key press
		ShiftPress();
		shfState = TRUE;
	}
}
void VirtualKeyboard::ShiftPress()
{
	
	m_ButtonQ.SetWindowText(_T("Q"));
	m_ButtonW.SetWindowText(_T("W"));
	m_ButtonE.SetWindowText(_T("E"));
	m_ButtonR.SetWindowText(_T("R"));
	m_ButtonT.SetWindowText(_T("T"));
	m_ButtonY.SetWindowText(_T("Y"));
	m_ButtonU.SetWindowText(_T("U"));
	m_ButtonI.SetWindowText(_T("I"));
	m_ButtonO.SetWindowText(_T("O"));
	m_ButtonP.SetWindowText(_T("P"));
	m_ButtonA.SetWindowText(_T("A"));
	m_ButtonS.SetWindowText(_T("S"));
	m_ButtonD.SetWindowText(_T("D"));
	m_ButtonF.SetWindowText(_T("F"));
	m_ButtonG.SetWindowText(_T("G"));
	m_ButtonH.SetWindowText(_T("H"));
	m_ButtonJ.SetWindowText(_T("J"));
	m_ButtonK.SetWindowText(_T("K"));
	m_ButtonL.SetWindowText(_T("L"));
	m_ButtonZ.SetWindowText(_T("Z"));
	m_ButtonX.SetWindowText(_T("X"));
	m_ButtonC.SetWindowText(_T("C"));
	m_ButtonV.SetWindowText(_T("V"));
	m_ButtonB.SetWindowText(_T("B"));
	m_ButtonN.SetWindowText(_T("N"));
	m_ButtonM.SetWindowText(_T("M"));
}
void VirtualKeyboard::ShiftRelease()
{

	m_ButtonQ.SetWindowText(_T("q"));
	m_ButtonW.SetWindowText(_T("w"));
	m_ButtonE.SetWindowText(_T("e"));
	m_ButtonR.SetWindowText(_T("r"));
	m_ButtonT.SetWindowText(_T("t"));
	m_ButtonY.SetWindowText(_T("y"));
	m_ButtonU.SetWindowText(_T("u"));
	m_ButtonI.SetWindowText(_T("i"));
	m_ButtonO.SetWindowText(_T("o"));
	m_ButtonP.SetWindowText(_T("p"));
	m_ButtonA.SetWindowText(_T("a"));
	m_ButtonS.SetWindowText(_T("s"));
	m_ButtonD.SetWindowText(_T("d"));
	m_ButtonF.SetWindowText(_T("f"));
	m_ButtonG.SetWindowText(_T("g"));
	m_ButtonH.SetWindowText(_T("h"));
	m_ButtonJ.SetWindowText(_T("j"));
	m_ButtonK.SetWindowText(_T("k"));
	m_ButtonL.SetWindowText(_T("l"));
	m_ButtonZ.SetWindowText(_T("z"));
	m_ButtonX.SetWindowText(_T("x"));
	m_ButtonC.SetWindowText(_T("c"));
	m_ButtonV.SetWindowText(_T("v"));
	m_ButtonB.SetWindowText(_T("b"));
	m_ButtonN.SetWindowText(_T("n"));
	m_ButtonM.SetWindowText(_T("m"));
}
void VirtualKeyboard::OnBnClickedButtonBsp()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_BACK, 0, 0, 0);
}

void VirtualKeyboard::OnBnClickedButtonArleft()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_LEFT, 0,0,0);
	keybd_event(VK_LEFT, 0,KEYEVENTF_KEYUP,0);
}

void VirtualKeyboard::OnBnClickedButtonArup()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_UP, 0,0,0);
}

void VirtualKeyboard::OnBnClickedButtonArright()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_RIGHT, 0,0,0);
}

void VirtualKeyboard::OnBnClickedButtonArdown()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_DOWN, 0,0,0);
}

void VirtualKeyboard::OnBnClickedButtonTab()
{
	// TODO: Add your control notification handler code here
	keybd_event(VK_TAB, 0,0,0);
}

void VirtualKeyboard::OnBnClickedButtonAltLeft()
{
	// TODO: Add your control notification handler code here
	if(altState == TRUE)
	{
		keybd_event(VK_MENU, 0,KEYEVENTF_KEYUP,0);
		altState = FALSE;
	}
	else
	{
		keybd_event(VK_MENU, 0, 0 ,0);
		altState = TRUE;
	}
}

void VirtualKeyboard::OnBnClickedButtonCtrlLeft()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	if(CtrlState == TRUE)
	{
		keybd_event(VK_CONTROL, 0,KEYEVENTF_KEYUP,0);
		CtrlState = FALSE;
	}
	else
	{
		keybd_event(VK_CONTROL, 0, 0 ,0);
		CtrlState = TRUE;
	}
}



void VirtualKeyboard::OnBnClickedButtonCap()
{
	// TODO: Add your control notification handler code here

	keybd_event(VK_CAPITAL, 0, 0 ,0);
	keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP ,0);
}
