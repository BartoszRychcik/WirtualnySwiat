#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Barszcz.h"
#include "Czlowiek.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include "Napis.h"
#define Liczba_roznych_organizmow 10 //bez czlowieka

Swiat::Swiat(pair<int, int> rozmiar):rozmiar_swiata(rozmiar)
	{
	this->tura = 0;
	this->Organizmy = new Organizm**[this->rozmiar_swiata.second];
	for (int i = 0; i < this->rozmiar_swiata.second; i++)
		Organizmy[i] = new Organizm*[this->rozmiar_swiata.first];

	for (int i = 0; i < this->rozmiar_swiata.second; i++)
		for (int j = 0; j < this->rozmiar_swiata.first; j++)
			Organizmy[i][j] = NULL;
	graficzny = new Interface;
	}

Swiat::~Swiat()
	{
	for (int i = 0; i < this->rozmiar_swiata.second; i++)
		delete[] Organizmy[i];
	delete[] Organizmy;
	delete graficzny;
	delete czlowiek;
	}

void Swiat::Start(int tryb,string nazwa_pliku)
	{
	switch (tryb)
		{
		case 0:
			{
			this->Inicjalizuj_nowy_swiat();
			break;
			}
		case 1:
			{
			this->Wczytaj_swiat(nazwa_pliku);
			break;
			}
		}
	this->Pokaz_swiat();
	while (czlowiek!=NULL)this->Wykonaj_ture();
	while (dir=_getch())this->Wykonaj_ture();
	}

bool Swiat::kryteria_porownywania(const Organizm * a, const Organizm * b)
	{
	if (a->Pokaz_inicjatywe() == b->Pokaz_inicjatywe())
		return a->Pokaz_wiek() > b->Pokaz_wiek();
	return a->Pokaz_inicjatywe() > b->Pokaz_inicjatywe();
	}

void Swiat::Wykonaj_ture()
	{	
	this->Polecenie_menu(' ');
	sort(kolejka_ruchu.begin(), kolejka_ruchu.end(),kryteria_porownywania);
	this->tura++;
	rozmiar_ruchu_inicjatywy = kolejka_ruchu.size(); //pomocniczo zmienny rozmiar vectora, zeby w danej turze nie bralo dzieci ktore dopiero doszly i zeby nie wykroczylo za zakres jak sie zjedza
	for (iterator_organizmow = 0; iterator_organizmow < rozmiar_ruchu_inicjatywy; iterator_organizmow++)
		this->kolejka_ruchu[iterator_organizmow]->akcja();
	for (int j = 0; j<rozmiar_ruchu_inicjatywy; j++)
		this->kolejka_ruchu[j]->Postarz_organizm();
	this->Pokaz_swiat();
	}

bool Swiat::Poza_tablice(pair<int,int>wspolrzedne) //prawda gdy wyjdzie poza tablice
	{
	if (wspolrzedne.first < 0 || wspolrzedne.second < 0 || wspolrzedne.first >= rozmiar_swiata.first || wspolrzedne.second >= rozmiar_swiata.second)
		return true;
	return false;
	}

bool Swiat::Wygrany_ruch(pair<int,int>wspolrzedne,int sila) //prawda gdy ruch jest wygrany
	{
	if ((!Poza_tablice(wspolrzedne) && (Organizmy[wspolrzedne.second][wspolrzedne.first] == NULL || (Organizmy[wspolrzedne.second][wspolrzedne.first]!=NULL && Organizmy[wspolrzedne.second][wspolrzedne.first]->Pokaz_sile() <= sila))))
		return true;
	return false;
	}

bool Swiat::Puste_miejsce(pair<int,int>wspolrzedne) //prawda gdy wskazane miejsce jest puste
	{
	if (!Poza_tablice(wspolrzedne) && Organizmy[wspolrzedne.second][wspolrzedne.first] == NULL)
		return true;
	return false;
	}

