#pragma once
#include "Organizm.h"
class Zwierzeta :public Organizm
{
public:
	Zwierzeta(Swiat &,int,int);
	virtual ~Zwierzeta();
protected:
	void akcja();
	virtual void rozmnazanie(int, int);
	virtual void ruch();
	virtual bool mozliwosc_wykonania_ruchu() = 0;
};