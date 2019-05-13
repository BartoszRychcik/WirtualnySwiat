#pragma once
#include<iostream>
#include<stack>
using namespace std;
class Powiadomienia
{
public:
	Powiadomienia();
	~Powiadomienia();
	void Wypisz(pair<int,int>);
	void Powiadom_o_walce(char, char);
	void Powiadom_o_narodzinach(char);
	void Powiadomienie_specjalne(char,string,char);
	void Wyczysc_komunikaty();
private:
	void Dodaj_powiadomienie(string);
	stack <string> stos;
};

