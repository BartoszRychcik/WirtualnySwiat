#include "Zolw.h"

Zolw::Zolw(Swiat &swiatref, int x, int y) :Zwierzeta(swiatref, x, y)
	{
	this->sila = 2;
	this->inicjatywa = 1;
	this->symbol = 'Z';
	}

bool Zolw::specjalna_akcja()
	{
	if (this->mozliwosc_wykonania_ruchu())
		return false;
	return true;
	}

bool Zolw::specjalna_kolizja(Organizm* inny)
	{
	if (inny->Pokaz_sile() < 5 && inny->Pokaz_sile() > 0) { refswiat.Informuj(this->Pokaz_symbol(), " odparl ", inny->Pokaz_symbol()); return true; }
	return false;
	}

bool Zolw::mozliwosc_wykonania_ruchu()
	{
	int procenty = rand() % 101;
	if (procenty > 20 && procenty <= 45)return true;
	return false;
	}