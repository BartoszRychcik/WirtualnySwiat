#include "Ramka.h"
#define MAX_SIZE_RAMKI 4000 //zalozenie ¿e nie bedzie potrzeba wiekszego interfejsu niz 1000 na 1000 (potrzebne do wywolania konstruktorów bazowych)

Ramka::Ramka():znaki(new Znak[MAX_SIZE_RAMKI])
	{
	this->x = 0;
	this->y = 0;
	this->szerokosc = 0;
	this->wysokosc = 0;
	}

void Ramka::Pokaz_rysunek()
	{
	Skonstruuj_rysunek();
	for (int i = 0; i <= this->liczba_znakow; i++)
		znaki[i].Pokaz_rysunek();
	}

void Ramka::Skonstruuj_rysunek()
	{
	this->liczba_znakow = 0;
	znaki[liczba_znakow].Ustaw_pozycje(x, y);
	znaki[liczba_znakow].Ustaw_wlasciwosc(char(lewy_gorny));
	for (int j = 0; j < szerokosc; j++)
		{
		znaki[++liczba_znakow].Ustaw_pozycje(++x, y);
		znaki[liczba_znakow].Ustaw_wlasciwosc(char(poziomy));
		}
	znaki[++liczba_znakow].Ustaw_pozycje(++x, y);
	znaki[liczba_znakow].Ustaw_wlasciwosc(char(prawy_gorny));
	
	for(int j=0;j<wysokosc;j++)
		{
		znaki[++liczba_znakow].Ustaw_pozycje(x, ++y);
		znaki[liczba_znakow].Ustaw_wlasciwosc(char(pionowy));
		znaki[++liczba_znakow].Ustaw_pozycje(x-szerokosc-1, y);
		znaki[liczba_znakow].Ustaw_wlasciwosc(char(pionowy));
		}
	znaki[++liczba_znakow].Ustaw_pozycje(x-szerokosc-1, ++y);
	znaki[liczba_znakow].Ustaw_wlasciwosc(char(lewy_dolny));
	znaki[++liczba_znakow].Ustaw_pozycje(x, y);
	znaki[liczba_znakow].Ustaw_wlasciwosc(char(prawy_dolny));
	x = x - szerokosc-1;

	for (int j = 0; j < szerokosc; j++)
		{
		znaki[++liczba_znakow].Ustaw_pozycje(++x, y);
		znaki[liczba_znakow].Ustaw_wlasciwosc(char(poziomy));
		}
	}

void Ramka::Ustaw_wlasciwosc(int szerokosc,int wysokosc)
	{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	}

Ramka::~Ramka()
	{
	delete[] znaki;
	}
