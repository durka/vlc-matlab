#include <stdio.h>
#include <fcntl.h>
#include <windows.h>
#pragma comment(lib,"user32.lib")

const char g_szClassName[] = "vlc-matlab";
HINSTANCE g_hInstance;

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void real_create_window(HWND *out, int x, int y, int w, int h, const char *title)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = g_hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc) && GetLastError() != ERROR_CLASS_ALREADY_EXISTS)
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
		hwnd = (HWND)-1;
        return;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        title == NULL ? "VLC-Matlab" : title,
        WS_OVERLAPPEDWINDOW,
        x, y, w, h,
        NULL, NULL, g_hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
		hwnd = (HWND)-1;
        return;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);
	
	*out = hwnd;

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}

DWORD WINAPI ThreadFunc(LPVOID param)
{
	real_create_window(param, CW_USEDEFAULT, CW_USEDEFAULT, 720, 480, NULL);
	
	return 0;
}

__declspec(dllexport)
HWND create_window(int x, int y, int w, int h, const char *title)
{
	HANDLE thread;
	HWND hwnd;
	
	thread = CreateThread(NULL, 0, &ThreadFunc, &hwnd, 0, NULL);
	while (hwnd == NULL);
	
	return hwnd;
}

__declspec(dllexport)
void close_window(HWND hwnd)
{
	if (hwnd) SendMessage(hwnd, WM_CLOSE, 0, 0);
}

/*
void SetStdOutToNewConsole()
{
  int hConHandle;
  long lStdHandle;
  FILE *fp;

  // allocate a console for this app
  AllocConsole();

  // redirect unbuffered STDOUT to the console
  lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
  hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
  fp = _fdopen( hConHandle, "w" );
  *stdout = *fp;

  setvbuf( stdout, NULL, _IONBF, 0 );
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	g_hInstance = hInstance;
	
	// get a console (FIXME remove this)
	SetStdOutToNewConsole();
	
	hwnd = create_window(CW_USEDEFAULT, CW_USEDEFAULT, 720, 480, NULL);
	printf("hwnd = %x\n", hwnd);
	getch();
	close_window(hwnd);
	
	return 0;
}
*/
