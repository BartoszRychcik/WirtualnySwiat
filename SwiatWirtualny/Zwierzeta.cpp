#include "Zwierzeta.h"

Zwierzeta::Zwierzeta(Swiat &swiatref,int x,int y):Organizm(swiatref,x,y)
	{
	}

Zwierzeta::~Zwierzeta()
	{
	}

void Zwierzeta::rozmnazanie(int x1, int y1)
	{
	int x, y;
	bool czy_jest_miejsce_na_dziecko_przy_tacie = false;
	bool czy_jest_miejsce_na_dziecko_przy_mamie = false;

	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			{
			if ((i != 0 || j != 0) && refswiat.Puste_miejsce({ x1 + i,y1 + j }))
				czy_jest_miejsce_na_dziecko_przy_mamie = true;
			if ((i != 0 || j != 0) && refswiat.Puste_miejsce({ this->lokalizacja.first + i,this->lokalizacja.second + j }))
				czy_jest_miejsce_na_dziecko_przy_tacie = true;
			}
	
	if (czy_jest_miejsce_na_dziecko_przy_mamie||czy_jest_miejsce_na_dziecko_przy_tacie)
		{
		int przesunX = 0, przesunY = 0;
		if(czy_jest_miejsce_na_dziecko_przy_mamie)
			{x = x1; y = y1;}
		else
			{x = this->lokalizacja.first; y = this->lokalizacja.second;}

		while ((przesunX == 0 && przesunY == 0) || (!refswiat.Puste_miejsce({ x + przesunX, y + przesunY })))
			{
			przesunX = rand() % 3 - 1;
			przesunY = rand() % 3 - 1;
			}
		refswiat.Dodaj_organizm(x+przesunX,y+przesunY,this->symbol);
		}

	}

void Zwierzeta::akcja()
	{
	if(specjalna_akcja())return;
	else this->ruch();
	}

void Zwierzeta::ruch()
	{
	int przesunX=0, przesunY=0;
	while ((przesunX == 0 && przesunY == 0) || (refswiat.Poza_tablice({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY })))
		{
		przesunX = rand() % 3 - 1;
		przesunY = rand() % 3 - 1;
		}
	refswiat.Wykonaj_ruch(this->lokalizacja.first,this->lokalizacja.second,this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY);
	}
