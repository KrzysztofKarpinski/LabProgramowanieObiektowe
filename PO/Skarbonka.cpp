#include "Skarbonka.h"

Skarbonka::Skarbonka()
{
	money = 150;
}

Skarbonka::Skarbonka(float a)
{
	money = a ;
}

float Skarbonka::PayForDinner() 
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