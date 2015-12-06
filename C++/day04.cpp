#include "days.h"
#include "md5.h"
#include <iostream>

std::pair<int, int> Day04(std::string input)
{
	MD5 md5;

	int h5 = 0;
	int h6 = 0;

	for (int i = 0;; i++)
	{
		std::string newInput = input + std::to_string(i);
		std::string hashed = md5.digestString((char*)&newInput[0]);

		if (!h5 && hashed.find("00000", 0, 5) == 0)
			h5 = i;
		if (!h6 && hashed.find("000000", 0, 6) == 0)
			h6 = i;
		if (h5 && h6)
			break;
	}

	return{ 0, 0 };
}

bool Day04Check(std::string input)
{
	if (input.length() < 4 || input.length() > 10)
		return false;
	return true;
	return false;
}
