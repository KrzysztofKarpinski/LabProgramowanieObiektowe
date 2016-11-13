#include "Posilek.h"
#include<iostream>

using namespace std;

Posilek::Posilek()
{
	newCena = 10;
}

Posilek::Posilek(float cena)
{
	newCena = cena;
}

float Posilek::getCena()
{
	int menu;
	cout << "Menu:" << endl << endl << "1. Schabowy z ziemniakami: 19.99zl." << endl << "2. Pierogi ruskie: 12.99zl." << endl << "3. Kluski slaskie: 10.99zl" << endl;
	cin >> menu;
	if (menu == 1) { newCena = 19.99; }
	if (menu == 2) { newCena = 12.99; }
	if (menu == 3) { newCena = 10.99; }

	return (newCena);
}

