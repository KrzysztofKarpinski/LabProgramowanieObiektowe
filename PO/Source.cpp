#include<iostream>
#include<string>
#include<vector>

#include"Pracownik.h"
#include"Stazysta.h"
#include"Kasa.h"
#include"Tests.h"

using namespace std;

void ClrScr();

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
		

		cout << "	Menu	" << endl << "1. Dodaj konto pracownika" << endl << "2. Dodaj konto stazysty" << endl << "3. Usun konto pracownika" 
			<< endl << "4. Usun konto stazysty" << endl << "5. Edytuj saldo konta" << endl << "6. Wykonaj przelew" << endl 
			<< "7. Wyswietl stan kasy" << endl << "8. Wyswietl konta" << endl << "9. Zamow grupowo obiad" << endl <<"10. Wyjscie" << endl;
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
			cout << "Kogo usunac? (imie i nazwisko)" << endl;
			string imie, nazwisko;
			cin >> imie;
			cin >> nazwisko;
			kasa.UsunKontoPracownika(imie, nazwisko);
			kasa.ZapiszPracownikow();
		}

		if (menu == 4)
		{
			cout << "Kogo usunac? (imie i nazwisko)" << endl;
			string imie, nazwisko;
			cin >> imie;
			cin >> nazwisko;
			kasa.UsunKontoStazysty(imie, nazwisko);
			kasa.ZapiszStazystow();
		}

		if (menu == 5)
		{

			kasa.ZmianaSalda();
			kasa.ZapiszPracownikow();
			kasa.ZapiszStazystow();
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
			kasa.ZamowGrupowo();
			kasa.WypiszDlugi();
		}
		if (menu == 10)
		{
			return (doexit = false);
		}
	}
	cin.ignore();
}