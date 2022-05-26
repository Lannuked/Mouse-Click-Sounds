#pragma once
#include <windows.h>
#include <iostream>
#include <thread>
#include "Resource.h"
using namespace std;

extern HMENU hMenuPopup;
extern HHOOK MouseHook;
extern HINSTANCE theHInst;

void CreateAudioStuff();
void SoundPlay(int Res);
void ShowTheMenu(HWND hwnd);
void CreateIcon(HINSTANCE hInst, HWND hwnd);
LRESULT CALLBACK mouseProc(int Code, WPARAM wParam, LPARAM lParam);