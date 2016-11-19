#include "Pracownik.h"

int Pracownik::idBiezace = 0;			//Te dwie zmienne s¹ takie same dla KLASY - nie dla obiektu
int Pracownik::idMaksymalne = 99;

Pracownik::Pracownik(string b, string c, float d) : Czlowiek()
{
	id = idBiezace++;
	imie = b;
	nazwisko = c;
	saldo = d;
}

Pracownik::Pracownik(int a, string b, string c, float d) : Czlowiek()
{
	id = a;
	imie = b;
	nazwisko = c;
	saldo = d;

	if (Pracownik::idBiezace <= id)
	{
		Pracownik::idBiezace = id + 1;
	}
}

int Pracownik::getId()
{
	return id;
}

int Pracownik::setId(int newId)
{
	idBiezace = newId;
	return idBiezace;
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

float Pracownik::setSaldo(float saldo1)
{
	saldo = saldo1;
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
	if (saldo >= ile)
	{
		return (saldo -= ile);
	}
	else
		cout << "Brak wystarczajacych srodkow na koncie!" << endl;
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

string Pracownik::toString()
{
	return to_string(this->getId()) + "\n"
		+ this->getImie() + "\n"
		+ this->getNazwisko() + "\n"
		+ to_string(this->getSaldo()) + "\n";
}