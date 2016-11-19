#pragma once
#include<iostream>
#include<vector>
#include"Czlowiek.h"
#include"Pracownik.h"
#include"Stazysta.h"
#include<string>

using namespace std;

class Kasa
{
public:
	vector<Stazysta> Lista_Stazystow;
	vector<Pracownik> Lista_Pracownikow;

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

	void UsunKontoStazysty(int Id);

	void UsunKontoPracownika(int Id);

	void ZapiszStazystow();

	void ZapiszPracownikow();

	void Przelew();

	void ZmianaSalda();

	void ZaplacZaObiad();
};