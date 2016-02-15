#include <windows.h>


BOOL IsRunning = TRUE;

LRESULT CALLBACK MainWindProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	// Catch any relevant windows messages here.
	switch (uMsg)
	{
		case WM_KEYUP:
			IsRunning = FALSE;
			break;
		case WM_ACTIVATE:
		case WM_CREATE:
		case WM_DESTROY:
			IsRunning = FALSE;
			break;

		default:
			result = DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return result;
}

// Entry point for windows applications.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// initalize this object to 0.
	// Only initialze the properties we actually need.
	WNDCLASS winClass = { 0 } ;
	winClass.lpfnWndProc = MainWindProc;
	winClass.hInstance = hInstance;
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.lpszClassName = "Module 2";

	if (!RegisterClass(&winClass))
		exit(EXIT_FAILURE); // Just shuts down the application OR return 1;

	// Window Handle
	HWND mainWindow;
	//Window Style
	DWORD windowStyle = WS_OVERLAPPEDWINDOW;

	// Rect to define the exact size of the window we want.
	RECT rect = { 0 };
	rect.right = 800;
	rect.bottom = 600;

	// Adjust the window to the specific dimensions of rect.
	AdjustWindowRect(&rect, windowStyle, 0);

	// Window creation
	mainWindow =  CreateWindowEx(
		0,
		"Module 2",
		"Lesson 2.1",
		windowStyle,
		200,		
		200,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		hInstance,
		0
		);

	// Makes the window visible
	ShowWindow(mainWindow, SW_SHOWDEFAULT);

	// Handle to the Device Context
	HDC deviceContext = GetDC(mainWindow);
	PatBlt(deviceContext, 0, 0, 800, 600, BLACKNESS);
	ReleaseDC(mainWindow, deviceContext);

	// Windows message
	MSG msg;
	LRESULT result;
	// Game Loop
	while (IsRunning)
	{
		// Check in with the OS

		if (PeekMessage(&msg, NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			result = DispatchMessage(&msg);

		}

		// Update our game if its time to
		// Draw graphics if it's time to
	}

	return 0;
}