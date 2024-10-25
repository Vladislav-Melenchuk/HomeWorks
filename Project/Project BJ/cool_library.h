/*********************************************************************/
/*                                                                   */
/*    ConsoleLib [Release 2.7]                                       */
/*    Console Utility Functions Library                              */
/*                                                                   */
/*    Copyright (�) 2005-2023, Oleksandr Zahoruiko                   */
/*                                                                   */
/*    E-mail:   sunmeatrich@gmail.com                                */
/*    Web:      http://sunmeat.github.io/                            */
/*                                                                   */
/*********************************************************************/

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <random>
#include <ctime>
using namespace std;

// ������ �������
HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE h_in = GetStdHandle(STD_INPUT_HANDLE);
HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

//////////////////////////////////////////////////////////////////////////////////
// �������� ���������� � ���������:
unsigned int console_window_width = 120 * 8; // px
unsigned int console_window_height = 30 * 12; // px
bool random_started = false; // ��� �� ������� �������� ��������� ��������� �����

const double PI = 3.141592653589793;
const double E = 2.718281828459045;

//////////////////////////////////////////////////////////////////////////////////
// ���� ������������:

// �����
enum ConsoleColor
{
	BLACK = 0,
	DARKBLUE = 1,
	DARKGREEN = 2,
	DARKCYAN = 3,
	DARKRED = 4,
	DARKMAGENTA = 5,
	DARKYELLOW = 6,
	GREY = 7,
	GRAY = 7,
	DARKGREY = 8,
	DARKGRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	MAGENTA = 13,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15
};

// ���� ������
enum ConsoleKeys
{
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
	ENTER = 13,
	RETURN = 13,
	BACKSPACE = 8,
	SPACE = 32,
	ESCAPE = 27
};

//////////////////////////////////////////////////////////////////////////////////
// ��������� ���������� �������:

// ������������� ��������� ����������� ����
void SetTitle(string title = "My Console App");

// ������������� ������� ��� ����������� ���� � ������� �� ������ � ������
void SetConsoleWindowColumnsAndRows(unsigned int columns, unsigned int rows);

// ������������� ������� ��� ����������� ���� � ��������
void SetConsoleWindowSize(unsigned int width, unsigned int height);

// ������������ ���������� ���� �� ������ ������
void CenterScreen();

// ��������/��������� ��������� ���������
void SetCyrillicEncoding(bool cyrillic = true);

// ������� ����� �������
void ClearScreen();

// ��������� �������
void Exit();

// ����������/������ ��������� ������
void ShowCursor(bool visible);

// ������������� ���� �������� � ����
void SetColor(ConsoleColor foreground, ConsoleColor background);

// ���������� ������ � �������� �������
void GotoXY(int x, int y);

// ������� �������� ������ � �������� �������
void WriteText(int x, int y, string text);

// ������� �������� ������, ������� � �������� �������
void WriteChar(int x, int y, char symbol);

// ������� ��������� ���������� �������� �������� ������� � �������� �������
void WriteChars(int x, int y, char symbol, unsigned int length);

// ��������� �������� ��������� ��������� �����
void StartRandomize();

// ���������� ��������� ����� ����� � �������� ���������
int NextInt(int min, int max);

// ���������� ��������� ������������ ����� � �������� ���������
double NextDouble(double min, double max);

// ������� ��������� �������� ���� ����������� ����
void QuickSetup(string title = "My Console App", int columns = 120, int rows = 30);

//////////////////////////////////////////////////////////////////////////////////
// ����������:

// ������������� ��������� ����������� ����
void SetTitle(string title)
{
	title = "title " + title;
	system(title.c_str());
}

// ������������� ������� ��� ����������� ���� � ������� �� ������ � ������
void SetConsoleWindowColumnsAndRows(unsigned int columns, unsigned int rows)
{
	string width = to_string(columns);
	string height = to_string(rows);
	string command = "mode con cols=" + width + " lines=" + height;
	system(command.c_str());

	COORD bufferSize;
	bufferSize.X = columns; // ������ ������
	bufferSize.Y = 1001; // ������ ������
	SetConsoleScreenBufferSize(h_out, bufferSize);
}

// ������������� ������� ��� ����������� ���� � ��������
void SetConsoleWindowSize(unsigned int width, unsigned int height)
{
	if (width > 1200) width = 1200;
	if (height > 600) height = 600;
	console_window_width = width;
	console_window_height = height;
	MoveWindow(hwnd, 10, 10, width, height, true);
}

// ������������ ���������� ���� �� ������ ������
void CenterScreen()
{
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);
	int left_shift = (desktop_width - console_window_width) / 2;
	int top_shift = (desktop_height - console_window_height) / 2;
	MoveWindow(hwnd, left_shift, top_shift, console_window_width, console_window_height, true);
}

// ��������/��������� ��������� ���������
void SetCyrillicEncoding(bool cyrillic)
{
	if (cyrillic) setlocale(0, "UKR");
	else setlocale(0, "C");
}

// ������� ����� �������
void ClearScreen()
{
	system("cls");
}

// ��������� �������
void Exit()
{
	int code = _getch();
	SetConsoleTextAttribute(h_in, (WORD)ConsoleColor::BLACK);
}

// ����������/������ ��������� ������
void ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(h_out, &cci);
}

// ������������� ���� �������� � ����
void SetColor(ConsoleColor foreground, ConsoleColor background)
{
	SetConsoleTextAttribute(h_out, (WORD)((background << 4) | foreground));
}

// ���������� ������ � �������� �������
void GotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(h_out, coord);
}

// ������� �������� ������ � �������� �������
void WriteText(int x, int y, string text)
{
	GotoXY(x, y);
	cout << text;
}

// ������� �������� ������, ������� � �������� �������
void WriteChar(int x, int y, char symbol)
{
	GotoXY(x, y);
	cout << symbol;
}

// ������� ��������� ���������� �������� �������� ������� � �������� �������
void WriteChars(int x, int y, char symbol, unsigned int length)
{
	GotoXY(x, y);
	for (unsigned int i = 0; i < length; i++)
		cout << symbol;
}

// ��������� �������� ��������� ��������� �����
void StartRandomize()
{
	srand(time(0));
	rand();
	random_started = true;
}

// ���������� ��������� ����� ����� � �������� ���������
int NextInt(int min, int max)
{
	if (!random_started) StartRandomize();
	if (min > max) swap(min, max);
	return (rand() * rand()) % (max - min + 1) + min;
}

// ���������� ��������� ������������ ����� � �������� ���������
double NextDouble(double min, double max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(min, max);

	return round(dist(gen) * 100000.0) / 100000.0;
}

// ������� ��������� �������� ���� ����������� ����
void QuickSetup(string title, int columns, int rows)
{
	SetTitle(title);
	SetConsoleWindowColumnsAndRows(columns, rows);
	SetConsoleWindowSize(1000, 500);
	CenterScreen();
	ShowCursor(false);
	StartRandomize();
	SetCyrillicEncoding();
}