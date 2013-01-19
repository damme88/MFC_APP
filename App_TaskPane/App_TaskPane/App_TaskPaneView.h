
// App_TaskPaneView.h : interface of the CApp_TaskPaneView class
//

#pragma once


class CApp_TaskPaneView : public CView
{
protected: // create from serialization only
	CApp_TaskPaneView();
	DECLARE_DYNCREATE(CApp_TaskPaneView)

// Attributes
public:
	CApp_TaskPaneDoc* GetDocument() const;

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
	virtual ~CApp_TaskPaneView();
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

#ifndef _DEBUG  // debug version in App_TaskPaneView.cpp
inline CApp_TaskPaneDoc* CApp_TaskPaneView::GetDocument() const
   { return reinterpret_cast<CApp_TaskPaneDoc*>(m_pDocument); }
#endif

