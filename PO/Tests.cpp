#include"Tests.h"
#include<fstream>
#include<iostream>

void PracownikTest()
{
	Pracownik pracownik("Jan", "Niezbedny", 120);

	//cout << pracownik.getId()<< endl;
	cout << pracownik.getImie()<< endl;
	cout << pracownik.getNazwisko() << endl;
	cout << pracownik.getSaldo() << endl;
	cout << pracownik.Oddaj() << endl;
	cout << pracownik.Pozycz() << endl;
	//pracownik.przywitanie();
}

void StazystaTest()
{
	Stazysta stazysta("Jasiu", "Pacula", 1245.7);

	//cout << stazysta.getId() << endl;
	cout << stazysta.getImie() << endl;
	cout << stazysta.getNazwisko() << endl;
	cout << stazysta.getSaldo() << endl;
	//stazysta.przywitanie();
}

/*void CzlowiekTest()
{
	Czlowiek czlowiek;

	czlowiek.przywitanie();
}*/

void KasaTest()
{
	Kasa kasa;

	Kasa DodajKontoPracownika(Pracownik pracownik);    //wpisywanie id, imie, nazwisko, saldo pracownika
	Kasa DodajKontoStazysty(Stazysta stazysta);			//wpisywanie id, imie, nazwisko, saldo stazysty
	Kasa JestNaLiscie(Pracownik pracownik);				//sprawdza czy id pracownika jest wolne
	Kasa JestNaLiscie(Stazysta stazysta);				//sprawdza czy id stazysty jest wolne
	Kasa PokazKonta();									// wypisuje konta, stazystow i pracownikow
	Kasa PokazLaczneSaldo();							// suma sald pracownikow i stazystow
	Kasa UsunKontoStazysty(int id);						// usuwa konto stazysty o podanym id (tak samo z pracownikiem)
	Kasa Wczytaj();
}

void StazysciPracownicyTworzenieTest()
{
	cout << "Przyklad: " << endl;
	Pracownik P1("Janek", "Maci", 7889.3);
	Pracownik P2("Maciej", "Miszt", 890.7);
	Pracownik P3("Kuba", "Kras", 687.3);
	Stazysta S1("Lucjan", "Mars", 7876.6);
	Stazysta S2("Alan", "Walker", 67868.4);
	Stazysta S3("Darek", "Just", 67687.2);
}

void MapyTest(Kasa& kasa)
{
	kasa.ZamowGrupowo();
	kasa.ZamowGrupowo();
	kasa.WypiszDlugi();
}
