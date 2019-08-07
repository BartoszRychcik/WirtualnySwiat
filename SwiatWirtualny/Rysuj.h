#pragma once
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
class Rysuj
{
public:
	virtual void Ustaw_pozycje(int, int);
	virtual void Pokaz_rysunek()= 0;
protected:
	enum znaki { poziomy = 205, pionowy = 186, lewy_dolny = 200, lewy_gorny = 201, prawy_gorny = 187, prawy_dolny = 188 };
	void Gotoxy(int, int);
	int x;
	int y;
	virtual ~Rysuj();
};

