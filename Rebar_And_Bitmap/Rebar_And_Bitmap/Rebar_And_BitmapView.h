
// Rebar_And_BitmapView.h : interface of the Rebar_And_BitmapView class
//

#pragma once


class Rebar_And_BitmapView : public CView
{
protected: // create from serialization only
	Rebar_And_BitmapView();
	DECLARE_DYNCREATE(Rebar_And_BitmapView)

// Attributes
public:
	Rebar_And_BitmapDoc* GetDocument() const;

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
	virtual ~Rebar_And_BitmapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  afx_msg void OnViewLargeicon();
	afx_msg void OnUpdateViewLargeicon(CCmdUI* pCmdUI);
	afx_msg void OnViewDetails();
	afx_msg void OnUpdateViewDetails(CCmdUI* pCmdUI);
	afx_msg void OnViewList();
	afx_msg void OnUpdateViewList(CCmdUI* pCmdUI);
	afx_msg void OnViewSmallicon();
	afx_msg void OnUpdateViewSmallicon(CCmdUI* pCmdUI);



protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Rebar_And_BitmapView.cpp
inline Rebar_And_BitmapDoc* Rebar_And_BitmapView::GetDocument() const
   { return reinterpret_cast<Rebar_And_BitmapDoc*>(m_pDocument); }
#endif

