#pragma once
#include"Czlowiek.h"

class Pracownik : public Czlowiek
{
public:
	Pracownik(int a, string b, string c, float d);

	float Pozycz();

	float Oddaj();
};

