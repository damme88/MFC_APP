
// App_Main_Doc_ViewDoc.h : interface of the CApp_Main_Doc_ViewDoc class
//


#pragma once


class CApp_Main_Doc_ViewDoc : public CDocument
{
protected: // create from serialization only
	CApp_Main_Doc_ViewDoc();
	DECLARE_DYNCREATE(CApp_Main_Doc_ViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CApp_Main_Doc_ViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
  static CApp_Main_Doc_ViewDoc* GetDoc();
protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
