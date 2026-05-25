#include <iostream>
#include <windows.h>
#include <string>

#include "utils.h"
#include "ActivityManager.h"

int main()
{
	PrintWelcome();

	std::string name{ "" };
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	ActivityManager activityManager;
	std::string command{ "" };

	while (true)
	{
		command = GetCommand();

		if (!ProcessCommand(command, activityManager))
			break;
	}

	PrintGoodbye(name);
	std::cin.get();

	return 0;
}