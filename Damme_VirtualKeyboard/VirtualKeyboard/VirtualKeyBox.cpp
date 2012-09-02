// VirtualKeyBox.cpp : implementation file
//

#include "stdafx.h"
#include "VirtualKeyboard.h"
#include "VirtualKeyBox.h"


// CVirtualKeyBox dialog

IMPLEMENT_DYNAMIC(CVirtualKeyBox, CDialog)

CVirtualKeyBox::CVirtualKeyBox(CWnd* pParent /*=NULL*/)
	: CDialog(CVirtualKeyBox::IDD, pParent)
{
	
}

CVirtualKeyBox::~CVirtualKeyBox()
{
}

void CVirtualKeyBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_A, m_ButtonA);
	DDX_Control(pDX, IDC_BUTTON_Z, m_ButtonZ);
	DDX_Control(pDX, IDC_BUTTON_X, m_b);
}


BEGIN_MESSAGE_MAP(CVirtualKeyBox, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_S, &CVirtualKeyBox::OnBnClickedButtonS)
	ON_BN_CLICKED(IDC_BUTTON_A, &CVirtualKeyBox::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_Q, &CVirtualKeyBox::OnBnClickedButtonQ)

	ON_BN_CLICKED(IDC_BUTTON_ARLEFT, &CVirtualKeyBox::OnBnClickedButtonArleft)
	ON_BN_CLICKED(IDC_BUTTON_ALT_LEFT, &CVirtualKeyBox::OnBnClickedButtonAltLeft)
	
END_MESSAGE_MAP()


// CVirtualKeyBox message handlers

void CVirtualKeyBox::OnBnClickedButtonS()
{
	// TODO: Add your control notification handler code here
}

void CVirtualKeyBox::OnBnClickedButtonA()
{
	// TODO: Add your control notification handler code here

}

void CVirtualKeyBox::OnBnClickedButtonQ()
{
	// TODO: Add your control notification handler code here
}

void CVirtualKeyBox::OnBnClickedButtonArleft()
{
	// TODO: Add your control notification handler code here
}

void CVirtualKeyBox::OnBnClickedButtonAltLeft()
{
	// TODO: Add your control notification handler code here
}

void CVirtualKeyBox::OnBnClickedButton97()
{
	// TODO: Add your control notification handler code here
}
