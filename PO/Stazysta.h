#pragma once
#include"Czlowiek.h"

class Stazysta : public Czlowiek
{
private:
	static int idBiezace;
	static int idMaksymalne;

public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Stazysta(string b, string c, float d);

	Stazysta(int a, string b, string c, float d);

	int getId();

	string getImie();

	string getNazwisko();

	float getSaldo();

	float SaldoPoWplacieNaObiad();

	void przywitanie();

	string toString();
};

