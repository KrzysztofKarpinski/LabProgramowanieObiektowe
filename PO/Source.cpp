#include<iostream>
#include<string>
#include<vector>

#include"Posilek.h"
#include"Skarbonka.h"
#include"Konto.h"
#include"Pracownik.h"
#include"Sta¿ysta.h"
#include"Kasa.h"

using namespace std;

int main()
{
	bool doexit;
	int menu;

	/*Pracownik pracownik(1, "Jan", "Niezbedny", 120000);
	Sta¿ysta sta¿ysta(2, "Lucjan", "Wisniewski", 100000);
	Konto konto(3, "Anna", "Wesolowska", 220000);
	cout << konto.WplacNaObiad(1000) << endl;
	cout << sta¿ysta.WplacNaObiad(1000) << endl;
	cout << pracownik.WplacNaObiad(1000) << endl;
	cout << pracownik.Pozycz(50000) << endl;
	*/
	
	Skarbonka money(200.99);
	cout << "Saldo poczatkowe:" << money.getmoney() << endl;
	cout << "Reszta w skarbonce:" << money.PayForDinner() << endl;
	cout << "Skarbonka po wplacie:" << money.Wp³aæNaObiad() << endl;

	Cz³owiek czlowiek(1, "Adam","Wisniewski",1534.72);
	cout << "Saldo po wplacie na obiad:  " << czlowiek.SaldoPoWp³acieNaObiad()<< endl;



	Pracownik robol(2, "Jan", "Szczesny", 1234.67);
	cout <<"Saldo po wplacie na obiad przez robola: "<< robol.SaldoPoWp³acieNaObiad() << endl;

	Sta¿ysta S(3, "Jacek", "Maoki", 1223.7);
	cout << "Saldo S:" << S.SaldoPoWp³acieNaObiad() << endl;

	Pracownik P(4, "asd", "hgf", 1256.32);
	cout << "Przed pozyczka: " << P.getSaldo() << endl;
	cout << "Po pozyczce: " << P.Pozycz() << endl;


	Kasa osoba;
	Konto konto;
	
	cout << "Osoba: " << osoba.DodajKontoPracownika(konto) << endl;

	
	while (doexit = false)
	{
		cout << "1. Dodaj konto" << endl << "2. Usun konto" << endl << "3. Edytuj saldo konta" << endl << "4. Wykonaj przelew miedzy kontami" << endl << "5. Wyswietl stan kasy i salda wszystkich kont" << endl << "6. Wyjscie" << endl;
		cin >> menu;
		if (menu == 1); //Kasa::DodajKonto;
		if (menu == 2); //Kasa::UsunKonto;
		if (menu == 3); //Kasa::EdytujSaldo;
		if (menu == 4); //Kasa::WykonajPrzelew;
		if (menu == 5); //Kasa::WyswietlStan;
		if (menu == 6) return (doexit=false);
		
	}
	system("pause");
	return 0;
}