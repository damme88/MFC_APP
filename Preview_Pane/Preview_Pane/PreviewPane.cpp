// PreviewPane.cpp : implementation file
// PreviewPane la mot thanh panel thuong dat o bottom cua mot app
// No co ung dung de hien thi cac thong tin cua mot ung dung khi thuc hien chuc nang nao do
// Su dung PrevewPane don gian nhat la cho viec the hien cac thong tin can thiet duoc hien thi ra


#include "stdafx.h"
#include "Preview_Pane.h"
#include "PreviewPane.h"


// CPreviewPane
const int nHorzMargin = 2;
const int nVertMargin = 2;
IMPLEMENT_DYNCREATE(CPreviewPane, CView)

CPreviewPane::CPreviewPane() {

}

CPreviewPane::~CPreviewPane() {
}

BEGIN_MESSAGE_MAP(CPreviewPane, CView)
END_MESSAGE_MAP()


// CPreviewPane drawing
// Ham nay se la noi thuc hien cac draw 
void CPreviewPane::OnDraw(CDC* pDC) {
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
 CRect rect_client;  
 GetClientRect(rect_client);                                                  // lay ve kich thuoc cua vung xu ly la windows
 CRect rect_caption = rect_client ;                                           // lua kich thuoc cho caption cua preview
 rect_caption.bottom = rect_caption.top + afxGlobalData.GetTextHeight() + 4;  // thay doi kich thuoc cua bottom

 CRect rect_message = rect_client;                                            // xac dinh kich thuoc cua vung show message
 rect_message.top = rect_caption.bottom;
 CBrush pBrush;
 pBrush.CreateSolidBrush(RGB(250, 250,0));                                    // color = yellow
 pDC->FillRect(rect_caption, &pBrush);                                        // do mau cho vung caption
 pDC->FillRect(rect_message, &afxGlobalData.brWindow);                        // do mau cho vung message- white

 int old_bk_mode = pDC->SetBkMode(TRANSPARENT);                               // Lay chi so mau nen cua windows
 COLORREF clr_old_text = pDC->SetTextColor(afxGlobalData.clrBarText);
 CFont* pold_font = (CFont*)pDC->SelectStockObject(DEFAULT_GUI_FONT);
 
 CRect rect_text = rect_caption;
 rect_text.left += 2*nHorzMargin;
 rect_text.right -=2*nVertMargin; +rect_text.Height();
 CString str_caption = __T("Preview Area");
 pDC->DrawText(str_caption, rect_text, DT_END_ELLIPSIS | DT_SINGLELINE | DT_VCENTER);
 pDC->SetTextColor(afxGlobalData.clrWindowText);                             // use black text of windows
                                                                             // chung ta co the lua chon mau tuy y
 rect_text = rect_message;
 rect_text.DeflateRect(nHorzMargin, nVertMargin);

 CString str_text = __T(" Hi developers on the world \n I am Damme 88 \n I am Graphics Developer");
 pDC->DrawText(str_text, rect_text, DT_WORDBREAK | DT_END_ELLIPSIS);
 pDC->SelectObject(pold_font);
 pDC->SetTextColor(clr_old_text);
 pDC->SetBkMode(old_bk_mode);
}


// CPreviewPane diagnostics

#ifdef _DEBUG
void CPreviewPane::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPreviewPane::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


BOOL CPreviewPane::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}
// CPreviewPane message handlers
