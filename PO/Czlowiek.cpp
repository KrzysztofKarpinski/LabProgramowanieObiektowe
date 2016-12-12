#include "Czlowiek.h"

Czlowiek::Czlowiek(string b, string c, float d)
{
	imie = b;
	nazwisko = c;
	saldo = d;
}

string Czlowiek::getImie()
{
	return imie;
}

string Czlowiek::getNazwisko()
{
	return nazwisko;
}

float Czlowiek::getSaldo()
{
	return saldo;
}

float Czlowiek::setSaldo(float saldo1)
{
	saldo = saldo1;
	return saldo;
}

string Czlowiek::toString()
{
	return this->getImie() + "\n"
		+ this->getNazwisko() + "\n"
		+ to_string(this->getSaldo()) + "\n";
}