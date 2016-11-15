#pragma once
#include<iostream>
#include<vector>
#include"Czlowiek.h"
#include"Pracownik.h"
#include"Sta¿ysta.h"
#include<string>

using namespace std;

class Kasa
{
public:
	vector<Czlowiek> Lista_Ludzi;

	Kasa();
	
	virtual ~Kasa();

	void DodajKontoPracownika(Pracownik pracownik);

	void DodajKontoStazysty(Stazysta stazysta);

	bool JestNaLiscie(Czlowiek kontoWejsciowe);

	void PokazKonta();

	float PokazLaczneSaldo();

	friend float Czlowiek::getSaldo();

	void UsunKonto(int Id);

	void Wczytaj();

	void Zapisz();
};