
// Preview_PaneView.h : interface of the CPreview_PaneView class
//

#pragma once


class CPreview_PaneView : public CView
{
protected: // create from serialization only
	CPreview_PaneView();
	DECLARE_DYNCREATE(CPreview_PaneView)

// Attributes
public:
	CPreview_PaneDoc* GetDocument() const;

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
	virtual ~CPreview_PaneView();
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

#ifndef _DEBUG  // debug version in Preview_PaneView.cpp
inline CPreview_PaneDoc* CPreview_PaneView::GetDocument() const
   { return reinterpret_cast<CPreview_PaneDoc*>(m_pDocument); }
#endif

