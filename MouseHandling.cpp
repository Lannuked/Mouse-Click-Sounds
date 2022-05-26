#include "connector.h"

void SoundPlay(int Res)
{
	PlaySound(MAKEINTRESOURCE(Res), NULL, SND_RESOURCE | SND_ASYNC);
}

LRESULT CALLBACK mouseProc(int Code, WPARAM wParam, LPARAM lParam)
{
	MOUSEHOOKSTRUCT* MhookS = (MOUSEHOOKSTRUCT*)lParam;
	if (MhookS != NULL)
	{
		switch (wParam) {
		case WM_LBUTTONDOWN:
			SoundPlay(IDR_WAVE1);
			break;
		case WM_LBUTTONUP:
			SoundPlay(IDR_WAVE2);
			break;
		}
	}
	return CallNextHookEx(MouseHook, Code, wParam, lParam);
}

void CreateAudioStuff()
{
	HINSTANCE hInst = GetModuleHandle(NULL);
	MouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, hInst, NULL);

	MSG message;
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	UnhookWindowsHookEx(MouseHook);
}