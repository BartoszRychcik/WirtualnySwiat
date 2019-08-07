#include "Guarana.h"

Guarana::Guarana(Swiat &refswiat, int x, int y) :Rosliny(refswiat, x, y)
	{
	this->sila = 0;
	this->symbol = 'G';
	this->prawdopodobienstwo = 4;
	}

bool Guarana::specjalna_akcja()
	{
	return false;
	}

bool Guarana::specjalna_kolizja(Organizm* inny)
	{
	refswiat.Informuj(this->Pokaz_symbol(), " wzmocnil ", inny->Pokaz_symbol());
	inny->Ustaw_sile(inny->Pokaz_sile() + 3);
	return false;
	}