#include<vector>
#include "Kasa.h"
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include <map>

using namespace std;

vector<Stazysta> Lista_Stazystow;
vector<Pracownik> Lista_Pracownikow;							//http://geosoft.no/development/cppstyle.html
vector<Czlowiek> Lista_Ludzi;
map<string, double> ListaDlugow;


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
		Lista_Ludzi.push_back(pracownik);
	}
	else											//je¿eli jest to
	{
		cout << "Ten pracownik juz istnieje" << endl;	//Wyœwietl informacjê, ¿e u¿ytkownik ju¿ jest w systemie
	}
}

bool Kasa::JestNaLiscie(Pracownik kontoWejsciowePracownika)
{
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		if (pracownik->getImie() == kontoWejsciowePracownika.getImie() && pracownik->getNazwisko() == kontoWejsciowePracownika.getNazwisko())
		{
			return true;
		}
	}
	return false;
}

void Kasa::DodajKontoStazysty(Stazysta stazysta)
{
	if (!this->JestNaLiscie(stazysta))		
	{
		Lista_Stazystow.push_back(stazysta);
		Lista_Ludzi.push_back(stazysta);
	}
	else											
	{
		cout << "Ten stazysta juz istnieje" << endl;
	}
}

bool Kasa::JestNaLiscie(Stazysta kontoWejscioweStazysty)
{
	for (vector<Stazysta>::iterator stazysta= this->Lista_Stazystow.begin(); stazysta!= this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getImie() == kontoWejscioweStazysty.getImie() && stazysta->getNazwisko() == kontoWejscioweStazysty.getNazwisko())
		{
			return true;
		}
	}
	return false;
}

bool Kasa::Istnieje(string imie, string nazwisko)
{
	for (vector<Czlowiek>::iterator czlowiek = this->Lista_Ludzi.begin(); czlowiek != this->Lista_Ludzi.end(); czlowiek++)
	{
		if ((czlowiek->getImie() == imie) && (czlowiek->getNazwisko() == nazwisko))
		{
			return true;
		}
	}
	return false;
}

void Kasa::WczytajKontaStazystow()
{
	fstream plik;
	plik.open("Stazysci.txt", ios::in | ios::out);
	if (plik.good())
	{
		bool flag = true;
		string linie[3];								//Zamiast tworzyæ cztery ró¿ne zmienne mo¿na zapisaæ wszsystkie cztery informacje o u¿ytkowniku w jednej tablicy
		while (!plik.eof())
		{
			for (int i = 0; i < 3; i++)					//Wczytaj dane jednego u¿ytkownika
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
					linie[0],
					linie[1],
					stof(linie[2])						//stof = string to float
					);
				Lista_Stazystow.push_back(*stazysta);
				Lista_Ludzi.push_back(*stazysta);
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
	plik.open("Pracownicy.txt", ios::in | ios::out);
	if (plik.good())
	{
		bool flag = true;
		string linie[3];								//Zamiast tworzyæ cztery ró¿ne zmienne mo¿na zapisaæ wszsystkie cztery informacje o u¿ytkowniku w jednej tablicy
		while (!plik.eof())
		{
			for (int i = 0; i < 3; i++)					//Wczytaj dane jednego u¿ytkownika
			{
				if (plik.eof())							//sprawdzamy to za ka¿dym razem, gdy¿ u¿ytkownicy s¹ zapisywani ze znakiem nowej liniii na koñcu - daj breakpoint na for i uruchom debugger, przeklikaj do konca pliku
				{
					flag = false;
					break;
				}
				getline(plik, linie[i]);
			}

			if (flag)
			{
				Pracownik *pracownik = new Pracownik(
					linie[0],
					linie[1],
					stof(linie[2])						//stof = string to float
				);
				Lista_Pracownikow.push_back(*pracownik);
				Lista_Ludzi.push_back(*pracownik);
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
		cout << stazysta->toString() << endl;
	}
}

void Kasa::PokazKontaPracownikow()
{
	int i = 0;
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
			cout << pracownik->toString() << endl;
	}
}

void Kasa::PokazLaczneSaldo()
{
	float suma=0;
	for (vector<Czlowiek>::iterator czlowiek = this->Lista_Ludzi.begin(); czlowiek != this->Lista_Ludzi.end(); czlowiek++)
	{
		suma += czlowiek->getSaldo();
	}
	cout << suma << endl;
}

void Kasa::UsunKontoPracownika(string imie, string nazwisko)
{
	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		if (pracownik->getImie() == imie && pracownik->getNazwisko()==nazwisko && pracownik->getSaldo() == 0)
		{
			Lista_Pracownikow.erase(pracownik);
			break;
		}

		if (pracownik->getImie() == imie&& pracownik ->getNazwisko() == nazwisko && pracownik->getSaldo() != 0)
		{
			cout << "Nie udalo sie usunac z powodu niezerowego stanu konta." << endl;
		}

		if ((pracownik->getImie() != imie || pracownik->getNazwisko()== nazwisko) && pracownik->getSaldo() == 0)
		{
			cout << "Nie ma takiego pracownika" << endl;
		}
	}
}

void Kasa::UsunKontoStazysty(string imie, string nazwisko)
{
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getImie() == imie&& stazysta->getNazwisko()== nazwisko && stazysta->getSaldo() == 0)
		{
			Lista_Stazystow.erase(stazysta);
			break;
		}

		if (stazysta->getImie() == imie && stazysta->getNazwisko()==nazwisko && stazysta->getSaldo() != 0)
		{
			cout << "Nie udalo sie usunac z powodu niezerowego stanu konta." << endl;
		}

		if (stazysta->getImie() != imie&& stazysta->getNazwisko() == nazwisko && stazysta->getSaldo() == 0)
		{
			cout << "Nie ma takiego stazysty" << endl;
		}
	}
}
void Kasa::UsunKonto(string imie, string nazwisko)
{
	for (vector<Czlowiek>::iterator czlowiek = this->Lista_Ludzi.begin(); czlowiek != this->Lista_Ludzi.end(); czlowiek++)
	{
		if (czlowiek->getImie() == imie && czlowiek->getNazwisko() == nazwisko && czlowiek->getSaldo() == 0)
		{
			Lista_Ludzi.erase(czlowiek);
			break;
		}

		if (czlowiek->getImie() == imie && czlowiek->getNazwisko() == nazwisko && czlowiek->getSaldo() != 0)
		{
			cout << "Nie udalo sie usunac z powodu niezerowego stanu konta." << endl;
		}

		if (czlowiek->getImie() != imie&& czlowiek->getNazwisko() == nazwisko && czlowiek->getSaldo() == 0)
		{
			cout << "Nie ma takiego stazysty" << endl;
		}
	}
}

