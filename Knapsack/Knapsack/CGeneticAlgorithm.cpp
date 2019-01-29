#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm(double dCrossProb, double dMutProb, int iPopSize, int iIterations)
{
	i_pop_size = iPopSize;
	i_iterations = iIterations;
	d_cross_prob = dCrossProb;
	d_mut_prob = dMutProb;
}

vector<CItem*> CGeneticAlgorithm::vResolveProblem()
{
	vector<CIndividual*> population;
	vector<CIndividual*> new_generation;
	for (int i = 0; i < i_pop_size; i++)
	{
		population.push_back(new CIndividual(v_all_items, sRandomCombination()));
	}
	for (int j = 0; j < i_iterations; j++)
	{
		for (int i = 0; i < i_pop_size; i = i + 2)
		{
			vCrossing(&population, &new_generation);
			vMutation(&new_generation.at(i));
			vMutation(&new_generation.at(i + 1));
		}
		for (int i = 0; i < i_pop_size; i++)
		{
			delete population.at(i);
		}
		population.clear();
		for (int i = 0; i < i_pop_size; i++)
		{
			population.push_back(new_generation.at(i));
		}
		new_generation.clear();
	}

	return vGetTheBest(&population);
}

CIndividual * CGeneticAlgorithm::cGetBestOfTwo(vector<CIndividual*> &vGeneration)
{
	CIndividual* ind1 = vGeneration.at(iGetRandom(0, i_pop_size - 1));
	CIndividual* ind2 = vGeneration.at(iGetRandom(0, i_pop_size - 1));
	return (ind1->dGetFitness(d_capacity) >= ind2->dGetFitness(d_capacity)) ? ind1 : ind2;
}

string CGeneticAlgorithm::sRandomCombination()
{
	string chain = "";

	for (int i = 0; i < v_all_items->size(); i++)
		chain += to_string(iGetRandom(0, 1));

	return chain;
}

void CGeneticAlgorithm::vCrossing(vector<CIndividual*>* vOldGeneration, vector<CIndividual*>* vNewGeneration)
{
	CIndividual* ind1 = cGetBestOfTwo(*vOldGeneration);
	CIndividual* ind2 = cGetBestOfTwo(*vOldGeneration);
	string s_parent1 = ind1->sGetGenotype();
	string s_parent2 = ind2->sGetGenotype();
	if ((double)iGetRandom(0, 100) / 100.0 <= d_cross_prob)
	{
		int i_crossing_point = iGetRandom(1, v_all_items->size() - 1);

		string s_child1;
		string s_child2;

		for (int i = 0; i < i_crossing_point; i++)
		{
			s_child1 += s_parent1[i];
			s_child2 += s_parent2[i];
		}
		for (int i = i_crossing_point; i < v_all_items->size(); i++)
		{
			s_child1 += s_parent2[i];
			s_child2 += s_parent1[i];
		}

		vNewGeneration->push_back(new CIndividual(v_all_items, s_child1));
		vNewGeneration->push_back(new CIndividual(v_all_items, s_child2));
	}
	else
	{
		vNewGeneration->push_back(new CIndividual(*ind1));
		vNewGeneration->push_back(new CIndividual(*ind2));
	}
}

CIndividual** CGeneticAlgorithm::cCrossing(CIndividual* cInd1, CIndividual *cInd2)
{
	CIndividual* new_ind1;
	CIndividual* new_ind2;
	string s_parent1 = cInd1->sGetGenotype();
	string s_parent2 = cInd2->sGetGenotype();
	if ((double)iGetRandom(0, 100) / 100.0 <= d_cross_prob)
	{
		int i_crossing_point = iGetRandom(1, v_all_items->size() - 1);

		string s_child1;
		string s_child2;

		for (int i = 0; i < i_crossing_point; i++)
		{
			s_child1 += s_parent1[i];
			s_child2 += s_parent2[i];
		}
		for (int i = i_crossing_point; i < v_all_items->size(); i++)
		{
			s_child1 += s_parent2[i];
			s_child2 += s_parent1[i];
		}

		new_ind1 = new CIndividual(v_all_items, s_child1);
		new_ind2 = new CIndividual(v_all_items, s_child2);
	}
	else
	{
		new_ind1 = new CIndividual(v_all_items, s_parent1);
		new_ind2 = new CIndividual(v_all_items, s_parent2);
	}
	CIndividual ** return_pack = new CIndividual *[2];
	return_pack[0] = new_ind1;
	return_pack[1] = new_ind2;
	return return_pack;
}

void CGeneticAlgorithm::vMutation(CIndividual ** cIndividual)
{
	string s_new_genotype = (*cIndividual)->sGetGenotype();

	for (int i = 0; i < v_all_items->size(); i++)
	{
		if ((double)iGetRandom(0, 100) / 100.0 <= d_mut_prob)
		{
			if (s_new_genotype.at(i) == S_0)
				s_new_genotype.at(i) = S_1;
			else
				s_new_genotype.at(i) = S_0;
		}
	}
	if (s_new_genotype != (*cIndividual)->sGetGenotype())
	{
		delete *cIndividual;
		*cIndividual = new CIndividual(v_all_items, s_new_genotype);
	}
}

int CGeneticAlgorithm::iGetRandom(int iFrom, int iTo)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(iFrom, iTo);
	return dis(gen);
}

void CGeneticAlgorithm::vSetItems(vector<CItem*>* vAllItems)
{
	v_all_items = vAllItems;
}

void CGeneticAlgorithm::vSetCapacity(double dCapacity)
{
	d_capacity = dCapacity;
}

void CGeneticAlgorithm::vDisplayAll(vector<CIndividual*> vPopulation)
{
	for (int i = 0; i < vPopulation.size(); i++)
	{
		cout << vPopulation.at(i)->sGetGenotype() << endl;
	}
	cout << endl;
}

vector<CItem *> CGeneticAlgorithm::vGetTheBest(vector<CIndividual*>* vPopulation)
{
	CIndividual* best = new CIndividual();
	for (int i = 0; i < vPopulation->size(); i++)
	{
		if (vPopulation->at(i)->dGetFitness(d_capacity) > best->dGetFitness(d_capacity))
		{
			delete best;
			best = vPopulation->at(i);
		}
		else
		{
			delete vPopulation->at(i);
		}
	}
	vector<CItem*> bestItems = best->vGetItems();
	delete best;

	return bestItems;
}



