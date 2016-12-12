#include "Pracownik.h"


Pracownik::Pracownik(string b, string c, float d) : Czlowiek(b,c,d)
{
	imie = b;
	nazwisko = c;
	saldo = d;
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