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
	if (!this->JestNaLiscie(pracownik))		//jezeli konta nie ma na li�cie to
	{
		Lista_Pracownikow.push_back(pracownik);//dodaj pracownika
	}
	else											//je�eli jest to
	{
		cout << "To Id jest ju� zaj�te" << endl;	//Wy�wietl informacj�, �e u�ytkownik ju� jest w systemie
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
	if (!this->JestNaLiscie(stazysta))		//jezeli konta nie ma na li�cie to
	{
		Lista_Stazystow.push_back(stazysta);//dodaj pracownika
	}
	else											//je�eli jest to
	{
		cout << "To Id jest ju� zaj�te" << endl;	//Wy�wietl informacj�, �e u�ytkownik ju� jest w systemie
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


void Kasa::WczytajKontaStazystow()
{
	//cout << "Wczytywanie: " << endl;
	fstream plik;
	plik.open("Zapis1.txt", ios::in | ios::out);
	if (plik.good())
	{
		bool flag = true;
		string linie[4];								//Zamiast tworzy� cztery r�ne zmienne mo�na zapisa� wszsystkie cztery informacje o u�ytkowniku w jednej tablicy
		while (!plik.eof())
		{
			for (int i = 0; i < 4; i++)					//Wczytaj dane jednego u�ytkownika
			{
				if (plik.eof())							//sprawdzamy to za ka�dym razem, gdy� u�ytkownicy s� zapisywani ze znakiem nowej liniii na ko�cu - daj breakpoint na for i uruchom debugger, przeklikaj do konca pliku
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
				if (stazysta->getId() < 200 && stazysta->getId() >= 100)
				{
					cout << "Stazysta" << endl;
					Lista_Stazystow.push_back(*stazysta);
				}
			}
		}
		plik.close();
	}
	else 
		cout << "Blad";
}

void Kasa::WczytajKontaPracownikow()
{
	//cout << "Wczytywanie: " << endl;
	fstream plik;
	plik.open("Zapis.txt", ios::in | ios::out);
	if (plik.good())
	{
		bool flag = true;
		string linie[4];								//Zamiast tworzy� cztery r�ne zmienne mo�na zapisa� wszsystkie cztery informacje o u�ytkowniku w jednej tablicy
		while (!plik.eof())
		{
			for (int i = 0; i < 4; i++)					//Wczytaj dane jednego u�ytkownika
			{
				if (plik.eof())							//sprawdzamy to za ka�dym razem, gdy� u�ytkownicy s� zapisywani ze znakiem nowej liniii na ko�cu - daj breakpoint na for i uruchom debugger, przeklikaj do konca pliku
				{
					flag = false;
					break;
				}
				getline(plik, linie[i]);
			}

			if (flag)
			{
				Pracownik *pracownik = new Pracownik(
					stoi(linie[0]),						//stoi = string to int
					linie[1],
					linie[2],
					stof(linie[3])						//stof = string to float
				);
				if (pracownik->getId() <100)
				{
					cout << "Pracownik" << endl;
					Lista_Pracownikow.push_back(*pracownik);
				}
				
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
		if (100 < stazysta->getId() < 200)
		{
			cout << "Stazysta numer " << i++ << ":" << endl;
			cout << stazysta->toString() << endl;
		}
	}
}

void Kasa::PokazKontaPracownikow()
{
	int i = 0;
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		if (pracownik->getId() < 100)
		{
			cout << "Pracownik numer " << i++ << ":" << endl;
			cout << pracownik->toString() << endl;
		}
	}
}

void Kasa::PokazLaczneSaldo()
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
	float suma = suma1 + suma2;
	cout << suma << endl;
}

void Kasa::UsunKontoPracownika(int Id)
{
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		if (pracownik->getId() == Id)
		{
			Lista_Pracownikow.erase(pracownik);
			break;
		}
	}
}

void Kasa::UsunKontoStazysty(int Id)
{
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getId() == Id)
		{
			Lista_Stazystow.erase(stazysta);
			break;
		}
	}
}

void Kasa::ZapiszStazystow()
{
	ofstream os("Zapis1.txt");										//ten dosy� brzydki zabieg czy�ci ca�� zawarto�� pliku
	fstream plik;
	plik.open("Zapis1.txt", ios::app | ios::in | ios::out);			
	if (plik.good() == true)										
	{
		//cout << "Uzyskano dostep do pliku!" << endl;
		for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
		{
			plik << stazysta->toString();
		}
		
		plik.close();
	}
	else cout << "Dostep do pliku zostal zabroniony!" << endl;
}

void Kasa::ZapiszPracownikow()
{
	ofstream os("Zapis.txt");										//ten dosy� brzydki zabieg czy�ci ca�� zawarto�� pliku
	fstream plik;
	plik.open("Zapis.txt", ios::app | ios::in | ios::out);
	if (plik.good() == true)
	{
		//cout << "Uzyskano dostep do pliku!" << endl;
		for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
		{
			plik << pracownik->toString();
		}

		plik.close();
	}
	else cout << "Dostep do pliku zostal zabroniony!" << endl;
}

void Kasa::Przelew()
{
	string imie1, imie2, nazwisko1, nazwisko2;
	float saldo1, saldo2;

	cout << "Od kogo ?" << endl;
	cin >> imie1;
	cin >> nazwisko1;

	cout << "Dla kogo?" << endl;
	cin >> imie2;
	cin >> nazwisko2;

	cout << "Kwota pozyczki:" << endl;
	float kwota;
	cin >> kwota;

	for (vector<Pracownik>::iterator pracownik1 = this->Lista_Pracownikow.begin(); pracownik1 != this->Lista_Pracownikow.end(); pracownik1++)
	{
		for (vector<Pracownik>::iterator pracownik2 = this->Lista_Pracownikow.begin(); pracownik2 != this->Lista_Pracownikow.end(); pracownik2++)
		{
			if ((pracownik1->getImie() == imie1) && (pracownik1->getNazwisko() == nazwisko1) && (pracownik2->getImie() == imie2) && (pracownik2->getNazwisko() == nazwisko2))
			{
				saldo1 = pracownik1->getSaldo();
				saldo2 = pracownik2->getSaldo();

				saldo1 -= kwota;
				saldo2 += kwota;

				pracownik1->setSaldo(saldo1);
				pracownik2->setSaldo(saldo2);
			}
		}
		
	}
}

void Kasa::ZmianaSalda()
{
	string imie, nazwisko;
	float saldo;

	cout << "Komu zmienic saldo konta ?" << endl;
	cin >> imie;
	cin >> nazwisko;

	cout << "Na jaka kwote zmienic?" << endl;
	cin >> saldo;

	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		if (pracownik->getImie() == imie && pracownik->getNazwisko() == nazwisko)
		{
			pracownik->setSaldo(saldo);
		}
	}
}