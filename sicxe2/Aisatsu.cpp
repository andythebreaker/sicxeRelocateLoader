#include "pch.h"
#include "Aisatsu.h"

#define setdbg false
#define dbg if(setdbg)
#define consts "andythebreaker loader"

Aisatsu::Aisatsu()
{
	consts_ = consts;
	consth = consts_.length();

#ifdef __linux__ 
	//linux code goes here

	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	dbg printf("lines %d\n", w.ws_row);
	dbg printf("columns %d\n", w.ws_col);
	Tcolumns = columns;
	Trows = rows;

#elif _WIN32
	// windows code goes here

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	dbg printf("columns: %d\n", columns);
	dbg printf("rows: %d\n", rows);
	Tcolumns = columns;
	Trows = rows;
#else

#endif
}

void Aisatsu::greeting() {
	for (size_t i = 0; i < (Tcolumns- consth)/2; i++)
	{
		cout << "=";
	}
	cout << consts;
	for (size_t i = 0; i < Tcolumns-(Tcolumns - consth) / 2 - consth; i++)
	{
		cout << "=";
	}
}

void Aisatsu::greeting(string midword) {
	for (size_t i = 0; i < (Tcolumns - midword.length()) / 2; i++)
	{
		cout << "=";
	}
	cout << midword;
	for (size_t i = 0; i < Tcolumns - (Tcolumns - midword.length()) / 2 - midword.length(); i++)
	{
		cout << "=";
	}
}

Aisatsu::~Aisatsu()
{
}
