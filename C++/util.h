#pragma once
#include <string>
#include <vector>

std::string GetClipboardText();

void ClearConsole();

std::vector<std::string> split(const std::string &s, char delim);
