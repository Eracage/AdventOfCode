#include "days.h"
#include <regex>
#include <iostream>
#include <sstream>

std::pair<int, int> Day05(std::string input)
{
	int niceStrings = 0;
	int niceStrings2 = 0;

	std::istringstream is(input);

	std::string line;

	while (std::getline(is, line))
	{
		int vowelCount = 0;

		bool row = false;

		char ago2 = 0;
		char last = 0;

		bool nice = true;

		bool pair = false;

		bool repeat = false;

		for (int i = 0; i < line.length(); i++)
		{
			switch (line[i])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowelCount++;
			default:
				break;
			}

			if (last)
			{
				if (last == line[i])
					row = true;

				switch (last)
				{
				case 'a':
					nice = line[i] == 'b' ? false : nice;
					break;
				case 'c':
					nice = line[i] == 'd' ? false : nice;
					break;
				case 'p':
					nice = line[i] == 'q' ? false : nice;
					break;
				case 'x':
					nice = line[i] == 'y' ? false : nice;
					break;
				default:
					break;
				}

				std::string d;
				d += last;
				d += line[i];

				if (line.find(d.c_str(), i + 1, 2) != std::string::npos)
					pair = true;
			}
			if (ago2)
			{
				if (ago2 == line[i])
					repeat = true;
			}
			ago2 = last;
			last = line[i];
		}

		if (nice && vowelCount >= 3 && row)
		{
			niceStrings++;
		}
		if (pair && repeat)
		{
			niceStrings2++;
		}
	}

	return{ niceStrings, niceStrings2 };
}

bool Day05Check(std::string input)
{
	if (input.length() < 15000 || input.length() > 20000)
		return false;
	std::regex pattern("[a-z]{16}");

	return std::regex_search(input, pattern);
	return true;
}
