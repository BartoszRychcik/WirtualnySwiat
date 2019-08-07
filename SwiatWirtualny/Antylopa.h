#pragma once
#include "Zwierzeta.h"
class Antylopa :public Zwierzeta
{
public:
	Antylopa(Swiat &, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
	bool mozliwosc_wykonania_ruchu();
};