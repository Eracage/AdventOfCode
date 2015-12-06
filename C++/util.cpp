#include <Windows.h>
#include <sstream>
#include "util.h"

std::string GetClipboardText()
{
	std::string retVal;
	if (!OpenClipboard(nullptr))
	{
		return retVal;
	}

	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr)
	{
		return retVal;
	}

	char* ptr = static_cast<char*>(GlobalLock(hData));
	if (ptr == nullptr)
	{
		return retVal;
	}

	std::string text(ptr);

	GlobalUnlock(hData);

	CloseClipboard();

	return text;
}

void ClearConsole()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	SetConsoleCursorPosition(console, topLeft);
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
