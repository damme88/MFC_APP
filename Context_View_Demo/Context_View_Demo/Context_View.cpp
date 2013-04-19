// Context_View.cpp : implementation file
//

#include "stdafx.h"
#include "Context_View_Demo.h"
#include "Context_View.h"
#include "SliderBar.h"
#include "resource.h"
// Context_View
//#define COLOR_FOR_BACKGROUND
//#define GRADIENT_FOR_BACKGROUND
#define BITMAP_FOR_BACKGROUND
IMPLEMENT_DYNCREATE(Context_View, CFormView)

Context_View::Context_View()
	: CFormView(Context_View::IDD)
  , str_edit_1(_T(""))
{
  progress_bar.SetBkBitmap(IDB_BITMAP2);
}

Context_View::~Context_View()
{
}

void Context_View::DoDataExchange(CDataExchange* pDX)
{
  CFormView::DoDataExchange(pDX);
  DDX_Text(pDX, IDC_EDIT1, str_edit_1);
  DDX_Control(pDX, IDC_CHECK1, checbox_1);
  DDX_Control(pDX, IDC_RADIO3, radio_btn_3);
}

BEGIN_MESSAGE_MAP(Context_View, CFormView)
  ON_BN_CLICKED(IDC_RADIO1, &Context_View::OnBnClickedRadio1)
  ON_WM_ERASEBKGND()
  ON_WM_CREATE()
  ON_WM_SIZE()
  //ON_WM_HSCROLL()
  //ON_WM_VSCROLL()
  ON_WM_LBUTTONUP()
  ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Context_View diagnostics

#ifdef _DEBUG
void Context_View::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Context_View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Context_View message handlers




void Context_View::OnBnClickedRadio1()
{
  ;// TODO: Add your control notification handler code here
}


int Context_View::OnCreate(LPCREATESTRUCT lpCreateStruct) {
  if (CFormView::OnCreate(lpCreateStruct) == -1) {
    return -1;
  }
  InitContextView();
  return 0;
}

void Context_View::OnInitialUpdate() {
  CFormView::OnInitialUpdate();
  checbox_1.SetCheck(1);
  radio_btn_3.SetCheck(1);
  str_edit_1 = "2.000";
  UpdateData(FALSE);
  EnableScrollBarCtrl(SB_BOTH, FALSE);  // don't use scroll bar
}
void Context_View::InitContextView() {
  // create progress bar
  CRect rect;
  GetClientRect(rect);
  progress_bar.SetRect(rect);
  progress_bar.Create(this, IDC_SLIDER_BAR);
  progress_bar.SetRange(0, 100, TRUE);
  // set post for progress bar
  progress_bar.SetWindowPos(NULL, 0, 0,
                            rect.right, 30,
                            SWP_SHOWWINDOW);

}


BOOL Context_View::OnEraseBkgnd(CDC* pDC) {

#ifdef COLOR_FOR_BACKGROUND 
  CRect rect;
  pDC->GetClipBox(&rect);
  CBrush back_brush(RGB(220, 220, 220 ));
  CBrush* pOldBrush = pDC->SelectObject(&back_brush);

  pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
  pDC->SelectObject(pOldBrush);
  return TRUE;
#endif

#ifdef GRADIENT_FOR_BACKGROUND
  CPen myPen[55] ;
  int i ;
  CRect rect ;
  GetClientRect(&rect);
  for (i = 0 ; i <50 ; i++) {
    myPen[i].CreatePen(PS_SOLID, 1, RGB (i*4, i*4, 220));
  }
   CPen *oldPen = pDC->SelectObject(&myPen[0]) ;

   for(i = 0 ; i <= rect.bottom;) {
     pDC->MoveTo(0, i);
     pDC->LineTo(rect.right, i);
     i++;
     pDC->SelectObject (&myPen[i*50/ rect.bottom]);
   }
   pDC->SelectObject(oldPen);
   return TRUE;
#endif

#ifdef BITMAP_FOR_BACKGROUND
  CBitmap cbitmap;
  cbitmap.LoadBitmap(IDB_BITMAP1);
  CRect rect;
  GetClientRect(&rect);
  // make size bitmap is same rect 
  CImage img;
  img.LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP1);
  int dimx = rect.Width();
  int dimy = rect.Height();

  CDC mDC;
  mDC.CreateCompatibleDC(pDC);
  CBitmap scale_bitmap;
  scale_bitmap.CreateCompatibleBitmap(pDC, dimx, dimy);
  CBitmap *cbit = mDC.SelectObject(&scale_bitmap);
  img.StretchBlt(mDC.m_hDC, 0, 0, dimx, dimy, 0, 0, img.GetWidth(), img.GetHeight(), SRCCOPY);
  mDC.SelectObject(cbit);


  CDC dc;
  // create device context which is compatible with pDC
  dc.CreateCompatibleDC(pDC);
  // get old bitmap 
  CBitmap *old_bitmap = dc.SelectObject(&scale_bitmap);
  BITMAP bitmap;
  ZeroMemory(&bitmap, sizeof(BITMAP));
  // get infor about bitmap in cbitmap then save bitmap
  scale_bitmap.GetObject(sizeof(BITMAP), &bitmap);

  int nx = 0;
  int ny = 0;
  while(ny < rect.Height()) {
    while(nx < rect.Width()) {
      // copies bitmap form dc to pDC
      pDC->BitBlt(nx, ny, rect.right, rect.bottom, &dc, 0, 0, SRCCOPY);
      nx += (int)bitmap.bmWidth;
    }
    nx = 0;
    ny += (int)bitmap.bmHeight;
  }

  dc.SelectObject(old_bitmap);
  return TRUE ; 
#endif
}


void Context_View::OnSize(UINT nType, int cx, int cy) {
  //CFormView::OnSize(nType, cx, cy);
  CRect rect;
  GetClientRect(rect);
  // when size of form is changed so progress is changed too
  progress_bar.SetWindowPos(NULL, 0, 0,
                            rect.right, 30,
                            SWP_SHOWWINDOW);
  RedrawWindow();
}

void Context_View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
  CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
  RedrawWindow();
}

void Context_View::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
  CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
  RedrawWindow();
}

// ham nay de transparent static text va khac phuc hien tuong nhay khi di chuyen slider bar
HBRUSH Context_View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) {
  if(pWnd->GetDlgCtrlID() == IDC_STATIC) {
    pDC->SetBkMode(TRANSPARENT);
    return reinterpret_cast<HBRUSH>(::GetStockObject(NULL_BRUSH));
  } else {
    return CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
  }
}