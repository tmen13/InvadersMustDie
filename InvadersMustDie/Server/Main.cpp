#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <tchar.h>

#include <stdio.h>
#include "../GameLibrary/Core.h"

LRESULT
CALLBACK
WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	const struct powerup ajux = get_powerup();

	PAINTSTRUCT ps;
	HDC hdc;
	char teste[5];

	TCHAR greeting[100];
	swprintf(greeting, 100, TEXT("Power up: %hs"), powerup_type_string[ajux.type]);
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.  
		// For this introduction, we just print out "Hello, World!"  
		// in the top left corner.  
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.  
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

//
//
// WinMain - Win32 application entry point.
//
//
int
APIENTRY
wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nShowCmd)
{
	// Setup window class attributes.
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(wcex);	// WNDCLASSEX size in bytes
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// Window class styles
	wcex.lpszClassName = TEXT("INVADERSMUSTDIECLASS");	// Window class name
	wcex.hbrBackground = HBRUSH(COLOR_WINDOW + 1);	// Window background brush color.
	wcex.hCursor = LoadCursor(hInstance, IDC_ARROW); // Window cursor
	wcex.lpfnWndProc = WndProc;		// Window procedure associated to this window class.
	wcex.hInstance = hInstance;	// The application instance.

								// Register window and ensure registration success.
	if (!RegisterClassEx(&wcex))
		return 1;

	// Setup window initialization attributes.
	CREATESTRUCT cs;
	ZeroMemory(&cs, sizeof(cs));

	cs.x = 0;	// Window X position
	cs.y = 0;	// Window Y position
	cs.cx = 640;	// Window width
	cs.cy = 480;	// Window height
	cs.hInstance = hInstance; // Window instance.
	cs.lpszClass = wcex.lpszClassName;		// Window class name
	cs.lpszName = TEXT("Invaders Must Die");	// Window title
	cs.style = WS_OVERLAPPEDWINDOW;		// Window style

										// Create the window.
	HWND hWnd = CreateWindowEx(
		cs.dwExStyle,
		cs.lpszClass,
		cs.lpszName,
		cs.style,
		cs.x,
		cs.y,
		cs.cx,
		cs.cy,
		cs.hwndParent,
		cs.hMenu,
		cs.hInstance,
		cs.lpCreateParams);

	// Validate window.
	if (!hWnd)
		return 1;

	// Display the window.
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	// Main message loop.
	MSG msg;
	while (GetMessage(&msg, hWnd, 0, 0) > 0)
		DispatchMessage(&msg);

	// Unregister window class, freeing the memory that was
	// previously allocated for this window.
	UnregisterClass(wcex.lpszClassName, hInstance);

	return int(msg.wParam);
}

