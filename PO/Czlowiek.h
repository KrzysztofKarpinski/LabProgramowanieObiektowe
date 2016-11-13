#pragma once
#include <string>
#include<iostream>
#include"Skarbonka.h"
#include"Czlowiek.h"

using namespace std;

class Cz³owiek
{
public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Cz³owiek(int a, string b, string c, float d);

	~Cz³owiek();

	friend float Skarbonka::getGotówka();

	float SaldoPoWp³acieNaObiad();

	float getSaldo();
};
