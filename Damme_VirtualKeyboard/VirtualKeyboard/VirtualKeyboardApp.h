
// Phan xu ly doccument and view. VirtualKeyboardApp se xu ly cac thong diep
// chuan cua windows
// no duoc ke thua tu ham CWinApp
#include "VirtualKeyboard.h"
class VirtualKeyboardApp:public CWinApp
{
	VirtualKeyboard VKeyboard;
public:
	BOOL InitInstance();
	HICON hIcon1;
};
VirtualKeyboardApp vKeyboard;