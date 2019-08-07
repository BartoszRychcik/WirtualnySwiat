#include "Barszcz.h"

Barszcz::Barszcz(Swiat &refswiat, int x, int y) :Rosliny(refswiat, x, y)
	{
	this->sila = 10;
	this->symbol = 'B';
	this->prawdopodobienstwo = 3;
	}

bool Barszcz::specjalna_akcja()
	{
	refswiat.Informuj(this->Pokaz_symbol(), " czysci okol. ", '\0');
	refswiat.Wyczysc_okolice(1,this->lokalizacja.first,this->lokalizacja.second);
	return true;
	}

bool Barszcz::specjalna_kolizja(Organizm* inny)
	{
	refswiat.Informuj(this->Pokaz_symbol(), " otrul ", inny->Pokaz_symbol());
	refswiat.Usun_organizm(*inny);
	refswiat.Usun_organizm(*this);
	return true;
	}