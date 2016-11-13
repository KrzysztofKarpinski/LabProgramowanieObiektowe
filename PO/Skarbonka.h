#pragma once
#include"Posilek.h"

class Skarbonka
{
public:
	float gotówka;

	Skarbonka();

	Skarbonka(float a);
	
	friend float Posilek::getCena();

	float Zap³aæZaObiad();

	float Wp³aæNaObiad();

	float getGotówka();
};
