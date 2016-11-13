#include "Konto.h"

vector<Stazysta> sta¿ysta;
vector<Pracownik> pracownik;

Konto::Konto(int a, string b, string c, float d)
{
	this->Id = a;
	this->Imie = b;
	this->nazwisko = c;
	this->setSaldo(saldo);
}

Konto::~Konto()
{
}

int Konto::getId()
{
	return Id;
}

string Konto::getImie()
{
	return Imie;
}

string Konto::getNazwisko()
{
	return Nazwisko;
}