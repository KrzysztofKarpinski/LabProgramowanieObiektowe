#pragma once
#include"Czlowiek.h"

class Pracownik : public Czlowiek
{
private:
	static int idBiezace;
	static int idMaksymalne;
public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Pracownik(string b, string c, float d);

	Pracownik(int a, string b, string c, float d);

	int getId();

	string getImie();

	string getNazwisko();

	float getSaldo();

	float setSaldo(float saldo1);

	float Pozycz();

	float Oddaj();

	float SaldoPoWplacieNaObiad();

	void przywitanie();

	string toString();
};

