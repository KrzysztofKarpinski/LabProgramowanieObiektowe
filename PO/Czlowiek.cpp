#include "Czlowiek.h"



Czlowiek::Czlowiek(int a, string b, string c, float d)
{

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