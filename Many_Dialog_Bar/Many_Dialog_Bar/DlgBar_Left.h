#pragma once



// DlgBar_Left form view

class DlgBar_Left : public CFormView
{
	DECLARE_DYNCREATE(DlgBar_Left)

protected:
	DlgBar_Left();           // protected constructor used by dynamic creation
	virtual ~DlgBar_Left();

public:
	enum { IDD = IDD_DLGBAR_LEFT };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


