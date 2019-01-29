#pragma once
#include "CItem.h"
#include <vector>

using namespace std;

class CIndividual
{
public:
	CIndividual();
	CIndividual(CIndividual& pcOther);
	~CIndividual();
	CIndividual(vector<CItem*>* vAllItems, string sGenotype);
	double dGetFitness(double dCapacity);
	double dGetWeight();
	double dGetValue();
	string sToString();
	string sGetGenotype();
	vector<CItem*> vGetItems();

private:
	vector<CItem*>* v_all_items;
	string s_genotype;
	double d_value;
	double d_weight;
	double d_fitness;
};

