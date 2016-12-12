#pragma once
#include <string>
#include<iostream>

using namespace std;

class Czlowiek
{
public:
	string imie;
	string nazwisko;
	float saldo;

	Czlowiek(string b, string c, float d);

	void foo() {}

	string getImie();

	string getNazwisko();

	float getSaldo();

	float setSaldo(float saldo1);

	string toString();
};
