// TabBar.cpp : implementation file
//

#include "stdafx.h"
#include "WorkSpaceDemo.h"
#include "TabBar.h"


// TabBar

IMPLEMENT_DYNAMIC(TabBar, CMFCTabCtrl)

TabBar::TabBar()
{

}

TabBar::~TabBar()
{
}


BEGIN_MESSAGE_MAP(TabBar, CMFCTabCtrl)
  ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// TabBar message handlers


void TabBar::OnLButtonDown(UINT nFlags, CPoint point) {
  m_bWindowPosChanged = FALSE;

	CWnd::OnLButtonDown(nFlags, point);

	if (m_rectCloseButton.PtInRect(point))
	{
		m_bTabCloseButtonPressed = TRUE;
		RedrawWindow(m_rectCloseButton);
		return;
	}

	m_iHighlighted = GetTabFromPoint(point);
	int iHighlighted = m_iHighlighted;

	if (iHighlighted >= 0)
	{
		BOOL bTabWasMoved = FALSE;

		if (!ActivateOnBtnUp())
		{
			int nTab = GetTabFromPoint(point);

			if (nTab >= 0 && nTab != m_iActiveTab)
			{
				m_iLastActiveTab = m_iActiveTab;

				m_bSetActiveTabFired = FALSE;
				m_bSetActiveTabByMouseClick = TRUE;
				m_bUserSelectedTab = TRUE;

				if (!SetActiveTab(nTab))
				{
					m_bSetActiveTabFired = TRUE;
					m_bSetActiveTabByMouseClick = FALSE;
					m_bUserSelectedTab = FALSE;
					m_bWindowPosChanged = FALSE;
					return;
				}

				m_bSetActiveTabByMouseClick = FALSE;
				m_bUserSelectedTab = FALSE;

				if (!m_bSetActiveTabFired)
				{
					FireChangeActiveTab(m_iActiveTab);
				}

				m_bSetActiveTabFired = FALSE;
			}
			else if (nTab == m_iActiveTab)
			{
				//-----------------------------
				// Set focus to the tab window:
				//-----------------------------
				CWnd* pWnd = GetTabWnd(nTab);
				if (pWnd->GetSafeHwnd() != NULL)
				{
					pWnd->SetFocus();
				}
			}

			bTabWasMoved = (nTab != GetTabFromPoint(point));

			m_iHighlighted = -1;
			ReleaseCapture();
		}
		else
		{
			m_iPressed = m_iHighlighted;
		}

		if (iHighlighted != m_iActiveTab)
		{
			InvalidateTab(iHighlighted);
		}

		if (!bTabWasMoved && !m_bWindowPosChanged)
		{
			EnterDragMode();
		}
	}
	m_bWindowPosChanged = FALSE;
  return;
}

