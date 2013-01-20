
// Dialog_Bar_FormView.h : interface of the CDialog_Bar_FormView class
//

#pragma once


class CDialog_Bar_FormView : public CView
{
protected: // create from serialization only
	CDialog_Bar_FormView();
	DECLARE_DYNCREATE(CDialog_Bar_FormView)

// Attributes
public:
	CDialog_Bar_FormDoc* GetDocument() const;

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
	virtual ~CDialog_Bar_FormView();
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

#ifndef _DEBUG  // debug version in Dialog_Bar_FormView.cpp
inline CDialog_Bar_FormDoc* CDialog_Bar_FormView::GetDocument() const
   { return reinterpret_cast<CDialog_Bar_FormDoc*>(m_pDocument); }
#endif

