#include "Jagody.h"

Jagody::Jagody(Swiat &refswiat, int x, int y) :Rosliny(refswiat, x, y)
	{
	this->sila = 99;
	this->symbol = 'J';
	this->prawdopodobienstwo = 5;
	}

bool Jagody::specjalna_akcja()
	{
	return false;
	}

bool Jagody::specjalna_kolizja(Organizm* inny)
	{
	refswiat.Informuj(this->Pokaz_symbol(), " otrul ", inny->Pokaz_symbol());
	refswiat.Usun_organizm(*inny);
	refswiat.Usun_organizm(*this);
	return true;
	}