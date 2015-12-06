#include <iostream>
#include "util.h"
#include "days.h"
#include <Windows.h>
#include <sstream>

int main()
{
	std::stringstream title;

	std::string input;
	std::string lastInput;

	void* ptr;

	int day = -1;

	title << "Advent of Code 2015 Solver"
		<< std::endl
		<< std::endl << "To Begin, please copy the input into clipboard"
		<< std::endl
		<< std::endl;

	std::cout << title.str();

	do 
	{
		input = GetClipboardText();
		if (input != lastInput)
		{
			ClearConsole();

			std::cout << title.str();

			day = RecognizeDay(input);

			if (day > 0)
			{
				AnswerDay(day,input);
			}
			else
			{
				std::cout << "Input not recognized as input for any of the known problems";
			}
			lastInput = input;
		}
	} while (true);

}
