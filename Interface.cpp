#include "Interface.h"
#include <fstream>
#include <string.h>
#include "Swiat.h"
#define ESC 13
#define SKOK 7 //odstep od kolejnych opcji
#define START_X 16 //odstep od krawedzi ekranu
#define BLOK 219 //pelny blok do zaznaczania poprawnej odpowiedzi
#define PUSTY 32 //spacja do zaznaczania falszywej odpowiedzi
#define EKRAN_X 26 //pozycja kursora wczytujacego
#define EKRAN_Y 8 //pozycja kursora wczytujacego
#define MIN_ROZMIAR_SWIATA 1 
#define MAX_ROZMIAR_SWIATA 1000
#define MIN_DL_NAZWY_PLIKU 3

Interface::Interface():moje_menu(new Menu[1])
	{
	}	

Interface::~Interface()
	{
	delete[] moje_menu;
	}

void Interface::Start()
	{
	pair <int, int> rozmiar_swiata = { 0,0 };
	string nazwa_pliku;
	enum tryb { nowy_swiat, wczytany_swiat };
	int akcja = this->Wybierz_opcje();
		switch (akcja)
		{
		case 1:
			{
			while (!this->Pobierz_dane(&rozmiar_swiata));
			Swiat swiat(rozmiar_swiata);
			swiat.Start(nowy_swiat, "");
			break;
			}
		case 2:
			{
			while (!this->Pobierz_dane(&rozmiar_swiata, nazwa_pliku));
			Swiat swiat(rozmiar_swiata);
			swiat.Start(wczytany_swiat, nazwa_pliku);
			break;
			}
		default:
			exit(0);
		}
	}	
int Interface::Wybierz_opcje()
	{
	int wykonaj_akcje = 1; //domyslne ustawienie wyboru pierwszej akcji
	x = START_X; y = SKOK;
	przelacznik.Ustaw_pozycje(x,y);
	przelacznik.Ustaw_wlasciwosc(BLOK);
	system("cls");
	moje_menu[0].Pokaz_menu(start);
	przelacznik.Pokaz_rysunek();
	int dir = getch();
	while (dir != ESC) 
		{
		dir = getch();
		przelacznik.Ustaw_wlasciwosc(PUSTY);
		przelacznik.Pokaz_rysunek();
		if (dir == GORA)
			{
			if (wykonaj_akcje > 1)
				{
				wykonaj_akcje--;
				y -= SKOK;
				}
			}
		else
			if (dir == DOL)
			{
			if (wykonaj_akcje < 3)
				{
				wykonaj_akcje++;
				y += SKOK;
				}
			}
		przelacznik.Ustaw_wlasciwosc(BLOK);
		przelacznik.Ustaw_pozycje(x, y);
		przelacznik.Pokaz_rysunek();
		}
	return wykonaj_akcje;
}

bool Interface::Pobierz_dane(std::pair<int, int> *rozmiar_swiata)
	{
	wskaznik.Ustaw_pozycje(EKRAN_X, EKRAN_Y);
	system("cls");
	moje_menu[0].Pokaz_menu(odczyt_rozmiaru);
	int x, y;
	wskaznik.Pokaz_rysunek();
	scanf("%d%d",&x,&y);
	if(x>=MIN_ROZMIAR_SWIATA&&y>=MIN_ROZMIAR_SWIATA&&x<=MAX_ROZMIAR_SWIATA&&y<=MAX_ROZMIAR_SWIATA)
		{
		(*rozmiar_swiata).first = x;
		(*rozmiar_swiata).second = y;
		return true;
		}
	return false;
	}

bool Interface::Pobierz_dane(std::string& nazwa_pliku)
	{
	wskaznik.Ustaw_pozycje(EKRAN_X, EKRAN_Y);
	system("cls");
	moje_menu[0].Pokaz_menu(odczyt_nazwy);
	char nazwa[1001];
	wskaznik.Pokaz_rysunek();
	scanf("%s", &nazwa);
	nazwa_pliku = nazwa;
	if (nazwa_pliku.size() >= MIN_DL_NAZWY_PLIKU)return true;
	return false;
	}

bool Interface::Pobierz_dane(std::pair<int, int>*rozmiar_swiata, std::string& nazwa_pliku)
	{
	wskaznik.Ustaw_pozycje(EKRAN_X, EKRAN_Y);
	system("cls");
	moje_menu[0].Pokaz_menu(odczyt_nazwy);
	char nazwa[1001];
	char b[] = ".txt";
	wskaznik.Pokaz_rysunek();
	scanf("%s", &nazwa);
	int i = 0, k = 0;
	while (nazwa[i] != '\0')i++;
		while (b[k] != '\0')
			{
			nazwa[i] = b[k];
			i++;
			k++;
			}
	nazwa[i] = '\0';
	FILE *plik;
	ifstream odczyt;
	if (plik = fopen(nazwa, "r"))
		{
		odczyt.open(nazwa);
		odczyt >> (*rozmiar_swiata).first;
		odczyt >> (*rozmiar_swiata).second;
		nazwa_pliku = nazwa;
		odczyt.close();
		return true;
		}
	return false;
	}

void Interface::Pokaz_swiat(int tura, std::pair<int, int>rozmiar_swiata)
	{
	system("cls");
	moje_menu[0].Pokaz_swiat(tura, rozmiar_swiata);
	}