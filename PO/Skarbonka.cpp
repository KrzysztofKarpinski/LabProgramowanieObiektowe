#include "Skarbonka.h"

Skarbonka::Skarbonka()
{
	got�wka = 150;
}

Skarbonka::Skarbonka(float a)
{
	got�wka = a ;
}

float Skarbonka::Zap�a�ZaObiad() 
{ 
	Posilek posilek;
	got�wka -= posilek.getCena();
	return (got�wka); 
}

float Skarbonka::Wp�a�NaObiad()
{
	Posilek posilek;
	got�wka += posilek.getCena();
	return (got�wka);
}

float Skarbonka::getGot�wka()
{
	return (got�wka);
}