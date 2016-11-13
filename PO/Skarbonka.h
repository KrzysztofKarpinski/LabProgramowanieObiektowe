#pragma once
#include"Posilek.h"

class Skarbonka
{
public:
	float money;

	Skarbonka();

	Skarbonka(float a);
	
	friend float Posilek::getCena();

	float PayForDinner();

	float WplacNaObiad();

	float getmoney();
};
