#include "Skarbonka.h"

Skarbonka::Skarbonka()
{
	money = 0;
}

Skarbonka::Skarbonka(float a)
{
	money = a ;
}

float Skarbonka::ZaplacZaObiad() 
{ 
	Posilek posilek;
	money -= posilek.getCena();
	return (money); 
}

float Skarbonka::WplacNaObiad()
{
	Posilek posilek;
	money += posilek.getCena();
	return (money);
}

float Skarbonka::getmoney()
{
	return (money);
}