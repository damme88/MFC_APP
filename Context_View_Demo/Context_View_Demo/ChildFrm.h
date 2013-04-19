
// ChildFrm.h : interface of the ChildFrame class
//


#pragma once
#include "Context_View.h"
class ChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(ChildFrame)
public:
	ChildFrame();

// Attributes
public:

// Operations
private:
  CSplitterWnd m_wndSplitter;
  Context_View *context_view_;
// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~ChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  BOOL OnCreateClient(LPCREATESTRUCT lpCreateStruct, CCreateContext *pContext);
};
