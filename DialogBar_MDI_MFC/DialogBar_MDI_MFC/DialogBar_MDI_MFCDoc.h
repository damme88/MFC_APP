
// DialogBar_MDI_MFCDoc.h : interface of the CDialogBar_MDI_MFCDoc class
//


#pragma once


class CDialogBar_MDI_MFCDoc : public CDocument
{
protected: // create from serialization only
	CDialogBar_MDI_MFCDoc();
	DECLARE_DYNCREATE(CDialogBar_MDI_MFCDoc)

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
	virtual ~CDialogBar_MDI_MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
