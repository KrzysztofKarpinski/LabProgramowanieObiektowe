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
map<Czlowiek, double> ListaDlugow;


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
		cout << "To Id jest juz zajete" << endl;	//Wyœwietl informacjê, ¿e u¿ytkownik ju¿ jest w systemie
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
	if (!this->JestNaLiscie(stazysta))		
	{
		Lista_Stazystow.push_back(stazysta);
	}
	else											
	{
		cout << "To Id jest juz zajete" << endl;
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

bool Kasa::IstniejeId(int id)
{
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
		{
			if (stazysta->getId() == id || (pracownik->getId() == id))
			{
				return true;
			}
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
				if (stazysta->getId() < 200 && stazysta->getId() >= 100)
				{
					//cout << "Stazysta" << endl;
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
					//cout << "Pracownik" << endl;
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
		if (pracownik->getId() == Id && pracownik->getSaldo() == 0)
		{
			Lista_Pracownikow.erase(pracownik);
			break;
		}
		if (pracownik->getId() == Id && pracownik->getSaldo() != 0)
		{
			cout << "Nie udalo sie usunac z powodu niezerowego stanu konta." << endl;
		}
		if (pracownik->getId() != Id && pracownik->getSaldo() == 0)
		{
			cout << "Nie ma takiego Id" << endl;
		}
	}
}

void Kasa::UsunKontoStazysty(int Id)
{
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getId() == Id && stazysta->getSaldo() == 0)
		{
			Lista_Stazystow.erase(stazysta);
			break;
		}
		if (stazysta->getId() == Id && stazysta->getSaldo() != 0)
		{
			cout << "Nie udalo sie usunac z powodu niezerowego stanu konta." << endl;
		}
		if (stazysta->getId() != Id && stazysta->getSaldo() == 0)
		{
			cout << "Nie ma takiego Id" << endl;
		}
	}
}

void Kasa::ZapiszStazystow()
{
	ofstream os("Zapis1.txt");										//ten dosyæ brzydki zabieg czyœci ca³¹ zawartoœæ pliku
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
	ofstream os("Zapis.txt");										//ten dosyæ brzydki zabieg czyœci ca³¹ zawartoœæ pliku
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

	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		if (stazysta->getImie() == imie && stazysta->getNazwisko() == nazwisko)
		{
			stazysta->setSaldo(saldo);
		}
	}


}

void  Kasa::ZaplacZaObiad()
{
	Posilek posilek;

	Skarbonka skarbonka;
	
	int i = 0;

	for (vector<Pracownik>::iterator pracownik = this->Lista_Pracownikow.begin(); pracownik != this->Lista_Pracownikow.end(); pracownik++)
	{
		
		cout << "Pracownik numer " << i << ", ktory posilek?" << endl;
		float saldoP = pracownik->getSaldo();
		saldoP -= posilek.getCena();
		pracownik->setSaldo(saldoP);
		i++;
	}

	i = 0;
	for (vector<Stazysta>::iterator stazysta = this->Lista_Stazystow.begin(); stazysta != this->Lista_Stazystow.end(); stazysta++)
	{
		cout << "Stazysta numer " << i << ", ktory posilek?" << endl;
		float saldoS = stazysta->getSaldo();
		saldoS -= posilek.getCena();
		stazysta->setSaldo(saldoS);
		i++;
	}
}

void Kasa::ZamowGrupowo()
{
	double zaplacono;
	double rachunek;
	string identyfikator;

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
	cout << endl << endl << "Podaj identyfikatory kupujacych lub 'x', jesli skonczyles je wprowadzac." 
		<< endl << "**************************" << endl;
	cin >> identyfikator;
	
	vector<int> zrzutkowcy;
	
	while (identyfikator != "x")
	{
		try
		{
			if (IstniejeId(stoi(identyfikator)))
			{
				zrzutkowcy.push_back(stoi(identyfikator));
				cin >> identyfikator;
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
	
	cout << zaplacono << endl<< rachunek << endl << zrzutkowcy.size() << endl;
	
	double dlug = (zaplacono / rachunek) / zrzutkowcy.size();

	for (auto id = zrzutkowcy.begin(); id != zrzutkowcy.end(); id++)
	{
		if(this->listaDlugow.count(*id) == 0)
		{
			this->listaDlugow[*id] = dlug;
		}
		else
		{
			this->listaDlugow[*id] += dlug;
		}
	}

	cout << "Zamowienie zostalo zrealizowane, a kazdy ze zrzutkowcow jestesmy winni " << dlug << endl << endl;
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