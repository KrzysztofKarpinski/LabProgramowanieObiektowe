#include<iostream>
#include<string>
#include<vector>

#include"Posilek.h"
#include"Skarbonka.h"
#include"Pracownik.h"
#include"Stazysta.h"
#include"Kasa.h"
#include"Tests.h"

using namespace std;

int main()
{	
	Kasa kasa;
	StazysciPracownicyTworzenieTest();
	//kasa.ZapiszStazystow();
	kasa.WczytajKonta();
	kasa.PokazKontaStazystow();


	/*bool doexit=true;
	int menu;
	
	while (doexit == true)
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
		
	}*/
	cin.ignore();			//Zatrzymuje dzia³anie programu - u¿ytkownik mo¿e wpisaæ cokolwiek
	system("pause");
	return 0;
}