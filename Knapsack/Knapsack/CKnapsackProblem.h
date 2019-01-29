#pragma once
#include "CItem.h"
#include "CSolution.h"
#include <vector>
#include <string>
#include "Commands.h"
#include <iostream>

using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem(vector<CItem*>* pItems, double dCapacity, CSolution* cSolution);
	vector<CItem*> vUseSolution();
private:
	double d_capacity;
	vector<CItem*>* v_items;
	CSolution* v_solution;
};