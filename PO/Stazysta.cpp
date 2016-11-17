#include "Stazysta.h"

int Stazysta::idBiezace = 100;			//Te dwie zmienne s¹ takie same dla KLASY - nie dla obiektu
int Stazysta::idMaksymalne = 199;

Stazysta::Stazysta(string b, string c, float d) : Czlowiek()
{
	id = Stazysta::idBiezace++;
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
	return (saldo -= cena.getCena());
}

void Stazysta::przywitanie()
{
	cout << "Jestem Stazysta! :D" << endl << "Moje imie to " << this->getImie() << endl << "Moje nazwisko to " 
		<< this->getNazwisko() << endl << "Moje id to " << this->getId() << endl << endl;
}