
// Context_View_DemoView.h : interface of the Context_View_DemoView class
//

#pragma once
#include "Context_View_DemoDoc.h"

class Context_View_DemoView : public CView
{
protected: // create from serialization only
	Context_View_DemoView();
	DECLARE_DYNCREATE(Context_View_DemoView)

// Attributes
public:
	Context_View_DemoDoc* GetDocument() const;

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
	virtual ~Context_View_DemoView();
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

#ifndef _DEBUG  // debug version in Context_View_DemoView.cpp
inline Context_View_DemoDoc* Context_View_DemoView::GetDocument() const
   { return reinterpret_cast<Context_View_DemoDoc*>(m_pDocument); }
#endif

