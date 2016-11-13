#include "Skarbonka.h"

Skarbonka::Skarbonka()
{
	gotówka = 150;
}

Skarbonka::Skarbonka(float a)
{
	gotówka = a ;
}

float Skarbonka::Zap³aæZaObiad() 
{ 
	Posilek posilek;
	gotówka -= posilek.getCena();
	return (gotówka); 
}

float Skarbonka::Wp³aæNaObiad()
{
	Posilek posilek;
	gotówka += posilek.getCena();
	return (gotówka);
}

float Skarbonka::getGotówka()
{
	return (gotówka);
}