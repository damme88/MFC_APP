
// Text_EditorView.h : interface of the CText_EditorView class
//

#pragma once


class CText_EditorView : public CView
{
protected: // create from serialization only
	CText_EditorView();
	DECLARE_DYNCREATE(CText_EditorView)

// Attributes
public:
	CText_EditorDoc* GetDocument() const;

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
	virtual ~CText_EditorView();
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

#ifndef _DEBUG  // debug version in Text_EditorView.cpp
inline CText_EditorDoc* CText_EditorView::GetDocument() const
   { return reinterpret_cast<CText_EditorDoc*>(m_pDocument); }
#endif

