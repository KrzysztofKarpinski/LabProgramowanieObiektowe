#include<vector>
#include "Kasa.h"
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

vector<Czlowiek> Lista_Ludzi;			//http://geosoft.no/development/cppstyle.html

Kasa::Kasa()
{
	Lista_Ludzi.clear();
}

Kasa::~Kasa()
{

}

void Kasa::DodajKontoPracownika(Pracownik pracownik)
{
	if (!this->JestNaLiscie(pracownik))		//jezeli konta nie ma na liœcie to
	{
		Lista_Ludzi.push_back(pracownik);//dodaj pracownika
	}
	else											//je¿eli jest to
	{
		cout << "To Id jest ju¿ zajête" << endl;	//Wyœwietl informacjê, ¿e u¿ytkownik ju¿ jest w systemie
	}
}

void Kasa::DodajKontoStazysty(Stazysta stazysta)
{
	if (!this->JestNaLiscie(stazysta))		//jezeli konta nie ma na liœcie to
	{
		Lista_Ludzi.push_back(stazysta);//dodaj pracownika
	}
	else											//je¿eli jest to
	{
		cout << "To Id jest ju¿ zajête" << endl;	//Wyœwietl informacjê, ¿e u¿ytkownik ju¿ jest w systemie
	}
}

bool Kasa::JestNaLiscie(Czlowiek kontoWejsciowe)
{
	for (vector<Czlowiek>::iterator czlowiek= this->Lista_Ludzi.begin(); czlowiek!= this->Lista_Ludzi.end(); czlowiek++)
	{
		if (czlowiek->getId() == kontoWejsciowe.getId())
		{
			return true;
		}
	}
	return false;
}


void Kasa::PokazKonta()
{

}


float Kasa::PokazLaczneSaldo()
{
	float suma=0;
	for (vector<Czlowiek>::iterator czlowiek = this->Lista_Ludzi.begin(); czlowiek != this->Lista_Ludzi.end(); czlowiek++)
	{
		suma += czlowiek->getSaldo();
	}
	return suma;
}

void Kasa::UsunKonto(int Id)
{
	for (vector<Czlowiek>::iterator czlowiek = this->Lista_Ludzi.begin(); czlowiek != this->Lista_Ludzi.end(); czlowiek++)
	{
		if (czlowiek->getId() == Id)
		{
			Lista_Ludzi.erase(czlowiek);
		}
	}
}

void Kasa::Wczytaj()
{
	cout << "Jestem tu!" << endl << endl;
	fstream plik;
	plik.open("Zapis.txt", ios::app | ios::in | ios::out);
	string dane;
	getline(plik, dane);
	cout << "Wczytane!" << endl << endl;
}

void Kasa::Zapisz()
{

}