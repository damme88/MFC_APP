#pragma once


// CPreviewPane view

class CPreviewPane : public CView
{
	DECLARE_DYNCREATE(CPreviewPane)

protected:
	CPreviewPane();           // protected constructor used by dynamic creation
	virtual ~CPreviewPane();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


