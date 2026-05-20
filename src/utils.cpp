#include "utils.h"

#include <windows.h>

void PrintWelcome()
{
	std::cout << "Welcome user" << std::endl;
}

void PrintMenu()
{
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Add an activity" << std::endl;
	std::cout << "2. Remove an activity" << std::endl;
	std::cout << "3. Print all activities" << std::endl;
	std::cout << "4. Print long activities" << std::endl;
	std::cout << "5. Print shortest activity" << std::endl;
	std::cout << "6. Print longest activity" << std::endl;
	std::cout << "7. Print average activity name length" << std::endl;
	std::cout << "8. Mark activity as completed" << std::endl;
	std::cout << "9. Show developer mode" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

void PrintGoodbye(const std::string& name)
{
	std::cout << "Goodbye " << name << std::endl;
}

void PrintColoredMessage(const std::string& message, const unsigned short color)
{
	HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
	SetConsoleTextAttribute(hConsole, color);
	std::cout << message << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void PrintWarning(const std::string& message)
{
	PrintColoredMessage(message, 14);
}

void PrintError(const std::string& message)
{
	PrintColoredMessage(message, 12);
}