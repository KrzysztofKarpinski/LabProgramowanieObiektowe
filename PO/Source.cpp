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
	//StazysciPracownicyTworzenieTest();
	//kasa.ZapiszStazystow();
	//kasa.WczytajKonta();
	//kasa.ZapiszStazystow();
	//kasa.PokazKontaStazystow();
	//kasa.PokazLaczneSaldo();
	
	bool doexit=true;
	int menu;
	
	kasa.WczytajKontaStazystow();

	while (doexit == true)
	{
		

		cout << "	Menu	" << endl << "1. Dodaj konto pracownika" << endl << "2. Dodaj konto stazysty" << endl << "3. Usun konto pracownika" << endl << "4. Usun konto stazysty" << endl << "5. Edytuj saldo konta" << endl << "6. Wykonaj przelew" << endl << "7. Wyswietl stan kasy" << endl << "8. Wyswietl konta" << endl << "9. Wyjscie" << endl;
		cin >> menu;
		if (menu == 1)
		{

		}

		if (menu == 2)
		{
			cout << "Imie, nazwisko, saldo" << endl;

			string imie;
			cin >> imie;

			string nazwisko;
			cin >> nazwisko;

			float saldo;
			cin >> saldo;

			Stazysta S(imie, nazwisko, saldo);
			
			kasa.DodajKontoStazysty(S);
			kasa.ZapiszStazystow();
		}

		if (menu == 3)
		{

		}

		if (menu == 4)
		{
			int n;
			cin >> n;
			kasa.UsunKontoStazysty(n);
			kasa.ZapiszStazystow();
		}

		if (menu == 5)
		{
			//Kasa::EdytujSaldo;
		}

		
		if (menu == 6)
		{
			//Wykonaj przelew
		}
		if (menu == 7)
		{
			kasa.PokazLaczneSaldo();
		}
		
		if (menu == 8)
		{
			kasa.PokazKontaStazystow();
		}
		
		if (menu == 9)
		{
			return (doexit = false);
		}
	}
	cin.ignore();			//Zatrzymuje dzia³anie programu - u¿ytkownik mo¿e wpisaæ cokolwiek
	system("pause");
	return 0;
}