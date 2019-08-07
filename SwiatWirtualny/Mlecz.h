#pragma once
#include "Rosliny.h"
class Mlecz :public Rosliny
{
public:
	Mlecz(Swiat&, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
};

