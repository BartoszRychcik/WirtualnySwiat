#pragma once
#include "Zwierzeta.h"
class Owca :public Zwierzeta
{
public:
	Owca(Swiat &, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
	bool mozliwosc_wykonania_ruchu();
};