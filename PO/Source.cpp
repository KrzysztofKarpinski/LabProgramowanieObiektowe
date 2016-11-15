#include<iostream>
#include<string>
#include<vector>

#include"Posilek.h"
#include"Skarbonka.h"
#include"Pracownik.h"
#include"Sta퓓sta.h"
#include"Kasa.h"

using namespace std;

int main()
{
	bool doexit;
	int menu;

	/*Pracownik pracownik(1, "Jan", "Niezbedny", 120000);
	Sta퓓sta sta퓓sta(2, "Lucjan", "Wisniewski", 100000);
	cout << konto.WplacNaObiad(1000) << endl;
	cout << sta퓓sta.WplacNaObiad(1000) << endl;
	cout << pracownik.WplacNaObiad(1000) << endl;
	cout << pracownik.Pozycz(50000) << endl;
	
	
	Skarbonka money(200.99);
	cout << "Saldo poczatkowe:" << money.getmoney() << endl;
	cout << "Reszta w skarbonce:" << money.ZaplacZaObiad() << endl;
	cout << "Skarbonka po wplacie:" << money.WplacNaObiad() << endl;

	Czlowiek czlowiek(1, "Adam","Wisniewski",1534.72);
	cout << "Saldo po wplacie na obiad:  " << czlowiek.SaldoPoWplacieNaObiad()<< endl;



	Pracownik robol(2, "Jan", "Szczesny", 1234.67);
	cout <<"Saldo po wplacie na obiad przez robola: "<< robol.SaldoPoWplacieNaObiad() << endl;

	Stazysta S(3, "Jacek", "Maoki", 1223.7);
	cout << "Saldo S:" << S.SaldoPoWplacieNaObiad() << endl;

	Pracownik P(4, "asd", "hgf", 1256.32);
	cout << "Przed pozyczka: " << P.getSaldo() << endl;
	cout << "Po pozyczce: " << P.Pozycz() << endl;

	Kasa K;
	*/
	//Czlowiek czlowiek;

	
	while (doexit = true)
	{
		cout << "1. Dodaj konto" << endl << "2. Usun konto" << endl << "3. Edytuj saldo konta" << endl << "4. Wykonaj przelew miedzy kontami" << endl << "5. Wyswietl stan kasy i salda wszystkich kont" << endl << "6. Wczytaj" << endl << "7. Wyjscie" << endl;
		cin >> menu;
		if (menu == 1); Kasa DodajKontoPracownika(Czlowiek kontoWejsciowe);
		if (menu == 2); //Kasa::UsunKonto;
		if (menu == 3); //Kasa::EdytujSaldo;
		if (menu == 4); //Kasa::WykonajPrzelew;
		if (menu == 5); //Kasa::WyswietlStan;
		if (menu == 6) 
			Kasa Wczytaj();
		if (menu == 7) return (doexit=false);
		
	}
	system("pause");
	return 0;
}