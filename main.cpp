#include "connector.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	theHInst = hInstance;
	MSG msg = { 0 };
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "ScrSave";

	if (!RegisterClass(&wc))
		return 1;

	if (!CreateWindow(wc.lpszClassName,
		0,
		SS_NOTIFY,
		0, 0, 0, 0, 0, 0, 0, 0))
		return 2;

	while (GetMessage(&msg, NULL, 0, 0) > 0)
		DispatchMessage(&msg);

	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		AppendMenu(hMenuPopup, MF_STRING, 1000, TEXT("Exit"));
		CreateIcon(theHInst, hWnd);
		thread A(CreateAudioStuff);
		A.detach();
		break;
	}
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		if (wParam == 1000) 
		{
			ExitProcess(0);
		}
		break;
	case WM_APP + 1:
	{
		switch (lParam) 
		{
		case WM_RBUTTONUP:
		{
			ShowTheMenu(hWnd);
			break;
		}
		}
		break;
	}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}