#pragma once
#include "Zwierzeta.h"
class Lis :public Zwierzeta
{
public:
	Lis(Swiat &, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
	bool mozliwosc_wykonania_ruchu();
};