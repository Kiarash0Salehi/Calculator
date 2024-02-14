#include <windows.h>

// CreateButton fanction
HWND CreateButton(int Handle, HWND ParentWindow, int x, int y, int width, int height, LPCWSTR Text)
{
	return CreateWindow(
		L"BUTTON",
		Text,
		WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
		x,
		y,
		width,
		height,
		ParentWindow,
		(HMENU)Handle,
		(HINSTANCE)GetWindowLongPtr(ParentWindow, GWLP_HINSTANCE),
		0
	);
}
