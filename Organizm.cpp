#include "Organizm.h"

Organizm::Organizm(Swiat &refswiat,int x, int y):refswiat(refswiat)
	{
	this->lokalizacja.first = x;
	this->lokalizacja.second = y;
	this->wiek = 0;
	}
Organizm::~Organizm()
	{
	}

void Organizm::Postarz_organizm()
	{
	this->wiek++;
	}

int Organizm::Pokaz_wiek()const
	{
	return this->wiek;
	}

pair<int, int> Organizm::Pokaz_lokalizacje()const
	{
	return this->lokalizacja;
	}

char Organizm::Pokaz_symbol()const
	{
	return this->symbol;
	}

int Organizm::Pokaz_sile()const
	{
	return this->sila;
	}

int Organizm::Pokaz_inicjatywe()const
	{
	return this->inicjatywa;
	}

void Organizm::Ustaw_symbol(char symbols)
	{
	this->symbol = symbols;
	}

void Organizm::Ustaw_lokalizacje(pair<int, int>lokalizacja)
	{
	this->lokalizacja = lokalizacja;
	}

void Organizm::Ustaw_sile(int sila)
	{
	this->sila = sila;
	}

void Organizm::Ustaw_inicjatywe(int inicjatywa)
	{
	this->inicjatywa = inicjatywa;
	}

void Organizm::Ustaw_wiek(int wiek)
	{
	this->wiek = wiek;
	}

bool Organizm::specjalna_akcja()
	{
	return false;
	}

bool Organizm::specjalna_kolizja(Organizm *)
	{
	return false;
	}