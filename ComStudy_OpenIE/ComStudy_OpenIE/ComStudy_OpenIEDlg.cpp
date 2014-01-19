
// ComStudy_OpenIEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComStudy_OpenIE.h"
#include "ComStudy_OpenIEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ComStudy_OpenIEDlg dialog




ComStudy_OpenIEDlg::ComStudy_OpenIEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ComStudy_OpenIEDlg::IDD, pParent)
  , link_web_(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ComStudy_OpenIEDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, IDC_EDIT_LINK_WEB, link_web_);
}

BEGIN_MESSAGE_MAP(ComStudy_OpenIEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDC_BTN_OPEN_IE, &ComStudy_OpenIEDlg::OnHandleOpenIE)
END_MESSAGE_MAP()


// ComStudy_OpenIEDlg message handlers

BOOL ComStudy_OpenIEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void ComStudy_OpenIEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void ComStudy_OpenIEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR ComStudy_OpenIEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void ComStudy_OpenIEDlg::OnHandleOpenIE() {
  ::CoInitialize(NULL);
  IWebBrowser2 *pbrowse = NULL;
  if (!pbrowse)
  {
    HRESULT hresult = CoCreateInstance(CLSID_InternetExplorer, NULL,
                                       CLSCTX_LOCAL_SERVER, IID_IWebBrowser2,
                                       (void**)&pbrowse);
    if(FAILED(hresult)) {
       MessageBox(L"Failed to open IE");
       return;
    }
  }

  VARIANT vempty;
  VariantInit(&vempty);
  UpdateData(TRUE);
  USES_CONVERSION;

  // convert CString to char
  char * str = new char [MAX_PATH];
  long nsize = link_web_.GetLength();
  memset(str, 0, nsize);
  wcstombs(str, link_web_, nsize+1);

  BSTR bstr_URL = SysAllocString(A2OLE((const char*) str));
  HRESULT hr = pbrowse->Navigate(bstr_URL, &vempty, &vempty, &vempty, &vempty);
  if (SUCCEEDED(hr)) {
    pbrowse->put_Visible(VARIANT_TRUE);
  } else {
    pbrowse->Quit();
  }

  SysFreeString(bstr_URL);
  pbrowse->Release();
  pbrowse = NULL;
}