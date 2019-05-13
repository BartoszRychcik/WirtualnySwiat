#pragma once
#include "Rysuj.h"
#include "Znak.h"
class Przycisk:public Rysuj
{
public:
	Przycisk();
	~Przycisk();
	void Pokaz_rysunek();
private:
	Znak *znaki;
	void Skonstruuj_rysunek();
};