void Kasa::ZapiszStazystow()
{
	ofstream os("Stazysci.txt");										//ten dosyæ brzydki zabieg czyœci ca³¹ zawartoœæ pliku
	fstream plik;
	plik.open("Stazysci.txt", ios::app | ios::in | ios::out);			
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
	ofstream os("Pracownicy.txt");										//ten dosyæ brzydki zabieg czyœci ca³¹ zawartoœæ pliku
	fstream plik;
	plik.open("Pracownicy.txt", ios::app | ios::in | ios::out);
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

	cout << "Od kogo ? (imie i nazwisko)" << endl;
	cin >> imie1;
	cin >> nazwisko1;

	cout << "Dla kogo? (imie i nazwisko)" << endl;
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

	cout << "Komu zmienic saldo konta ? (imie i nazwisko)" << endl;
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

	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getImie() == imie && stazysta->getNazwisko() == nazwisko)
		{
			stazysta->setSaldo(saldo);
		}
	}

	for (vector<Czlowiek>::iterator czlowiek = this->Lista_Ludzi.begin(); czlowiek != this->Lista_Ludzi.end(); czlowiek++)
	{
		if (czlowiek->getImie() == imie && czlowiek->getNazwisko() == nazwisko)
		{
			czlowiek->setSaldo(saldo);
		}
	}


}

void Kasa::ZamowGrupowo()
{
	double zaplacono;
	double rachunek;
	string imie, nazwisko, identyfikator;

	try
	{
		cout << "Podaj kwote, jaka zaplacono: ";
		cin >> zaplacono;
		cout << endl << "Podaj kwote, na jaka opiewa rachunek: ";
		cin >> rachunek;
	}
	catch(string exception)
	{
		cout << "Wprowadzono niepoprawna wartosc" << endl;
		cout << exception << endl;
		cout << "Program wyjdzie z funkcji" << endl;
		return;
	}

	if (zaplacono >= rachunek)
	{
		cout << endl << endl << "Podaj identyfikatory kupujacych lub 'x', jesli skonczyles je wprowadzac."
			<< endl << "**************************" << endl;
		cin >> imie >> nazwisko;

		vector<string> zrzutkowcy;

		while (imie != "x" && nazwisko !="x")
		{
			try
			{
				if (Istnieje(imie, nazwisko))
				{
					identyfikator = Nazwa(imie, nazwisko);
					zrzutkowcy.push_back(identyfikator);
					cin >> imie >> nazwisko;
				}
				else
				{
					cout << "Nie ma takiej osoby w firmie" << endl;
					cin >> identyfikator;
				}
			}
			catch (string exception)
			{
				cout << "Niepoprawny format. Sprobuj jeszcze raz.";
			}
		}

		cout << "**************************" << endl;
		
		double dlug = (zaplacono - rachunek) / zrzutkowcy.size();
		
		/*for (auto id = zrzutkowcy.begin(); id != zrzutkowcy.end(); id++)
		{
			if (this->listaDlugow.count(*id) == 0)
			{
				this->listaDlugow[*id] = dlug;
			}
			else
			{
				this->listaDlugow[*id] += dlug;
			}
		}*/

		cout << "Zamowienie zostalo zrealizowane, a kazdy ze zrzutkowcow jestesmy winni " << dlug << endl << endl;
		
	}
	else
		cout << "Nie mozna zaplacic za obiad z powodu zbyt malej kwoty zebranej" << endl;

}

void Kasa::WypiszDlugi()
{
	fstream plik;
	plik.open("Dlugi.txt", ios::app | ios::in | ios::out);
	for (auto id = this->listaDlugow.begin(); id != this->listaDlugow.end(); id++)
	{
		cout << "Uzytkownikowi o id " << id->first << " jestesmy winni " << id->second << endl;
		plik << id->first << endl << id->second<< endl;
	}
}

string Kasa::Nazwa(string a, string b)
{
	return (a+b);
}