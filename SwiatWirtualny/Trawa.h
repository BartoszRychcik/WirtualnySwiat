#pragma once
#include "Rosliny.h"
class Trawa :public Rosliny
{
public:
	Trawa(Swiat&,int,int);
private:
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
};