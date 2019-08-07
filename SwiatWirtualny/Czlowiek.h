#pragma once
#include "Zwierzeta.h"
class Czlowiek :public Zwierzeta
{
public:
	Czlowiek(Swiat&,int,int);
	void rozmnazanie(int, int)override; 
	bool Czy_to_ja(Organizm*)const;
	bool Pokaz_aktywnosc_umiejetnosci()const;
	int Pokaz_ladowanie_umiejetnosci()const;
	void Ustaw_aktywnosc_umiejetnosci(bool);
	void Ustaw_ladowanie_umiejetnosci(int);
private:
	int przesunX;
	int przesunY;
	bool umiejetnosc;
	int ladowanie_umiejetnosci;
	enum RUCH { GORA = 0x48, DOL = 0x50, LEWO = 0x4b, PRAWO = 0x4d };
	bool mozliwosc_wykonania_ruchu();
	bool specjalna_akcja();
	bool specjalna_kolizja(Organizm*);
	void sterowanie();
};