
// Many_Dialog_BarView.h : interface of the CMany_Dialog_BarView class
//

#pragma once
#include "Many_Dialog_BarDoc.h"

class CMany_Dialog_BarView : public CView
{
protected: // create from serialization only
	CMany_Dialog_BarView();
	DECLARE_DYNCREATE(CMany_Dialog_BarView)

// Attributes
public:
	CMany_Dialog_BarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMany_Dialog_BarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Many_Dialog_BarView.cpp
inline CMany_Dialog_BarDoc* CMany_Dialog_BarView::GetDocument() const
   { return reinterpret_cast<CMany_Dialog_BarDoc*>(m_pDocument); }
#endif

