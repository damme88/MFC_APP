
// Toolbar_XmlView.h : interface of the CToolbar_XmlView class
//

#pragma once


class CToolbar_XmlView : public CView
{
protected: // create from serialization only
	CToolbar_XmlView();
	DECLARE_DYNCREATE(CToolbar_XmlView)

// Attributes
public:
	CToolbar_XmlDoc* GetDocument() const;

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
	virtual ~CToolbar_XmlView();
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

#ifndef _DEBUG  // debug version in Toolbar_XmlView.cpp
inline CToolbar_XmlDoc* CToolbar_XmlView::GetDocument() const
   { return reinterpret_cast<CToolbar_XmlDoc*>(m_pDocument); }
#endif

