#include "days.h"
#include <vector>
#include <sstream>
#include <iostream>

int RecognizeDay(std::string input)
{

	if (Day01Check(input)) return 1;
	if (Day02Check(input)) return 2;
	if (Day03Check(input)) return 3;
	if (Day04Check(input)) return 4;
	if (Day05Check(input)) return 5;
	if (Day06Check(input)) return 6;
	if (Day07Check(input)) return 7;
	if (Day08Check(input)) return 8;
	if (Day09Check(input)) return 9;
	if (Day10Check(input)) return 10;
	if (Day11Check(input)) return 11;
	if (Day12Check(input)) return 12;
	if (Day13Check(input)) return 13;
	if (Day14Check(input)) return 14;
	if (Day15Check(input)) return 15;
	if (Day16Check(input)) return 16;
	if (Day17Check(input)) return 17;
	if (Day18Check(input)) return 18;
	if (Day19Check(input)) return 19;
	if (Day20Check(input)) return 20;
	if (Day21Check(input)) return 21;
	if (Day22Check(input)) return 22;
	if (Day23Check(input)) return 23;
	if (Day24Check(input)) return 24;
	if (Day25Check(input)) return 25;

	return -1;
}

void AnswerDay(int day, std::string input)
{
	std::pair<int, int> answer;
	switch (day)
	{
	case 1: answer = Day01(input); break;
	case 2: answer =  Day02(input); break;
	case 3: answer =  Day03(input); break;
	case 4: answer =  Day04(input); break;
	case 5: answer =  Day05(input); break;
	case 6: answer =  Day06(input); break;
	case 7: answer =  Day07(input); break;
	case 8: answer =  Day08(input); break;
	case 9: answer =  Day09(input); break;
	case 10: answer =  Day10(input); break;
	case 11: answer =  Day11(input); break;
	case 12: answer =  Day12(input); break;
	case 13: answer =  Day13(input); break;
	case 14: answer =  Day14(input); break;
	case 15: answer =  Day15(input); break;
	case 16: answer =  Day16(input); break;
	case 17: answer =  Day17(input); break;
	case 18: answer =  Day18(input); break;
	case 19: answer =  Day19(input); break;
	case 20: answer =  Day20(input); break;
	case 21: answer =  Day21(input); break;
	case 22: answer =  Day22(input); break;
	case 23: answer =  Day23(input); break;
	case 24: answer =  Day24(input); break;
	case 25: answer =  Day25(input); break;
	default:
		break;
	}

	std::cout << "Answers to Day " << day << " problem:"
		<< std::endl
		<< std::endl << "Part 1: " << answer.first
		<< std::endl << "Part 2: " << answer.second
		<< std::endl;
}
