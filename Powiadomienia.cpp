#include "Powiadomienia.h"
#include "Znak.h"
Powiadomienia::Powiadomienia()
	{
	}	

Powiadomienia::~Powiadomienia()
	{
	}

void Powiadomienia::Dodaj_powiadomienie(std::string text)
	{
	this->stos.push(text);
	}

void Powiadomienia::Wypisz(pair<int,int>rozmiar_swiata)
	{
	Znak wskaznik;
	wskaznik.Ustaw_wlasciwosc(char(186));
	int zliczaj = 0;
	while (!stos.empty() && zliczaj<rozmiar_swiata.second )
		{
		string pom = stos.top();
		wskaznik.Ustaw_pozycje(28 + (rozmiar_swiata.first>10 ? rozmiar_swiata.first - 10 : 0), 6 + zliczaj);
		wskaznik.Pokaz_rysunek();
		printf("%s", pom.c_str());
		this->stos.pop();
		zliczaj++;
		}
	this->Wyczysc_komunikaty();
	}

void Powiadomienia::Powiadom_o_walce(char wygrany,char przegrany)
	{
	string powiadom = "";
	powiadom += char(wygrany);
	powiadom += " pokonal ";
	powiadom += char(przegrany);
	Dodaj_powiadomienie(powiadom);
	}

void Powiadomienia::Powiadom_o_narodzinach(char znak)
	{
	string powiadom = "";
	powiadom += char(znak);
	powiadom +=" urodzil sie";
	Dodaj_powiadomienie(powiadom);
	}

void Powiadomienia::Powiadomienie_specjalne(char pierwszy,string komunikat,char drugi='\0')
	{
	string powiadom = "";
	powiadom += char(pierwszy);
	powiadom += komunikat;
	powiadom += char(drugi);
	Dodaj_powiadomienie(powiadom);
	}

void Powiadomienia::Wyczysc_komunikaty()
	{
	while (!stos.empty())
		stos.pop();
	}