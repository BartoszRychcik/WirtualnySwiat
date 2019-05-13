#include "Antylopa.h"

Antylopa::Antylopa(Swiat &swiatref, int x, int y) :Zwierzeta(swiatref, x, y)
	{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbol = 'A';
	}

bool Antylopa::specjalna_akcja()
	{
	int przesunX = 0, przesunY = 0;
	while ((przesunX == 0 && przesunY == 0) || (refswiat.Poza_tablice({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY })))
		{
		przesunX = rand() % 5 - 2;
		przesunY = rand() % 5 - 2;
		}
	refswiat.Wykonaj_ruch(this->lokalizacja.first, this->lokalizacja.second, this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY);
	return true;
	}

bool Antylopa::specjalna_kolizja(Organizm* inny)
	{
	if (this->mozliwosc_wykonania_ruchu())
		{
		int przesunX = 0, przesunY = 0;
		while ((przesunX == 0 && przesunY == 0) || (!refswiat.Puste_miejsce({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY })))
			{
			przesunX = rand() % 3 - 1;
			przesunY = rand() % 3 - 1;
			}
		refswiat.Wykonaj_ruch(this->lokalizacja.first, this->lokalizacja.second, this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY);
		refswiat.Informuj(this->Pokaz_symbol()," ucieka przed ",inny->Pokaz_symbol());
		return true;
		}
	return false;
	}	

bool Antylopa::mozliwosc_wykonania_ruchu()
	{
	int szansa = rand() % 2;
	bool czy_moze_sie_ruszyc = false;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i != 0 || j != 0) && refswiat.Puste_miejsce({ this->lokalizacja.first + i, this->lokalizacja.second + j }))
				czy_moze_sie_ruszyc = true;

	if (szansa == 0 && czy_moze_sie_ruszyc)return true;
	return false;
	}