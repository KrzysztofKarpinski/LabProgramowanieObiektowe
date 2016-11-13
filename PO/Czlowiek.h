#pragma once
#include <string>
#include<iostream>
#include"Skarbonka.h"
#include"Czlowiek.h"

using namespace std;

class Czlowiek
{
public:
	int id;
	string imie;
	string nazwisko;
	float saldo;

	Czlowiek(int a, string b, string c, float d);

	~Czlowiek();

	friend float Skarbonka::getmoney();

	float SaldoPoWplacieNaObiad();

	float getSaldo();
};
