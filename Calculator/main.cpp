//----------------------------------------//
//                                        //
// Created in 2/15/2024 by Kiarash Salehi //
//                                        //
//----------------------------------------//

#include "Create.h"
#include "Resource.h"

// FANCTIONS //

bool Init(HINSTANCE, int);
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

// VALUES //

double result = 0.00000;
double num1 = 0.00000;
double num2 = 0.00000;
char _operator;
wchar_t Text[256];

//Main Window fanction
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	if (!Init(hInstance, nCmdShow))
	{
		return 0;
	}
	SendMessage(TextField, WM_SETFONT, (WPARAM)tFont, TRUE);
	for (int i = 0;i < 19; i++)
	{
		SendMessage(BUTTONARRAY[i], WM_SETFONT, (WPARAM)bFont, TRUE);
	}
	MSG message = {};
	while (GetMessage(&message, 0, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return 0;
}



// Init Window
bool Init(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASS wc = {};
	wc.hbrBackground = CreateSolidBrush(RGB(192, 192, 192));
	wc.lpszClassName = TEXT("WinMain");
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	RegisterClass(&wc);
	HWND hwnd = CreateWindowEx(
		0,
		TEXT("WinMain"),
		TEXT("Calculator"),
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		450,
		600,
		0,
		0,
		hInstance,
		0
	);
	if (hwnd == 0) { return false; }
	ShowWindow(hwnd, nCmdShow);
	return true;
}

// Window Proc
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	case WM_CREATE:
	{
		// TextField creation
		TextField = CreateWindowEx(
			WS_EX_CLIENTEDGE,           
			L"EDIT",                     
			L"\0",                         
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_READONLY | ES_RIGHT,
			10, 10, 410, 80,            
			hwnd,                       
			NULL,                       
			NULL,                       
			NULL                        
		);

		// Buttons creation
		createButton(hwnd);
		break;
	}

	// Handle Buttons
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_ONE:
		{
			wcscat_s(Text, L"1");

			SetWindowText(TextField, Text);
			break;
		}
		case ID_BUTTON_TWO:
		{
			wcscat_s(Text, L"2");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_THREE:
		{
			wcscat_s(Text, L"3");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_FOUR:
		{
			wcscat_s(Text, L"4");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_FIVE:
		{
			wcscat_s(Text, L"5");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_SIX:
		{
			wcscat_s(Text, L"6");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_SEVEN:
		{
			wcscat_s(Text, L"7");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_EIGHT:
		{
			wcscat_s(Text, L"8");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_NINE:
		{
			wcscat_s(Text, L"9");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_ZERO:
		{
			wcscat_s(Text, L"0");

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_PLUS:
		{
			num1 = wcstod(Text, 0);
			_operator = '+';
			Text[0] = 0;
			SetWindowText(TextField, 0);
			
			
		}
			break;
		case ID_BUTTON_SUB:
		{
			num1 = wcstod(Text, 0);
			_operator = '-';
			for (int i = 0; i < wcslen(Text); i++) { Text[i] = 0; }
			SetWindowText(TextField, 0);


		}
			break;
		case ID_BUTTON_EQUAL:
		{
			switch (_operator)
			{
			case '+':
			{
				num2 = wcstod(Text, 0);
				result = num1 + num2;
			}
				break;
			case '-':
			{
				num2 = wcstod(Text, 0);
				result = num1 - num2;
			}
				break;
			case '*':
			{
				num2 = wcstod(Text, 0);
				result = num1 * num2;
			}
				break;
			case '/':
			{
				num2 = wcstod(Text, 0);
				result = num1 / num2;
			}
				break;
			default:
				break;
			}
			num1 = 0.0;
			_operator = '\0';
			std::string resStr = std::to_string(result);
			swprintf(Text, resStr.length(), L"%f", result);
			if (result - round(result) == 0)
			{
				for (int i = wcslen(Text); i > 0; i--)
				{
					if (Text[i] == L'.')
					{
						Text[i] = 0;
						break;
					}
					else
					Text[i] = 0;
				}
			}
			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_MULTIPLY:
		{
			num1 = wcstod(Text, 0);
			_operator = '*';
			for (int i = 0; i < wcslen(Text); i++) { Text[i] = 0; }
			SetWindowText(TextField, 0);


		}
			break;
		case ID_BUTTON_DIV:
		{
			num1 = wcstod(Text, 0);
			_operator = '/';
			for (int i = 0; i < wcslen(Text); i++) { Text[i] = 0; }
			SetWindowText(TextField, 0);


		}
			break;
		case ID_BUTTON_CLEAR:
		{
			Text[0] = 0;
			_operator = '\0';
			SetWindowText(TextField, 0);
		}
			break;
		case ID_BUTTON_DELETE:
		{
			int length = wcslen(Text);
			if(length > 0)
			Text[length - 1] = 0;

			SetWindowText(TextField, Text);
		}
			break;
		case ID_BUTTON_DECIMAL:
		{
			wcscat_s(Text, L".");
			SetWindowText(TextField, Text);

		}
			break;
		case ID_BUTTON_NEGTIVE:
		{
			if (Text[0] != 0)
			{
				if (Text[0] != L'-' && Text[1] != L'-')
				{
					for (int i = wcslen(Text); i >= 0; i--) { Text[i + 1] = Text[i]; }
					Text[0] = L'-';
				}
				else if (Text[0] == L'-')
				{
					for (int i = 0; i < wcslen(Text); i++) { Text[i] = Text[i + 1]; }
				}
			}


			SetWindowText(TextField, Text);


		}
			break;

		}
		
		break;
	}
	case WM_CLOSE:
		DeleteObject(Text);
		DestroyWindow(hwnd);
		break;
	default:
		return ::DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
