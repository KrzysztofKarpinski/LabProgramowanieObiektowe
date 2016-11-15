#pragma once
#include"Czlowiek.h"

class Stazysta : public Czlowiek
{
public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Stazysta(int a, string b, string c, float d);

	int getId();

	string getImie();

	string getNazwisko();

	float getSaldo();

	float SaldoPoWplacieNaObiad();

	void przywitanie();
};

