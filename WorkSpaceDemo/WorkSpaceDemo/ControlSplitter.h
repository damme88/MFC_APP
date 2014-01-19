#ifndef CONTROL_SPLITTER_H_
#define CONTROL_SPLITTER_H_

#if _MSC_VER > 1000
#pragma once
#define SPF_TOP             0x0010
#define SPF_BOTTOM          0x0020
#define SPF_LEFT            0x0040
#define SPF_RIGHT           0x0080

#endif
#include <vector>

#define UWM_SPLIT_MOVED_MSG _T("UWM_SPLIT_MOVED_MSG	")
static UINT UWM_SPLIT_MOVED   = ::RegisterWindowMessage(UWM_SPLIT_MOVED_MSG);

class CControlSplitter : public CButton
{
public:
	typedef enum {
		CS_VERT = 1,
		CS_HORZ = 2,
		CS_NONE = 0
	};
	CControlSplitter();

public:
	void AddToBottomOrRightCtrls(UINT nCtrlId, WORD nFlags = SPF_TOP|SPF_LEFT|SPF_RIGHT|SPF_BOTTOM);
	void AddToTopOrLeftCtrls(UINT nCtrlId, WORD nFlags = SPF_TOP|SPF_LEFT|SPF_BOTTOM|SPF_RIGHT);
	void SetType(UINT nType);
	virtual ~CControlSplitter();

protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

	DECLARE_MESSAGE_MAP()
private:
	unsigned int m_nType;
	std::vector<DWORD> m_vtTopLeftControls;
	std::vector<DWORD> m_vtBottomRightControls;
	CWnd * m_pOldDragCapture;
	CPoint m_ptStartDrag,m_ptStartPos;  
    bool m_bDragging;
	HCURSOR m_hCursor;
	CRect m_rectMax;
};

#endif //CONTROL_SPLITTER_H_
