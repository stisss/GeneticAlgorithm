#pragma once
#include "CSolution.h"
#include <random>
#include "CIndividual.h"


class CGeneticAlgorithm : public CSolution
{
public:
	CGeneticAlgorithm(double dCrossProb, double dMutProb, int iPopSize, int iIterations);
	vector<CItem*> vResolveProblem() override;
	vector<CItem*> vGetTheBest(vector<CIndividual*>* vPopulation);
	CIndividual* cGetBestOfTwo(vector<CIndividual*>& vPopulation);
	CIndividual** cCrossing(CIndividual* cInd1, CIndividual *cInd2);
	string sRandomCombination();
	int iGetRandom(int iFrom, int iTo);
	void vSetItems(vector < CItem*>* vAllItems) override;
	void vSetCapacity(double dCapacity);
	void vDisplayAll(vector<CIndividual*> vPopulation);
	void vCrossing(vector<CIndividual*>* vOldPopulation, vector<CIndividual*>* vNewGeneration);
	void vMutation(CIndividual** cIndividual);
private:
	int i_pop_size;
	int i_iterations;
	double d_cross_prob;
	double d_mut_prob;
	double d_capacity;
	vector<CItem*>* v_all_items;

};