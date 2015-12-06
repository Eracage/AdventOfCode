#include "days.h"
#include <regex>
#include <iostream>
#include <sstream>

std::pair<int, int> Day02(std::string input)
{
	int size = 0;

	int ribLen = 0;

	std::istringstream is(input);

	std::string line;

	while (std::getline(is, line))
	{
		std::istringstream is2(line);
		std::string temp;
		std::vector<int> dim;
		while (std::getline(is2, temp, 'x'))
			dim.push_back(std::stoi(temp));


		const int l = dim[0];
		const int w = dim[1];
		const int h = dim[2];

		const int lw = l * w;
		const int wh = w * h;
		const int hl = h * l;

		std::vector<int> m;
		m.push_back(l);
		m.push_back(w);
		m.push_back(h);

		std::sort(m.begin(), m.end());

		size += lw * 2 + wh * 2 + hl * 2 + m[0] * m[1];

		ribLen += (m[0] + m[1]) * 2 + l * w * h;
	}

	return{ size, ribLen };
}

bool Day02Check(std::string input)
{
	if (input.length() < 5000 || input.length() > 10000)
		return false;
	std::regex pattern("(\\d{1,3})x(\\d{1,3})x(\\d{1,3})");

	return std::regex_search(input, pattern);
}
