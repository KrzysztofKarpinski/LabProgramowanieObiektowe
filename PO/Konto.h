#pragma once
#include <string>
#include<iostream>
#include<vector>
#include"Pracownik.h"
#include"Sta¿ysta.h"

using namespace std;

class Konto
{
public:
	vector<Sta¿ysta> sta¿ysta;
	vector<Pracownik> pracownik;

	Konto(int a, string b, string c, float d);

	~Konto();

	int getId();

	string getImie();

	string getNazwisko();

	float getSaldo();
};
