#pragma once



// Dialog_Bar form view
class CDialogBar_MDI_MFCDoc;
class Dialog_Bar : public CFormView
{
	DECLARE_DYNCREATE(Dialog_Bar)

protected:
	Dialog_Bar();           // protected constructor used by dynamic creation
	virtual ~Dialog_Bar();

public:
	enum { IDD = IDD_DIALOG_BAR };
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


