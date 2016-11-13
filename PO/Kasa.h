#pragma once
#include<iostream>
#include<vector>
#include"Konto.h"
#include"Pracownik.h"
#include"Sta¿ysta.h"
#include<string>

using namespace std;

class Kasa
{
public:
	vector<Konto> Lista_Kont;

	Kasa();
	
	virtual ~Kasa();

	void DodajKontoPracownika(Konto kontoWejsciowe);

	bool JestNaLiscie(Konto kontoWejsciowe);

	void PokazKonta();

	void UsuñKonto();

	void Wczytaj();

	void Zapisz();
};