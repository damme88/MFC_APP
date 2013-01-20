
// DialogBar_MDI_MFCDoc.cpp : implementation of the CDialogBar_MDI_MFCDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DialogBar_MDI_MFC.h"
#endif

#include "DialogBar_MDI_MFCDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDialogBar_MDI_MFCDoc

IMPLEMENT_DYNCREATE(CDialogBar_MDI_MFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogBar_MDI_MFCDoc, CDocument)
END_MESSAGE_MAP()


// CDialogBar_MDI_MFCDoc construction/destruction

CDialogBar_MDI_MFCDoc::CDialogBar_MDI_MFCDoc()
{
	// TODO: add one-time construction code here

}

CDialogBar_MDI_MFCDoc::~CDialogBar_MDI_MFCDoc()
{
}

BOOL CDialogBar_MDI_MFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDialogBar_MDI_MFCDoc serialization

void CDialogBar_MDI_MFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDialogBar_MDI_MFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CDialogBar_MDI_MFCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDialogBar_MDI_MFCDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDialogBar_MDI_MFCDoc diagnostics

#ifdef _DEBUG
void CDialogBar_MDI_MFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogBar_MDI_MFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDialogBar_MDI_MFCDoc commands
