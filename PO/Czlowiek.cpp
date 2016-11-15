#include "Czlowiek.h"



Czlowiek::Czlowiek(int a, string b, string c, float d)
{
	this->id = a;
	this->imie = b;
	this->nazwisko = c;
	this->saldo = d;
}

Czlowiek::~Czlowiek()
{
}

float Czlowiek::SaldoPoWplacieNaObiad()
{
	Posilek cena;
	return (saldo -= cena.getCena());
}

float Czlowiek::getSaldo()
{
	return (saldo);
}

int Czlowiek::getId()
{
	return id;
}

string Czlowiek::getImie()
{
	return imie;
}

string Czlowiek::getNazwisko()
{
	return nazwisko;
}