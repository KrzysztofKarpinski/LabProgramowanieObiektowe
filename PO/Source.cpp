#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#include"Posilek.h"
#include"Skarbonka.h"
#include"Pracownik.h"
#include"Stazysta.h"
#include"Kasa.h"
#include"Tests.h"

using namespace std;

int main()
{	
	//PracownikTest();
	//StazystaTest();
	//CzlowiekTest();
	//SkarbonkaTest();
	//PosilekTest();
	//KasaTest();
	Kasa kasa;

	Przyklad();

	bool doexit=true;
	int menu;
	
	while (doexit == true)
	{
		cout << "1. Dodaj konto" << endl << "2. Usun konto" << endl << "3. Edytuj saldo konta" << endl << "4. Wykonaj przelew miedzy kontami" << endl << "5. Wyswietl stan kasy i salda wszystkich kont" << endl << "6. Wczytaj" << endl << "7. Wyjscie" << endl;
		cin >> menu;
		if (menu == 1); //kasa.DodajKontoPracownika();
		if (menu == 2); //Kasa::UsunKonto;
		if (menu == 3); //Kasa::EdytujSaldo;
		if (menu == 4); //Kasa::WykonajPrzelew;
		if (menu == 5) kasa.PokazKonta();
		if (menu == 6) kasa.Wczytaj();
		if (menu == 7) return (doexit = false);
	}
	system("pause");
	return 0;
}