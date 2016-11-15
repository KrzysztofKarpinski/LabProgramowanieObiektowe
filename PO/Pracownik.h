#pragma once
#include"Czlowiek.h"

class Pracownik : public Czlowiek
{
public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Pracownik(int a, string b, string c, float d);

	int getId();

	string getImie();

	string getNazwisko();

	float getSaldo();

	float Pozycz();

	float Oddaj();

	float SaldoPoWplacieNaObiad();

	void przywitanie();
};

