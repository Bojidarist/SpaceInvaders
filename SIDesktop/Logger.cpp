#include "Logger.h"
#include <iostream>
#include <Windows.h>

#define GREEN 2
#define DEFAULTCOLOR 7
#define RED 12
#define YELLOW 14

namespace SI {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void LogMessage(const char* message, bool newLine)
	{
		SetConsoleTextAttribute(hConsole, GREEN);
		if(!newLine)
			std::cout << message;
		else
			std::cout << message << std::endl;
		SetConsoleTextAttribute(hConsole, DEFAULTCOLOR);
	}

	void LogWarning(const char* warning, bool newLine)
	{
		SetConsoleTextAttribute(hConsole, YELLOW);
		if (!newLine)
			std::cout << warning;
		else
			std::cout << warning << std::endl;
		SetConsoleTextAttribute(hConsole, DEFAULTCOLOR);
	}

	void LogError(const char* error, bool newLine)
	{
		SetConsoleTextAttribute(hConsole, RED);
		if (!newLine)
			std::cout << error;
		else
			std::cout << error << std::endl;
		SetConsoleTextAttribute(hConsole, DEFAULTCOLOR);
	}
}
