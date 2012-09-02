#include "VirtualKeyboardApp.h"
BOOL VirtualKeyboardApp::InitInstance()
{
	
	m_pMainWnd = &VKeyboard;
	INT_PTR nResponse = VKeyboard.DoModal();
	return FALSE;
}