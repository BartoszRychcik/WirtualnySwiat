#pragma once
#include "Rosliny.h"
class Barszcz :public Rosliny
{
public:
	Barszcz(Swiat&, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
};