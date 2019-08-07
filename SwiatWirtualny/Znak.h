#pragma once
#include "Rysuj.h"
class Znak: public Rysuj
{
public:
	Znak();
	void Pokaz_rysunek()override;
	void Ustaw_wlasciwosc(char);
private:
	char znak;
};

