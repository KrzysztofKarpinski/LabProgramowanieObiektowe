#pragma once
#include <string>
#include<iostream>
#include"Skarbonka.h"
#include"Czlowiek.h"

using namespace std;

class Cz�owiek
{
public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Cz�owiek(int a, string b, string c, float d);

	~Cz�owiek();

	friend float Skarbonka::getGot�wka();

	float SaldoPoWp�acieNaObiad();

	float getSaldo();
};
