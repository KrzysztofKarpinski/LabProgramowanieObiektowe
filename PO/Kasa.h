#pragma once
#include<iostream>
#include<vector>
#include"Czlowiek.h"
#include"Pracownik.h"
#include"Stazysta.h"
#include<string>
#include <map>

using namespace std;

class Kasa
{
public:
	vector<Stazysta> Lista_Stazystow;
	vector<Pracownik> Lista_Pracownikow;
	vector<Czlowiek> Lista_Ludzi;
	map<int, double> listaDlugow;

	Kasa();
	
	virtual ~Kasa();

	void DodajKontoPracownika(Pracownik pracownik);

	bool JestNaLiscie(Pracownik kontoWejsciowePracownika);

	void DodajKontoStazysty(Stazysta stazysta);

	bool JestNaLiscie(Stazysta kontoWejscioweStazysty);

	void WczytajKontaStazystow();

	void WczytajKontaPracownikow();

	void PokazKontaStazystow();

	void PokazKontaPracownikow();

	void PokazLaczneSaldo();

	void UsunKontoStazysty(string imie, string nazwisko);

	void UsunKontoPracownika(string imie, string nazwisko);

	void UsunKonto(string imie, string nazwisko);

	void ZapiszStazystow();

	void ZapiszPracownikow();

	void Przelew();

	void ZmianaSalda();

	void ZamowGrupowo();

	void WypiszDlugi();

	bool Istnieje(string imie, string nazwisko);

	string Nazwa(string a, string b);
};