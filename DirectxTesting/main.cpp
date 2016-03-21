#include <WindowsX.h>
#include <stdio.h>
#include "graphics.h"
#include "Level1.h"
#include "gameController.h"
// hInstance: This is an ID for the application which the OS uses to load some resouces, such as windows, icons and bitmaps
// hPrevInstance: Always NULL nowadays, it was used in 16 bit programs as a handle to an already running instance of the app
// pCmdLine: Command line arguments
// nCmdShow: Starting windows size (minimized or maximized)

// hwnd: handle to the window
// uMsg: the event message

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	wchar_t msg[32];
	bool static max = false;
	
		if (GetKeyState(VK_ESCAPE) & 0x8000) { DestroyWindow(hwnd); }
		if (GetKeyState(VK_TAB) & 0x8000 && max == false){ ShowWindow(hwnd, SW_MAXIMIZE); max = !max; }
		else if (GetKeyState(VK_TAB) & 0x8000 && max == true) { ShowWindow(hwnd, SW_RESTORE); max = !max; }
		if (GetKeyState(VK_MENU) & 0x8000) { CloseWindow(hwnd); }

	if (uMsg == WM_DESTROY) { PostQuitMessage(0); return 0;}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow)
{

	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClass.hInstance = hInstance;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.lpszClassName = "MainWindow";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;



	RegisterClassEx(&windowClass);

	RECT rect = { 0, 0, 800, 600 };
	AdjustWindowRectEx(&rect, WS_EX_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", "DirectX Window!", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left,
		rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowHandle)
	{
		return -1;
	}
	graphics = new Graphics();
	if (!graphics->Init(windowHandle))
	{
		delete graphics;
		return -1;
	}

	GameLevel::Init(graphics);

	ShowWindow(windowHandle, nCmdShow);

	GameController::LoadInitialLevel(new Level1());

	MSG message;
	message.message = WM_NULL;
	

	//game loop
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&message);
		}
		else
		{
			GameController::Update();
			graphics->BeginDraw();
			GameController::Render();
			graphics->EndDraw();
		}
	}
}
