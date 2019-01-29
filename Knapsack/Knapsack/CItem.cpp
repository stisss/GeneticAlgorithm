#include "CItem.h"

CItem::CItem()
{
	CItem(0.0, 0.0);
}

CItem::CItem(double dValue, double dWeight)
{
	d_value = dValue;
	d_weight = dWeight;
}

string CItem::sToString()
{
	return S_SQUARE_BRACKET_LEFT + to_string(d_value) + S_COMA + to_string(d_weight) + S_SQUARE_BRACKET_RIGHT;
}

double CItem::dGetValue()
{
	return d_value;
}

double CItem::dGetWeight()
{
	return d_weight;
}
