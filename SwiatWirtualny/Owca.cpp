#include "Owca.h"

Owca::Owca(Swiat &swiatref, int x, int y) :Zwierzeta(swiatref, x, y)
	{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbol = 'O';
	}

bool Owca::specjalna_akcja()
	{
	return false;
	}

bool Owca::specjalna_kolizja(Organizm* inny)
	{
	return false;
	}

bool Owca::mozliwosc_wykonania_ruchu()
	{
	return true;
	}