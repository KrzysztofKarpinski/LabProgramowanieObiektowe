#include<vector>
#include "Kasa.h"
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

vector<Stazysta> Lista_Stazystow;
vector<Pracownik> Lista_Pracownikow;							//http://geosoft.no/development/cppstyle.html

Kasa::Kasa()
{
	Lista_Stazystow.clear();
	Lista_Pracownikow.clear();
}

Kasa::~Kasa()
{

}

void Kasa::DodajKontoPracownika(Pracownik pracownik)
{
	if (!this->JestNaLiscie(pracownik))		//jezeli konta nie ma na liœcie to
	{
		Lista_Pracownikow.push_back(pracownik);//dodaj pracownika
	}
	else											//je¿eli jest to
	{
		cout << "To Id jest ju¿ zajête" << endl;	//Wyœwietl informacjê, ¿e u¿ytkownik ju¿ jest w systemie
	}
}

bool Kasa::JestNaLiscie(Pracownik kontoWejsciowePracownika)
{
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		if (pracownik->getId() == kontoWejsciowePracownika.getId())
		{
			return true;
		}
	}
	return false;
}


void Kasa::DodajKontoStazysty(Stazysta stazysta)
{
	if (!this->JestNaLiscie(stazysta))		//jezeli konta nie ma na liœcie to
	{
		Lista_Stazystow.push_back(stazysta);//dodaj pracownika
	}
	else											//je¿eli jest to
	{
		cout << "To Id jest ju¿ zajête" << endl;	//Wyœwietl informacjê, ¿e u¿ytkownik ju¿ jest w systemie
	}
}

bool Kasa::JestNaLiscie(Stazysta kontoWejscioweStazysty)
{
	for (vector<Stazysta>::iterator stazysta= this->Lista_Stazystow.begin(); stazysta!= this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getId() == kontoWejscioweStazysty.getId())
		{
			return true;
		}
	}
	return false;
}


void Kasa::PokazKonta()
{
	cout << "Wczytywanie: " << endl;
	fstream plik;
	plik.open("Zapis.txt", ios::in | ios::out);
	if (plik.good)
	{
		string napis;
		cout << endl;
		while (!plik.eof())
		{
			cout << "what" << endl;
			getline(plik, napis);
			cout << napis << endl;
		}
		plik.close();
	}
	else 
		cout << "Blad";
}


float Kasa::PokazLaczneSaldo()
{
	float suma1=0;
	float suma2 = 0;
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		suma1 += pracownik->getSaldo();
	}
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		suma2 += stazysta->getSaldo();
	}
	return (suma1 + suma2);
}

void Kasa::UsunKontoStazysty(int Id)
{
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getId() == Id)
		{
			Lista_Stazystow.erase(stazysta);
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