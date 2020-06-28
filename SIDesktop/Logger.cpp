#include "Logger.h"
#include <iostream>
#include <Windows.h>

#define GREEN 2
#define DEFAULTCOLOR 7
#define RED 12
#define YELLOW 14

namespace Logger {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void LogMessage(const char* message)
	{
		SetConsoleTextAttribute(hConsole, GREEN);
		std::cout << message << std::endl;
		SetConsoleTextAttribute(hConsole, DEFAULTCOLOR);
	}

	void LogWarning(const char* warning)
	{
		SetConsoleTextAttribute(hConsole, YELLOW);
		std::cout << warning << std::endl;
		SetConsoleTextAttribute(hConsole, DEFAULTCOLOR);
	}

	void LogError(const char* error)
	{
		SetConsoleTextAttribute(hConsole, RED);
		std::cout << error << std::endl;
		SetConsoleTextAttribute(hConsole, DEFAULTCOLOR);
	}
}
