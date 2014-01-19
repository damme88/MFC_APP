
// RestartAppAutomaticView.h : interface of the RestartAppAutomaticView class
//

#pragma once


class RestartAppAutomaticView : public CView
{
protected: // create from serialization only
	RestartAppAutomaticView();
	DECLARE_DYNCREATE(RestartAppAutomaticView)

// Attributes
public:
	RestartAppAutomaticDoc* GetDocument() const;

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
	virtual ~RestartAppAutomaticView();
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
  afx_msg void RestartTheApplication();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RestartAppAutomaticView.cpp
inline RestartAppAutomaticDoc* RestartAppAutomaticView::GetDocument() const
   { return reinterpret_cast<RestartAppAutomaticDoc*>(m_pDocument); }
#endif

