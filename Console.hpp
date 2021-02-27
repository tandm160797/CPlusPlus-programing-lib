#ifndef Console_hpp
#define Console_hpp

#include <stdio.h>
#include <conio.h>
#include <windows.h>

namespace csl
{
	enum Color
	{
		Black, DarkBlue, DarkGreen, DarkCyan, DarkRed, DarkPink, DarkYellow, DarkWhite, Grey, Blue, Green, Cyan, Red, Pink, Yellow, White
	};
	enum DirectionKey
	{
		KeyUp = 1072,
		KeyDown = 1080,
		KeyLeft = 1075,
		KeyRight = 1077,
		KeyNone = -1
	};

	Color iToColor(int color);
	//
	int inputKey();
	//
	void resize(int width, int height);
	void setTitle(char *title);
	void noCursorType();
	void clrscr();
	//
	int whereX();
	int whereY();
	void gotoXY(int x, int y);
	//
	Color getTextColor();
	Color getBgTextColor();
	void setColor(Color textColor, Color bgTextColor);
	void resetColor();
	void setTextColor(Color color);
	void setBgTextColor(Color color);
	void resetTextColor();
	void resetTextBgTextColor();
	//
	char getCharXY(int x, int y);
	void setCharXY(int x, int y, char ch);
	void setCharXY(int x, int y, char ch, Color textColor);
	void setCharXY(int x, int y, char ch, Color textColor, Color bgTextColor);
	void setStringXY(int x, int y, char* str);
	void setStringXY(int x, int y, char* str, Color textColor);
	void setStringXY(int x, int y, char* str, Color textColor, Color bgTextColor);
	void setIntergerXY(int x, int y, long long interger);
	void setIntergerXY(int x, int y, long long interger, Color textColor);
	void setIntergerXY(int x, int y, long long interger, Color textColor, Color bgTextColor);
	void setDoubleXY(int x, int y, double realNumber);
	void setDoubleXY(int x, int y, double realNumber, Color textColor);
	void setDoubleXY(int x, int y, double realNumber, Color textColor, Color bgTextColor);
}

#endif //Console.hpp