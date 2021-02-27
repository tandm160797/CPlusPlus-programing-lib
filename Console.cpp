#include "Console.hpp"

namespace csl
{
	Color iToColor(int intColor)
	{
		Color color;
		if (intColor == 0)
		{
			color = Color::Black;
		}
		else if (intColor == 1)
		{
			color = Color::DarkBlue;
		}
		else if (intColor == 2)
		{
			color = Color::DarkGreen;
		}
		else if (intColor == 3)
		{
			color = Color::DarkCyan;
		}
		else if (intColor == 4)
		{
			color = Color::DarkRed;
		}
		else if (intColor == 5)
		{
			color = Color::DarkPink;
		}
		else if (intColor == 6)
		{
			color = Color::DarkYellow;
		}
		else if (intColor == 7)
		{
			color = Color::DarkWhite;
		}
		else if (intColor == 8)
		{
			color = Color::Grey;
		}
		else if (intColor == 9)
		{
			color = Color::Blue;
		}
		else if (intColor == 10)
		{
			color = Color::Green;
		}
		else if (intColor == 11)
		{
			color = Color::Cyan;
		}
		else if (intColor == 12)
		{
			color = Color::Red;
		}
		else if (intColor == 13)
		{
			color = Color::Pink;
		}
		else if (intColor == 14)
		{
			color = Color::Yellow;
		}
		else if (intColor == 15)
		{
			color = Color::White;
		}
		return color;
	}
	//
	int inputKey()
	{
		if (_kbhit())
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				return key + 1000;
			}
			return key;
		}
		else
		{
			return KeyNone;
		}
		return KeyNone;
	}
	//
	void resize(int width, int height)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, width * 15, height * 15, TRUE);
	}
	void setTitle(char *title)
	{
		SetConsoleTitle(title);
	}
	void noCursorType()
	{
		CONSOLE_CURSOR_INFO info;
		info.bVisible = FALSE;
		info.dwSize = 20;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}
	void clrscr()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
		HANDLE hConsoleOut;
		COORD Home = { 0, 0 };
		DWORD dummy;
		hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
		FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
		csbiInfo.dwCursorPosition.X = 0;
		csbiInfo.dwCursorPosition.Y = 0;
		SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
	}
	//
	int whereX()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		{
			return csbi.dwCursorPosition.X;
		}
		return -1;
	}
	int whereY()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		{
			return csbi.dwCursorPosition.Y;
		}
		return -1;
	}
	void gotoXY(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	//
	Color getTextColor()
	{
		Color color;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		color = iToColor((info.wAttributes & 0xf));
		return color;
	}
	Color getBgTextColor()
	{
		Color color;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		color = iToColor(((info.wAttributes & 0xf0) >> 4));
		return color;
	}
	void setColor(Color textColor, Color bgTextColor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgTextColor & 0xf) << 4) | (textColor & 0xf));
	}
	void resetColor()
	{
		setTextColor(Color::DarkWhite);
		setBgTextColor(Color::Black);
	}
	void setTextColor(Color color)
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
	}
	void setBgTextColor(Color color)
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((color & 0xf) << 4) | (info.wAttributes & 0xf));
	}
	void resetTextColor()
	{
		setTextColor(Color::DarkWhite);
	}
	void resetTextBgTextColor()
	{
		setBgTextColor(Color::Black);
	}
	//
	char getCharXY(int x, int y)
	{
		char ch;
		HANDLE hOut;
		COORD Where;
		DWORD NumRead;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		Where.X = x;
		Where.Y = y;
		ReadConsoleOutputCharacter(hOut, &ch, 1, Where, &NumRead);
		return ch;
	}
	void setCharXY(int x, int y, char ch)
	{
		gotoXY(x, y);
		printf_s("%c", ch);
	}
	void setCharXY(int x, int y, char ch, Color textColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		printf_s("%c", ch);
	}
	void setCharXY(int x, int y, char ch, Color textColor, Color bgTextColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		setBgTextColor(bgTextColor);
		printf_s("%c", ch);
	}
	void setStringXY(int x, int y, char* str)
	{
		gotoXY(x, y);
		printf_s("%s", str);
	}
	void setStringXY(int x, int y, char* str, Color textColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		printf_s("%s", str);
	}
	void setStringXY(int x, int y, char* str, Color textColor, Color bgTextColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		setBgTextColor(bgTextColor);
		printf_s("%s", str);
	}
	void setIntergerXY(int x, int y, long long interger)
	{
		gotoXY(x, y);
		printf_s("%d", interger);
	}
	void setIntergerXY(int x, int y, long long interger, Color textColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		printf_s("%d", interger);
	}
	void setIntergerXY(int x, int y, long long interger, Color textColor, Color bgTextColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		setBgTextColor(bgTextColor);
		printf_s("%d", interger);
	}
	void setDoubleXY(int x, int y, double realNumber)
	{
		gotoXY(x, y);
		printf_s("%f", realNumber);
	}
	void setDoubleXY(int x, int y, double realNumber, Color textColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		printf_s("%f", realNumber);
	}
	void setDoubleXY(int x, int y, double realNumber, Color textColor, Color bgTextColor)
	{
		gotoXY(x, y);
		setTextColor(textColor);
		setBgTextColor(bgTextColor);
		printf_s("%f", realNumber);
	}
}