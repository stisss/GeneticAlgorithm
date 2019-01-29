#pragma once
#include "CItem.h"
#include <iostream>
#include <vector>

using namespace std;

class CSolution 
{
public:
	virtual vector<CItem*> vResolveProblem() = 0;
	virtual void vSetCapacity(double dCapacity) = 0;
	virtual void vSetItems(vector < CItem*>* vAllItems) = 0;	
};