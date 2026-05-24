#include "utils.h"

#include <windows.h>
#include <string>

void PrintWelcome()
{
	std::cout << "Welcome user" << std::endl;
}

void PrintMenu()
{
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Add an activity" << std::endl;
	std::cout << "2. Start an activity" << std::endl;
	std::cout << "3. Complete activity" << std::endl;
	std::cout << "4. Remove an activity" << std::endl;
	std::cout << "5. Sort activities by name" << std::endl;
	std::cout << "6. Sort activities by priority" << std::endl;
	std::cout << "7. Sort activities by status" << std::endl;
	std::cout << "8. Sort activities by priority then name" << std::endl;
	std::cout << "9. Print all activities" << std::endl;
	std::cout << "0. Print long activities" << std::endl;
	std::cout << "a. Print shortest activity" << std::endl;
	std::cout << "b. Print longest activity" << std::endl;
	std::cout << "c. Print average activity name length" << std::endl;
	std::cout << "d. Print todo activities" << std::endl;
	std::cout << "e. Print in-progress activities" << std::endl;
	std::cout << "f. Print completed activities" << std::endl;
	std::cout << "g. Clear all activities" << std::endl;
	std::cout << "h. Show developer mode" << std::endl;
	std::cout << "i. Exit" << std::endl;
}

void PrintPriorityMenu()
{
	std::cout << "Priority levels:" << std::endl;
	std::cout << "1. Lowest" << std::endl;
	std::cout << "2. Low" << std::endl;
	std::cout << "3. Medium" << std::endl;
	std::cout << "4. High" << std::endl;
	std::cout << "5. Highest" << std::endl;
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

bool TryToGetInputNumber(const std::string& inputString, int& outputNumber)
{
	try
	{
		outputNumber = std::stoi(inputString);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}