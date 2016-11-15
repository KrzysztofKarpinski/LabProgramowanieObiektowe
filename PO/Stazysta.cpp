#include "Stazysta.h"

Stazysta::Stazysta(int a, string b, string c, float d) : Czlowiek()
{

}

int Stazysta::getId()
{
	return id;
}

string Stazysta::getImie()
{
	return imie;
}

string Stazysta::getNazwisko()
{
	return nazwisko;
}

float Stazysta::getSaldo()
{
	return saldo;
}

float Stazysta::SaldoPoWplacieNaObiad()
{
	Posilek cena;
	return (saldo -= cena.getCena());
}

void Stazysta::przywitanie()
{
	cout << "Jestem Stazysta! :D" << endl;
}