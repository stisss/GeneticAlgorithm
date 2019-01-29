#pragma once
#include <string>
#include <iostream>
#include "Commands.h"

using namespace std;

class CItem
{
public:
	CItem();
	CItem(double dValue, double dWeight);
	string sToString();
	double dGetValue();
	double dGetWeight();
private:
	double d_value;
	double d_weight;
};