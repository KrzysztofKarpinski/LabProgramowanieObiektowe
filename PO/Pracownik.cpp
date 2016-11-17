#include "Pracownik.h"

Pracownik::Pracownik(int a, string b, string c, float d) : Czlowiek()
{
	id = a;
	imie = b;
	nazwisko = c;
	saldo = d;
}

int Pracownik::getId()
{
	return id;
}

string Pracownik::getImie()
{
	return imie;
}

string Pracownik::getNazwisko()
{
	return nazwisko;
}

float Pracownik::getSaldo()
{
	return saldo;
}

float Pracownik::Pozycz()
{
	float ile;
	cout << "Ile pozyczyc?";
	cin >> ile;
	return (saldo += ile);
}

float Pracownik::Oddaj()
{
	float ile;
	cout << "Ile oddajesz?";
	cin >> ile;
	return (saldo -= ile);
}

float Pracownik::SaldoPoWplacieNaObiad()
{
	Posilek cena;
	return (saldo -= cena.getCena());
}

void Pracownik::przywitanie()
{
	cout << "Jestem Pracownikiem! :D" << endl;
}