#pragma once
#include "Rosliny.h"
class Guarana :public Rosliny
{
public:
	Guarana(Swiat&, int, int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
};