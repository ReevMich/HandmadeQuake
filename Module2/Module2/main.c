#include <windows.h>
#include<stdio.h>


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
			//IsRunning = FALSE;
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
		"Lesson 2.3",
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

	// LARGE INTEGER struct data structure
	LARGE_INTEGER frequency;

	// Find out what the frequency of what our program is running at.
	QueryPerformanceFrequency(&frequency);
	
	// convert frequency to the number of loops per second.
	double secondsPerTick = 1.0 / (double)frequency.QuadPart;


	// Time ticker. Tock is used to measure how long it takes for the 
	// game loop execute all the code inside. As for the Tick it measures the complete time its
	// taken since the last Tick which happens before the game loop ends.
	LARGE_INTEGER tick,tock;
	QueryPerformanceCounter(&tick); // Tick

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
		Sleep(1000);
		QueryPerformanceCounter(&tock); // Tock

		// Calculating the time it took to run the code above.
		__int64 interval = tock.QuadPart - tick.QuadPart;
		double secondsGoneBy = (double)interval * secondsPerTick;

		char buf[64];
		sprintf_s(buf, 64, "Total time: %3.7f \n", secondsGoneBy );
		OutputDebugString(buf);

		QueryPerformanceCounter(&tick); // Tick 
	}

	return 0;
}