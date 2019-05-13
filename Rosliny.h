#pragma once
#include "Organizm.h"
class Rosliny :public Organizm
{
public:
	Rosliny(Swiat &, int, int);
	virtual ~Rosliny();
protected:
	void akcja();
	virtual void rozmnazanie(int,int);
	virtual bool mozliwosc_rozmnazania();
	int prawdopodobienstwo;
};