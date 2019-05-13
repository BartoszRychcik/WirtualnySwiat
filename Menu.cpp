#include "Menu.h"
#define POZYCJA_ZERO 0
#define SZER_START 70 //szerokosc menu startowego
#define WYS_START 28 //wysokosc menu startowego
#define ODL_LEWA 23 //odleglosc od lewego kranca ekranu dla opcji
#define ODL_GORA 5 //odleglosc od gornego kranca ekranu dla pierwszej opcji
#define SZER_RAMKI 30 //wysokosc ramki dla opcji
#define WYS_RAMKI 4 //szerokosc ramki dla opcji
#define SKOK 7 //odstep pomiedzy elementami
#define LEGENDA 16 //liczba napisow w legendzie
#define ODL_LEWA_LEGENDY 15 //odleglosc legendy od lewego kranca

Menu::Menu():tytulowy(new Napis[ile_opcji_start+2]),glowna(new Ramka[1]),opcje(new Ramka[ile_opcji_start]),wybieranie(new Przycisk[ile_opcji_start])
	{
	}

std::string Menu::Lokalne_Menu[LEGENDA] = {"W-wilk","O-owca","L-lis","Z-zolw","A-antylopa","T-trawa","M-mlecz","G-guarana","J-jagody","B-barszcz","C-czlowiek","----------","a-umiejet","s-zapisz","r-wczytaj","e-menu"};

void Menu::Pokaz_menu(int tryb)
	{
	Skonstruuj_menu(tryb);
	glowna[0].Pokaz_rysunek();
	switch (tryb)
		{
		case startowe:
			{
			for (int i = 0; i < ile_opcji_start; i++)
				{
				opcje[i].Pokaz_rysunek();
				wybieranie[i].Pokaz_rysunek();
				}
			for (int i = 0; i < ile_opcji_start + 2; i++)
				tytulowy[i].Pokaz_rysunek();
			break;
			}
		case odczyt_liczb:
			{
			opcje[0].Pokaz_rysunek();
			for (int i = 0; i < ile_opcji_odczyt + 2 ; i++)
				tytulowy[i].Pokaz_rysunek();
			break;
			}
		case odczyt_nazwy:
			{
			opcje[0].Pokaz_rysunek();
			for (int i = 0; i < ile_opcji_odczyt + 1; i++)
				tytulowy[i].Pokaz_rysunek();
			break;
			}
		}
	}

void::Menu::Pokaz_swiat(int tura, std::pair<int, int>rozmiar_swiata)
	{
	Ustaw_wlasciwosc("W I R T U A L N Y   S W I A T");
	glowna[0].Ustaw_pozycje(POZYCJA_ZERO, POZYCJA_ZERO);
	glowna[0].Ustaw_wlasciwosc(max(rozmiar_swiata.first+36,70), max(rozmiar_swiata.second+5,23)+2);
		glowna[0].Pokaz_rysunek();
	opcje[0].Ustaw_pozycje(POZYCJA_ZERO+2, ODL_GORA);
	opcje[0].Ustaw_wlasciwosc(rozmiar_swiata.first, rozmiar_swiata.second);
		opcje[0].Pokaz_rysunek();
	opcje[1].Ustaw_pozycje(ODL_LEWA_LEGENDY + (rozmiar_swiata.first>10 ? rozmiar_swiata.first - 10 : 0), ODL_GORA);
	opcje[1].Ustaw_wlasciwosc(POZYCJA_ZERO+2+SKOK+1,LEGENDA);
		opcje[1].Pokaz_rysunek();
	opcje[2].Ustaw_pozycje(WYS_START + (rozmiar_swiata.first>10 ? rozmiar_swiata.first - 10 : 0), ODL_GORA);
	opcje[2].Ustaw_wlasciwosc(ODL_LEWA_LEGENDY+1, rozmiar_swiata.second);
		opcje[2].Pokaz_rysunek();
	tytulowy[0].Ustaw_pozycje(ODL_LEWA-3, POZYCJA_ZERO+2);
	tytulowy[0].Ustaw_wlasciwosc(tytul_menu);
		tytulowy[0].Pokaz_rysunek();
	for (int i = 0; i < LEGENDA; i++)
		{
		tytulowy[1].Ustaw_pozycje(ODL_LEWA_LEGENDY+1+(rozmiar_swiata.first>10?rozmiar_swiata.first-10:0),ODL_GORA+1+i );
		tytulowy[1].Ustaw_wlasciwosc(Lokalne_Menu[i]);
		tytulowy[1].Pokaz_rysunek();
		}	
	tytulowy[2].Ustaw_pozycje(POZYCJA_ZERO+2,rozmiar_swiata.second+SKOK);
	tytulowy[2].Ustaw_wlasciwosc("Tura nr: ");
		tytulowy[2].Pokaz_rysunek();
	printf("%d", tura);
	}

