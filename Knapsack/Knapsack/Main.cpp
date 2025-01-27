#include "stdafx.h"
#include <iostream>
#include "Commands.h"
#include "CItem.h"
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include <string>

using namespace std;

int main()
{

	int i_pop_size = 20;
	int i_iterations = 1000;
	double d_capacity = 20.0;
	double d_cross_prob = 0.6;
	double d_mut_prob = 0.05;

	vector<CItem*> items;
	items.push_back(new CItem(1,1));
	items.push_back(new CItem(2, 3));
	items.push_back(new CItem(5, 10));
	items.push_back(new CItem(2, 1));
	items.push_back(new CItem(8, 9));
	CGeneticAlgorithm gen_alg(d_cross_prob, d_mut_prob, i_pop_size, i_iterations);
	CSolution* solution = &gen_alg;
	CKnapsackProblem problem(&items, d_capacity, solution);
	vector<CItem*> resolvedCombination;
	resolvedCombination = problem.vUseSolution();
	for (int i = 0; i < resolvedCombination.size(); i++)
	{
		cout << resolvedCombination.at(i)->sToString() << endl;
	}
	for (int i = 0; i < items.size(); i++)
	{
		delete items.at(i);
	}	
	system("pause");
}