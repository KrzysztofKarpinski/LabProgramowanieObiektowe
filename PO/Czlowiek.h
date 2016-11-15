#pragma once
#include <string>
#include<iostream>
#include"Skarbonka.h"

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

	int getId();

	string getImie();

	string getNazwisko();

	float getSaldo();
};
