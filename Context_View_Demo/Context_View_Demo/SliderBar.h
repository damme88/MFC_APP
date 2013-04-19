#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CSliderBar :
	public CSliderCtrl
{
// Construction
public:
	CSliderBar();

// Attributes
public:
	void SetActive(BOOL bActive = TRUE) {
		m_isActive = bActive;
	}

	BOOL IsActive() {
		return m_isActive;
	}

// Operations
public:

// Implementation
public:
	virtual ~CSliderBar();
	virtual BOOL Create(CWnd* pParent, UINT nID = 0);

	void SetRect(CRect rect) { m_rect = rect; }

	void GetRect(CRect& rect) { rect = m_rect; }

 BOOL SetBkBitmap(UINT bmpId);

 BOOL SetBkBitmap(CBitmap& bmp);
	// Generated message map functions
protected:
	//{{AFX_MSG(CMySliderControl)
		afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
		afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
  CDC			m_dcBk;
  CBitmap		m_bmpBk;
  CBitmap     *m_bmpBkOld;
  CRect m_rect;
  BOOL m_isActive;
public:
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