BOOL TabBar::SetActiveTab(int iTab) {
  if (iTab < 0 || iTab >= m_iTabsNum)
	{
		TRACE(_T("SetActiveTab: illegal tab number %d\n"), iTab);
		return FALSE;
	}

	if (iTab >= m_arTabs.GetSize())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	BOOL bIsFirstTime = (m_iActiveTab == -1);

	if (m_iActiveTab == iTab) // Already active, do nothing
	{
		if (IsMDITabGroup())
		{
			ActivateMDITab(m_iActiveTab);
		}

		return TRUE;
	}

	if (FireChangingActiveTab(iTab))
	{
		return FALSE;
	}

	CMDIFrameWndEx* pParentFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetParentFrame());
	BOOL bEnableSetRedraw = FALSE;

	//if (pParentFrame != NULL && m_bIsMDITab)
	//{
	//	;//bEnableSetRedraw = !pParentFrame->m_bClosing && !CMDIFrameWndEx::m_bDisableSetRedraw;
	//}

	CWnd* pWndParent = GetParent();
	ASSERT_VALID(pWndParent);

	if (m_iTabsNum > 1 && bEnableSetRedraw)
	{
		pWndParent->SetRedraw(FALSE);
	}

	if (m_iActiveTab != -1 && m_bHideInactiveWnd)
	{
		//--------------------
		// Hide active window:
		//--------------------
		CWnd* pWndActive = GetActiveWnd();
		if (pWndActive != NULL)
		{
			pWndActive->ShowWindow(SW_HIDE);
		}
	}

	m_iActiveTab = iTab;

	//------------------------
	// Show new active window:
	//------------------------
	HideActiveWindowHorzScrollBar();

	CWnd* pWndActive = GetActiveWnd();
	if (pWndActive == NULL)
	{
		ASSERT(FALSE);
		pWndParent->SetRedraw(TRUE);
		return FALSE;
	}

	ASSERT_VALID(pWndActive);

	pWndActive->ShowWindow(SW_SHOW);
	if (!m_bHideInactiveWnd)
	{
		pWndActive->BringWindowToTop();
	}

	if (m_bAutoSizeWindow)
	{
		//----------------------------------------------------------------------
		// Small trick: to adjust active window scroll sizes, I should change an
		// active window size twice(+1 pixel and -1 pixel):
		//----------------------------------------------------------------------
		pWndActive->SetWindowPos(NULL, -1, -1, m_rectWndArea.Width() + 1, m_rectWndArea.Height(), SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
		pWndActive->SetWindowPos(NULL, -1, -1, m_rectWndArea.Width(), m_rectWndArea.Height(), SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
	}

	EnsureVisible(m_iActiveTab);

	if (m_bFlat)
	{
		SynchronizeScrollBar();
	}

	//--------------------------------------------------
	// Set text to the parent frame/docking control bar:
	//--------------------------------------------------
	CTabbedPane* pTabControlBar = DYNAMIC_DOWNCAST(CTabbedPane, GetParent());
	if (pTabControlBar != NULL && pTabControlBar->CanSetCaptionTextToTabName()) // tabbed dock bar - redraw caption only in this case
	{
		CString strCaption;
		GetTabLabel(m_iActiveTab, strCaption);

		// miniframe will take the text from the tab control bar
		pTabControlBar->SetWindowText(strCaption);

		CWnd* pWndToUpdate = pTabControlBar;
		if (!pTabControlBar->IsDocked())
		{
			pWndToUpdate = pTabControlBar->GetParent();
		}

		if (pWndToUpdate != NULL)
		{
			pWndToUpdate->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INVALIDATE);
		}
	}

	if (m_bIsActiveTabBold || m_bActiveTabCloseButton)
	{
		RecalcLayout();
	}

	//-------------
	// Redraw tabs:
	//-------------
	Invalidate();
	UpdateWindow();

	if (!bIsFirstTime)
	{
		CView* pActiveView = DYNAMIC_DOWNCAST(CView, pWndActive);
		if (pActiveView != NULL)
		{
			CFrameWnd* pFrame = AFXGetParentFrame(pActiveView);
			ASSERT_VALID(pFrame);

			//pFrame->SetActiveView(pActiveView);
		}
		else if (m_bEnableActivate)
		{
			pWndActive->SetFocus();
		}
	}

	if (m_btnClose.GetSafeHwnd() != NULL)
	{
		//----------------------------------------------------
		// Enable/disable "Close" button according to ability
		// to close an active window:
		//----------------------------------------------------
		BOOL bEnableClose = TRUE;

		HMENU hSysMenu = pWndActive->GetSystemMenu(FALSE)->GetSafeHmenu();
		if (hSysMenu != NULL)
		{
			MENUITEMINFO menuInfo;
			ZeroMemory(&menuInfo,sizeof(MENUITEMINFO));
			menuInfo.cbSize = sizeof(MENUITEMINFO);
			menuInfo.fMask = MIIM_STATE;

			if (!::GetMenuItemInfo(hSysMenu, SC_CLOSE, FALSE, &menuInfo) || (menuInfo.fState & MFS_GRAYED) || (menuInfo.fState & MFS_DISABLED))
			{
				bEnableClose = FALSE;
			}
		}

		m_btnClose.EnableWindow(bEnableClose);
	}

	FireChangeActiveTab(m_iActiveTab);

	if (m_iTabsNum > 1 && bEnableSetRedraw)
	{
		pWndParent->SetRedraw(TRUE);

		const UINT uiRedrawFlags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN;

		if (m_bSetActiveTabByMouseClick)
		{
			CRect rectWindow;
			GetWindowRect(rectWindow);
			GetParent()->ScreenToClient(rectWindow);

			pWndParent->RedrawWindow(rectWindow, NULL, uiRedrawFlags);
		}
		else
		{
			pWndParent->RedrawWindow(NULL, NULL, uiRedrawFlags);
		}
	}


	if (m_iActiveTab != -1 && pTabControlBar != NULL)
	{
		CBasePane* pBar = DYNAMIC_DOWNCAST(CBasePane, GetTabWnd(m_iActiveTab));
		if (pBar != NULL)
		{
			CPaneFrameWnd* pParentMiniFrame = pBar->GetParentMiniFrame();

			if (pBar->GetControlBarStyle() & AFX_CBRS_AUTO_ROLLUP)
			{
        DWORD ControlBarStyle = pTabControlBar->GetControlBarStyle();
				ControlBarStyle |= AFX_CBRS_AUTO_ROLLUP;
        pTabControlBar->SetControlBarStyle(ControlBarStyle);
				if (pParentMiniFrame != NULL)
				{
					pParentMiniFrame->OnSetRollUpTimer();
				}
			}
			else
			{  
        DWORD ControlBarStyle = pTabControlBar->GetControlBarStyle();
				ControlBarStyle &= ~AFX_CBRS_AUTO_ROLLUP;
        pTabControlBar->SetControlBarStyle(ControlBarStyle);
				if (pParentMiniFrame != NULL)
				{
					pParentMiniFrame->OnKillRollUpTimer();
				}

			}
		}
	}
  return TRUE;
}

