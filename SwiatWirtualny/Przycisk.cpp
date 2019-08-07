#include "Przycisk.h"

Przycisk::Przycisk(): znaki(new Znak[8])
	{
	this->x = 0;
	this->y = 0;
	}

void Przycisk::Pokaz_rysunek()
	{
	Skonstruuj_rysunek();
	for (int i = 0; i < 8; i++)
		znaki[i].Pokaz_rysunek();
	}

void Przycisk::Skonstruuj_rysunek()
	{
	znaki[0].Ustaw_pozycje(x + 1, y);
	znaki[0].Ustaw_wlasciwosc(char(poziomy));
	znaki[1].Ustaw_pozycje(x + 1, y+2);
	znaki[1].Ustaw_wlasciwosc(char(poziomy));
	znaki[2].Ustaw_pozycje(x, y+1);
	znaki[2].Ustaw_wlasciwosc(char(pionowy));
	znaki[3].Ustaw_pozycje(x + 2, y+1);
	znaki[3].Ustaw_wlasciwosc(char(pionowy));
	znaki[4].Ustaw_pozycje(x, y+2);
	znaki[4].Ustaw_wlasciwosc(char(lewy_dolny));
	znaki[5].Ustaw_pozycje(x+2, y);
	znaki[5].Ustaw_wlasciwosc(char(prawy_gorny));
	znaki[6].Ustaw_pozycje(x+2, y+2);
	znaki[6].Ustaw_wlasciwosc(char(prawy_dolny));
	znaki[7].Ustaw_pozycje(x, y);
	znaki[7].Ustaw_wlasciwosc(char(lewy_gorny));
	}

Przycisk::~Przycisk()
	{
	delete[] znaki;
	}