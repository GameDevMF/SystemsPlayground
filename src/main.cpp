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
				std::cout << "Enter the priority of the activity: ";
				
				PrintPriorityMenu();

				std::getline(std::cin, inputString);

				if (inputString.size() != 1)
				{
					PrintError("The Priority must be between 1 and 5");
				}
				else if (!TryToGetInputNumber(inputString, inputNumber))
				{
					PrintError("The Priority must be a valid number");
					continue;
				}

				if (inputNumber < 1 || inputNumber > 5)
					PrintError("The Priority must be between 1 and 5");
				else
					break;
			}
			activityManager.AddActivity({ activityName, static_cast<PriorityLevel>(inputNumber) });
			break;
		case START_ACTIVITY_OPTION:
			while (true)
			{
				std::cout << "Enter the index of the activity you want to start: ";

				activityManager.PrintActivities();

				std::getline(std::cin, inputString);

				if (!TryToGetInputNumber(inputString, inputNumber))
				{
					PrintError("The Priority must be a valid number");
					continue;
				}
				
				break;
			}

			inputNumber--;
			activityManager.StartActivity(inputNumber);
			break;
		case COMPLETE_ACTIVITY_OPTION:
			while (true)
			{
				std::cout << "Enter the index of the activity you want to complete: ";

				activityManager.PrintActivities();

				std::getline(std::cin, inputString);

				if (!TryToGetInputNumber(inputString, inputNumber))
				{
					PrintError("The Priority must be a valid number");
					continue;
				}

				break;
			}

			inputNumber--;
			activityManager.CompleteActivity(inputNumber);
			break;
		case REMOVE_ACTIVITY_OPTION:
			while (true)
			{
				std::cout << "Enter the index of the activity you want to remove: ";

				activityManager.PrintActivities();

				std::getline(std::cin, inputString);

				if (!TryToGetInputNumber(inputString, inputNumber))
				{
					PrintError("The Priority must be a valid number");
					continue;
				}

				break;
			}

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
		case PRINT_TODO_ACTIVITIES_OPTION:
			activityManager.PrintActivitiesByStatus(ActivityStatus::Todo);
			break;
		case PRINT_IN_PROGRESS_ACTIVITIES_OPTION:
			activityManager.PrintActivitiesByStatus(ActivityStatus::InProgress);
			break;
		case PRINT_COMPLETED_ACTIVITIES_OPTION:
			activityManager.PrintActivitiesByStatus(ActivityStatus::Completed);
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