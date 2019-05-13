#pragma once
#include "Menu.h"
#include "Znak.h"
#include <string.h>
#include <iostream>
using namespace std;
class Interface
{
public:
	Interface();
	~Interface();
	void Start();
	bool Pobierz_dane(pair<int,int>*);
	bool Pobierz_dane(string&);
	bool Pobierz_dane(pair<int, int>*, string&);
	void Pokaz_swiat(int, pair<int, int>);
private:
	int Wybierz_opcje();
	enum RUCH { GORA = 0x48, DOL = 0x50, LEWO = 0x4b, PRAWO = 0x4d };
	enum tryb{start,odczyt_rozmiaru,odczyt_nazwy};
	int x, y;
	Znak przelacznik;
	Znak wskaznik;
	Menu *moje_menu;
};

