#pragma once
#include "Znak.h"
#include "Rysuj.h"
class Ramka:public Rysuj
{
public:
	Ramka();
	~Ramka();
	void Pokaz_rysunek();
	void Ustaw_wlasciwosc(int,int);
private:
	int liczba_znakow;
	int szerokosc;
	int wysokosc;
	Znak *znaki; 
	void Skonstruuj_rysunek();
};

