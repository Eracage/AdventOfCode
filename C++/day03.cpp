#include "days.h"
#include <map>

std::pair<int, int> Day03(std::string input)
{
	int houseCount = 0;
	int houseCount2 = 0;

	std::map<std::pair<int, int>, int> houses;
	std::map<std::pair<int, int>, int> houses2;

	int x[] = { 0, 0, 0 };
	int y[] = { 0, 0, 0 };

	bool robo = false;

	houses[{x[0], y[0]}]++;

	houses2[{x[1], y[1]}]++;
	houses2[{x[2], y[2]}]++;

	for each (auto c in input)
	{
		switch (c)
		{
		case '<':
			x[0]--;
			x[1 + robo]--;
			break;
		case '>':
			x[0]++;
			x[1 + robo]++;
			break;
		case '^':
			y[0]++;
			y[1 + robo]++;
			break;
		case 'v':
			y[0]--;
			y[1 + robo]--;
			break;
		default:
			break;
		}

		robo = !robo;

		houses[{x[0], y[0]}]++;
		houses2[{x[1+robo], y[1+robo]}]++;
	}

	houseCount = houses.size();
	houseCount2 = houses2.size();


	return{ houseCount, houseCount2 };
}

bool Day03Check(std::string input)
{
	if (input.length() < 5000 || input.length() > 10000)
		return false;
	for each (auto c in input)
	{
		if (c != '<' &&
			c != '>' &&
			c != '^' &&
			c != 'v')
			return false;
	}
	return true;
}
