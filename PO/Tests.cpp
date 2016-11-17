#include"Tests.h"
#include<fstream>
#include <iostream>

void PracownikTest()
{
	Pracownik pracownik(1, "Jan", "Niezbedny", 120);

	cout << pracownik.getId()<< endl;
	cout << pracownik.getImie()<< endl;
	cout << pracownik.getNazwisko() << endl;
	cout << pracownik.getSaldo() << endl;
	cout << pracownik.Oddaj() << endl;
	cout << pracownik.Pozycz() << endl;
	cout << pracownik.SaldoPoWplacieNaObiad() << endl;
	pracownik.przywitanie();
}

void StazystaTest()
{
	Stazysta stazysta("Jasiu", "Pacula", 1245.7);

	cout << stazysta.getId() << endl;
	cout << stazysta.getImie() << endl;
	cout << stazysta.getNazwisko() << endl;
	cout << stazysta.getSaldo() << endl;
	cout << stazysta.SaldoPoWplacieNaObiad() << endl;
	stazysta.przywitanie();
}

void CzlowiekTest()
{
	Czlowiek czlowiek;

	czlowiek.przywitanie();
}

void SkarbonkaTest()
{
	Skarbonka skarbonka;

	skarbonka.getmoney();
	skarbonka.WplacNaObiad();
	skarbonka.ZaplacZaObiad();
}

void PosilekTest()
{
	Posilek posilek;
	posilek.getCena();
}

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
	Pracownik P1(1, "Janek", "Maci", 7889.3);
	Pracownik P2(2, "Maciej", "Miszt", 890.7);
	Pracownik P3(3, "Kuba", "Kras", 687.3);
	Stazysta S1("Lucjan", "Mars", 7876.6);
	Stazysta S2("Alan", "Walker", 67868.4);
	Stazysta S3("Darek", "Just", 67687.2);

	fstream plik;
	plik.open("Zapis.txt", ios::app | ios::in | ios::out);
	if (plik.good() == true)
	{
		cout << "Uzyskano dostep do pliku!" << endl;
		string stazysta = S1.toString();
		plik << stazysta;
		plik.close();
	}
	else cout << "Dostep do pliku zostal zabroniony!" << endl;

}