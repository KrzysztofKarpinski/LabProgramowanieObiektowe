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
	kasa.WczytajKontaPracownikow();

	while (doexit == true)
	{
		

		cout << "	Menu	" << endl << "1. Dodaj konto pracownika" << endl << "2. Dodaj konto stazysty" << endl << "3. Usun konto pracownika" << endl << "4. Usun konto stazysty" << endl << "5. Edytuj saldo konta" << endl << "6. Wykonaj przelew" << endl << "7. Wyswietl stan kasy" << endl << "8. Wyswietl konta" << endl << "9. Zaplac za obiad" << endl <<"10. Wyjscie" << endl;
		cin >> menu;
		if (menu == 1)
		{
			cout << "Imie, nazwisko, saldo" << endl;

			string imie;
			cin >> imie;

			string nazwisko;
			cin >> nazwisko;

			float saldo;
			cin >> saldo;

			Pracownik P(imie, nazwisko, saldo);

			kasa.DodajKontoPracownika(P);
			kasa.ZapiszPracownikow();
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
			cout << "Jaki numer konta usunac? (Id pracownika od 0 do 99)" << endl;
			int n;
			cin >> n;
			kasa.UsunKontoPracownika(n);
			kasa.ZapiszPracownikow();
		}

		if (menu == 4)
		{
			cout << "Jaki numer konta usunac? (Id stazysty od 100 do 199)" << endl;
			int n;
			cin >> n;
			kasa.UsunKontoStazysty(n);
			kasa.ZapiszStazystow();
		}

		if (menu == 5)
		{

			kasa.ZmianaSalda();
			kasa.ZapiszPracownikow();
		}

		
		if (menu == 6)
		{
			kasa.Przelew();
			kasa.ZapiszPracownikow();
		}
		if (menu == 7)
		{
			kasa.PokazLaczneSaldo();
		}
		
		if (menu == 8)
		{
			kasa.PokazKontaPracownikow();
			kasa.PokazKontaStazystow();
		}
		

		if (menu == 9)
		{
			kasa.ZaplacZaObiad();
		}
		if (menu == 10)
		{
			return (doexit = false);
		}
	}
	cin.ignore();			//Zatrzymuje dzia³anie programu - u¿ytkownik mo¿e wpisaæ cokolwiek
	system("pause");
	return 0;
}