#include "Znak.h"

Znak::Znak()
	{
	this->x = 0;
	this->y = 0;
	this->znak = ' ';
	}

void Znak::Ustaw_wlasciwosc(char wyswietlany_znak)
	{
	this->znak = wyswietlany_znak;
	}

void Znak::Pokaz_rysunek()
	{
	Gotoxy(x, y); printf("%c", znak);
	}
