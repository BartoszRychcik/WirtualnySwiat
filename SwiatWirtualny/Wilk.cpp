#include "Wilk.h"

Wilk::Wilk(Swiat &swiatref,int x,int y):Zwierzeta(swiatref,x,y)
	{
	this->sila = 9;
	this->inicjatywa = 5;
	this->symbol = 'W';
	}

bool Wilk::specjalna_akcja()
	{
	return false;
	}

bool Wilk::specjalna_kolizja(Organizm* inny)
	{
	return false;
	}

bool Wilk::mozliwosc_wykonania_ruchu()
	{
	return true;
	}