#pragma once
#include"Posilek.h"

class Skarbonka
{
public:
	float got�wka;

	Skarbonka();

	Skarbonka(float a);
	
	friend float Posilek::getCena();

	float Zap�a�ZaObiad();

	float Wp�a�NaObiad();

	float getGot�wka();
};
