#include "Czlowiek.h"



Cz�owiek::Cz�owiek(int a, string b, string c, float d)
{

}

Cz�owiek::~Cz�owiek()
{
}

float Cz�owiek::SaldoPoWp�acieNaObiad()
{
	Posilek cena;
	return (saldo -= cena.getCena());
}

float Cz�owiek::getSaldo()
{
	return (saldo);
}