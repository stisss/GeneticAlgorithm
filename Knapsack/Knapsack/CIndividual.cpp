#include "stdafx.h"
#include "CIndividual.h"

CIndividual::CIndividual()
{
	d_value = 0;
	d_weight = 0;
}
CIndividual::CIndividual(CIndividual & pcOther)
{
	d_value = 0;
	d_weight = 0;
	v_all_items = pcOther.v_all_items;
	s_genotype = pcOther.s_genotype;
	for (int i = 0; i < v_all_items->size(); i++)
	{
		if (s_genotype.at(i) == S_1)
		{
			d_value +=v_all_items->at(i)->dGetValue();
			d_weight += v_all_items->at(i)->dGetWeight();
		}
	}
}
CIndividual::~CIndividual()
{

}
CIndividual::CIndividual(vector<CItem*>* vAllItems, string sGenotype)
{
	d_value = 0;
	d_weight = 0;
	v_all_items = vAllItems;
	s_genotype = sGenotype;
	for (int i = 0; i < vAllItems->size(); i++)
	{
		if (sGenotype.at(i) == S_1)
		{
			d_value += vAllItems->at(i)->dGetValue();
			d_weight += vAllItems->at(i)->dGetWeight();
		}
	}
}

double CIndividual::dGetFitness(double dCapacity)
{
	if (d_weight == 0 || d_weight > dCapacity)
		return 0;
	else
		return dGetValue();
}

double CIndividual::dGetWeight()
{
	return d_weight;
}

double CIndividual::dGetValue()
{
	return d_value;
}

string CIndividual::sToString()
{
	string temp = "";
	for (int i = 0; i < (int)v_all_items->size(); i++)
	{
		if (s_genotype.at(i) == S_1)
			temp += v_all_items->at(i)->sToString();
	}

	return S_SQUARE_BRACKET_LEFT + temp + S_SQUARE_BRACKET_RIGHT;
}

string CIndividual::sGetGenotype()
{
	return s_genotype;
}

vector<CItem*> CIndividual::vGetItems()
{
	vector<CItem*> vec;
	for (int i = 0; i < v_all_items->size(); i++)
		if (sGetGenotype().at(i) == S_1)
			vec.push_back(v_all_items->at(i));
	return vec;
}


