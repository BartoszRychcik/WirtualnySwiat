#include "Trawa.h"

Trawa::Trawa(Swiat &refswiat,int x,int y):Rosliny(refswiat,x,y)
	{
	this->sila = 0;
	this->symbol = 'T';
	this->prawdopodobienstwo = 4;
	}

bool Trawa::specjalna_akcja()
	{
	return false;
	}	

bool Trawa::specjalna_kolizja(Organizm* inny)
	{
	return false;
	}
