#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem(vector<CItem*>* pItems, double dCapacity, CSolution* cSolution)
{
	if (pItems == nullptr || cSolution == nullptr)
	{
		cout << S_CONSTRUCTOR_ERROR << endl;
	}
	v_items = pItems;
	d_capacity = dCapacity;
	v_solution = cSolution;
	v_solution->vSetItems(v_items);
	v_solution->vSetCapacity(d_capacity);
	
}

vector<CItem*> CKnapsackProblem::vUseSolution()
{
	return v_solution->vResolveProblem();
}
