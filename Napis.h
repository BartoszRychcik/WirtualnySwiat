#pragma once
#include "Rysuj.h"
class Napis :public Rysuj
{
public:
	Napis();
	void Pokaz_rysunek()override;
	void Ustaw_wlasciwosc(std::string);
private:
	std::string napis;
};

