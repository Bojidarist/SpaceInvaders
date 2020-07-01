#include "SIMath.h"
#include <iostream>

int SI::SIMath::Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else if (x > y)
	{
		return y;
	}

	return x;
}

int SI::SIMath::Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else if (x < y)
	{
		return y;
	}

	return x;
}

int SI::SIMath::Clamp(int x, int lower, int upper)
{
	return SI::SIMath::Min(upper, SI::SIMath::Max(x, lower));
}
