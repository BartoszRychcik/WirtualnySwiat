#pragma once
#include "Znak.h"
#include "Napis.h"
#include "Przycisk.h"
#include "Ramka.h"
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void Pokaz_menu(int);
	void Pokaz_swiat(int, pair<int, int>);
	void Ustaw_wlasciwosc(string);
private:
	enum menu {startowe,odczyt_liczb,odczyt_nazwy};
	static string Lokalne_Menu[16];
	const int ile_opcji_start = 3;
	const int ile_opcji_odczyt = 1;
	string tytul_menu;
	Ramka *glowna;
	Ramka *opcje;
	Przycisk *wybieranie;
	Napis *tytulowy;
	void Skonstruuj_menu(int);
};

