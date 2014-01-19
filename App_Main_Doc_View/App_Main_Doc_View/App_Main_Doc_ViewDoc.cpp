
// App_Main_Doc_ViewDoc.cpp : implementation of the CApp_Main_Doc_ViewDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "App_Main_Doc_View.h"
#endif

#include "App_Main_Doc_ViewDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CApp_Main_Doc_ViewDoc

IMPLEMENT_DYNCREATE(CApp_Main_Doc_ViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CApp_Main_Doc_ViewDoc, CDocument)
END_MESSAGE_MAP()


// CApp_Main_Doc_ViewDoc construction/destruction

CApp_Main_Doc_ViewDoc::CApp_Main_Doc_ViewDoc()
{
	// TODO: add one-time construction code here

}

CApp_Main_Doc_ViewDoc::~CApp_Main_Doc_ViewDoc()
{
}

BOOL CApp_Main_Doc_ViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CApp_Main_Doc_ViewDoc serialization

void CApp_Main_Doc_ViewDoc::Serialize(CArchive& ar)
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
void CApp_Main_Doc_ViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CApp_Main_Doc_ViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CApp_Main_Doc_ViewDoc::SetSearchContent(const CString& value)
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

// CApp_Main_Doc_ViewDoc diagnostics

#ifdef _DEBUG
void CApp_Main_Doc_ViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CApp_Main_Doc_ViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CApp_Main_Doc_ViewDoc commands

CApp_Main_Doc_ViewDoc* CApp_Main_Doc_ViewDoc::GetDoc() {
  // if application is 
  /*
  CFrameWnd* pFrame = (CFrameWnd*)(AfxGetApp()->m_pMainWnd);
  return (CApp_Main_Doc_ViewDoc*) pFrame->GetActiveDocument();
  */

  // with MDI MFC
  CMDIChildWnd* pChild = ((CMDIFrameWnd*)(AfxGetApp()->m_pMainWnd))->MDIGetActive();
  if (!pChild)
    return NULL;
  CDocument* pDoc = pChild->GetActiveDocument();
  if (!pDoc)
    return NULL;
  if (!pDoc->IsKindOf(RUNTIME_CLASS(CApp_Main_Doc_ViewDoc)))
    return NULL;
  return (CApp_Main_Doc_ViewDoc*)pDoc;
}