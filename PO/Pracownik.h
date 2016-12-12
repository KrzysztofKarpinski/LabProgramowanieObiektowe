#pragma once
#include"Czlowiek.h"

class Pracownik : public Czlowiek
{
public:

	Pracownik(string b, string c, float d);

	float Pozycz();

	float Oddaj();

	void foo() {}
};

