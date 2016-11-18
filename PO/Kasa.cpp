#include<vector>
#include "Kasa.h"
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

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


void Kasa::WczytajKonta()
{
	cout << "Wczytywanie: " << endl;
	fstream plik;
	plik.open("Zapis.txt", ios::in | ios::out);
	if (plik.good())
	{
		bool flag = true;
		string linie[4];								//Zamiast tworzyæ cztery ró¿ne zmienne mo¿na zapisaæ wszsystkie cztery informacje o u¿ytkowniku w jednej tablicy
		while (!plik.eof())
		{
			for (int i = 0; i < 4; i++)					//Wczytaj dane jednego u¿ytkownika
			{
				if (plik.eof())							//sprawdzamy to za ka¿dym razem, gdy¿ u¿ytkownicy s¹ zapisywani ze znakiem nowej liniii na koñcu - daj breakpoint na for i uruchom debugger, przeklikaj do konca pliku
				{
					flag = false;
					break;
				}
				getline(plik, linie[i]);	
			}

			if(flag)
			{
				Stazysta *stazysta = new Stazysta(
					stoi(linie[0]),						//stoi = string to int
					linie[1],
					linie[2],
					stof(linie[3])						//stof = string to float
					);

				Lista_Stazystow.push_back(*stazysta);
			}
		}
		plik.close();
	}
	else 
		cout << "Blad";
}

void Kasa::PokazKontaStazystow()
{
	int i = 0;
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		cout << "Stazysta numer " << i++ << ":" << endl;
		cout << stazysta->toString() << endl;
	}
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