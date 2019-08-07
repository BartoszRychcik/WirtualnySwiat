#include "Lis.h"

Lis::Lis(Swiat &swiatref, int x, int y) :Zwierzeta(swiatref, x, y)
	{
	this->sila = 3;
	this->inicjatywa = 7;
	this->symbol = 'L';
	}
	
bool Lis::specjalna_akcja()
	{
	if(this->mozliwosc_wykonania_ruchu())
		{ 
		int przesunX = 0, przesunY = 0;
		while ((przesunX == 0 && przesunY == 0) || (refswiat.Poza_tablice({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY })) || (!refswiat.Wygrany_ruch({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY }, this->sila)))
			{
			przesunX = rand() % 3 - 1;
			przesunY = rand() % 3 - 1;
			}
		refswiat.Wykonaj_ruch(this->lokalizacja.first, this->lokalizacja.second, this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY);
		}
	return true;
	}

bool Lis::specjalna_kolizja(Organizm* inny)
	{
	return false;
	}

bool Lis::mozliwosc_wykonania_ruchu()
	{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i != 0 || j != 0) && refswiat.Wygrany_ruch({ this->lokalizacja.first + i, this->lokalizacja.second + j }, this->sila))
				return true;
	return false;
	}