void Swiat::Dodaj_organizm(int x_gen, int y_gen, char typ_gen)
	{
	switch (typ_gen)
	{
	case 'C':
		Organizmy[y_gen][x_gen] = new Czlowiek(*this, x_gen, y_gen);
		break;
	case 'W':
		Organizmy[y_gen][x_gen] = new Wilk(*this, x_gen, y_gen);
		break;
	case 'O':
		Organizmy[y_gen][x_gen] = new Owca(*this, x_gen, y_gen);
		break;
	case 'L':
		Organizmy[y_gen][x_gen] = new Lis(*this, x_gen, y_gen);
		break;
	case 'Z':
		Organizmy[y_gen][x_gen] = new Zolw(*this, x_gen, y_gen);
		break;
	case 'A':
		Organizmy[y_gen][x_gen] = new Antylopa(*this, x_gen, y_gen);
		break;
	case 'T':
		Organizmy[y_gen][x_gen] = new Trawa(*this, x_gen, y_gen);
		break;
	case 'M':
		Organizmy[y_gen][x_gen] = new Mlecz(*this, x_gen, y_gen);
		break;
	case 'G':
		Organizmy[y_gen][x_gen] = new Guarana(*this, x_gen, y_gen);
		break;
	case 'J':
		Organizmy[y_gen][x_gen] = new Jagody(*this, x_gen, y_gen);
		break;
	case 'B':
		Organizmy[y_gen][x_gen] = new Barszcz(*this, x_gen, y_gen);
		break;
	}
	kolejka_ruchu.push_back(Organizmy[y_gen][x_gen]);
	komunikat.Powiadom_o_narodzinach(Organizmy[y_gen][x_gen]->Pokaz_symbol());
	}

void Swiat::Wykonaj_ruch(int x_start, int y_start, int x_cel, int y_cel)
	{
	if (Organizmy[y_cel][x_cel] == NULL)
		{
		Organizmy[y_cel][x_cel] = Organizmy[y_start][x_start];
		Organizmy[y_start][x_start] = NULL;
		Organizmy[y_cel][x_cel]->Ustaw_lokalizacje({ x_cel,y_cel });
		}
	else
		{
		if(Organizmy[y_cel][x_cel]->Pokaz_symbol()==Organizmy[y_start][x_start]->Pokaz_symbol())
			{
			Organizmy[y_start][x_start]->rozmnazanie(x_cel,y_cel);
			}
		else 
			{
			if (Organizmy[y_start][x_start]->specjalna_kolizja(Organizmy[y_cel][x_cel]))return;
			if (Organizmy[y_cel][x_cel]->specjalna_kolizja(Organizmy[y_start][x_start]))return;

			if (Organizmy[y_start][x_start]->Pokaz_sile() >= Organizmy[y_cel][x_cel]->Pokaz_sile())
				{
				komunikat.Powiadom_o_walce(Organizmy[y_start][x_start]->Pokaz_symbol(), Organizmy[y_cel][x_cel]->Pokaz_symbol());
				this->Usun_organizm(*Organizmy[y_cel][x_cel]);
				Organizmy[y_cel][x_cel] = Organizmy[y_start][x_start];
				Organizmy[y_start][x_start] = NULL;
				Organizmy[y_cel][x_cel]->Ustaw_lokalizacje({ x_cel,y_cel });
				}	
			else
				{
				komunikat.Powiadom_o_walce(Organizmy[y_cel][x_cel]->Pokaz_symbol(),Organizmy[y_start][x_start]->Pokaz_symbol());
				this->Usun_organizm(*Organizmy[y_start][x_start]);
				}
			}
		}
	}

void Swiat::Wyczysc_okolice(int tryb,int x,int y) //0 calkowity ; 1 tylko zwierzeta
	{
	bool czy_mam_usunac = false;
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if ((i != 0 || j != 0) && (!Poza_tablice({ x + i, y + j })) && (Organizmy[y + j][x + i] != NULL))
				{
				if(tryb == 0) czy_mam_usunac = true;
				else
				if (tryb == 1)
					if (Zwierzeta *zwierzak = dynamic_cast<Zwierzeta*>(Organizmy[y + j][x + i])) czy_mam_usunac = true;

				if(czy_mam_usunac)
					{
					this->Usun_organizm(*Organizmy[y + j][x + i]);
					Organizmy[y + j][x + i] = NULL;
					}
				}
	}

