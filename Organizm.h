#pragma once
#include <iostream>
#include "Swiat.h"
using namespace std;
class Swiat;
class Organizm
{
public:
	Organizm(Swiat &,int, int);
	virtual ~Organizm();
	void Postarz_organizm();
	int Pokaz_wiek()const;
	pair<int, int> Pokaz_lokalizacje()const;
	char Pokaz_symbol()const;
	int Pokaz_sile()const;
	int Pokaz_inicjatywe()const;
	void Ustaw_symbol(char);
	void Ustaw_lokalizacje(pair<int, int>);
	void Ustaw_sile(int);
	void Ustaw_inicjatywe(int);
	void Ustaw_wiek(int);
	virtual void rozmnazanie(int, int) = 0;
	virtual void akcja() = 0;
	virtual bool specjalna_kolizja(Organizm*)=0;
protected:
	virtual bool specjalna_akcja() = 0;
	int sila;
	int inicjatywa;
	pair <int, int> lokalizacja;
	Swiat &refswiat;
	int wiek;
	char symbol;	
};


