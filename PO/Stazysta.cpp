#include "Stazysta.h"

Stazysta::Stazysta(int a, string b, string c, float d) : Czlowiek()
{
	id = a;
	imie = b;
	nazwisko = c;
	saldo = d;
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
	float cena1 = cena.getCena();
	if (saldo >= cena1)
	{
		return (saldo -= cena1);
	}
	else
		cout << "Nie stac Cie na obiad!" << endl;
}

void Stazysta::przywitanie()
{
	cout << "Jestem Stazysta! :D" << endl;
}