void Swiat::Usun_organizm(Organizm &organizm)
	{
	if (czlowiek->Czy_to_ja(&organizm))czlowiek = NULL;
	for (int i = 0; i < int(kolejka_ruchu.size()); i++)
		if (&organizm == kolejka_ruchu[i])
			{
			kolejka_ruchu.erase(kolejka_ruchu.begin() + i); //usuwanie zjedzonego organizmu z kolejki
			if(rozmiar_ruchu_inicjatywy>i) //jesli zjedzone zostalo dziecko narodzone w tej turze to rozmiar vectora sie nie zmienia
				rozmiar_ruchu_inicjatywy--;
			if (iterator_organizmow >= i) //jesli zjedzony organizm jest wczesniej w kolejce to vector sie spisuje do tylu wiec i wskaznik trzeba przesunac
				iterator_organizmow--;
			break;
			}
	Organizmy[organizm.Pokaz_lokalizacje().second][organizm.Pokaz_lokalizacje().first] = NULL;
	delete &organizm;
	}

void Swiat::Inicjalizuj_nowy_swiat()
	{
	int startowa_liczba_obiektow = (rand() % 10 + 5)*this->rozmiar_swiata.first*this->rozmiar_swiata.second / 100; //5-14% calej powierzchni
	int x_gen, y_gen;
	this->Dodaj_organizm(0, 0, 'C');
	czlowiek = dynamic_cast<Czlowiek*>(Organizmy[0][0]);
	char typ_gen;
	string symbole = "WOLZATMGJB";
	for (int i = 0; i < startowa_liczba_obiektow; i++)
		{
		x_gen = 0; y_gen = 0;
		while ((x_gen == 0 && y_gen == 0) || (!this->Puste_miejsce({ x_gen, y_gen })))
			{
			x_gen = rand() % this->rozmiar_swiata.first;
			y_gen = rand() % this->rozmiar_swiata.second;
			typ_gen = symbole[rand() % Liczba_roznych_organizmow];
			}
		this->Dodaj_organizm(x_gen, y_gen, typ_gen);
		}
	}

void Swiat::Pokaz_swiat()
	{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Znak wskaznik; 
	wskaznik.Ustaw_wlasciwosc(char(186));
	(*graficzny).Pokaz_swiat(this->tura, this->rozmiar_swiata);
	for (int i = 0; i < this->rozmiar_swiata.second; i++)
		{
		wskaznik.Ustaw_pozycje(2, 6 + i);
		wskaznik.Pokaz_rysunek();
		for (int j = 0; j < this->rozmiar_swiata.first; j++)
			{
			if (Organizmy[i][j] == NULL)
				cout << " ";
			else
				{
				if ((*Organizmy[i][j]).Pokaz_symbol() == 'C')
					{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << (*Organizmy[i][j]).Pokaz_symbol();
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); 
					}
				else
					if (czlowiek!=NULL&&((*Organizmy[i][j]).Pokaz_symbol() == 'B' || (*Organizmy[i][j]).Pokaz_sile()>czlowiek->Pokaz_sile()))
						{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << (*Organizmy[i][j]).Pokaz_symbol();
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
						}
				else
				cout << (*Organizmy[i][j]).Pokaz_symbol();
				}
			}
		}
	//dla lepszego zorientowania
	Napis um_special;
	komunikat.Wypisz(rozmiar_swiata);
	um_special.Ustaw_pozycje(2,4);
	if(czlowiek!=NULL)
		{
		if (czlowiek->Pokaz_aktywnosc_umiejetnosci())
			um_special.Ustaw_wlasciwosc("Calopalenie-wlaczone");
		else
			um_special.Ustaw_wlasciwosc("Calopalenie-wylaczone");
		}
	else
		um_special.Ustaw_wlasciwosc("Czlowiek nie zyje!");
	um_special.Pokaz_rysunek();
	}

void Swiat::Informuj(char pierwszy_org, string komunikat, char drugi_org = '\0')
	{
	Swiat::komunikat.Powiadomienie_specjalne(pierwszy_org,komunikat,drugi_org);
	}

void Swiat::Polecenie_menu(char polecenie_czlowieka=' ')
	{
	if (dir == 's'|| polecenie_czlowieka=='s')this->Zapisz_swiat();
	else
	if (dir == 'r' || polecenie_czlowieka == 'r')this->Wczytaj_swiat("");
	else
	if (dir == 'e' || polecenie_czlowieka == 'e')this->Wroc_do_Menu();
	}

