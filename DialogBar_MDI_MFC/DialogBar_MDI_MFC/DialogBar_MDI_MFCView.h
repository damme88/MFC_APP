
// DialogBar_MDI_MFCView.h : interface of the CDialogBar_MDI_MFCView class
//

#pragma once


class CDialogBar_MDI_MFCView : public CView
{
protected: // create from serialization only
	CDialogBar_MDI_MFCView();
	DECLARE_DYNCREATE(CDialogBar_MDI_MFCView)

// Attributes
public:
	CDialogBar_MDI_MFCDoc* GetDocument() const;

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
	virtual ~CDialogBar_MDI_MFCView();
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

#ifndef _DEBUG  // debug version in DialogBar_MDI_MFCView.cpp
inline CDialogBar_MDI_MFCDoc* CDialogBar_MDI_MFCView::GetDocument() const
   { return reinterpret_cast<CDialogBar_MDI_MFCDoc*>(m_pDocument); }
#endif

