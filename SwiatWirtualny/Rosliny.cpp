#include "Rosliny.h"

Rosliny::Rosliny(Swiat &swiatref, int x, int y):Organizm(swiatref, x, y)
	{
	this->inicjatywa = 0;
	}

Rosliny::~Rosliny()
	{
	}

void Rosliny::akcja()
	{
	if (specjalna_akcja())return;
	else this->rozmnazanie(this->lokalizacja.first,this->lokalizacja.second);
	}

void Rosliny::rozmnazanie(int x,int y)
	{
	if (this->mozliwosc_rozmnazania())
		{
		int przesunX = 0, przesunY = 0;
		while ((przesunX == 0 && przesunY == 0) || (!refswiat.Puste_miejsce({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY })))
			{
			przesunX = rand() % 3 - 1;
			przesunY = rand() % 3 - 1;
			}
		refswiat.Dodaj_organizm(this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY, this->symbol);
		}
	}

bool Rosliny::mozliwosc_rozmnazania()
{
	int szansa = rand() % 100;
	bool czy_jest_miejsce_na_nasiona = false;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i != 0 || j != 0) && refswiat.Puste_miejsce({ this->lokalizacja.first + i, this->lokalizacja.second + j }))
				czy_jest_miejsce_na_nasiona = true;

	if (szansa <this->prawdopodobienstwo && czy_jest_miejsce_na_nasiona)return true;
	return false;
}
