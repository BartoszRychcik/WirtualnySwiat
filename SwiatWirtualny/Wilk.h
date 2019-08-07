#pragma once
#include "Zwierzeta.h"
class Wilk :public Zwierzeta
{
public:
	Wilk(Swiat &,int,int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
	bool mozliwosc_wykonania_ruchu();
};