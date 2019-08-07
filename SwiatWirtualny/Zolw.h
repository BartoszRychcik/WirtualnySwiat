#pragma once
#include "Zwierzeta.h"
class Zolw :public Zwierzeta
{
public:
	Zolw(Swiat &, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
	bool mozliwosc_wykonania_ruchu();
};
