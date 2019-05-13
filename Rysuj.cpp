#include "Rysuj.h"

void Rysuj::Gotoxy(int x, int y)
	{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

void Rysuj::Ustaw_pozycje(int x, int y)
	{
	this->x = x;
	this->y = y;
	}

Rysuj::~Rysuj()
	{
	}