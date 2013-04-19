#include "stdafx.h"
#include "SliderBar.h"
#include "resource.h"

CSliderBar::CSliderBar()
{
	m_dcBk.m_hDC = NULL;
	m_isActive = TRUE;
}

CSliderBar::~CSliderBar()
{
	DeleteObject(m_dcBk.SelectObject(&m_bmpBkOld));
	DeleteDC(m_dcBk);
}


BEGIN_MESSAGE_MAP(CSliderBar, CSliderCtrl)
	//{{AFX_MSG_MAP(CMySliderControl)
		ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
		ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	 ON_WM_MOUSEMOVE()
	 ON_WM_LBUTTONDOWN()
   ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

void CSliderBar::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
//
// Description	:	Sent by the slider control to notify the parent window
//					about drawing operations. This notification is sent in
//					the form of a WM_NOTIFY message.
// Parameters	:	pNMHDR - a pointer to a NM_CUSTOMDRAW structure.
//					pResult - value depends on the current drawing state.
{
  LPNMCUSTOMDRAW lpcd = (LPNMCUSTOMDRAW)pNMHDR;
  CDC *pDC = CDC::FromHandle(lpcd->hdc);
  switch(lpcd->dwDrawStage) {
		case CDDS_PREPAINT:
			 *pResult = CDRF_NOTIFYITEMDRAW ;
			 break;
		case CDDS_ITEMPREPAINT:
		  if (lpcd->dwItemSpec == TBCD_THUMB) {
			   *pResult = CDRF_DODEFAULT;
			   break;
		  }
    if (lpcd->dwItemSpec == TBCD_CHANNEL) {
      *pResult = 0;
      break;  // Do not load bitmap to transparent bkgn for slider bar
      CClientDC clientDC(GetParent());
      CDC			tempDcBk;

      CRect crect;
      CRect wrect;
      GetClientRect(crect);
      GetWindowRect(wrect);
      GetParent()->ScreenToClient(wrect);
			if (m_dcBk.m_hDC == NULL) {
        m_dcBk.CreateCompatibleDC(pDC);
        //m_bmpBk.LoadBitmapW(IDB_CONTEXT_BK);
				    m_bmpBkOld = m_dcBk.SelectObject(&m_bmpBk);
			}

      BITMAP bmpInfo;
      m_bmpBk.GetBitmap(&bmpInfo);
      CRect rectOnParent;
      GetRect(rectOnParent);
      pDC->StretchBlt(0, 0, crect.Width(), crect.Height(), &m_dcBk, 0, rectOnParent.top, bmpInfo.bmWidth, crect.Height(), SRCCOPY);

      *pResult = 0;
		  	 break;
		  }
	 }
}

BOOL CSliderBar::OnEraseBkgnd(CDC* pDC)
{
  return FALSE;
}

BOOL CSliderBar::Create(CWnd* pParent, UINT nID) {

  DWORD dwStyle = WS_CHILD | WS_VISIBLE | TBS_TRANSPARENTBKGND; /* TBS_AUTOTICKS*/
  int width_slider = m_rect.Width();
  CRect rect(0, 0, width_slider, 30);
  CSliderCtrl::Create(dwStyle, rect, pParent, nID);
  return TRUE;
}

void CSliderBar::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (!m_isActive) return;

	CSliderCtrl::OnMouseMove(nFlags, point);
}

void CSliderBar::OnLButtonDown(UINT nFlags, CPoint point)
{
  if (!m_isActive) return;

  CSliderCtrl::OnLButtonDown(nFlags, point);
}

void CSliderBar::OnLButtonUp(UINT nFlags, CPoint point)
{
  if (!m_isActive) return;

  CSliderCtrl::OnLButtonUp(nFlags, point);
}

BOOL CSliderBar::SetBkBitmap(UINT bmpId) {
  if (m_bmpBk.GetSafeHandle()) {
    m_bmpBk.Detach();
  }
  return m_bmpBk.LoadBitmapW(bmpId);
}

BOOL CSliderBar::SetBkBitmap(CBitmap& bmp) {
  if (m_bmpBk.GetSafeHandle()) {
    m_bmpBk.Detach();
  }
  LPBITMAP lpBitmap;
  bmp.GetBitmap(lpBitmap);
  return m_bmpBk.CreateBitmapIndirect(lpBitmap);
}