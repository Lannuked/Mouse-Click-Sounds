#include "connector.h"

void ShowTheMenu(HWND hwnd)
{
	SetForegroundWindow(hwnd);
	POINT pt;
	GetCursorPos(&pt);

	ClientToScreen(hwnd, &pt);
	TrackPopupMenu(hMenuPopup,
		0,
		pt.x,
		pt.y,
		0,
		hwnd,
		NULL);
}

void CreateIcon(HINSTANCE hInst, HWND hwnd)
{
	HICON TheIcon = LoadIcon(hInst, MAKEINTRESOURCE(MAINICON));

	NOTIFYICONDATA IconDat = {};
	IconDat.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	IconDat.hWnd = hwnd;
	IconDat.uCallbackMessage = WM_APP + 1;
	IconDat.hIcon = TheIcon;

	Shell_NotifyIcon(NIM_ADD, &IconDat);
}