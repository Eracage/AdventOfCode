#include "days.h"
#include <iostream>

std::pair<int, int> Day01(std::string input)
{
	int floor = 0;
	int cellar = 0;
	for (int i = 0; i < input.length(); i++)
	{
		input[i] == '(' ? floor++ : floor--;
		if (!cellar && floor == -1)
			cellar = i + 1;
	}
	return{ floor, cellar };
}

bool Day01Check(std::string input)
{
	if (input.length() < 6000 || input.length() > 8000)
		return false;
	for each (auto c in input)
	{
		if (c != '(' && c != ')')
			return false;
	}
	return true;
}
