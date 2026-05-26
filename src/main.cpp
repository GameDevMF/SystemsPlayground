#include <iostream>
#include <windows.h>
#include <string>

#include "utils.h"
#include "ActivityManager.h"

static AppConfig s_appConfig;

int main()
{
	if (s_appConfig.bShowWelcomeMessage)
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

	if (s_appConfig.bShowDeveloperModeEnabled)
		activityManager.ShowDeveloperMode();

	std::cin.get();

	return 0;
}