void Swiat::Wroc_do_Menu()
	{
	this->Wyczysc_swiat();
	graficzny->Start(); 
	}

void Swiat::Wyczysc_swiat()
	{
	komunikat.Wyczysc_komunikaty();
	for (int i = 0; i < this->rozmiar_swiata.second; i++)
		delete[] Organizmy[i];
	delete[] Organizmy;
	delete czlowiek;
	kolejka_ruchu.clear();
	}

void Swiat::Wczytaj_swiat(string nazwa_pliku)
	{
	dir = 'k'; //zmiana na znak bez akcji, w przeciwnym wypadku zapetli sie ciagle wczytywanie
	ifstream odczyt;
	if (nazwa_pliku == "") //jak nie ma nazwy pliku to trzeba ja pobrac 5 linijek nizej
		{
		this->Wyczysc_swiat();

		pair<int, int>rozmiar;
		while(!graficzny->Pobierz_dane(&rozmiar,nazwa_pliku));

		this->rozmiar_swiata.first = rozmiar.first;
		this->rozmiar_swiata.second = rozmiar.second;

		this->Organizmy = new Organizm**[this->rozmiar_swiata.second];
		for (int i = 0; i < this->rozmiar_swiata.second; i++)
			Organizmy[i] = new Organizm*[this->rozmiar_swiata.first];

		for (int i = 0; i < this->rozmiar_swiata.second; i++)
			for (int j = 0; j < this->rozmiar_swiata.first; j++)
				Organizmy[i][j] = NULL;
		}

	int i,j,inicjatywa,sila,wiek,ladowanie;
	char symbol;
	bool umiejetnosc;
	this->czlowiek = NULL;
	odczyt.open(nazwa_pliku);
	odczyt >> rozmiar_swiata.first >> rozmiar_swiata.second;
	odczyt >> tura;
	while (odczyt >> j >> i)
		{
		odczyt >> inicjatywa >> sila >> symbol >> wiek;
		this->Dodaj_organizm(j,i,symbol);
		Organizmy[i][j]->Ustaw_inicjatywe(inicjatywa);
		Organizmy[i][j]->Ustaw_lokalizacje({j,i});
		Organizmy[i][j]->Ustaw_sile(sila);
		Organizmy[i][j]->Ustaw_symbol(symbol);
		Organizmy[i][j]->Ustaw_wiek(wiek);
		if (symbol == 'C')
			{
			odczyt >> ladowanie >> umiejetnosc;
			czlowiek = dynamic_cast<Czlowiek*>(Organizmy[i][j]);
			czlowiek->Ustaw_aktywnosc_umiejetnosci(umiejetnosc);
			czlowiek->Ustaw_ladowanie_umiejetnosci(ladowanie);
			}
		}
	odczyt.close();
	this->Pokaz_swiat();
	this->Start(2,""); //rozpoczecie grania na swiecie z pomijaniem opcji w metodzie Startowej
	}

void Swiat::Zapisz_swiat()
	{
	string nazwa_pliku;
	graficzny->Pobierz_dane(nazwa_pliku);
	ofstream plik;
	plik.open(nazwa_pliku+".txt");
	plik << rozmiar_swiata.first << " " << rozmiar_swiata.second << endl;
	plik << tura << endl;
	for(int i=0;i<rozmiar_swiata.second;i++)
		for(int j=0;j<rozmiar_swiata.first;j++)
			if (Organizmy[i][j] != NULL)
				{
				plik << j << " " << i << " ";
				plik << Organizmy[i][j]->Pokaz_inicjatywe() << " ";
				plik << Organizmy[i][j]->Pokaz_sile() << " ";
				plik << Organizmy[i][j]->Pokaz_symbol() << " ";
				plik << Organizmy[i][j]->Pokaz_wiek() << " ";
				if (Organizmy[i][j]->Pokaz_symbol() == 'C')
					plik << czlowiek->Pokaz_ladowanie_umiejetnosci() << " " << czlowiek->Pokaz_aktywnosc_umiejetnosci();
				plik << endl;
				}
	plik.close();
	this->Pokaz_swiat();
	}