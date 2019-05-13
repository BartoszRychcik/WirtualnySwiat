#include "Napis.h"

Napis::Napis()
	{
	this->napis = "";
	this->x = 0;
	this->y = 0;
	}

void Napis::Ustaw_wlasciwosc(std::string tresc_napisu)
	{
	this->napis = tresc_napisu;
	}

void Napis::Pokaz_rysunek()
	{
	Gotoxy(x, y); printf("%s", napis.c_str());
	}