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

	void WczytajKonta();

	void PokazKontaStazystow();

	float PokazLaczneSaldo();

	//friend float Czlowiek::getSaldo();

	void UsunKontoStazysty(int Id);

	void Wczytaj();

	void ZapiszStazystow();
};