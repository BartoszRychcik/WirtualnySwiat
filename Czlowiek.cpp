#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat &refswiat,int x,int y) :Zwierzeta(refswiat, x, y)
	{
	this->inicjatywa = 4;
	this->sila = 5;
	this->symbol = 'C';
	this->umiejetnosc = false;
	this->wiek = 0;
	this->ladowanie_umiejetnosci = 0;
	}

bool Czlowiek::specjalna_akcja()
	{
	this->sterowanie();
	return true;
	}

bool Czlowiek::mozliwosc_wykonania_ruchu()
	{
	return true;
	}

void Czlowiek::rozmnazanie(int x, int y)
	{
	return;
	}

bool Czlowiek::specjalna_kolizja(Organizm *inny)
	{
	if (umiejetnosc)
		{
		refswiat.Informuj(this->Pokaz_symbol(), " czysci okol. ", '\0');
		refswiat.Wyczysc_okolice(0, this->lokalizacja.first, this->lokalizacja.second);
		refswiat.Wykonaj_ruch(this->lokalizacja.first, this->lokalizacja.second, this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY);
		return true;
		}
	return false;
	}

void Czlowiek::sterowanie()
	{
	if (ladowanie_umiejetnosci < 7)umiejetnosc = false;
	if (ladowanie_umiejetnosci > 0)ladowanie_umiejetnosci--;
	int dir = 0;
	przesunX = 0, przesunY = 0;
	while (refswiat.Poza_tablice({ this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY }) || (przesunX == 0 && przesunY == 0))
		{
		int dir = _getch();
			switch (dir)
				{
				case DOL:
					{
					przesunX = 0; przesunY = 1;
					break;
					}
				case GORA:
					{
					przesunX = 0; przesunY = -1;
					break;
					}
				case PRAWO:
					{
					przesunX = 1; przesunY = 0;
					break;
					}
				case LEWO:
					{
					przesunX = -1; przesunY = 0;
					break;
					}
				case 'e':
					{
					refswiat.Polecenie_menu('e');
					break;
					}
				case 's':
					{
					refswiat.Polecenie_menu('s');
					break;
					}
				case 'r':
					{
					refswiat.Polecenie_menu('r');
					break;
					}
				case 'a' :
					{
					if (!umiejetnosc && ladowanie_umiejetnosci == 0) { umiejetnosc = true; ladowanie_umiejetnosci = 10;}
					break;
					}
				}
			}
	refswiat.Wykonaj_ruch(this->lokalizacja.first, this->lokalizacja.second, this->lokalizacja.first + przesunX, this->lokalizacja.second + przesunY);
	}	

bool Czlowiek::Czy_to_ja(Organizm* jakis)const
	{
	if (Czlowiek *test = dynamic_cast<Czlowiek*>(jakis))
		return true;
	return false;
	}

bool Czlowiek::Pokaz_aktywnosc_umiejetnosci()const
	{
	return this->umiejetnosc;
	}

int Czlowiek::Pokaz_ladowanie_umiejetnosci()const
	{
	return this->ladowanie_umiejetnosci;
	}

void Czlowiek::Ustaw_aktywnosc_umiejetnosci(bool umiejetnosc)
	{
	this->umiejetnosc = umiejetnosc;
	}

void Czlowiek::Ustaw_ladowanie_umiejetnosci(int ladowanie)
	{
	this->ladowanie_umiejetnosci = ladowanie;
	}
