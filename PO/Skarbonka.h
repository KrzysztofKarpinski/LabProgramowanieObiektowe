#pragma once
#include"Posilek.h"

class Skarbonka
{
public:
	float money;

	Skarbonka();

	Skarbonka(float a);
	
	friend float Posilek::getCena();

	float ZaplacZaObiad();

	float WplacNaObiad();

	float getmoney();
};
