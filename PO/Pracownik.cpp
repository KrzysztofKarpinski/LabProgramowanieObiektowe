#include "Pracownik.h"



Pracownik::Pracownik(int a, string b, string c, float d) : Cz³owiek(a,b,c,d)
{

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
	return (saldo += ile);
}