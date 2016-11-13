#include<vector>
#include "Kasa.h"
#include<stdio.h>
#include<string>

vector<Konto> Lista_Kont;

Kasa::Kasa()
{
	Lista_Kont.clear();
}

Kasa::~Kasa()
{

}

void Kasa::DodajKontoPracownika(Konto P)
{
	bool istnieje;
	for (vector<Konto>::iterator konto = this->Lista_Kont.begin(); konto != this->Lista_Kont.end(); konto++)
	{
		if (konto->getId() == P.getId())
		{
			cout << "Z³y Id" << endl;
			istnieje = true;
		}
	}
	if (istnieje = false)
	{
		Lista_Kont.push_back(P);
	}
}



void PokazKonta()
{

}

void UsuñKonto()
{

}