#pragma once



// DlgBar_Sub form view

class DlgBar_Sub : public CFormView
{
	DECLARE_DYNCREATE(DlgBar_Sub)

protected:
	DlgBar_Sub();           // protected constructor used by dynamic creation
	virtual ~DlgBar_Sub();

public:
	enum { IDD = IDD_DLGBAR_SUB };
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