void Menu::Ustaw_wlasciwosc(std::string tytul)
	{
	this->tytul_menu = tytul;
	}

void Menu::Skonstruuj_menu(int tryb)
	{
	Ustaw_wlasciwosc("W I R T U A L N Y   S W I A T");
	glowna[0].Ustaw_pozycje(POZYCJA_ZERO, POZYCJA_ZERO);
	glowna[0].Ustaw_wlasciwosc(SZER_START, WYS_START);
	tytulowy[0].Ustaw_pozycje(ODL_LEWA-3, POZYCJA_ZERO+2);
	tytulowy[0].Ustaw_wlasciwosc(tytul_menu);

	if (tryb == startowe)
		{
		opcje[0].Ustaw_pozycje(ODL_LEWA, ODL_GORA);
		opcje[0].Ustaw_wlasciwosc(SZER_RAMKI, WYS_RAMKI);
		opcje[1].Ustaw_pozycje(ODL_LEWA, ODL_GORA+SKOK);
		opcje[1].Ustaw_wlasciwosc(SZER_RAMKI, WYS_RAMKI);
		opcje[2].Ustaw_pozycje(ODL_LEWA, ODL_GORA+2*SKOK);
		opcje[2].Ustaw_wlasciwosc(SZER_RAMKI, WYS_RAMKI);

		wybieranie[0].Ustaw_pozycje(ODL_LEWA-8, ODL_GORA+1);
		wybieranie[1].Ustaw_pozycje(ODL_LEWA-8, ODL_GORA + SKOK+1);
		wybieranie[2].Ustaw_pozycje(ODL_LEWA-8, ODL_GORA + 2*SKOK+1);

		tytulowy[1].Ustaw_pozycje(ODL_LEWA+9, ODL_GORA + 2);
		tytulowy[1].Ustaw_wlasciwosc("NOWA GRA");
		tytulowy[2].Ustaw_pozycje(ODL_LEWA+9, ODL_GORA + SKOK + 2);
		tytulowy[2].Ustaw_wlasciwosc("WCZYTAJ GRE");
		tytulowy[3].Ustaw_pozycje(ODL_LEWA+9, ODL_GORA + 2 * SKOK + 2);
		tytulowy[3].Ustaw_wlasciwosc("ZAMKNIJ PROGRAM");
		tytulowy[4].Ustaw_pozycje(POZYCJA_ZERO+2, WYS_START-2);
		tytulowy[4].Ustaw_wlasciwosc("Wybierz opcje uzywajac strzalek i zaakceptuj enterem.");
		}
	else
		{
		opcje[0].Ustaw_pozycje(ODL_LEWA-4, ODL_GORA);
		opcje[0].Ustaw_wlasciwosc(SZER_RAMKI, WYS_RAMKI);
		tytulowy[1].Ustaw_pozycje(POZYCJA_ZERO + 2, WYS_START - 4);
		tytulowy[1].Ustaw_wlasciwosc("Wpisz szerokosc i wysokosc tworzonego swiata i zaakceptuj enterem.");
		tytulowy[2].Ustaw_pozycje(POZYCJA_ZERO + 2, WYS_START - 2);
		tytulowy[2].Ustaw_wlasciwosc("Dozwolone wartosci z przedzialu [1;1000].");
		if(tryb==odczyt_nazwy)
			tytulowy[1].Ustaw_wlasciwosc("Wpisz nazwe pliku.");
		}
	}

Menu::~Menu()
	{
	delete[] glowna;
	delete[] tytulowy;
	delete[] opcje;
	delete[] wybieranie;
	}
