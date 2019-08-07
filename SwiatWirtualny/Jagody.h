#pragma once
#include "Rosliny.h"
class Jagody :public Rosliny
{
public:
	Jagody(Swiat&, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
};