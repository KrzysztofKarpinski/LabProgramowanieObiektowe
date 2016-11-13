#include<vector>
#include "Kasa.h"
#include<stdio.h>
#include<string>

vector<Konto> Lista_Kont;			//http://geosoft.no/development/cppstyle.html

Kasa::Kasa()
{
	Lista_Kont.clear();
}

Kasa::~Kasa()
{

}

void Kasa::DodajKontoPracownika(Konto kontoWejsciowe)
{
	if (!this->JestNaLiscie(kontoWejsciowe))		//jezeli konta nie ma na li�cie to
	{
		//dodaj pracownika
	}
	else											//je�eli jest to
	{
		//Wy�wietl informacj�, �e u�ytkownik ju� jest w systemie
	}
}

bool Kasa::JestNaLiscie(Konto kontoWejsciowe)
{
	for (vector<Konto>::iterator konto = this->Lista_Kont.begin(); konto != this->Lista_Kont.end(); konto++)
	{
		if (konto->getId() == kontoWejsciowe.getId())
		{
			return true;
		}
	}
	return false;
}


void PokazKonta()
{

}

void Usu�Konto()
{

}