
// App_Main_Doc_ViewView.h : interface of the CApp_Main_Doc_ViewView class
//

#pragma once


class CApp_Main_Doc_ViewView : public CView
{
protected: // create from serialization only
	CApp_Main_Doc_ViewView();
	DECLARE_DYNCREATE(CApp_Main_Doc_ViewView)

// Attributes
public:
	CApp_Main_Doc_ViewDoc* GetDocument() const;

// Operations
public:
  static CApp_Main_Doc_ViewView* GetView();
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
	virtual ~CApp_Main_Doc_ViewView();
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

#ifndef _DEBUG  // debug version in App_Main_Doc_ViewView.cpp
inline CApp_Main_Doc_ViewDoc* CApp_Main_Doc_ViewView::GetDocument() const
   { return reinterpret_cast<CApp_Main_Doc_ViewDoc*>(m_pDocument); }
#endif

