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

	std::string inputString{ "" };
	int inputNumber{ -1 };
	std::string activityName;

	ActivityManager activityManager;

	while (true)
	{
		PrintMenu();

		std::string menu{ "" };
		std::getline(std::cin, menu);

		if (menu.empty())
		{
			PrintError("Please enter a menu option.");
			continue;
		}

		switch (menu[0])
		{
		case ADD_ACTIVITY_OPTION:
			std::cout << "Enter an activity you want to do: ";
			std::getline(std::cin, activityName);
			while (true)
			{
				std::cout << "Enter the priority from 1 to 9 of the activity: ";
				std::getline(std::cin, inputString);

				if (inputString.size() != 1)
				{
					PrintError("The Priority must be between 1 and 9");
				}
				else
				{
					try
					{
						inputNumber = std::stoi(inputString);
					}
					catch (const std::exception& e)
					{
						PrintError("The Priority must be between 1 and 9");
						continue;
					}
				}

				if (inputNumber < 1 || inputNumber > 9)
					PrintError("The Priority must be between 1 and 9");
				else
					break;
			}
			activityManager.AddActivity({ activityName, inputNumber });
			break;
		case REMOVE_ACTIVITY_OPTION:
			activityManager.PrintActivities();
			std::cout << "Enter the index of the activity you want to remove: ";
			std::cin >> inputNumber;
			inputNumber--;
			activityManager.RemoveActivity(inputNumber);
			break;
		case PRINT_ALL_ACTIVITIES_OPTION:
			activityManager.PrintActivities();
			break;
		case PRINT_LONG_ACTIVITIES_OPTION:
			activityManager.PrintLongActivities();
			break;
		case PRINT_SHORTEST_ACTIVITY_OPTION:
			activityManager.PrintShortestActivity();
			break;
		case PRINT_LONGEST_ACTIVITY_OPTION:
			activityManager.PrintLongestActivity();
			break;
		case PRINT_AVERAGE_ACTIVITY_NAME_LENGTH_OPTION:
			activityManager.PrintAverageActivityNameLength();
			break;
		case MARK_ACTIVITY_COMPLETE_OPTION:
			activityManager.PrintActivities();
			std::cout << "Enter the index of the activity you want to complete: ";
			std::cin >> inputNumber;
			std::cin.ignore(256, '\n');
			inputNumber--;
			activityManager.CompleteActivity(inputNumber);
			break;
		case SHOW_DEVELOPER_OPTION:
			activityManager.ShowDeveloperMode();
			break;
		case EXIT_OPTION:
			PrintGoodbye(name);
			std::cin.get();
			return 0;
		default:
			PrintError("Invalid option. Please try again.");
		}
	}

	return 0;
}