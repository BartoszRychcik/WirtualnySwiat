#pragma once
#include "Organizm.h"
#include "Powiadomienia.h"
#include "Interface.h"
#include <vector>
#include <iostream>
using namespace std;
class Organizm;
class Czlowiek;
class Swiat
{
public:
	Swiat(pair<int, int>);
	~Swiat();
	void Start(int,string);
	bool Poza_tablice(pair<int,int>);
	void Wykonaj_ruch(int, int, int, int);
	bool Wygrany_ruch(pair<int,int>,int);
	bool Puste_miejsce(pair<int,int>);
	void Dodaj_organizm(int, int, char);
	void Usun_organizm(Organizm&);
	void Informuj(char, string, char);
	void Wyczysc_okolice(int,int,int);
	void Polecenie_menu(char);
private:
	void Zapisz_swiat();
	void Wczytaj_swiat(string);
	void Wroc_do_Menu();
	void Wyczysc_swiat();
	Powiadomienia komunikat;
	int tura;
	int rozmiar_ruchu_inicjatywy;
	int iterator_organizmow;
	void Wykonaj_ture();
	void Inicjalizuj_nowy_swiat();
	Interface *graficzny;
	Organizm ***Organizmy;
	vector<Organizm*>kolejka_ruchu;
	pair<int, int>rozmiar_swiata;
	void Pokaz_swiat();
	Czlowiek *czlowiek;
	int dir;
	static bool kryteria_porownywania(const Organizm*, const  Organizm*);
};

