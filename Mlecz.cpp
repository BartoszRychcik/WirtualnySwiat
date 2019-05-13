#include "Mlecz.h"

Mlecz::Mlecz(Swiat &refswiat, int x, int y) :Rosliny(refswiat, x, y)
	{
	this->sila = 0;
	this->symbol = 'M';
	this->prawdopodobienstwo = 3;
	}

bool Mlecz::specjalna_akcja()
	{
	for(int i=0;i<3;i++)
		this->rozmnazanie(this->lokalizacja.first, this->lokalizacja.second);
	return true;
	}

bool Mlecz::specjalna_kolizja(Organizm* inny)
	{
	return false;
	}

